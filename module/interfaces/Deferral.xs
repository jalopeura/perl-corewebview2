#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Deferral

PROTOTYPES: DISABLE

HRESULT
ICoreWebView2Deferral::Complete()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Deferral*)THIS)->lpVtbl->Complete(THIS);
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
