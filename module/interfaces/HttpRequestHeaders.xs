#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::HttpRequestHeaders

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2HttpRequestHeaders::GetHeader(name)
	INPUT:
		LPCWSTR name;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2HttpRequestHeaders*)THIS)->lpVtbl->GetHeader(THIS, name, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2HttpHeadersCollectionIterator*
ICoreWebView2HttpRequestHeaders::GetHeaders(name)
	INPUT:
		LPCWSTR name;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2HttpRequestHeaders*)THIS)->lpVtbl->GetHeaders(THIS, name, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2HttpRequestHeaders::Contains(name)
	INPUT:
		LPCWSTR name;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2HttpRequestHeaders*)THIS)->lpVtbl->Contains(THIS, name, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2HttpRequestHeaders::SetHeader(name, value)
	INPUT:
		LPCWSTR name;
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2HttpRequestHeaders*)THIS)->lpVtbl->SetHeader(THIS, name, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2HttpRequestHeaders::RemoveHeader(name)
	INPUT:
		LPCWSTR name;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2HttpRequestHeaders*)THIS)->lpVtbl->RemoveHeader(THIS, name);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2HttpHeadersCollectionIterator*
ICoreWebView2HttpRequestHeaders::GetIterator()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2HttpRequestHeaders*)THIS)->lpVtbl->GetIterator(THIS, &RETVAL);
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
