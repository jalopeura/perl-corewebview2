use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# ProcessExtendedInfoCollection
ok(0, 'ProcessExtendedInfoCollection::GetValueAtIndex');
ok(0, 'ProcessExtendedInfoCollection::get_Count');

