#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::ContextMenuItem

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2ContextMenuItem::get_Name()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_Name(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ContextMenuItem::get_Label()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_Label(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2ContextMenuItem::get_CommandId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_CommandId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2ContextMenuItem::get_ShortcutKeyDescription()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_ShortcutKeyDescription(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

IStream*
ICoreWebView2ContextMenuItem::get_Icon()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_Icon(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_CONTEXT_MENU_ITEM_KIND
ICoreWebView2ContextMenuItem::get_Kind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_Kind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuItem::put_IsEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->put_IsEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ContextMenuItem::get_IsEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_IsEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuItem::put_IsChecked(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->put_IsChecked(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2ContextMenuItem::get_IsChecked()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_IsChecked(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ContextMenuItemCollection*
ICoreWebView2ContextMenuItem::get_Children()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->get_Children(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2ContextMenuItem::add_CustomItemSelected(eventHandler)
	INPUT:
		ICoreWebView2CustomItemSelectedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->add_CustomItemSelected(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2ContextMenuItem::remove_CustomItemSelected(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2ContextMenuItem*)THIS)->lpVtbl->remove_CustomItemSelected(THIS, token);
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
