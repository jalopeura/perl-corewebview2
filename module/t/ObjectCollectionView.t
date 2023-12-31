use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# ObjectCollectionView
ok(0, 'ObjectCollectionView::GetValueAtIndex');
ok(0, 'ObjectCollectionView::get_Count');

