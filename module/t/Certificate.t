use strict;
use warnings;

use Test::More tests => 9;
BEGIN { use_ok('CoreWebView2') };

# Certificate
ok(0, 'Certificate::ToPemEncoding');
ok(0, 'Certificate::get_DerEncodedSerialNumber');
ok(0, 'Certificate::get_DisplayName');
ok(0, 'Certificate::get_Issuer');
ok(0, 'Certificate::get_PemEncodedIssuerCertificateChain');
ok(0, 'Certificate::get_Subject');
ok(0, 'Certificate::get_ValidFrom');
ok(0, 'Certificate::get_ValidTo');

