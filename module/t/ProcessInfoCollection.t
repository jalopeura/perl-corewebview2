use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# ProcessInfoCollection
ok(0, 'ProcessInfoCollection::GetValueAtIndex');
ok(0, 'ProcessInfoCollection::get_Count');

