/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class WebMessageReceivedEventHandler : public HandlerBase {
public:
	WebMessageReceivedEventHandler(SV* perl_object);
	virtual ~WebMessageReceivedEventHandler();

	WebMessageReceivedEventHandler(const WebMessageReceivedEventHandler&) = delete;
	WebMessageReceivedEventHandler(WebMessageReceivedEventHandler&&) = delete;
	WebMessageReceivedEventHandler& operator=(const WebMessageReceivedEventHandler&) = delete;
	WebMessageReceivedEventHandler& operator=(WebMessageReceivedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2WebMessageReceivedEventHandler
	WRAP_INTERFACE(WebMessageReceivedEventHandler1, ICoreWebView2WebMessageReceivedEventHandler, WebMessageReceivedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args);
};
