#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ServerCertificateErrorDetectedEventArgs

PROTOTYPES: DISABLE

COREWEBVIEW2_WEB_ERROR_STATUS
ICoreWebView2ServerCertificateErrorDetectedEventArgs::get_ErrorStatus()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ServerCertificateErrorDetectedEventArgs*)THIS)->lpVtbl->get_ErrorStatus(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ServerCertificateErrorDetectedEventArgs::get_RequestUri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ServerCertificateErrorDetectedEventArgs*)THIS)->lpVtbl->get_RequestUri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Certificate*
ICoreWebView2ServerCertificateErrorDetectedEventArgs::get_ServerCertificate()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ServerCertificateErrorDetectedEventArgs*)THIS)->lpVtbl->get_ServerCertificate(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_SERVER_CERTIFICATE_ERROR_ACTION
ICoreWebView2ServerCertificateErrorDetectedEventArgs::get_Action()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ServerCertificateErrorDetectedEventArgs*)THIS)->lpVtbl->get_Action(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ServerCertificateErrorDetectedEventArgs::put_Action(value)
	INPUT:
		COREWEBVIEW2_SERVER_CERTIFICATE_ERROR_ACTION value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ServerCertificateErrorDetectedEventArgs*)THIS)->lpVtbl->put_Action(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2ServerCertificateErrorDetectedEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ServerCertificateErrorDetectedEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
