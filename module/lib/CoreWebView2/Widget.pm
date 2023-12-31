use strict;
use CoreWebView2;

package CoreWebView2::Widget;
use Scalar::Util qw(blessed);

our $DEBUG = 0;

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

my %EVENTS = (
	'globals' => [qw(CreateCoreWebView2EnvironmentCompleted)],
	'BrowserExtension' => [qw(BrowserExtensionEnableCompleted BrowserExtensionRemoveCompleted)],
	'CompositionController' => [qw(CursorChanged)],
	'ContextMenuItem' => [qw(CustomItemSelected)],
	'Controller' => [qw(AcceleratorKeyPressed FocusChanged MoveFocusRequested RasterizationScaleChanged ZoomFactorChanged)],
	'CookieManager' => [qw(GetCookiesCompleted)],
	'CoreWebView2' => [qw(AddScriptToExecuteOnDocumentCreatedCompleted BasicAuthenticationRequested CallDevToolsProtocolMethodCompleted CapturePreviewCompleted ClearServerCertificateErrorActionsCompleted ClientCertificateRequested ContainsFullScreenElementChanged ContentLoading ContextMenuRequested DOMContentLoaded DocumentTitleChanged DownloadStarting ExecuteScriptCompleted FaviconChanged FrameCreated GetFaviconCompleted HistoryChanged IsDefaultDownloadDialogOpenChanged IsDocumentPlayingAudioChanged IsMutedChanged LaunchingExternalUriScheme NavigationCompleted NavigationStarting NewWindowRequested PermissionRequested PrintCompleted PrintToPdfCompleted PrintToPdfStreamCompleted ProcessFailed ScriptDialogOpening ServerCertificateErrorDetected SourceChanged StatusBarTextChanged TrySuspendCompleted WebMessageReceived WebResourceRequested WebResourceResponseReceived WindowCloseRequested)],
	'DevToolsProtocolEventReceiver' => [qw(DevToolsProtocolEventReceived)],
	'DownloadOperation' => [qw(BytesReceivedChanged EstimatedEndTimeChanged StateChanged)],
	'Environment' => [qw(BrowserProcessExited CreateCoreWebView2CompositionControllerCompleted CreateCoreWebView2ControllerCompleted GetProcessExtendedInfosCompleted NewBrowserVersionAvailable ProcessInfosChanged)],
	'Frame' => [qw(ExecuteScriptCompleted FrameContentLoading FrameDOMContentLoaded FrameDestroyed FrameNameChanged FrameNavigationCompleted FrameNavigationStarting FramePermissionRequested FrameWebMessageReceived)],
	'Profile' => [qw(ClearBrowsingDataCompleted GetNonDefaultPermissionSettingsCompleted ProfileAddBrowserExtensionCompleted ProfileDeleted ProfileGetBrowserExtensionsCompleted SetPermissionStateCompleted)],
	'WebResourceResponseView' => [qw(WebResourceResponseViewGetContentCompleted)],
);
sub events { %EVENTS }

my @params = (
	qw(environment uri),
	map { 'on' . $_ } (
		@{ $EVENTS{globals} },
		@{ $EVENTS{CoreWebView2} },
		@{ $EVENTS{CompositionController} },
		@{ $EVENTS{Controller} },
		@{ $EVENTS{CookieManager} },
		@{ $EVENTS{ContextMenuItem} },
		@{ $EVENTS{DevToolsProtocolEventReceiver} },
		@{ $EVENTS{DownloadOperation} },
		@{ $EVENTS{Environment} },
		@{ $EVENTS{Frame} },
		@{ $EVENTS{Profile} },
		@{ $EVENTS{WebResourceResponseView} },
		@{ $EVENTS{BrowserExtension} },
	)
);
sub params { @params }

