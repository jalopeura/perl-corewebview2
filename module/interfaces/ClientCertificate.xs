#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ClientCertificate

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2ClientCertificate::get_Subject()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_Subject(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ClientCertificate::get_Issuer()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_Issuer(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2ClientCertificate::get_ValidFrom()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_ValidFrom(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2ClientCertificate::get_ValidTo()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_ValidTo(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ClientCertificate::get_DerEncodedSerialNumber()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_DerEncodedSerialNumber(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ClientCertificate::get_DisplayName()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_DisplayName(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ClientCertificate::ToPemEncoding()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->ToPemEncoding(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2StringCollection*
ICoreWebView2ClientCertificate::get_PemEncodedIssuerCertificateChain()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_PemEncodedIssuerCertificateChain(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_CLIENT_CERTIFICATE_KIND
ICoreWebView2ClientCertificate::get_Kind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ClientCertificate*)THIS)->lpVtbl->get_Kind(THIS, &RETVAL);
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
