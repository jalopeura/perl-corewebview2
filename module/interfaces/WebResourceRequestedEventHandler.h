/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class WebResourceRequestedEventHandler : public HandlerBase {
public:
	WebResourceRequestedEventHandler(SV* perl_object);
	virtual ~WebResourceRequestedEventHandler();

	WebResourceRequestedEventHandler(const WebResourceRequestedEventHandler&) = delete;
	WebResourceRequestedEventHandler(WebResourceRequestedEventHandler&&) = delete;
	WebResourceRequestedEventHandler& operator=(const WebResourceRequestedEventHandler&) = delete;
	WebResourceRequestedEventHandler& operator=(WebResourceRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2WebResourceRequestedEventHandler
	WRAP_INTERFACE(WebResourceRequestedEventHandler1, ICoreWebView2WebResourceRequestedEventHandler, WebResourceRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2WebResourceRequestedEventArgs* args);
};
