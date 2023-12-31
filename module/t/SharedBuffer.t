use strict;
use warnings;

use Test::More tests => 6;
BEGIN { use_ok('CoreWebView2') };

# SharedBuffer
ok(0, 'SharedBuffer::Close');
ok(0, 'SharedBuffer::OpenStream');
ok(0, 'SharedBuffer::get_Buffer');
ok(0, 'SharedBuffer::get_FileMappingHandle');
ok(0, 'SharedBuffer::get_Size');

