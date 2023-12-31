/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class WebResourceResponseReceivedEventHandler : public HandlerBase {
public:
	WebResourceResponseReceivedEventHandler(SV* perl_object);
	virtual ~WebResourceResponseReceivedEventHandler();

	WebResourceResponseReceivedEventHandler(const WebResourceResponseReceivedEventHandler&) = delete;
	WebResourceResponseReceivedEventHandler(WebResourceResponseReceivedEventHandler&&) = delete;
	WebResourceResponseReceivedEventHandler& operator=(const WebResourceResponseReceivedEventHandler&) = delete;
	WebResourceResponseReceivedEventHandler& operator=(WebResourceResponseReceivedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2WebResourceResponseReceivedEventHandler
	WRAP_INTERFACE(WebResourceResponseReceivedEventHandler1, ICoreWebView2WebResourceResponseReceivedEventHandler, WebResourceResponseReceivedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2WebResourceResponseReceivedEventArgs* args);
};
