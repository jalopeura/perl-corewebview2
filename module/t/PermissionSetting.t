use strict;
use warnings;

use Test::More tests => 4;
BEGIN { use_ok('CoreWebView2') };

# PermissionSetting
ok(0, 'PermissionSetting::get_PermissionKind');
ok(0, 'PermissionSetting::get_PermissionOrigin');
ok(0, 'PermissionSetting::get_PermissionState');

