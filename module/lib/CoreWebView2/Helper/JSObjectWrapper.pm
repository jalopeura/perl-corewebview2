use strict;
package CoreWebView2::Helper::JSObjectWrapper;

#current issue: callbacks appear to not return values
#known issue
#https://github.com/MicrosoftEdge/WebView2Feedback/issues/515
#https://github.com/MicrosoftEdge/WebView2Feedback/issues/1248
# CoreWebView2::Helper::CodeRunner
# unable to set JS values from Perl - also a known issue?



#JavaScript doesn't distinguish between objects and hashes like Perl does; it just has objects with methods and objects
#without methods. And a "method" isn't really a method, it's just a property that happens to be a function. So a
#JavaScript object is exposed as a blessed Perl object, whether or not it has methods. You can call a method as you
#would in Perl, but you can also access it as a property, in which case the value will be a subref. That is, these will
#do the same thing:
#
#    $object->method(@params);
#    $object->{method}->(@params);

# id 0 is the top-level object
use overload
	'&{}' => sub {
		my $self = shift;
		return sub { CoreWebView2::Helper::JSObjectWrapper::Base::as_function($self, @_); };
	},
	fallback => 1;

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

sub new {
	my ($class, $dispatch) = @_;

	tie my %self, 'CoreWebView2::Helper::JSObjectWrapper::Base', $dispatch;

	return bless \%self, $class;
}

# nothing to do here, we just don't want it going through AUTOLOAD
sub DESTROY {}

our $AUTOLOAD;
sub AUTOLOAD {
	my ($self, @params) = @_;

	my ($key) = $AUTOLOAD=~/([^:]+)$/;
	my $function = $self->{$key};
	if ($function) {
		$function->(@params);
	}
	else {
		# generate the usual warning
		no strict;
		$AUTOLOAD->($self, @params);
	}
}

package CoreWebView2::Helper::JSObjectWrapper::Base;
use CoreWebView2 qw(:DISPATCH);

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

use Tie::Hash;
our @ISA = qw(Tie::StdHash);

sub as_function {
	my ($wrapper, @params) = @_;
	my $self = tied %$wrapper;

	# use id 0 to call object as function
	return $self->{dispatch}->Invoke(
		0,                  # id 0 is the dispatch itself - used for callbacks
		DISPATCH_METHOD,    # method/function not property
		defined(wantarray), # wants return
		\@params            # params
	);
}

sub TIEHASH {
	my ($class, $dispatch) = @_;

	return bless {
		dispatch => $dispatch, # DO NOT CHANGE this key - the XS code relies on it
	}, $class;
}

sub FETCH {
	my ($self, $key) = @_;

	my $id = $self->{dispatch}->GetIDsOfNames([$key]);
	return $self->{dispatch}->Invoke($id->[0], DISPATCH_PROPERTYGET, 1);
}

sub STORE {
	my ($self, $key, $value) = @_;

	my $id = $self->{dispatch}->GetIDsOfNames([$key]);
	return $self->{dispatch}->Invoke($id->[0], DISPATCH_PROPERTYPUT, 0, [ $value ]);
}

sub EXISTS {
	my ($self, $key) = @_;

	my $id = $self->{dispatch}->GetIDsOfNames([$key]);
	return defined $id;
}

sub FIRSTKEY {
	my ($self) = @_;

	$self->{keys} = $self->{dispatch}->GetKeys();
	return shift @{ $self->{keys} };
}

sub NEXTKEY {
	my ($self) = @_;

	return shift @{ $self->{keys} };
}

sub DELETE {
	my ($self, $key) = @_;

	die "Cannot delete JS object property from Perl";
}

sub CLEAR {
	my ($self) = @_;

	die "Cannot clear JS object from Perl";
}

# DISPATCH_METHOD         The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag can be set.
# DISPATCH_PROPERTYGET    The member is retrieved as a property or data member.
# DISPATCH_PROPERTYPUT    The member is changed as a property or data member.
# DISPATCH_PROPERTYPUTREF The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object.

1;
