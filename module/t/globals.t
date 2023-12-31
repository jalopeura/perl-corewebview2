use strict;
use warnings;

use Test::More tests => 6;
BEGIN { use_ok('CoreWebView2') };

# globals
ok(0, 'global function CompareBrowserVersions');
ok(0, 'global function CreateCoreWebView2Environment');
ok(0, 'global function CreateCoreWebView2EnvironmentWithOptions');
ok(0, 'global function GetAvailableCoreWebView2BrowserVersionString');

ok(0, 'CreateCoreWebView2EnvironmentCompleted event');

