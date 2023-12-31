/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class BrowserExtensionRemoveCompletedHandler : public HandlerBase {
public:
	BrowserExtensionRemoveCompletedHandler(SV* perl_object);
	virtual ~BrowserExtensionRemoveCompletedHandler();

	BrowserExtensionRemoveCompletedHandler(const BrowserExtensionRemoveCompletedHandler&) = delete;
	BrowserExtensionRemoveCompletedHandler(BrowserExtensionRemoveCompletedHandler&&) = delete;
	BrowserExtensionRemoveCompletedHandler& operator=(const BrowserExtensionRemoveCompletedHandler&) = delete;
	BrowserExtensionRemoveCompletedHandler& operator=(BrowserExtensionRemoveCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2BrowserExtensionRemoveCompletedHandler
	WRAP_INTERFACE(BrowserExtensionRemoveCompletedHandler1, ICoreWebView2BrowserExtensionRemoveCompletedHandler, BrowserExtensionRemoveCompletedHandler)
	HRESULT Invoke(HRESULT errorCode);
};
