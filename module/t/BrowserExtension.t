use strict;
use warnings;

use Test::More tests => 8;
BEGIN { use_ok('CoreWebView2') };

# BrowserExtension
ok(0, 'BrowserExtension::Enable');
ok(0, 'BrowserExtension::Remove');
ok(0, 'BrowserExtension::get_Id');
ok(0, 'BrowserExtension::get_IsEnabled');
ok(0, 'BrowserExtension::get_Name');

ok(0, 'BrowserExtensionEnableCompleted event');

ok(0, 'BrowserExtensionRemoveCompleted event');

