use strict;

package CoreWebView2::Widget::Prima;
use Prima;
use CoreWebView2::Widget;
our @ISA = qw(CoreWebView2::Widget Prima::Widget);
# Prima must be first in ancestors or we get a VMT error
#our @ISA = qw(Prima::Widget CoreWebView2::Widget);

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

# here alias us to Prima::WebView or similar?
{
	no strict 'refs';
	*{"Prima::CoreWebView2::"} = *{__PACKAGE__ . '::'};
}

sub create {
	my ($class, %options) = @_;

	my %init;
	for my $param ($class->params) {
		next unless $options{$param};
		$init{$param} = delete $options{$param};
	}
#warn Dumper \%init;
#warn Dumper \%options;
#warn;

	my $self = Prima::Widget->create(%options);
	bless $self, $class;

	my ($w, $h) = $self->size();
	$self->set_bounds({
		left   => 0,
		top    => 0,
		right  => $w,
		bottom => $h,
	});

	# weird format - starts with 0x but is a decimal
	($self->{hwnd} = $self->get_handle)=~s/^0x//;

#warn Dumper \%init;
	$self->CoreWebView2::Widget::init(%init);

	return $self;
}

sub on_size {
	my ($self, $oldw, $oldh, $neww, $newh) = @_;

	$self->set_bounds({
		left   => 0,
		top    => 0,
		right  => $neww,
		bottom => $newh,
	});

	# no Prima::Widget::on_size?
#	$self->Prima::Widget::on_size(@_);
}

1;
