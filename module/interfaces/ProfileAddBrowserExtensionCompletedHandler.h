/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ProfileAddBrowserExtensionCompletedHandler : public HandlerBase {
public:
	ProfileAddBrowserExtensionCompletedHandler(SV* perl_object);
	virtual ~ProfileAddBrowserExtensionCompletedHandler();

	ProfileAddBrowserExtensionCompletedHandler(const ProfileAddBrowserExtensionCompletedHandler&) = delete;
	ProfileAddBrowserExtensionCompletedHandler(ProfileAddBrowserExtensionCompletedHandler&&) = delete;
	ProfileAddBrowserExtensionCompletedHandler& operator=(const ProfileAddBrowserExtensionCompletedHandler&) = delete;
	ProfileAddBrowserExtensionCompletedHandler& operator=(ProfileAddBrowserExtensionCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ProfileAddBrowserExtensionCompletedHandler
	WRAP_INTERFACE(ProfileAddBrowserExtensionCompletedHandler1, ICoreWebView2ProfileAddBrowserExtensionCompletedHandler, ProfileAddBrowserExtensionCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2BrowserExtension* extension);
};
