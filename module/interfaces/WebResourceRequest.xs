#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::WebResourceRequest

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2WebResourceRequest::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceRequest::put_Uri(uri)
	INPUT:
		LPCWSTR uri;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->put_Uri(THIS, uri);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2WebResourceRequest::get_Method()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->get_Method(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceRequest::put_Method(method)
	INPUT:
		LPCWSTR method;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->put_Method(THIS, method);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

IStream*
ICoreWebView2WebResourceRequest::get_Content()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->get_Content(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceRequest::put_Content(content)
	INPUT:
		IStream* content;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->put_Content(THIS, content);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2HttpRequestHeaders*
ICoreWebView2WebResourceRequest::get_Headers()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequest*)THIS)->lpVtbl->get_Headers(THIS, &RETVAL);
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
