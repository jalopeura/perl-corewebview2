#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::WebResourceResponseReceivedEventArgs

PROTOTYPES: DISABLE

ICoreWebView2WebResourceRequest*
ICoreWebView2WebResourceResponseReceivedEventArgs::get_Request()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponseReceivedEventArgs*)THIS)->lpVtbl->get_Request(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2WebResourceResponseView*
ICoreWebView2WebResourceResponseReceivedEventArgs::get_Response()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceResponseReceivedEventArgs*)THIS)->lpVtbl->get_Response(THIS, &RETVAL);
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