sub init {
	my ($self, %options) = @_;

	$self->{pending} = [];

	$self->{events} = { map { ($_ => $options{'on' . $_}) } grep { s/^on// } keys %options };

	$self->{views} = [];
	my $view = $self->add_view(delete $options{uri});

	# do we have an environment option?
	if (my $environment = delete $options{environment}) {
		# blessed object?
		if (blessed($environment)) {
			# CoreWebview2::Widget?
			my $isa_widget = eval { $environment->isa(__PACKAGE__) };
			if ($isa_widget) {
				$environment = $environment->{environment};
			}

			# CoreWebview2::Environment?
			my $isa_object = eval { $environment->isa('CoreWebView2::Environment') };
			if ($isa_object) {
				$self->{environment} = $environment->{environment};
#
# TODO: "adopt" a view from another widget instead of adding an empty view
#
				$self->add_view();
				return $self;
			}
		}

		# if we have anything at all, assume href and create an environment object
		my $browser_folder = $environment->{browserExecutableFolder};
		my $data_folder    = $environment->{userDataFolder};
		my $options        = $environment->{environmentOptions};

		CoreWebView2::CreateCoreWebView2EnvironmentWithOptions($browser_folder, $data_folder, $options, $self);
	}
	else {
		# otherwise go with the defaults
		CoreWebView2::CreateCoreWebView2Environment($self);
	}

	return;
}

sub new_window {
	my $self = shift;
	my $class = ref $self;
	return $class->new(@_);
}

sub add_view {
	my ($self, $uri, $force) = @_;

	my $view = CoreWebView2::Widget::View->new(
		widget     => $self,
	);

	push @{ $self->{views} }, $view;

	if ($force || not defined $self->{active_view}) {
		$self->{active_view} = $#{ $self->{views} };
	}

	if ($uri) {
		$view->Navigate($uri);
	}

	$self->CreateCoreWebView2Controller($self->{hwnd}, $view);

	return $view;
}

sub views {
	my ($self) = @_;
	return @{ $self->{views} };
}

sub set_active_view {
	my ($self, $active) = @_;

	if (ref $active) {
		my @match = grep { $active == $self->{views}{$_} } (0..$#{ $self->{views} });
		unless (@match) {
			warn "The Widget does not contain the given View";
			return undef;
		}
	}

	unless ($self->{views} && $self->{views}[$active]) {
		warn "View $active does not exist yet";
		return undef;
	}

	# make this view visible
	$self->{views}[$active]->put_IsVisible(1);

	# make any other views invisible
	map { $self->{views}[$_]->put_IsVisible(0) }
		grep { $_ != $active }
		(0..$#{ $self->{views} });

	# mark this one active
	$self->{active_view} = $active;
}

sub get_active_view {
	my ($self) = @_;
	if ($self->{views} && @{ $self->{views} }) {
		return $self->{views}[ $self->{active_view} ];
	}
	return undef;
}

sub set_bounds {
	my ($self, $bounds) = @_;
warn "set_bounds";

	# store it so newly created views can size themselves right away
	$self->{bounds} = { %$bounds };

	# resize existing views
	$self->put_Bounds($bounds);
}

sub DESTROY {}


#
# explicit event handlers
#

sub CreateCoreWebView2EnvironmentCompleted {
	my ($self, $result, $environment) = @_;

	# result is dual value; numeric error code and string error message
	if ($result != 0) {
		my $code = $result & 0xffffffff;
		(my $message = $result)=~s/\r\n$//;
		die sprintf("Error %08x (%s) in CreateCoreWebView2EnvironmentCompleted", $code, $message);
	}

	$self->{environment} = $environment;

	my $pending = delete $self->{pending};
	for my $op (@$pending) {
		my ($method, @args) = @$op;
warn "Executing pending $method" if $DEBUG;
#		no strict 'refs';
		$self->$method(@args);
	}

	# fire this event, if desired
	if (my $handler = $self->{onCreateCoreWebView2EnvironmentCompleted}) {
		$handler->($self, $result, $environment);
	}

	# hook up any desired environment event methods
	# (except ControllerCompleted events, which we already hook up below)
	for my $event (@{ $EVENTS{Environment} }) {
		next if $event=~/ControllerCompleted/;
		if (my $handler = $self->{events}{$event}) {
			my $method = "add_$event";
			no strict;
			$environment->$method($self);
		}
	}

	return 0;
}

#
# AUTOLOAD - implicit event handlers and delegated methods
#

# some methods must be passed to ALL child views, not just the active one
my %all_views_methods = map { ($_ => 1) } qw(
	put_Bounds
);

my @delegates = qw(BrowserExtension Environment Profile);

sub AUTOLOAD {
	our $AUTOLOAD;
	my $self = shift;
	my ($method) = $AUTOLOAD=~/([^:]+)$/;
#warn $AUTOLOAD;

	my $method_sub;

	my $warning = $DEBUG ? "\nwarn Dumper([ '$method', \@_ ]);" : '';

	# is this an event we handle?
	for my $webview_class (@delegates) {
		if (grep { $method eq $_ } @{ $EVENTS{$webview_class} }) {
			$method_sub = <<HANDLER;
sub $method {$warning
	my \$self = shift;
	if (my \$handler = \$self->{events}{$method}) {
		\$handler->(\$self, \@_);
	}
}
HANDLER
		}
	}

	if (not $method_sub) {
		# is this an environment method?
		if (CoreWebView2::Environment->can($method)) {
			$method_sub = <<METHOD;
sub $method {$warning
	my \$self = shift;

	# are we still waiting on an Environment? queue up the methods for later
	if (\$self->{pending}) {
		push \@{ \$self->{pending} }, [ '$method', \@_ ];
		return 1;
	}

	return \$self->{environment}->$method(\@_);
}
METHOD
		}

		# does this go to all child views?
		elsif ($all_views_methods{$method}) {
			$method_sub = <<METHOD;
sub $method {$warning
	my \$self = shift;

	if (\$self->{views}) {
		for my \$view (\@{ \$self->{views} }) {
			\$view->$method(\@_);
		}
	}
}
METHOD
		}
		# otherwise pass to active view
		else {
			$method_sub = <<METHOD;
sub $method {$warning
	my \$self = shift;

	if (my \$view = \$self->get_active_view) {
		return \$view->$method(\@_);
	}
}
METHOD
		}
	}

warn "$AUTOLOAD => $method_sub" if $DEBUG;
	if ($method_sub) {
#warn $method_sub;
		eval $method_sub;
		if ($@) {
die $@;
		}
	}
	else {
		die "Method '$AUTOLOAD' not found";
	}

	no strict;
	return $self->$method(@_);
}

#
# subviews
#

package CoreWebView2::Widget::View;

our $DEBUG = $CoreWebView2::Widget::DEBUG;

use Data::Dumper;

sub new {
	my ($class, %options) = @_;

	my $self = bless \%options, $class;

	$self->{pending} = [];

	return $self;
}

#
# explicit event handlers
#

sub CreateCoreWebView2ControllerCompleted {
	my ($self, $result, $controller) = @_;

	# result is dual value; numeric error code and string error message
	if ($result != 0) {
		my $code = $result & 0xffffffff;
		(my $message = $result)=~s/\r\n$//;
		warn sprintf("Error %08x (%s)", $code, $message);
	}

	$self->{controller} = $controller;
	$self->{webview} = $controller->get_CoreWebView2();

	my $pending = delete $self->{pending};
	for my $op (@$pending) {
		my ($method, @args) = @$op;
warn "Executing pending $method" if $DEBUG;
#		no strict 'refs';
warn "before $method";
		$self->$method(@args);
warn "after $method";
	}

	if (my $bounds = $self->{widget}{bounds}) {
		$self->put_Bounds($bounds);
	}

	# hook up this event if desired
	if (my $handler = $self->{widget}{events}{CreateCoreWebView2ControllerCompleted}) {
		$handler->($self, $result, $controller);
	}

	# hook up any controller/webview methods
	my @events = (
		[ 'controller' => 'Controller' ],
		[ 'webview'    => 'CoreWebView2' ],
	);
	for my $event_group (@events) {
		my ($object, $key) = @$event_group;
		for my $event (@{ $EVENTS{$key} }) {
			if (my $handler = $self->{widget}{events}{$event}) {
				my $method = "add_$event";
				no strict;
#warn "$self->{$object} / $method / $self";
				$self->{$object}->$method($self);
			}
		}
	}

	return 0;
}

sub DESTROY {}

#
# AUTOLOAD - implicit event handlers and delegated methods
#

my %EVENTS = CoreWebView2::Widget->events();

my @delegates = qw(
	CompositionController ContextMenuItem Controller CookieManager CoreWebView2
	DevToolsProtocolEventReceiver DownloadOperation Frame WebResourceResponseView
);

sub AUTOLOAD {
	our $AUTOLOAD;
	my $self = shift;
	my ($method) = $AUTOLOAD=~/([^:]+)$/;
#warn $AUTOLOAD;

	my $method_sub;

	my $warning = $DEBUG ? "\nwarn Dumper([ '$method', \@_ ]);" : '';

	# is this an event we handle?
	for my $webview_class (@delegates) {
		if (grep { $method eq $_ } @{ $EVENTS{$webview_class} }) {
			$method_sub = <<HANDLER;
sub $method {$warning
	my \$self = shift;
	if (my \$handler = \$self->{widget}{events}{$method}) {
		\$handler->(\$self, \@_);
	}
}
HANDLER
		}
	}

	if (not $method_sub) {
		# is this a controller method?
		if (CoreWebView2::Controller->can($method)) {
#warn "$AUTOLOAD => Controller";
			$method_sub = <<METHOD;
sub $method {$warning
	my \$self = shift;

	# are we still waiting on an Controller? queue up the methods for later
	if (\$self->{pending}) {
		push \@{ \$self->{pending} }, [ '$method', \@_ ];
		return 1;
	}

	\$self->{controller}->$method(\@_);
}
METHOD
		}
		# otherwise pass to webview
		elsif (CoreWebView2->can($method)) {
#warn "$AUTOLOAD => CoreWebView2";
			$method_sub = <<METHOD;
sub $method {$warning
	my \$self = shift;

	# are we still waiting on an CoreWebView2? queue up the methods for later
	if (\$self->{pending}) {
		push \@{ \$self->{pending} }, [ '$method', \@_ ];
		return 1;
	}

	\$self->{webview}->$method(\@_);
}
METHOD
		}
	}

warn "$AUTOLOAD => $method_sub" if $DEBUG;
	if ($method_sub) {
#warn $method_sub;
		eval $method_sub;
		if ($@) {
die $@;
		}
	}
	else {
		die "Method '$AUTOLOAD' not found";
	}

	no strict;
	return $self->$method(@_);
}

=pod

CoreWebView2::Widget->new($handle, $environment, $events);
CoreWebView2::Widget->new($handle, $widget) - will take environment and events from $widget

CoreWebView2::Widget
	new($handle, $environment, $events)
		if $environment is a Widget, uses the same environment object
		else uses $environment as an aref and creates an environment object
	add_view()
	views()
	set_active_view()
	new_window()
	passes other methods on to the appropriate member objects

CoreWebView2::App

CoreWebView2::Widget::Win32GUI
	new()
		parses the params according to the associated framework
		creates the window within the framework
		calls SUPER::new() with the window handle
		triggers window resize once the webview object is ready
CoreWebView2::Widget::Prima
CoreWebView2::Widget::Standalone
subclasses can also 
CoreWebView2::Widget::View

CoreWebView2::Simple->new($window, $url);
	will create the environment and one view/controller combo
	will keep the view sized to the window
	will pass methods on to the appropriate object
	can make its own window if none passed in
	url is optional; you can Navigate later
	should probably spin until the webview is ready

=cut

1;

__END__

#
# helper app
#

package CoreWebView2::App;

sub new {
	my ($class, $uri) = @_;

	my $self = bless {
		uri => $uri,
	}, $class;

	$self->{window} = CoreWebView2::create_host_window(sub {
		$self->Resize(@_);
	});
	warn "CreateCoreWebView2Environment begin";
	CoreWebView2::CreateCoreWebView2Environment($self);
	warn "CreateCoreWebView2Environment end";

	return $self;
}

sub run {
	CoreWebView2::start_window_loop();
}

sub quit {
	my ($self) = @_;
	CoreWebView2::close_window($self->{window});
}

sub Resize {
	my ($self, $rect) = @_;
	return unless $self->{controller};
	$self->{controller}->put_Bounds($rect);
}

sub CreateCoreWebView2EnvironmentCompleted {
	my ($self, $result, $environment) = @_;

	$self->{environment} = $environment;
	warn "CreateCoreWebView2Controller begin";
	$environment->CreateCoreWebView2Controller($self->{window}, $self);
	warn "CreateCoreWebView2Controller end";

	return 0;
}

sub CreateCoreWebView2ControllerCompleted {
	my ($self, $result, $controller) = @_;

	$self->{controller} = $controller;
	$self->{webview} = $controller->get_CoreWebView2();

	$self->{token}{NavigationStarting}  = $self->{webview}->add_NavigationStarting($self);
	$self->{token}{NavigationCompleted} = $self->{webview}->add_NavigationCompleted($self);

	if ($self->{uri}) {
		$self->{webview}->Navigate($self->{uri});
	}

	# now that we have a controller, trigger a resize
	CoreWebView2::trigger_window_resize($self->{window});

	return 0;
}

sub NavigationStarting {
#use Data::Dumper;
#warn Dumper \@_;
	my ($self, $webview, $args) = @_;

	warn $args->get_Uri();

	return 0;
}

sub NavigationCompleted {
	my ($self, $webview, $args) = @_;

	warn $args->get_IsSuccess();

	return 0;
}