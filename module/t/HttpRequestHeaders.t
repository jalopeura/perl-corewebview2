use strict;
use warnings;

use Test::More tests => 7;
BEGIN { use_ok('CoreWebView2') };

# HttpRequestHeaders
ok(0, 'HttpRequestHeaders::Contains');
ok(0, 'HttpRequestHeaders::GetHeader');
ok(0, 'HttpRequestHeaders::GetHeaders');
ok(0, 'HttpRequestHeaders::GetIterator');
ok(0, 'HttpRequestHeaders::RemoveHeader');
ok(0, 'HttpRequestHeaders::SetHeader');

