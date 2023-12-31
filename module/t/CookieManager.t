use strict;
use warnings;

use Test::More tests => 10;
BEGIN { use_ok('CoreWebView2') };

# CookieManager
ok(0, 'CookieManager::AddOrUpdateCookie');
ok(0, 'CookieManager::CopyCookie');
ok(0, 'CookieManager::CreateCookie');
ok(0, 'CookieManager::DeleteAllCookies');
ok(0, 'CookieManager::DeleteCookie');
ok(0, 'CookieManager::DeleteCookies');
ok(0, 'CookieManager::DeleteCookiesWithDomainAndPath');
ok(0, 'CookieManager::GetCookies');

ok(0, 'GetCookiesCompleted event');

