#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2

PROTOTYPES: DISABLE

ICoreWebView2Settings*
ICoreWebView2_20::get_Settings()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_Settings(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2_20::get_Source()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_Source(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::Navigate(uri)
	INPUT:
		LPCWSTR uri;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->Navigate(THIS, uri);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::NavigateToString(htmlContent)
	INPUT:
		LPCWSTR htmlContent;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->NavigateToString(THIS, htmlContent);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_NavigationStarting(eventHandler)
	INPUT:
		ICoreWebView2NavigationStartingEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_NavigationStarting(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_NavigationStarting(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_NavigationStarting(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ContentLoading(eventHandler)
	INPUT:
		ICoreWebView2ContentLoadingEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ContentLoading(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ContentLoading(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ContentLoading(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_SourceChanged(eventHandler)
	INPUT:
		ICoreWebView2SourceChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_SourceChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_SourceChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_SourceChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_HistoryChanged(eventHandler)
	INPUT:
		ICoreWebView2HistoryChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_HistoryChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_HistoryChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_HistoryChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_NavigationCompleted(eventHandler)
	INPUT:
		ICoreWebView2NavigationCompletedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_NavigationCompleted(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_NavigationCompleted(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_NavigationCompleted(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_FrameNavigationStarting(eventHandler)
	INPUT:
		ICoreWebView2NavigationStartingEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_FrameNavigationStarting(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_FrameNavigationStarting(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_FrameNavigationStarting(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_FrameNavigationCompleted(eventHandler)
	INPUT:
		ICoreWebView2NavigationCompletedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_FrameNavigationCompleted(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_FrameNavigationCompleted(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_FrameNavigationCompleted(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ScriptDialogOpening(eventHandler)
	INPUT:
		ICoreWebView2ScriptDialogOpeningEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ScriptDialogOpening(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ScriptDialogOpening(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ScriptDialogOpening(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_PermissionRequested(eventHandler)
	INPUT:
		ICoreWebView2PermissionRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_PermissionRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_PermissionRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_PermissionRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ProcessFailed(eventHandler)
	INPUT:
		ICoreWebView2ProcessFailedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ProcessFailed(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ProcessFailed(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ProcessFailed(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::AddScriptToExecuteOnDocumentCreated(javaScript, handler)
	INPUT:
		LPCWSTR javaScript;
		ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->AddScriptToExecuteOnDocumentCreated(THIS, javaScript, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::RemoveScriptToExecuteOnDocumentCreated(id)
	INPUT:
		LPCWSTR id;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->RemoveScriptToExecuteOnDocumentCreated(THIS, id);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::ExecuteScript(javaScript, handler)
	INPUT:
		LPCWSTR javaScript;
		ICoreWebView2ExecuteScriptCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->ExecuteScript(THIS, javaScript, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::CapturePreview(imageFormat, imageStream, handler)
	INPUT:
		COREWEBVIEW2_CAPTURE_PREVIEW_IMAGE_FORMAT imageFormat;
		IStream* imageStream;
		ICoreWebView2CapturePreviewCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->CapturePreview(THIS, imageFormat, imageStream, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::Reload()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->Reload(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::PostWebMessageAsJson(webMessageAsJson)
	INPUT:
		LPCWSTR webMessageAsJson;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->PostWebMessageAsJson(THIS, webMessageAsJson);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::PostWebMessageAsString(webMessageAsString)
	INPUT:
		LPCWSTR webMessageAsString;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->PostWebMessageAsString(THIS, webMessageAsString);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_WebMessageReceived(handler)
	INPUT:
		ICoreWebView2WebMessageReceivedEventHandler* handler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_WebMessageReceived(THIS, handler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_WebMessageReceived(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_WebMessageReceived(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::CallDevToolsProtocolMethod(methodName, parametersAsJson, handler)
	INPUT:
		LPCWSTR methodName;
		LPCWSTR parametersAsJson;
		ICoreWebView2CallDevToolsProtocolMethodCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->CallDevToolsProtocolMethod(THIS, methodName, parametersAsJson, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2_20::get_BrowserProcessId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_BrowserProcessId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_CanGoBack()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_CanGoBack(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_CanGoForward()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_CanGoForward(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::GoBack()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->GoBack(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::GoForward()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->GoForward(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2DevToolsProtocolEventReceiver*
ICoreWebView2_20::GetDevToolsProtocolEventReceiver(eventName)
	INPUT:
		LPCWSTR eventName;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->GetDevToolsProtocolEventReceiver(THIS, eventName, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::Stop()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->Stop(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_NewWindowRequested(eventHandler)
	INPUT:
		ICoreWebView2NewWindowRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_NewWindowRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_NewWindowRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_NewWindowRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_DocumentTitleChanged(eventHandler)
	INPUT:
		ICoreWebView2DocumentTitleChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_DocumentTitleChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_DocumentTitleChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_DocumentTitleChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2_20::get_DocumentTitle()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_DocumentTitle(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::AddHostObjectToScript(name, object)
	INPUT:
		LPCWSTR name;
		VARIANT* object;
	INIT:
		SV* error_sv;
	WARN("!!!");
	CODE:
	WARN("!!!");
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->AddHostObjectToScript(THIS, name, object);
	WARN("!!!");
		CHECK_ERROR(RETVAL, error_sv);
	WARN("!!!");
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::RemoveHostObjectFromScript(name)
	INPUT:
		LPCWSTR name;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->RemoveHostObjectFromScript(THIS, name);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::OpenDevToolsWindow()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->OpenDevToolsWindow(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ContainsFullScreenElementChanged(eventHandler)
	INPUT:
		ICoreWebView2ContainsFullScreenElementChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ContainsFullScreenElementChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ContainsFullScreenElementChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ContainsFullScreenElementChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_ContainsFullScreenElement()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_ContainsFullScreenElement(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_WebResourceRequested(eventHandler)
	INPUT:
		ICoreWebView2WebResourceRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_WebResourceRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_WebResourceRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_WebResourceRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::AddWebResourceRequestedFilter(uri, resourceContext)
	INPUT:
		LPCWSTR uri;
		COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->AddWebResourceRequestedFilter(THIS, uri, resourceContext);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::RemoveWebResourceRequestedFilter(uri, resourceContext)
	INPUT:
		LPCWSTR uri;
		COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->RemoveWebResourceRequestedFilter(THIS, uri, resourceContext);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_WindowCloseRequested(eventHandler)
	INPUT:
		ICoreWebView2WindowCloseRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_WindowCloseRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_WindowCloseRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_WindowCloseRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_WebResourceResponseReceived(eventHandler)
	INPUT:
		ICoreWebView2WebResourceResponseReceivedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_WebResourceResponseReceived(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_WebResourceResponseReceived(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_WebResourceResponseReceived(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::NavigateWithWebResourceRequest(request)
	INPUT:
		ICoreWebView2WebResourceRequest* request;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->NavigateWithWebResourceRequest(THIS, request);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_DOMContentLoaded(eventHandler)
	INPUT:
		ICoreWebView2DOMContentLoadedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_DOMContentLoaded(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_DOMContentLoaded(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_DOMContentLoaded(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2CookieManager*
ICoreWebView2_20::get_CookieManager()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_CookieManager(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Environment*
ICoreWebView2_20::get_Environment()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_Environment(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::TrySuspend(handler)
	INPUT:
		ICoreWebView2TrySuspendCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->TrySuspend(THIS, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::Resume()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->Resume(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_IsSuspended()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_IsSuspended(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::SetVirtualHostNameToFolderMapping(hostName, folderPath, accessKind)
	INPUT:
		LPCWSTR hostName;
		LPCWSTR folderPath;
		COREWEBVIEW2_HOST_RESOURCE_ACCESS_KIND accessKind;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->SetVirtualHostNameToFolderMapping(THIS, hostName, folderPath, accessKind);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::ClearVirtualHostNameToFolderMapping(hostName)
	INPUT:
		LPCWSTR hostName;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->ClearVirtualHostNameToFolderMapping(THIS, hostName);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_FrameCreated(eventHandler)
	INPUT:
		ICoreWebView2FrameCreatedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_FrameCreated(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_FrameCreated(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_FrameCreated(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_DownloadStarting(eventHandler)
	INPUT:
		ICoreWebView2DownloadStartingEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_DownloadStarting(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_DownloadStarting(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_DownloadStarting(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ClientCertificateRequested(eventHandler)
	INPUT:
		ICoreWebView2ClientCertificateRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ClientCertificateRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ClientCertificateRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ClientCertificateRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::OpenTaskManagerWindow()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->OpenTaskManagerWindow(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::PrintToPdf(resultFilePath, printSettings, handler)
	INPUT:
		LPCWSTR resultFilePath;
		ICoreWebView2PrintSettings* printSettings;
		ICoreWebView2PrintToPdfCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->PrintToPdf(THIS, resultFilePath, printSettings, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_IsMutedChanged(eventHandler)
	INPUT:
		ICoreWebView2IsMutedChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_IsMutedChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_IsMutedChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_IsMutedChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_IsMuted()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_IsMuted(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::put_IsMuted(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->put_IsMuted(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_IsDocumentPlayingAudioChanged(eventHandler)
	INPUT:
		ICoreWebView2IsDocumentPlayingAudioChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_IsDocumentPlayingAudioChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_IsDocumentPlayingAudioChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_IsDocumentPlayingAudioChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_IsDocumentPlayingAudio()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_IsDocumentPlayingAudio(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_IsDefaultDownloadDialogOpenChanged(handler)
	INPUT:
		ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler* handler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_IsDefaultDownloadDialogOpenChanged(THIS, handler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_IsDefaultDownloadDialogOpenChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_IsDefaultDownloadDialogOpenChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2_20::get_IsDefaultDownloadDialogOpen()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_IsDefaultDownloadDialogOpen(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::OpenDefaultDownloadDialog()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->OpenDefaultDownloadDialog(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::CloseDefaultDownloadDialog()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->CloseDefaultDownloadDialog(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT
ICoreWebView2_20::get_DefaultDownloadDialogCornerAlignment()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_DefaultDownloadDialogCornerAlignment(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::put_DefaultDownloadDialogCornerAlignment(value)
	INPUT:
		COREWEBVIEW2_DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->put_DefaultDownloadDialogCornerAlignment(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

POINT
ICoreWebView2_20::get_DefaultDownloadDialogMargin()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_DefaultDownloadDialogMargin(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::put_DefaultDownloadDialogMargin(value)
	INPUT:
		POINT value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->put_DefaultDownloadDialogMargin(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_BasicAuthenticationRequested(eventHandler)
	INPUT:
		ICoreWebView2BasicAuthenticationRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_BasicAuthenticationRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_BasicAuthenticationRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_BasicAuthenticationRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::CallDevToolsProtocolMethodForSession(sessionId, methodName, parametersAsJson, handler)
	INPUT:
		LPCWSTR sessionId;
		LPCWSTR methodName;
		LPCWSTR parametersAsJson;
		ICoreWebView2CallDevToolsProtocolMethodCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->CallDevToolsProtocolMethodForSession(THIS, sessionId, methodName, parametersAsJson, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ContextMenuRequested(eventHandler)
	INPUT:
		ICoreWebView2ContextMenuRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ContextMenuRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ContextMenuRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ContextMenuRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_StatusBarTextChanged(eventHandler)
	INPUT:
		ICoreWebView2StatusBarTextChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_StatusBarTextChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_StatusBarTextChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_StatusBarTextChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2_20::get_StatusBarText()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_StatusBarText(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Profile*
ICoreWebView2_20::get_Profile()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_Profile(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_ServerCertificateErrorDetected(eventHandler)
	INPUT:
		ICoreWebView2ServerCertificateErrorDetectedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_ServerCertificateErrorDetected(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_ServerCertificateErrorDetected(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_ServerCertificateErrorDetected(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::ClearServerCertificateErrorActions(handler)
	INPUT:
		ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->ClearServerCertificateErrorActions(THIS, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_FaviconChanged(eventHandler)
	INPUT:
		ICoreWebView2FaviconChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_FaviconChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_FaviconChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_FaviconChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2_20::get_FaviconUri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_FaviconUri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::GetFavicon(format, completedHandler)
	INPUT:
		COREWEBVIEW2_FAVICON_IMAGE_FORMAT format;
		ICoreWebView2GetFaviconCompletedHandler* completedHandler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->GetFavicon(THIS, format, completedHandler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::Print(printSettings, handler)
	INPUT:
		ICoreWebView2PrintSettings* printSettings;
		ICoreWebView2PrintCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->Print(THIS, printSettings, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::ShowPrintUI(printDialogKind)
	INPUT:
		COREWEBVIEW2_PRINT_DIALOG_KIND printDialogKind;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->ShowPrintUI(THIS, printDialogKind);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::PrintToPdfStream(printSettings, handler)
	INPUT:
		ICoreWebView2PrintSettings* printSettings;
		ICoreWebView2PrintToPdfStreamCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->PrintToPdfStream(THIS, printSettings, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::PostSharedBufferToScript(sharedBuffer, access, additionalDataAsJson)
	INPUT:
		ICoreWebView2SharedBuffer* sharedBuffer;
		COREWEBVIEW2_SHARED_BUFFER_ACCESS access;
		LPCWSTR additionalDataAsJson;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->PostSharedBufferToScript(THIS, sharedBuffer, access, additionalDataAsJson);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2_20::add_LaunchingExternalUriScheme(eventHandler)
	INPUT:
		ICoreWebView2LaunchingExternalUriSchemeEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->add_LaunchingExternalUriScheme(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::remove_LaunchingExternalUriScheme(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->remove_LaunchingExternalUriScheme(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL
ICoreWebView2_20::get_MemoryUsageTargetLevel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_MemoryUsageTargetLevel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2_20::put_MemoryUsageTargetLevel(level)
	INPUT:
		COREWEBVIEW2_MEMORY_USAGE_TARGET_LEVEL level;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2_20*)THIS)->lpVtbl->put_MemoryUsageTargetLevel(THIS, level);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2_20::get_FrameId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2_20*)THIS)->lpVtbl->get_FrameId(THIS, &RETVAL);
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
