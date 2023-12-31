#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::LaunchingExternalUriSchemeEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2LaunchingExternalUriSchemeEventArgs::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2LaunchingExternalUriSchemeEventArgs*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2LaunchingExternalUriSchemeEventArgs::get_InitiatingOrigin()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2LaunchingExternalUriSchemeEventArgs*)THIS)->lpVtbl->get_InitiatingOrigin(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2LaunchingExternalUriSchemeEventArgs::get_IsUserInitiated()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2LaunchingExternalUriSchemeEventArgs*)THIS)->lpVtbl->get_IsUserInitiated(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2LaunchingExternalUriSchemeEventArgs::get_Cancel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2LaunchingExternalUriSchemeEventArgs*)THIS)->lpVtbl->get_Cancel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2LaunchingExternalUriSchemeEventArgs::put_Cancel(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2LaunchingExternalUriSchemeEventArgs*)THIS)->lpVtbl->put_Cancel(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2LaunchingExternalUriSchemeEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2LaunchingExternalUriSchemeEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
