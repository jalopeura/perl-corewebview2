#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::NavigationStartingEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2NavigationStartingEventArgs3::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2NavigationStartingEventArgs3::get_IsUserInitiated()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_IsUserInitiated(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2NavigationStartingEventArgs3::get_IsRedirected()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_IsRedirected(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2HttpRequestHeaders*
ICoreWebView2NavigationStartingEventArgs3::get_RequestHeaders()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_RequestHeaders(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2NavigationStartingEventArgs3::get_Cancel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_Cancel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2NavigationStartingEventArgs3::put_Cancel(cancel)
	INPUT:
		BOOL cancel;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->put_Cancel(THIS, cancel);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT64
ICoreWebView2NavigationStartingEventArgs3::get_NavigationId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_NavigationId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2NavigationStartingEventArgs3::get_AdditionalAllowedFrameAncestors()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_AdditionalAllowedFrameAncestors(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2NavigationStartingEventArgs3::put_AdditionalAllowedFrameAncestors(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->put_AdditionalAllowedFrameAncestors(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_NAVIGATION_KIND
ICoreWebView2NavigationStartingEventArgs3::get_NavigationKind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationStartingEventArgs3*)THIS)->lpVtbl->get_NavigationKind(THIS, &RETVAL);
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
