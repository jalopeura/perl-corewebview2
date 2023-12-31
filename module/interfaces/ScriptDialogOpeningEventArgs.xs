#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ScriptDialogOpeningEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2ScriptDialogOpeningEventArgs::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_SCRIPT_DIALOG_KIND
ICoreWebView2ScriptDialogOpeningEventArgs::get_Kind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->get_Kind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ScriptDialogOpeningEventArgs::get_Message()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->get_Message(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ScriptDialogOpeningEventArgs::Accept()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->Accept(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ScriptDialogOpeningEventArgs::get_DefaultText()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->get_DefaultText(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ScriptDialogOpeningEventArgs::get_ResultText()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->get_ResultText(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ScriptDialogOpeningEventArgs::put_ResultText(resultText)
	INPUT:
		LPCWSTR resultText;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->put_ResultText(THIS, resultText);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2ScriptDialogOpeningEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ScriptDialogOpeningEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
