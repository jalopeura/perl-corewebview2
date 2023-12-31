#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ContextMenuRequestedEventArgs

PROTOTYPES: DISABLE

ICoreWebView2ContextMenuItemCollection*
ICoreWebView2ContextMenuRequestedEventArgs::get_MenuItems()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->get_MenuItems(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ContextMenuTarget*
ICoreWebView2ContextMenuRequestedEventArgs::get_ContextMenuTarget()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->get_ContextMenuTarget(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

POINT
ICoreWebView2ContextMenuRequestedEventArgs::get_Location()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->get_Location(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuRequestedEventArgs::put_SelectedCommandId(value)
	INPUT:
		INT32 value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->put_SelectedCommandId(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2ContextMenuRequestedEventArgs::get_SelectedCommandId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->get_SelectedCommandId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuRequestedEventArgs::put_Handled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->put_Handled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ContextMenuRequestedEventArgs::get_Handled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->get_Handled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2ContextMenuRequestedEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuRequestedEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
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
