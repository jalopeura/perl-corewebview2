#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::DownloadOperation

PROTOTYPES: DISABLE

EventRegistrationToken
ICoreWebView2DownloadOperation::add_BytesReceivedChanged(eventHandler)
	INPUT:
		ICoreWebView2BytesReceivedChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->add_BytesReceivedChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadOperation::remove_BytesReceivedChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->remove_BytesReceivedChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2DownloadOperation::add_EstimatedEndTimeChanged(eventHandler)
	INPUT:
		ICoreWebView2EstimatedEndTimeChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->add_EstimatedEndTimeChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadOperation::remove_EstimatedEndTimeChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->remove_EstimatedEndTimeChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2DownloadOperation::add_StateChanged(eventHandler)
	INPUT:
		ICoreWebView2StateChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->add_StateChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadOperation::remove_StateChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->remove_StateChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DownloadOperation::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DownloadOperation::get_ContentDisposition()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_ContentDisposition(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DownloadOperation::get_MimeType()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_MimeType(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

INT64
ICoreWebView2DownloadOperation::get_TotalBytesToReceive()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_TotalBytesToReceive(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

INT64
ICoreWebView2DownloadOperation::get_BytesReceived()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_BytesReceived(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DownloadOperation::get_EstimatedEndTime()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_EstimatedEndTime(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DownloadOperation::get_ResultFilePath()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_ResultFilePath(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_DOWNLOAD_STATE
ICoreWebView2DownloadOperation::get_State()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_State(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_DOWNLOAD_INTERRUPT_REASON
ICoreWebView2DownloadOperation::get_InterruptReason()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_InterruptReason(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadOperation::Cancel()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->Cancel(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadOperation::Pause()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->Pause(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DownloadOperation::Resume()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->Resume(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2DownloadOperation::get_CanResume()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DownloadOperation*)THIS)->lpVtbl->get_CanResume(THIS, &RETVAL);
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
