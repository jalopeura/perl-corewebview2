#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::CookieManager

PROTOTYPES: DISABLE

ICoreWebView2Cookie*
ICoreWebView2CookieManager::CreateCookie(name, value, domain, path)
	INPUT:
		LPCWSTR name;
		LPCWSTR value;
		LPCWSTR domain;
		LPCWSTR path;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->CreateCookie(THIS, name, value, domain, path, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Cookie*
ICoreWebView2CookieManager::CopyCookie(cookieParam)
	INPUT:
		ICoreWebView2Cookie* cookieParam;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->CopyCookie(THIS, cookieParam, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CookieManager::GetCookies(uri, handler)
	INPUT:
		LPCWSTR uri;
		ICoreWebView2GetCookiesCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->GetCookies(THIS, uri, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CookieManager::AddOrUpdateCookie(cookie)
	INPUT:
		ICoreWebView2Cookie* cookie;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->AddOrUpdateCookie(THIS, cookie);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CookieManager::DeleteCookie(cookie)
	INPUT:
		ICoreWebView2Cookie* cookie;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->DeleteCookie(THIS, cookie);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CookieManager::DeleteCookies(name, uri)
	INPUT:
		LPCWSTR name;
		LPCWSTR uri;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->DeleteCookies(THIS, name, uri);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CookieManager::DeleteCookiesWithDomainAndPath(name, domain, path)
	INPUT:
		LPCWSTR name;
		LPCWSTR domain;
		LPCWSTR path;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->DeleteCookiesWithDomainAndPath(THIS, name, domain, path);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CookieManager::DeleteAllCookies()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CookieManager*)THIS)->lpVtbl->DeleteAllCookies(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

# Note that this method is not prefixed by the class name.
#
# This is because if we prefix the class name the first argument is
# automatically converted into the THIS pointer, and we no longer have
# access to the Perl object. But we need that access in order to unlink
# the C++ object, and to clean up the Perl object.
void
DESTROY(perl_obj)
	INPUT:
		SV* perl_obj;
	CODE:
		unlink_perl_object(perl_obj);
