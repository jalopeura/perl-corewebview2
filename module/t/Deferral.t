use strict;
use warnings;

use Test::More tests => 2;
BEGIN { use_ok('CoreWebView2') };

# Deferral
ok(0, 'Deferral::Complete');

