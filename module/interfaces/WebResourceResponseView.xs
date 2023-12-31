#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::WebResourceResponseView

PROTOTYPES: DISABLE

ICoreWebView2HttpResponseHeaders*
ICoreWebView2WebResourceResponseView::get_Headers()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponseView*)THIS)->lpVtbl->get_Headers(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

int
ICoreWebView2WebResourceResponseView::get_StatusCode()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponseView*)THIS)->lpVtbl->get_StatusCode(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2WebResourceResponseView::get_ReasonPhrase()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponseView*)THIS)->lpVtbl->get_ReasonPhrase(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceResponseView::GetContent(handler)
	INPUT:
		ICoreWebView2WebResourceResponseViewGetContentCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2WebResourceResponseView*)THIS)->lpVtbl->GetContent(THIS, handler);
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
