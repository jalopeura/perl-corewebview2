#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ProcessExtendedInfo

PROTOTYPES: DISABLE

ICoreWebView2ProcessInfo*
ICoreWebView2ProcessExtendedInfo::get_ProcessInfo()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessExtendedInfo*)THIS)->lpVtbl->get_ProcessInfo(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2FrameInfoCollection*
ICoreWebView2ProcessExtendedInfo::get_AssociatedFrameInfos()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessExtendedInfo*)THIS)->lpVtbl->get_AssociatedFrameInfos(THIS, &RETVAL);
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
