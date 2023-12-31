use strict;
use warnings;

use Test::More tests => 10;
BEGIN { use_ok('CoreWebView2') };

# ClientCertificate
ok(0, 'ClientCertificate::ToPemEncoding');
ok(0, 'ClientCertificate::get_DerEncodedSerialNumber');
ok(0, 'ClientCertificate::get_DisplayName');
ok(0, 'ClientCertificate::get_Issuer');
ok(0, 'ClientCertificate::get_Kind');
ok(0, 'ClientCertificate::get_PemEncodedIssuerCertificateChain');
ok(0, 'ClientCertificate::get_Subject');
ok(0, 'ClientCertificate::get_ValidFrom');
ok(0, 'ClientCertificate::get_ValidTo');

