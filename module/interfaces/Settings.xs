#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Settings

PROTOTYPES: DISABLE

BOOL
ICoreWebView2Settings8::get_IsScriptEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsScriptEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsScriptEnabled(isScriptEnabled)
	INPUT:
		BOOL isScriptEnabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsScriptEnabled(THIS, isScriptEnabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsWebMessageEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsWebMessageEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsWebMessageEnabled(isWebMessageEnabled)
	INPUT:
		BOOL isWebMessageEnabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsWebMessageEnabled(THIS, isWebMessageEnabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_AreDefaultScriptDialogsEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_AreDefaultScriptDialogsEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_AreDefaultScriptDialogsEnabled(areDefaultScriptDialogsEnabled)
	INPUT:
		BOOL areDefaultScriptDialogsEnabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_AreDefaultScriptDialogsEnabled(THIS, areDefaultScriptDialogsEnabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsStatusBarEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsStatusBarEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsStatusBarEnabled(isStatusBarEnabled)
	INPUT:
		BOOL isStatusBarEnabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsStatusBarEnabled(THIS, isStatusBarEnabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_AreDevToolsEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_AreDevToolsEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_AreDevToolsEnabled(areDevToolsEnabled)
	INPUT:
		BOOL areDevToolsEnabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_AreDevToolsEnabled(THIS, areDevToolsEnabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_AreDefaultContextMenusEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_AreDefaultContextMenusEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_AreDefaultContextMenusEnabled(enabled)
	INPUT:
		BOOL enabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_AreDefaultContextMenusEnabled(THIS, enabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_AreHostObjectsAllowed()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_AreHostObjectsAllowed(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_AreHostObjectsAllowed(allowed)
	INPUT:
		BOOL allowed;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_AreHostObjectsAllowed(THIS, allowed);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsZoomControlEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsZoomControlEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsZoomControlEnabled(enabled)
	INPUT:
		BOOL enabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsZoomControlEnabled(THIS, enabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsBuiltInErrorPageEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsBuiltInErrorPageEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsBuiltInErrorPageEnabled(enabled)
	INPUT:
		BOOL enabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsBuiltInErrorPageEnabled(THIS, enabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Settings8::get_UserAgent()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_UserAgent(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_UserAgent(userAgent)
	INPUT:
		LPCWSTR userAgent;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_UserAgent(THIS, userAgent);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_AreBrowserAcceleratorKeysEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_AreBrowserAcceleratorKeysEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_AreBrowserAcceleratorKeysEnabled(areBrowserAcceleratorKeysEnabled)
	INPUT:
		BOOL areBrowserAcceleratorKeysEnabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_AreBrowserAcceleratorKeysEnabled(THIS, areBrowserAcceleratorKeysEnabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsPasswordAutosaveEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsPasswordAutosaveEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsPasswordAutosaveEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsPasswordAutosaveEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsGeneralAutofillEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsGeneralAutofillEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsGeneralAutofillEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsGeneralAutofillEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsPinchZoomEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsPinchZoomEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsPinchZoomEnabled(enabled)
	INPUT:
		BOOL enabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsPinchZoomEnabled(THIS, enabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsSwipeNavigationEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsSwipeNavigationEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsSwipeNavigationEnabled(enabled)
	INPUT:
		BOOL enabled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsSwipeNavigationEnabled(THIS, enabled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PDF_TOOLBAR_ITEMS
ICoreWebView2Settings8::get_HiddenPdfToolbarItems()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_HiddenPdfToolbarItems(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_HiddenPdfToolbarItems(hidden_pdf_toolbar_items)
	INPUT:
		COREWEBVIEW2_PDF_TOOLBAR_ITEMS hidden_pdf_toolbar_items;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_HiddenPdfToolbarItems(THIS, hidden_pdf_toolbar_items);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Settings8::get_IsReputationCheckingRequired()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Settings8*)THIS)->lpVtbl->get_IsReputationCheckingRequired(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Settings8::put_IsReputationCheckingRequired(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Settings8*)THIS)->lpVtbl->put_IsReputationCheckingRequired(THIS, value);
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
