use strict;
use warnings;

use Test::More tests => 14;
BEGIN { use_ok('CoreWebView2') };

# ContextMenuTarget
ok(0, 'ContextMenuTarget::get_FrameUri');
ok(0, 'ContextMenuTarget::get_HasLinkText');
ok(0, 'ContextMenuTarget::get_HasLinkUri');
ok(0, 'ContextMenuTarget::get_HasSelection');
ok(0, 'ContextMenuTarget::get_HasSourceUri');
ok(0, 'ContextMenuTarget::get_IsEditable');
ok(0, 'ContextMenuTarget::get_IsRequestedForMainFrame');
ok(0, 'ContextMenuTarget::get_Kind');
ok(0, 'ContextMenuTarget::get_LinkText');
ok(0, 'ContextMenuTarget::get_LinkUri');
ok(0, 'ContextMenuTarget::get_PageUri');
ok(0, 'ContextMenuTarget::get_SelectionText');
ok(0, 'ContextMenuTarget::get_SourceUri');

