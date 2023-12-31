/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class DevToolsProtocolEventReceivedEventHandler : public HandlerBase {
public:
	DevToolsProtocolEventReceivedEventHandler(SV* perl_object);
	virtual ~DevToolsProtocolEventReceivedEventHandler();

	DevToolsProtocolEventReceivedEventHandler(const DevToolsProtocolEventReceivedEventHandler&) = delete;
	DevToolsProtocolEventReceivedEventHandler(DevToolsProtocolEventReceivedEventHandler&&) = delete;
	DevToolsProtocolEventReceivedEventHandler& operator=(const DevToolsProtocolEventReceivedEventHandler&) = delete;
	DevToolsProtocolEventReceivedEventHandler& operator=(DevToolsProtocolEventReceivedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2DevToolsProtocolEventReceivedEventHandler
	WRAP_INTERFACE(DevToolsProtocolEventReceivedEventHandler1, ICoreWebView2DevToolsProtocolEventReceivedEventHandler, DevToolsProtocolEventReceivedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2DevToolsProtocolEventReceivedEventArgs* args);
};
