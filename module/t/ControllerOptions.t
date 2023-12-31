use strict;
use warnings;

use Test::More tests => 7;
BEGIN { use_ok('CoreWebView2') };

# ControllerOptions
ok(0, 'ControllerOptions::get_IsInPrivateModeEnabled');
ok(0, 'ControllerOptions::get_ProfileName');
ok(0, 'ControllerOptions::get_ScriptLocale');
ok(0, 'ControllerOptions::put_IsInPrivateModeEnabled');
ok(0, 'ControllerOptions::put_ProfileName');
ok(0, 'ControllerOptions::put_ScriptLocale');

