use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# CookieList
ok(0, 'CookieList::GetValueAtIndex');
ok(0, 'CookieList::get_Count');

