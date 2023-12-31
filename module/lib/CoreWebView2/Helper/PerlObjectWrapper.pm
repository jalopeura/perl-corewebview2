use strict;
package CoreWebView2::Helper::PerlObjectWrapper;
use CoreWebView2 qw(:DISPATCH);

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

sub new {
	my ($class, $to_wrap) = @_;

	my $self = bless {
		wrapped => $to_wrap, # DO NOT CHANGE this key - the XS code relies on it
		id2name => [ '_' ],
		name2id => { '_' => 0 },
	}, $class;
#warn;
#CoreWebView2::dump($self);
#warn;
	return $self;
}

# $ref_id - current always IID_NULL
# $names - aref of names to return ids for
# $locale_id - can be ignored unless you want to support different names for different locales
#              (see https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8)

sub GetIDsOfNames {
	my ($self, $ref_id, $names, $locale_id) = @_;

	my @ids;
	for my $name (@$names) {
		unless ($self->{name2id}{$name}) {
			push @{ $self->{id2name} }, $name;
			$self->{name2id}{$name} = $#{ $self->{id2name} };
		}
		push @ids, $self->{name2id}{$name};
	}

	return \@ids;
}

# $id - the id of the method or property to be invoked
# $ref_id - current always IID_NULL
# $locale_id - can be ignored unless you want to support different names for different locales (see above)
# $flags - how to invoke
# $params - params to be passed to an invoked method (may be empty)

# the caller may not want a return value; wantarray() will return accordingly

sub Invoke {
	my ($self, $id, $ref_id, $locale_id, $flags, $params) = @_;
#warn Dumper \@_;

	my $name = $self->{id2name}[$id];
#warn;

	# when you call a method from JS, it first fetches the method function as a property, then invokes the function

	if ($flags == DISPATCH_METHOD) {
#warn "Method $name";
		# $id == 0 means the wrapped object is a function (coderef)
		if ($id == 0) {
			return $self->{wrapped}->(@$params);
		}

		# in theory, we should never get here from JS, but just in case
		no strict;
		return $self->{wrapped}->$name(@$params);
	}

	if ($flags == DISPATCH_PROPERTYGET) {
#warn "Get property $name";
		# for methods, JS fetches the function as a property, so we need to check that here
		if (my $subref = $self->{wrapped}->can($name)) {
			return sub { $subref->($self->{wrapped}, @_) };
		}
#warn "$name => $self->{wrapped}{$name}";
		return $self->{wrapped}{$name};
	}

	if ($flags == DISPATCH_PROPERTYPUT) {
#warn "Set property $name => $params->[0]";
		$self->{wrapped}{$name} = $params->[0];
		return $self->{wrapped}{$name};
	}

	if ($flags == DISPATCH_PROPERTYPUTREF) {
#warn "Set property as reference";
	}
#warn "Got here";
}

#sub DESTROY {
#warn;
#warn Dumper \@_;
#CoreWebView2::dump($_[0]{wrapped});
#warn;
#}

# DISPATCH_METHOD         The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag can be set.
# DISPATCH_PROPERTYGET    The member is retrieved as a property or data member.
# DISPATCH_PROPERTYPUT    The member is changed as a property or data member.
# DISPATCH_PROPERTYPUTREF The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object.

1;
