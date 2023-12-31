#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::BasicAuthenticationRequestedEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2BasicAuthenticationRequestedEventArgs::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationRequestedEventArgs*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2BasicAuthenticationRequestedEventArgs::get_Challenge()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationRequestedEventArgs*)THIS)->lpVtbl->get_Challenge(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2BasicAuthenticationResponse*
ICoreWebView2BasicAuthenticationRequestedEventArgs::get_Response()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationRequestedEventArgs*)THIS)->lpVtbl->get_Response(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2BasicAuthenticationRequestedEventArgs::get_Cancel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationRequestedEventArgs*)THIS)->lpVtbl->get_Cancel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2BasicAuthenticationRequestedEventArgs::put_Cancel(cancel)
	INPUT:
		BOOL cancel;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2BasicAuthenticationRequestedEventArgs*)THIS)->lpVtbl->put_Cancel(THIS, cancel);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2BasicAuthenticationRequestedEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationRequestedEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
