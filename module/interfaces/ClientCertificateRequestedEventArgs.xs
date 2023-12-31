#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ClientCertificateRequestedEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2ClientCertificateRequestedEventArgs::get_Host()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_Host(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

int
ICoreWebView2ClientCertificateRequestedEventArgs::get_Port()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_Port(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ClientCertificateRequestedEventArgs::get_IsProxy()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_IsProxy(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2StringCollection*
ICoreWebView2ClientCertificateRequestedEventArgs::get_AllowedCertificateAuthorities()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_AllowedCertificateAuthorities(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ClientCertificateCollection*
ICoreWebView2ClientCertificateRequestedEventArgs::get_MutuallyTrustedCertificates()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_MutuallyTrustedCertificates(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ClientCertificate*
ICoreWebView2ClientCertificateRequestedEventArgs::get_SelectedCertificate()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_SelectedCertificate(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ClientCertificateRequestedEventArgs::put_SelectedCertificate(value)
	INPUT:
		ICoreWebView2ClientCertificate* value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->put_SelectedCertificate(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ClientCertificateRequestedEventArgs::get_Cancel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_Cancel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ClientCertificateRequestedEventArgs::put_Cancel(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->put_Cancel(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ClientCertificateRequestedEventArgs::get_Handled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->get_Handled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ClientCertificateRequestedEventArgs::put_Handled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->put_Handled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2ClientCertificateRequestedEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificateRequestedEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
