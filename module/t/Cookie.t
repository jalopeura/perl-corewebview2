use strict;
use warnings;

use Test::More tests => 15;
BEGIN { use_ok('CoreWebView2') };

# Cookie
ok(0, 'Cookie::get_Domain');
ok(0, 'Cookie::get_Expires');
ok(0, 'Cookie::get_IsHttpOnly');
ok(0, 'Cookie::get_IsSecure');
ok(0, 'Cookie::get_IsSession');
ok(0, 'Cookie::get_Name');
ok(0, 'Cookie::get_Path');
ok(0, 'Cookie::get_SameSite');
ok(0, 'Cookie::get_Value');
ok(0, 'Cookie::put_Expires');
ok(0, 'Cookie::put_IsHttpOnly');
ok(0, 'Cookie::put_IsSecure');
ok(0, 'Cookie::put_SameSite');
ok(0, 'Cookie::put_Value');

