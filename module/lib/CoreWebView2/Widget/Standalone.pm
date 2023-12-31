use strict;

package CoreWebView2::Widget::Standalone;
use parent qw(CoreWebView2::Widget);

sub new {
	my ($class, %options) = @_;

	my %init;
	for my $param ($class->params) {
		next unless $options{$param};
		$init{$param} = delete $options{$param};
	}

	my $self = bless {}, $class;

	$self->{hwnd} = CoreWebView2::create_host_window(sub {
		my ($rect) = @_;
		$self->set_bounds($rect);
	});

	$self->init(%init);

	return $self;
}

sub run {
	CoreWebView2::start_window_loop();
}

sub quit {
	my ($self) = @_;
	CoreWebView2::close_window($self->{window});
}

1;
