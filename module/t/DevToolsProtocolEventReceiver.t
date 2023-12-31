use strict;
use warnings;

use Test::More tests => 6;
BEGIN { use_ok('CoreWebView2') };

# DevToolsProtocolEventReceiver
ok(0, 'DevToolsProtocolEventReceiver::add_DevToolsProtocolEventReceived');
ok(0, 'DevToolsProtocolEventReceiver::remove_DevToolsProtocolEventReceived');

ok(0, 'DevToolsProtocolEventReceived event');
ok(0, 'DevToolsProtocolEventReceivedEventArgs::get_ParameterObjectAsJson');
ok(0, 'DevToolsProtocolEventReceivedEventArgs::get_SessionId');

