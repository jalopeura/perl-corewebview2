use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# PermissionSettingCollectionView
ok(0, 'PermissionSettingCollectionView::GetValueAtIndex');
ok(0, 'PermissionSettingCollectionView::get_Count');

