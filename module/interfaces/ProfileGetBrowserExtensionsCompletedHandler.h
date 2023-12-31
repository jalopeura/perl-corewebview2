/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ProfileGetBrowserExtensionsCompletedHandler : public HandlerBase {
public:
	ProfileGetBrowserExtensionsCompletedHandler(SV* perl_object);
	virtual ~ProfileGetBrowserExtensionsCompletedHandler();

	ProfileGetBrowserExtensionsCompletedHandler(const ProfileGetBrowserExtensionsCompletedHandler&) = delete;
	ProfileGetBrowserExtensionsCompletedHandler(ProfileGetBrowserExtensionsCompletedHandler&&) = delete;
	ProfileGetBrowserExtensionsCompletedHandler& operator=(const ProfileGetBrowserExtensionsCompletedHandler&) = delete;
	ProfileGetBrowserExtensionsCompletedHandler& operator=(ProfileGetBrowserExtensionsCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler
	WRAP_INTERFACE(ProfileGetBrowserExtensionsCompletedHandler1, ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler, ProfileGetBrowserExtensionsCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2BrowserExtensionList* extensionList);
};
