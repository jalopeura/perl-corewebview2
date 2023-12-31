use strict;
use warnings;

use Test::More tests => 6;
BEGIN { use_ok('CoreWebView2') };

# HttpResponseHeaders
ok(0, 'HttpResponseHeaders::AppendHeader');
ok(0, 'HttpResponseHeaders::Contains');
ok(0, 'HttpResponseHeaders::GetHeader');
ok(0, 'HttpResponseHeaders::GetHeaders');
ok(0, 'HttpResponseHeaders::GetIterator');

