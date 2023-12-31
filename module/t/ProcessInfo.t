use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# ProcessInfo
ok(0, 'ProcessInfo::get_Kind');
ok(0, 'ProcessInfo::get_ProcessId');

