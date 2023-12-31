#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Environment

PROTOTYPES: DISABLE

HRESULT
ICoreWebView2Environment13::CreateCoreWebView2Controller(parentWindow, handler)
	INPUT:
		HWND parentWindow;
		ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateCoreWebView2Controller(THIS, parentWindow, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2WebResourceResponse*
ICoreWebView2Environment13::CreateWebResourceResponse(content, statusCode, reasonPhrase, headers)
	INPUT:
		IStream* content;
		int statusCode;
		LPCWSTR reasonPhrase;
		LPCWSTR headers;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
	#ifdef DEBUG
	WARN("!");
	#endif
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateWebResourceResponse(THIS, content, statusCode, reasonPhrase, headers, &RETVAL);
	#ifdef DEBUG
	WARN("!");
	#endif
		CHECK_ERROR(result, error_sv);
	#ifdef DEBUG
	WARN("!");
	#endif
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Environment13::get_BrowserVersionString()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->get_BrowserVersionString(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Environment13::add_NewBrowserVersionAvailable(eventHandler)
	INPUT:
		ICoreWebView2NewBrowserVersionAvailableEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->add_NewBrowserVersionAvailable(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::remove_NewBrowserVersionAvailable(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->remove_NewBrowserVersionAvailable(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2WebResourceRequest*
ICoreWebView2Environment13::CreateWebResourceRequest(uri, method, postData, headers)
	INPUT:
		LPCWSTR uri;
		LPCWSTR method;
		IStream* postData;
		LPCWSTR headers;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateWebResourceRequest(THIS, uri, method, postData, headers, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::CreateCoreWebView2CompositionController(parentWindow, handler)
	INPUT:
		HWND parentWindow;
		ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateCoreWebView2CompositionController(THIS, parentWindow, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2PointerInfo*
ICoreWebView2Environment13::CreateCoreWebView2PointerInfo()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateCoreWebView2PointerInfo(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

IUnknown*
ICoreWebView2Environment13::GetAutomationProviderForWindow(hwnd)
	INPUT:
		HWND hwnd;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->GetAutomationProviderForWindow(THIS, hwnd, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Environment13::add_BrowserProcessExited(eventHandler)
	INPUT:
		ICoreWebView2BrowserProcessExitedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->add_BrowserProcessExited(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::remove_BrowserProcessExited(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->remove_BrowserProcessExited(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2PrintSettings*
ICoreWebView2Environment13::CreatePrintSettings()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreatePrintSettings(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Environment13::get_UserDataFolder()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->get_UserDataFolder(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Environment13::add_ProcessInfosChanged(eventHandler)
	INPUT:
		ICoreWebView2ProcessInfosChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->add_ProcessInfosChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::remove_ProcessInfosChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->remove_ProcessInfosChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ProcessInfoCollection*
ICoreWebView2Environment13::GetProcessInfos()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->GetProcessInfos(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ContextMenuItem*
ICoreWebView2Environment13::CreateContextMenuItem(label, iconStream, kind)
	INPUT:
		LPCWSTR label;
		IStream* iconStream;
		COREWEBVIEW2_CONTEXT_MENU_ITEM_KIND kind;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateContextMenuItem(THIS, label, iconStream, kind, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2ControllerOptions*
ICoreWebView2Environment13::CreateCoreWebView2ControllerOptions()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateCoreWebView2ControllerOptions(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::CreateCoreWebView2ControllerWithOptions(parentWindow, options, handler)
	INPUT:
		HWND parentWindow;
		ICoreWebView2ControllerOptions* options;
		ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateCoreWebView2ControllerWithOptions(THIS, parentWindow, options, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::CreateCoreWebView2CompositionControllerWithOptions(parentWindow, options, handler)
	INPUT:
		HWND parentWindow;
		ICoreWebView2ControllerOptions* options;
		ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateCoreWebView2CompositionControllerWithOptions(THIS, parentWindow, options, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Environment13::get_FailureReportFolderPath()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->get_FailureReportFolderPath(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2SharedBuffer*
ICoreWebView2Environment13::CreateSharedBuffer(size)
	INPUT:
		UINT64 size;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Environment13*)THIS)->lpVtbl->CreateSharedBuffer(THIS, size, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Environment13::GetProcessExtendedInfos(handler)
	INPUT:
		ICoreWebView2GetProcessExtendedInfosCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Environment13*)THIS)->lpVtbl->GetProcessExtendedInfos(THIS, handler);
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
