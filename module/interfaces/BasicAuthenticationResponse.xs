#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::BasicAuthenticationResponse

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2BasicAuthenticationResponse::get_UserName()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationResponse*)THIS)->lpVtbl->get_UserName(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2BasicAuthenticationResponse::put_UserName(userName)
	INPUT:
		LPCWSTR userName;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2BasicAuthenticationResponse*)THIS)->lpVtbl->put_UserName(THIS, userName);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2BasicAuthenticationResponse::get_Password()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2BasicAuthenticationResponse*)THIS)->lpVtbl->get_Password(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2BasicAuthenticationResponse::put_Password(password)
	INPUT:
		LPCWSTR password;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2BasicAuthenticationResponse*)THIS)->lpVtbl->put_Password(THIS, password);
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
