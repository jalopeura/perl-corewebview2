use strict;
use warnings;

use Test::More tests => 15;
BEGIN { use_ok('CoreWebView2') };

# CompositionController
ok(0, 'CompositionController::DragEnter');
ok(0, 'CompositionController::DragLeave');
ok(0, 'CompositionController::DragOver');
ok(0, 'CompositionController::Drop');
ok(0, 'CompositionController::SendMouseInput');
ok(0, 'CompositionController::SendPointerInput');
ok(0, 'CompositionController::add_CursorChanged');
ok(0, 'CompositionController::get_AutomationProvider');
ok(0, 'CompositionController::get_Cursor');
ok(0, 'CompositionController::get_RootVisualTarget');
ok(0, 'CompositionController::get_SystemCursorId');
ok(0, 'CompositionController::put_RootVisualTarget');
ok(0, 'CompositionController::remove_CursorChanged');

ok(0, 'CursorChanged event');

