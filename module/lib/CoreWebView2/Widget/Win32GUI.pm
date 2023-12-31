use strict;

package CoreWebView2::Widget::Win32GUI;
use Win32::GUI;
use CoreWebView2::Widget;
our @ISA = qw(CoreWebView2::Widget Win32::GUI Win32::GUI::WindowProps);

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

sub Win32::GUI::Window::AddWebView { return __PACKAGE__->new(@_); }

sub new {
	my ($class, $parent, %options) = @_;

	my %init;
	for my $param ($class->params) {
		my $key = '-' . $param;
		next unless $options{$key};
		$init{$param} = delete $options{$key};
	}

	my $self = Win32::GUI->_new(Win32::GUI::_constant("WIN32__GUI__STATIC"), $class, $parent, %options);

	$self->{hwnd} = $self->{-handle};

	$self->init(%init);

	return $self;
}

sub Resize {
	my ($self, $width, $height) = @_;

	$self->put_Bounds({
		left   => 0,
		top    => 0,
		right  => $width,
		bottom => $height,
	});

	$self->SUPER::Resize($width, $height);
}

1;
