#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ProcessExtendedInfoCollection

PROTOTYPES: DISABLE

UINT
ICoreWebView2ProcessExtendedInfoCollection::get_Count()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessExtendedInfoCollection*)THIS)->lpVtbl->get_Count(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ProcessExtendedInfo*
ICoreWebView2ProcessExtendedInfoCollection::GetValueAtIndex(index)
	INPUT:
		UINT32 index;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ProcessExtendedInfoCollection*)THIS)->lpVtbl->GetValueAtIndex(THIS, index, &RETVAL);
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
