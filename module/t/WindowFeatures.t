use strict;
use warnings;

use Test::More tests => 11;
BEGIN { use_ok('CoreWebView2') };

# WindowFeatures
ok(0, 'WindowFeatures::get_HasPosition');
ok(0, 'WindowFeatures::get_HasSize');
ok(0, 'WindowFeatures::get_Height');
ok(0, 'WindowFeatures::get_Left');
ok(0, 'WindowFeatures::get_ShouldDisplayMenuBar');
ok(0, 'WindowFeatures::get_ShouldDisplayScrollBars');
ok(0, 'WindowFeatures::get_ShouldDisplayStatus');
ok(0, 'WindowFeatures::get_ShouldDisplayToolbar');
ok(0, 'WindowFeatures::get_Top');
ok(0, 'WindowFeatures::get_Width');

