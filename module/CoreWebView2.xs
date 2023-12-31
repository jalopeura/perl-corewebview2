#include "utils.h"
#include "variant.h"

#include "interfaces/AcceleratorKeyPressedEventHandler.h"
#include "interfaces/AddScriptToExecuteOnDocumentCreatedCompletedHandler.h"
#include "interfaces/BasicAuthenticationRequestedEventHandler.h"
#include "interfaces/BrowserExtensionEnableCompletedHandler.h"
#include "interfaces/BrowserExtensionRemoveCompletedHandler.h"
#include "interfaces/BrowserProcessExitedEventHandler.h"
#include "interfaces/BytesReceivedChangedEventHandler.h"
#include "interfaces/CallDevToolsProtocolMethodCompletedHandler.h"
#include "interfaces/CapturePreviewCompletedHandler.h"
#include "interfaces/ClearBrowsingDataCompletedHandler.h"
#include "interfaces/ClearServerCertificateErrorActionsCompletedHandler.h"
#include "interfaces/ClientCertificateRequestedEventHandler.h"
#include "interfaces/ContainsFullScreenElementChangedEventHandler.h"
#include "interfaces/ContentLoadingEventHandler.h"
#include "interfaces/ContextMenuRequestedEventHandler.h"
#include "interfaces/CreateCoreWebView2CompositionControllerCompletedHandler.h"
#include "interfaces/CreateCoreWebView2ControllerCompletedHandler.h"
#include "interfaces/CreateCoreWebView2EnvironmentCompletedHandler.h"
#include "interfaces/CursorChangedEventHandler.h"
#include "interfaces/CustomItemSelectedEventHandler.h"
#include "interfaces/DOMContentLoadedEventHandler.h"
#include "interfaces/DevToolsProtocolEventReceivedEventHandler.h"
#include "interfaces/DocumentTitleChangedEventHandler.h"
#include "interfaces/DownloadStartingEventHandler.h"
#include "interfaces/EstimatedEndTimeChangedEventHandler.h"
#include "interfaces/ExecuteScriptCompletedHandler.h"
#include "interfaces/FaviconChangedEventHandler.h"
#include "interfaces/FocusChangedEventHandler.h"
#include "interfaces/FrameContentLoadingEventHandler.h"
#include "interfaces/FrameCreatedEventHandler.h"
#include "interfaces/FrameDOMContentLoadedEventHandler.h"
#include "interfaces/FrameDestroyedEventHandler.h"
#include "interfaces/FrameNameChangedEventHandler.h"
#include "interfaces/FrameNavigationCompletedEventHandler.h"
#include "interfaces/FrameNavigationStartingEventHandler.h"
#include "interfaces/FramePermissionRequestedEventHandler.h"
#include "interfaces/FrameWebMessageReceivedEventHandler.h"
#include "interfaces/GetCookiesCompletedHandler.h"
#include "interfaces/GetFaviconCompletedHandler.h"
#include "interfaces/GetNonDefaultPermissionSettingsCompletedHandler.h"
#include "interfaces/GetProcessExtendedInfosCompletedHandler.h"
#include "interfaces/HistoryChangedEventHandler.h"
#include "interfaces/IsDefaultDownloadDialogOpenChangedEventHandler.h"
#include "interfaces/IsDocumentPlayingAudioChangedEventHandler.h"
#include "interfaces/IsMutedChangedEventHandler.h"
#include "interfaces/LaunchingExternalUriSchemeEventHandler.h"
#include "interfaces/MoveFocusRequestedEventHandler.h"
#include "interfaces/NavigationCompletedEventHandler.h"
#include "interfaces/NavigationStartingEventHandler.h"
#include "interfaces/NewBrowserVersionAvailableEventHandler.h"
#include "interfaces/NewWindowRequestedEventHandler.h"
#include "interfaces/PermissionRequestedEventHandler.h"
#include "interfaces/PrintCompletedHandler.h"
#include "interfaces/PrintToPdfCompletedHandler.h"
#include "interfaces/PrintToPdfStreamCompletedHandler.h"
#include "interfaces/ProcessFailedEventHandler.h"
#include "interfaces/ProcessInfosChangedEventHandler.h"
#include "interfaces/ProfileAddBrowserExtensionCompletedHandler.h"
#include "interfaces/ProfileDeletedEventHandler.h"
#include "interfaces/ProfileGetBrowserExtensionsCompletedHandler.h"
#include "interfaces/RasterizationScaleChangedEventHandler.h"
#include "interfaces/ScriptDialogOpeningEventHandler.h"
#include "interfaces/ServerCertificateErrorDetectedEventHandler.h"
#include "interfaces/SetPermissionStateCompletedHandler.h"
#include "interfaces/SourceChangedEventHandler.h"
#include "interfaces/StateChangedEventHandler.h"
#include "interfaces/StatusBarTextChangedEventHandler.h"
#include "interfaces/TrySuspendCompletedHandler.h"
#include "interfaces/WebMessageReceivedEventHandler.h"
#include "interfaces/WebResourceRequestedEventHandler.h"
#include "interfaces/WebResourceResponseReceivedEventHandler.h"
#include "interfaces/WebResourceResponseViewGetContentCompletedHandler.h"
#include "interfaces/WindowCloseRequestedEventHandler.h"
#include "interfaces/ZoomFactorChangedEventHandler.h"

