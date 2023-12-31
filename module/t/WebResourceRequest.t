use strict;
use warnings;

use Test::More tests => 8;
BEGIN { use_ok('CoreWebView2') };

# WebResourceRequest
ok(0, 'WebResourceRequest::get_Content');
ok(0, 'WebResourceRequest::get_Headers');
ok(0, 'WebResourceRequest::get_Method');
ok(0, 'WebResourceRequest::get_Uri');
ok(0, 'WebResourceRequest::put_Content');
ok(0, 'WebResourceRequest::put_Method');
ok(0, 'WebResourceRequest::put_Uri');

