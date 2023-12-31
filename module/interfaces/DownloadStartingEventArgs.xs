#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::DownloadStartingEventArgs

PROTOTYPES: DISABLE

ICoreWebView2DownloadOperation*
ICoreWebView2DownloadStartingEventArgs::get_DownloadOperation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->get_DownloadOperation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2DownloadStartingEventArgs::get_Cancel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->get_Cancel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadStartingEventArgs::put_Cancel(cancel)
	INPUT:
		BOOL cancel;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->put_Cancel(THIS, cancel);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DownloadStartingEventArgs::get_ResultFilePath()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->get_ResultFilePath(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadStartingEventArgs::put_ResultFilePath(resultFilePath)
	INPUT:
		LPCWSTR resultFilePath;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->put_ResultFilePath(THIS, resultFilePath);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2DownloadStartingEventArgs::get_Handled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->get_Handled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadStartingEventArgs::put_Handled(handled)
	INPUT:
		BOOL handled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->put_Handled(THIS, handled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2DownloadStartingEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadStartingEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
