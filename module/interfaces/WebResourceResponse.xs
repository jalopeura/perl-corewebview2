#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::WebResourceResponse

PROTOTYPES: DISABLE

IStream*
ICoreWebView2WebResourceResponse::get_Content()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->get_Content(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceResponse::put_Content(content)
	INPUT:
		IStream* content;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->put_Content(THIS, content);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2HttpResponseHeaders*
ICoreWebView2WebResourceResponse::get_Headers()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->get_Headers(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

int
ICoreWebView2WebResourceResponse::get_StatusCode()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->get_StatusCode(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceResponse::put_StatusCode(statusCode)
	INPUT:
		int statusCode;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->put_StatusCode(THIS, statusCode);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2WebResourceResponse::get_ReasonPhrase()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->get_ReasonPhrase(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceResponse::put_ReasonPhrase(reasonPhrase)
	INPUT:
		LPCWSTR reasonPhrase;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceResponse*)THIS)->lpVtbl->put_ReasonPhrase(THIS, reasonPhrase);
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
