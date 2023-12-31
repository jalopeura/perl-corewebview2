use strict;
use warnings;

use Test::More tests => 4;
BEGIN { use_ok('CoreWebView2') };

# HttpHeadersCollectionIterator
ok(0, 'HttpHeadersCollectionIterator::GetCurrentHeader');
ok(0, 'HttpHeadersCollectionIterator::MoveNext');
ok(0, 'HttpHeadersCollectionIterator::get_HasCurrentHeader');

