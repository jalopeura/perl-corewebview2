use strict;
use warnings;

use Test::More tests => 8;
BEGIN { use_ok('CoreWebView2') };

# CustomSchemeRegistration
ok(0, 'CustomSchemeRegistration::GetAllowedOrigins');
ok(0, 'CustomSchemeRegistration::SetAllowedOrigins');
ok(0, 'CustomSchemeRegistration::get_HasAuthorityComponent');
ok(0, 'CustomSchemeRegistration::get_SchemeName');
ok(0, 'CustomSchemeRegistration::get_TreatAsSecure');
ok(0, 'CustomSchemeRegistration::put_HasAuthorityComponent');
ok(0, 'CustomSchemeRegistration::put_TreatAsSecure');

