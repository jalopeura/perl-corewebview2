use strict;
use warnings;

use Test::More tests => 15;
BEGIN { use_ok('CoreWebView2') };

# ContextMenuItem
ok(0, 'ContextMenuItem::add_CustomItemSelected');
ok(0, 'ContextMenuItem::get_Children');
ok(0, 'ContextMenuItem::get_CommandId');
ok(0, 'ContextMenuItem::get_Icon');
ok(0, 'ContextMenuItem::get_IsChecked');
ok(0, 'ContextMenuItem::get_IsEnabled');
ok(0, 'ContextMenuItem::get_Kind');
ok(0, 'ContextMenuItem::get_Label');
ok(0, 'ContextMenuItem::get_Name');
ok(0, 'ContextMenuItem::get_ShortcutKeyDescription');
ok(0, 'ContextMenuItem::put_IsChecked');
ok(0, 'ContextMenuItem::put_IsEnabled');
ok(0, 'ContextMenuItem::remove_CustomItemSelected');

ok(0, 'CustomItemSelected event');