// helpers
#include "CustomSchemeRegistration.h"
#include "EnvironmentOptions.h"
#include "PerlObjectWrapper.h"
#include "StreamHandler.h"

void OnResizeWindow(HWND hWnd) {
	RECT bounds;
	SV* rect_sv;
	SV* subref;

	GetClientRect(hWnd, &bounds);
	rect_sv = rect_to_href(bounds);
	subref = (SV*)GetWindowLongPtr(hWnd, GWLP_USERDATA);

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 1); 
	PUSHMARK(SP);

	XPUSHs(rect_sv);

	PUTBACK;

	call_sv(subref, G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;
}

void OnCloseWindow(HWND hWnd) {
	SV* subref = (SV*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	SvREFCNT_dec(subref);
	DestroyWindow(hWnd);
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_SIZE:
		OnResizeWindow(hWnd);
		break;
	case WM_CLOSE:
		OnCloseWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

MODULE = CoreWebView2		PACKAGE = CoreWebView2

PROTOTYPES: DISABLE

void*
dump(scalar)
	INPUT:
		SV* scalar;
	CODE:
		sv_dump(scalar);

int
_refcount(scalar)
	INPUT:
		SV* scalar;
	CODE:
		if (SvROK(scalar)) {
			RETVAL = SvREFCNT(SvRV(scalar));
		}
		else {
			RETVAL = SvREFCNT(scalar);
		}
	OUTPUT:
		RETVAL

#
# host window
#

HWND
create_host_window(subref = NULL)
	INPUT:
		SV* subref
	CODE:
		SvREFCNT_inc(subref);

		RETVAL = CreateWindowEx(
			0,                     // extended styles
			TEXT("WebView2"),      // created below
			TEXT("CoreWebView2"),  // title
			WS_OVERLAPPEDWINDOW,   // style
			CW_USEDEFAULT,         // left
			CW_USEDEFAULT,         // top
			1024,                  // width
			768,                   // height
			nullptr,               // parent
			nullptr,               // menu
			GetModuleHandle(NULL), // current app
			0                      // creation data
		);
		SetWindowLongPtr(RETVAL, GWLP_USERDATA, (LONG_PTR)subref);

		ShowWindow(RETVAL, SW_SHOW);
		UpdateWindow(RETVAL);
		SetFocus(RETVAL);
	OUTPUT:
		RETVAL

void
start_window_loop()
	INIT:
		MSG msg;
	CODE:
		while (GetMessage(&msg, nullptr, 0, 0)) {
			if (msg.message == WM_QUIT) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

void
trigger_window_resize(hWnd)
	INPUT:
		HWND hWnd;
	CODE:
		OnResizeWindow(hWnd);

void
close_window(hWnd)
	INPUT:
		HWND hWnd;
	CODE:
		OnCloseWindow(hWnd);

BOOT:
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = TEXT("WebView2");
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.lpfnWndProc = WndProc;
	RegisterClassEx(&wc);
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

MODULE = CoreWebView2	PACKAGE = CoreWebView2::CustomSchemeRegistration

SV*
CustomSchemeRegistration::new(params = NULL)
	INPUT:
		SV* params;
	INIT:
		ICoreWebView2CustomSchemeRegistration* registration;
	CODE:
		registration = (ICoreWebView2CustomSchemeRegistration*)get_custom_registration(params, IID_ICoreWebView2CustomSchemeRegistration);
		create_perl_object(RETVAL, registration, CLASS);

		// create_perl_object() will call AddRef(), but get_custom_registration() returns with a refcount of 1
		// so we need to Release() one of the references
		registration->lpVtbl->Release(registration);
	OUTPUT:
		RETVAL

MODULE = CoreWebView2	PACKAGE = CoreWebView2::EnvironmentOptions

PROTOTYPES: DISABLE

SV*
EnvironmentOptions::new(params = NULL)
	INPUT:
		SV* params;
	INIT:
		ICoreWebView2EnvironmentOptions* options;
	CODE:
		options = (ICoreWebView2EnvironmentOptions*)get_environment_options(params, IID_ICoreWebView2EnvironmentOptions);
		create_perl_object(RETVAL, options, CLASS);

		// create_perl_object() will call AddRef(), but get_environment_options() returns with a refcount of 1
		// so we need to Release() one of the references
		options->lpVtbl->Release(options);
	OUTPUT:
		RETVAL

#MODULE = CoreWebView2	PACKAGE = CoreWebView2::PerlObjectWrapper
#
#PROTOTYPES: DISABLE
#
#SV*
#PerlObjectWrapper::new(wrapped)
#	INPUT:
#		SV* wrapped;
#	INIT:
#		PerlObjectWrapper* wrapper;
#		HV* hash;
#	CODE:
#		wrapper = new PerlObjectWrapper(NULL);
#
#		create_perl_object(&RETVAL, wrapper, CLASS);
#		// don't bother checking return value for NEW_OBJECT, because we know it's new - we just created it
#		// but we don't need to AddRef() because it happened in the constructor
#
#		// store the wrapper in the C++ object
#		// (DO NOT increment the ref count, this is circular containment)
#		wrapper->SetPerlObject(RETVAL);
#
#		// store the wrapped object in the wrapper
#		hash = (HV*)SvRV(RETVAL);
#		hv_store(hash, "wrapped", 7, wrapped, 0);
#	OUTPUT:
#		RETVAL

INCLUDE: interfaces/constants.xs
INCLUDE: interfaces/globals.xs
INCLUDE: interfaces/AcceleratorKeyPressedEventArgs.xs
INCLUDE: interfaces/BasicAuthenticationRequestedEventArgs.xs
INCLUDE: interfaces/BasicAuthenticationResponse.xs
INCLUDE: interfaces/BrowserExtension.xs
INCLUDE: interfaces/BrowserExtensionList.xs
INCLUDE: interfaces/BrowserProcessExitedEventArgs.xs
INCLUDE: interfaces/Certificate.xs
INCLUDE: interfaces/ClientCertificate.xs
INCLUDE: interfaces/ClientCertificateCollection.xs
INCLUDE: interfaces/ClientCertificateRequestedEventArgs.xs
INCLUDE: interfaces/CompositionController.xs
INCLUDE: interfaces/ContentLoadingEventArgs.xs
INCLUDE: interfaces/ContextMenuItem.xs
INCLUDE: interfaces/ContextMenuItemCollection.xs
INCLUDE: interfaces/ContextMenuRequestedEventArgs.xs
INCLUDE: interfaces/ContextMenuTarget.xs
INCLUDE: interfaces/Controller.xs
INCLUDE: interfaces/ControllerOptions.xs
INCLUDE: interfaces/Cookie.xs
INCLUDE: interfaces/CookieList.xs
INCLUDE: interfaces/CookieManager.xs
INCLUDE: interfaces/CoreWebView2.xs
INCLUDE: interfaces/CustomSchemeRegistration.xs
INCLUDE: interfaces/DOMContentLoadedEventArgs.xs
INCLUDE: interfaces/Deferral.xs
INCLUDE: interfaces/DevToolsProtocolEventReceivedEventArgs.xs
INCLUDE: interfaces/DevToolsProtocolEventReceiver.xs
INCLUDE: interfaces/DownloadOperation.xs
INCLUDE: interfaces/DownloadStartingEventArgs.xs
INCLUDE: interfaces/Environment.xs
INCLUDE: interfaces/EnvironmentOptions.xs
INCLUDE: interfaces/File.xs
INCLUDE: interfaces/Frame.xs
INCLUDE: interfaces/FrameCreatedEventArgs.xs
INCLUDE: interfaces/FrameInfo.xs
INCLUDE: interfaces/FrameInfoCollection.xs
INCLUDE: interfaces/FrameInfoCollectionIterator.xs
INCLUDE: interfaces/HttpHeadersCollectionIterator.xs
INCLUDE: interfaces/HttpRequestHeaders.xs
INCLUDE: interfaces/HttpResponseHeaders.xs
INCLUDE: interfaces/LaunchingExternalUriSchemeEventArgs.xs
INCLUDE: interfaces/MoveFocusRequestedEventArgs.xs
INCLUDE: interfaces/NavigationCompletedEventArgs.xs
INCLUDE: interfaces/NavigationStartingEventArgs.xs
INCLUDE: interfaces/NewWindowRequestedEventArgs.xs
INCLUDE: interfaces/ObjectCollectionView.xs
INCLUDE: interfaces/PermissionRequestedEventArgs.xs
INCLUDE: interfaces/PermissionSetting.xs
INCLUDE: interfaces/PermissionSettingCollectionView.xs
INCLUDE: interfaces/PointerInfo.xs
INCLUDE: interfaces/PrintSettings.xs
INCLUDE: interfaces/ProcessExtendedInfo.xs
INCLUDE: interfaces/ProcessExtendedInfoCollection.xs
INCLUDE: interfaces/ProcessFailedEventArgs.xs
INCLUDE: interfaces/ProcessInfo.xs
INCLUDE: interfaces/ProcessInfoCollection.xs
INCLUDE: interfaces/Profile.xs
INCLUDE: interfaces/ScriptDialogOpeningEventArgs.xs
INCLUDE: interfaces/ServerCertificateErrorDetectedEventArgs.xs
INCLUDE: interfaces/Settings.xs
INCLUDE: interfaces/SharedBuffer.xs
INCLUDE: interfaces/SourceChangedEventArgs.xs
INCLUDE: interfaces/StringCollection.xs
INCLUDE: interfaces/WebMessageReceivedEventArgs.xs
INCLUDE: interfaces/WebResourceRequest.xs
INCLUDE: interfaces/WebResourceRequestedEventArgs.xs
INCLUDE: interfaces/WebResourceResponse.xs
INCLUDE: interfaces/WebResourceResponseReceivedEventArgs.xs
INCLUDE: interfaces/WebResourceResponseView.xs
INCLUDE: interfaces/WindowFeatures.xs

INCLUDE: helpers/Stream.xs
INCLUDE: helpers/Dispatch.xs

##/*
##
###define CINTERFACE
###include "WebView2.h"
###include "event.h"
###include <tchar.h>
###include <locale>
###include <string>
###ifndef UNICODE
###include <codecvt>
###endif
##
##ICoreWebView2* webview2 = nullptr;
##ICoreWebView2Controller* controller = nullptr;
##
##std::wstring TStrToWStr(LPCTSTR str)
##{
###ifdef UNICODE
##    return std::wstring(str);
###else
##	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
##	return converter.from_bytes(str);
###endif
##}
##
##void GetDataPath(LPTSTR szOut, DWORD nSize)
##{
##	TCHAR szExePath[MAX_PATH];
##	GetModuleFileName(nullptr, szExePath, _countof(szExePath));
##
##	LPTSTR szExeName = _tcsrchr(szExePath, TEXT('\\'));
##	szExeName = szExeName ? szExeName + 1 : szExePath;
##
##	TCHAR szAppData[MAX_PATH];
##	GetEnvironmentVariable(TEXT("AppData"), szAppData, _countof(szAppData));
##
##	_tcsncpy(szOut, szAppData, nSize);
##	_tcsncat(szOut, TEXT("\\"), nSize);
##	_tcsncat(szOut, szExeName, nSize);
##}
##
##[[ noreturn ]] void FatalError(LPCTSTR format, ...)
##{
##	MessageBox(nullptr, format, TEXT("webview2-mingw"), MB_OK | MB_ICONSTOP);
##	ExitProcess(1);
##}
##
##void ResizeBrowser(HWND hWnd)
##{
##	if (!controller)
##	{
##		return;
##	}
##	RECT bounds;
##	GetClientRect(hWnd, &bounds);
##	controller->lpVtbl->put_Bounds(controller, bounds);
##}
##
##LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
##{
##	switch (msg)
##	{
##	case WM_SIZE:
##		ResizeBrowser(hWnd);
##		break;
##	case WM_CLOSE:
##		DestroyWindow(hWnd);
##		break;
##	case WM_DESTROY:
##        PostQuitMessage(0);
##		break;
##	default:
##		return DefWindowProc(hWnd, msg, wParam, lParam);
##	}
##	return 0;
##}
##
##INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
##{
##	UNREFERENCED_PARAMETER(hPrevInstance);
##	UNREFERENCED_PARAMETER(lpCmdLine);
##	UNREFERENCED_PARAMETER(nCmdShow);
##
##	HICON icon = reinterpret_cast<HICON>(LoadImage(
##		hInstance,
##		IDI_APPLICATION,
##		IMAGE_ICON,
##		GetSystemMetrics(SM_CXICON),
##		GetSystemMetrics(SM_CYICON),
##		0
##	));
##
##	WNDCLASSEX wc{};
##	wc.cbSize = sizeof(WNDCLASSEX);
##	wc.hInstance = hInstance;
##	wc.lpszClassName = TEXT("webview");
##	wc.hIcon = icon;
##	wc.hIconSm = icon;
##	wc.lpfnWndProc = WndProc;
##	RegisterClassEx(&wc);
##	HWND hWnd = CreateWindowEx(
##		0,
##		TEXT("webview"),
##		TEXT("MinGW WebView2 Demo"),
##		WS_OVERLAPPEDWINDOW,
##		CW_USEDEFAULT,
##		CW_USEDEFAULT,
##		1024,
##		768,
##		nullptr,
##		nullptr,
##		hInstance,
##		nullptr
##	);
##
##	ShowWindow(hWnd, SW_SHOW);
##	UpdateWindow(hWnd);
##	SetFocus(hWnd);
##
##	// Get data path.
##	TCHAR szDataPath[MAX_PATH];
##	GetDataPath(szDataPath, _countof(szDataPath));
##
##	// Set up some event handlers.
##	EventHandler handler{};
##
##	handler.EnvironmentCompleted = [&](HRESULT result, ICoreWebView2Environment* created_environment)
##	{
##		if (FAILED(result))
##		{
##			FatalError(TEXT("Failed to create environment?"));
##		}
##		created_environment->lpVtbl->CreateCoreWebView2Controller(created_environment, hWnd, &);
##		return S_OK;
##	};
##
##	handler.ControllerCompleted = [&](HRESULT result, ICoreWebView2Controller* new_controller)
##	{
##		if (FAILED(result))
##		{
##			FatalError(TEXT("Failed to create controller?"));
##		}
##		controller = new_controller;
##		controller->lpVtbl->AddRef(controller);
##		controller->lpVtbl->get_CoreWebView2(controller, &webview2);
##		webview2->lpVtbl->AddRef(webview2);
##		webview2->lpVtbl->Navigate(webview2, L"https://en.m.wikipedia.org/wiki/Tyson_Tan");
##		ResizeBrowser(hWnd);
##		return S_OK;
##	};
##
##	HRESULT result = CreateCoreWebView2EnvironmentWithOptions(
##		nullptr,
##		TStrToWStr(szDataPath).c_str(),
##		nullptr,
##		&handler
##	);
##	if (FAILED(result))
##	{
##		FatalError(TEXT("Call to CreateCoreWebView2EnvironmentWithOptions failed!"));
##	}
##
##	MSG msg;
##	while (GetMessage(&msg, nullptr, 0, 0))
##	{
##		if (msg.message == WM_QUIT)
##		{
##			break;
##		}
##		TranslateMessage(&msg);
##		DispatchMessage(&msg);
##	}
##
##	return 0;
##}
##
##*/
