use strict;
use warnings;

use Test::More tests => 4;
BEGIN { use_ok('CoreWebView2') };

# FrameInfoCollectionIterator
ok(0, 'FrameInfoCollectionIterator::GetCurrent');
ok(0, 'FrameInfoCollectionIterator::MoveNext');
ok(0, 'FrameInfoCollectionIterator::get_HasCurrent');

