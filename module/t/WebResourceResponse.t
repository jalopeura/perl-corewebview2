use strict;
use warnings;

use Test::More tests => 8;
BEGIN { use_ok('CoreWebView2') };

# WebResourceResponse
ok(0, 'WebResourceResponse::get_Content');
ok(0, 'WebResourceResponse::get_Headers');
ok(0, 'WebResourceResponse::get_ReasonPhrase');
ok(0, 'WebResourceResponse::get_StatusCode');
ok(0, 'WebResourceResponse::put_Content');
ok(0, 'WebResourceResponse::put_ReasonPhrase');
ok(0, 'WebResourceResponse::put_StatusCode');

