#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ContextMenuItemCollection

PROTOTYPES: DISABLE

UINT32
ICoreWebView2ContextMenuItemCollection::get_Count()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItemCollection*)THIS)->lpVtbl->get_Count(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ContextMenuItem*
ICoreWebView2ContextMenuItemCollection::GetValueAtIndex(index)
	INPUT:
		UINT32 index;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItemCollection*)THIS)->lpVtbl->GetValueAtIndex(THIS, index, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuItemCollection::RemoveValueAtIndex(index)
	INPUT:
		UINT32 index;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuItemCollection*)THIS)->lpVtbl->RemoveValueAtIndex(THIS, index);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuItemCollection::InsertValueAtIndex(index, value)
	INPUT:
		UINT32 index;
		ICoreWebView2ContextMenuItem* value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuItemCollection*)THIS)->lpVtbl->InsertValueAtIndex(THIS, index, value);
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
