use strict;
use warnings;

use Test::More tests => 6;
BEGIN { use_ok('CoreWebView2') };

# WebResourceResponseView
ok(0, 'WebResourceResponseView::GetContent');
ok(0, 'WebResourceResponseView::get_Headers');
ok(0, 'WebResourceResponseView::get_ReasonPhrase');
ok(0, 'WebResourceResponseView::get_StatusCode');

ok(0, 'WebResourceResponseViewGetContentCompleted event');

