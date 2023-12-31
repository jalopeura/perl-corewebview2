#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ProcessFailedEventArgs

PROTOTYPES: DISABLE

COREWEBVIEW2_PROCESS_FAILED_KIND
ICoreWebView2ProcessFailedEventArgs2::get_ProcessFailedKind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessFailedEventArgs2*)THIS)->lpVtbl->get_ProcessFailedKind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PROCESS_FAILED_REASON
ICoreWebView2ProcessFailedEventArgs2::get_Reason()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessFailedEventArgs2*)THIS)->lpVtbl->get_Reason(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

int
ICoreWebView2ProcessFailedEventArgs2::get_ExitCode()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessFailedEventArgs2*)THIS)->lpVtbl->get_ExitCode(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ProcessFailedEventArgs2::get_ProcessDescription()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessFailedEventArgs2*)THIS)->lpVtbl->get_ProcessDescription(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2FrameInfoCollection*
ICoreWebView2ProcessFailedEventArgs2::get_FrameInfosForFailedProcess()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessFailedEventArgs2*)THIS)->lpVtbl->get_FrameInfosForFailedProcess(THIS, &RETVAL);
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
