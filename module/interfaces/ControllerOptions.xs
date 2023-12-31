#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ControllerOptions

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2ControllerOptions2::get_ProfileName()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ControllerOptions2*)THIS)->lpVtbl->get_ProfileName(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ControllerOptions2::put_ProfileName(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ControllerOptions2*)THIS)->lpVtbl->put_ProfileName(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ControllerOptions2::get_IsInPrivateModeEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ControllerOptions2*)THIS)->lpVtbl->get_IsInPrivateModeEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ControllerOptions2::put_IsInPrivateModeEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ControllerOptions2*)THIS)->lpVtbl->put_IsInPrivateModeEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ControllerOptions2::get_ScriptLocale()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ControllerOptions2*)THIS)->lpVtbl->get_ScriptLocale(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ControllerOptions2::put_ScriptLocale(locale)
	INPUT:
		LPCWSTR locale;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ControllerOptions2*)THIS)->lpVtbl->put_ScriptLocale(THIS, locale);
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
