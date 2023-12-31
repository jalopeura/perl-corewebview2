#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Cookie

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2Cookie::get_Name()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_Name(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Cookie::get_Value()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_Value(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Cookie::put_Value(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Cookie*)THIS)->lpVtbl->put_Value(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Cookie::get_Domain()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_Domain(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Cookie::get_Path()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_Path(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2Cookie::get_Expires()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_Expires(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Cookie::put_Expires(expires)
	INPUT:
		double expires;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Cookie*)THIS)->lpVtbl->put_Expires(THIS, expires);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Cookie::get_IsHttpOnly()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_IsHttpOnly(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Cookie::put_IsHttpOnly(isHttpOnly)
	INPUT:
		BOOL isHttpOnly;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Cookie*)THIS)->lpVtbl->put_IsHttpOnly(THIS, isHttpOnly);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_COOKIE_SAME_SITE_KIND
ICoreWebView2Cookie::get_SameSite()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_SameSite(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Cookie::put_SameSite(sameSite)
	INPUT:
		COREWEBVIEW2_COOKIE_SAME_SITE_KIND sameSite;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Cookie*)THIS)->lpVtbl->put_SameSite(THIS, sameSite);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Cookie::get_IsSecure()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_IsSecure(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Cookie::put_IsSecure(isSecure)
	INPUT:
		BOOL isSecure;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Cookie*)THIS)->lpVtbl->put_IsSecure(THIS, isSecure);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Cookie::get_IsSession()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Cookie*)THIS)->lpVtbl->get_IsSession(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
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
