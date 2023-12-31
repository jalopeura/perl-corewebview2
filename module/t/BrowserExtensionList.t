use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# BrowserExtensionList
ok(0, 'BrowserExtensionList::GetValueAtIndex');
ok(0, 'BrowserExtensionList::get_Count');

