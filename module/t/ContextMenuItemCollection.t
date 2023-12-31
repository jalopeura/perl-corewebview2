use strict;
use warnings;

use Test::More tests => 5;
BEGIN { use_ok('CoreWebView2') };

# ContextMenuItemCollection
ok(0, 'ContextMenuItemCollection::GetValueAtIndex');
ok(0, 'ContextMenuItemCollection::InsertValueAtIndex');
ok(0, 'ContextMenuItemCollection::RemoveValueAtIndex');
ok(0, 'ContextMenuItemCollection::get_Count');

