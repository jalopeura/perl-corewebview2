#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::NavigationCompletedEventArgs

PROTOTYPES: DISABLE

BOOL
ICoreWebView2NavigationCompletedEventArgs2::get_IsSuccess()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationCompletedEventArgs2*)THIS)->lpVtbl->get_IsSuccess(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_WEB_ERROR_STATUS
ICoreWebView2NavigationCompletedEventArgs2::get_WebErrorStatus()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationCompletedEventArgs2*)THIS)->lpVtbl->get_WebErrorStatus(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT64
ICoreWebView2NavigationCompletedEventArgs2::get_NavigationId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationCompletedEventArgs2*)THIS)->lpVtbl->get_NavigationId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

int
ICoreWebView2NavigationCompletedEventArgs2::get_HttpStatusCode()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NavigationCompletedEventArgs2*)THIS)->lpVtbl->get_HttpStatusCode(THIS, &RETVAL);
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
