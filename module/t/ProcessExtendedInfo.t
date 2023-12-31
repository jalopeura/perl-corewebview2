use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# ProcessExtendedInfo
ok(0, 'ProcessExtendedInfo::get_AssociatedFrameInfos');
ok(0, 'ProcessExtendedInfo::get_ProcessInfo');

