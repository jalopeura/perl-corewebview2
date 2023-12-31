#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::DevToolsProtocolEventReceiver

PROTOTYPES: DISABLE

EventRegistrationToken
ICoreWebView2DevToolsProtocolEventReceiver::add_DevToolsProtocolEventReceived(handler)
	INPUT:
		ICoreWebView2DevToolsProtocolEventReceivedEventHandler* handler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2DevToolsProtocolEventReceiver*)THIS)->lpVtbl->add_DevToolsProtocolEventReceived(THIS, handler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2DevToolsProtocolEventReceiver::remove_DevToolsProtocolEventReceived(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2DevToolsProtocolEventReceiver*)THIS)->lpVtbl->remove_DevToolsProtocolEventReceived(THIS, token);
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
