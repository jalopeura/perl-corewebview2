#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::NewWindowRequestedEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2NewWindowRequestedEventArgs3::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2NewWindowRequestedEventArgs3::put_NewWindow(newWindow)
	INPUT:
		ICoreWebView2* newWindow;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->put_NewWindow(THIS, newWindow);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2*
ICoreWebView2NewWindowRequestedEventArgs3::get_NewWindow()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_NewWindow(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2NewWindowRequestedEventArgs3::put_Handled(handled)
	INPUT:
		BOOL handled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->put_Handled(THIS, handled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2NewWindowRequestedEventArgs3::get_Handled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_Handled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2NewWindowRequestedEventArgs3::get_IsUserInitiated()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_IsUserInitiated(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2NewWindowRequestedEventArgs3::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2WindowFeatures*
ICoreWebView2NewWindowRequestedEventArgs3::get_WindowFeatures()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_WindowFeatures(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2NewWindowRequestedEventArgs3::get_Name()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_Name(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2FrameInfo*
ICoreWebView2NewWindowRequestedEventArgs3::get_OriginalSourceFrameInfo()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2NewWindowRequestedEventArgs3*)THIS)->lpVtbl->get_OriginalSourceFrameInfo(THIS, &RETVAL);
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
