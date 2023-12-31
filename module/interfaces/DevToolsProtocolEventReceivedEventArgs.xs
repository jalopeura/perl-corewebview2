#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::DevToolsProtocolEventReceivedEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2DevToolsProtocolEventReceivedEventArgs2::get_ParameterObjectAsJson()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DevToolsProtocolEventReceivedEventArgs2*)THIS)->lpVtbl->get_ParameterObjectAsJson(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2DevToolsProtocolEventReceivedEventArgs2::get_SessionId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DevToolsProtocolEventReceivedEventArgs2*)THIS)->lpVtbl->get_SessionId(THIS, &RETVAL);
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
