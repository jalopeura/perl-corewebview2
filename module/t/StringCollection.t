use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# StringCollection
ok(0, 'StringCollection::GetValueAtIndex');
ok(0, 'StringCollection::get_Count');

