/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class BrowserExtensionEnableCompletedHandler : public HandlerBase {
public:
	BrowserExtensionEnableCompletedHandler(SV* perl_object);
	virtual ~BrowserExtensionEnableCompletedHandler();

	BrowserExtensionEnableCompletedHandler(const BrowserExtensionEnableCompletedHandler&) = delete;
	BrowserExtensionEnableCompletedHandler(BrowserExtensionEnableCompletedHandler&&) = delete;
	BrowserExtensionEnableCompletedHandler& operator=(const BrowserExtensionEnableCompletedHandler&) = delete;
	BrowserExtensionEnableCompletedHandler& operator=(BrowserExtensionEnableCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2BrowserExtensionEnableCompletedHandler
	WRAP_INTERFACE(BrowserExtensionEnableCompletedHandler1, ICoreWebView2BrowserExtensionEnableCompletedHandler, BrowserExtensionEnableCompletedHandler)
	HRESULT Invoke(HRESULT errorCode);
};
