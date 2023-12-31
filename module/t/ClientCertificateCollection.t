use strict;
use warnings;

use Test::More tests => 3;
BEGIN { use_ok('CoreWebView2') };

# ClientCertificateCollection
ok(0, 'ClientCertificateCollection::GetValueAtIndex');
ok(0, 'ClientCertificateCollection::get_Count');

