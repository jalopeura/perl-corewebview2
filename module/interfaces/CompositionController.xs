#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::CompositionController

PROTOTYPES: DISABLE

IUnknown*
ICoreWebView2CompositionController3::get_RootVisualTarget()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->get_RootVisualTarget(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CompositionController3::put_RootVisualTarget(target)
	INPUT:
		IUnknown* target;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->put_RootVisualTarget(THIS, target);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CompositionController3::SendMouseInput(eventKind, virtualKeys, mouseData, point)
	INPUT:
		COREWEBVIEW2_MOUSE_EVENT_KIND eventKind;
		COREWEBVIEW2_MOUSE_EVENT_VIRTUAL_KEYS virtualKeys;
		UINT32 mouseData;
		POINT point;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->SendMouseInput(THIS, eventKind, virtualKeys, mouseData, point);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CompositionController3::SendPointerInput(eventKind, pointerInfo)
	INPUT:
		COREWEBVIEW2_POINTER_EVENT_KIND eventKind;
		ICoreWebView2PointerInfo* pointerInfo;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->SendPointerInput(THIS, eventKind, pointerInfo);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HCURSOR
ICoreWebView2CompositionController3::get_Cursor()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->get_Cursor(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2CompositionController3::get_SystemCursorId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->get_SystemCursorId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2CompositionController3::add_CursorChanged(eventHandler)
	INPUT:
		ICoreWebView2CursorChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->add_CursorChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CompositionController3::remove_CursorChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->remove_CursorChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

IUnknown*
ICoreWebView2CompositionController3::get_AutomationProvider()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->get_AutomationProvider(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

DWORD
ICoreWebView2CompositionController3::DragEnter(dataObject, keyState, point)
	INPUT:
		IDataObject* dataObject;
		DWORD keyState;
		POINT point;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->DragEnter(THIS, dataObject, keyState, point, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CompositionController3::DragLeave()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->DragLeave(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

DWORD
ICoreWebView2CompositionController3::DragOver(keyState, point)
	INPUT:
		DWORD keyState;
		POINT point;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->DragOver(THIS, keyState, point, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

DWORD
ICoreWebView2CompositionController3::Drop(dataObject, keyState, point)
	INPUT:
		IDataObject* dataObject;
		DWORD keyState;
		POINT point;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CompositionController3*)THIS)->lpVtbl->Drop(THIS, dataObject, keyState, point, &RETVAL);
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
