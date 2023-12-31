use strict;
use warnings;

use Test::More tests => 5;
BEGIN { use_ok('CoreWebView2') };

# BasicAuthenticationResponse
ok(0, 'BasicAuthenticationResponse::get_Password');
ok(0, 'BasicAuthenticationResponse::get_UserName');
ok(0, 'BasicAuthenticationResponse::put_Password');
ok(0, 'BasicAuthenticationResponse::put_UserName');

