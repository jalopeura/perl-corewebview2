/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CallDevToolsProtocolMethodCompletedHandler : public HandlerBase {
public:
	CallDevToolsProtocolMethodCompletedHandler(SV* perl_object);
	virtual ~CallDevToolsProtocolMethodCompletedHandler();

	CallDevToolsProtocolMethodCompletedHandler(const CallDevToolsProtocolMethodCompletedHandler&) = delete;
	CallDevToolsProtocolMethodCompletedHandler(CallDevToolsProtocolMethodCompletedHandler&&) = delete;
	CallDevToolsProtocolMethodCompletedHandler& operator=(const CallDevToolsProtocolMethodCompletedHandler&) = delete;
	CallDevToolsProtocolMethodCompletedHandler& operator=(CallDevToolsProtocolMethodCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CallDevToolsProtocolMethodCompletedHandler
	WRAP_INTERFACE(CallDevToolsProtocolMethodCompletedHandler1, ICoreWebView2CallDevToolsProtocolMethodCompletedHandler, CallDevToolsProtocolMethodCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, LPCWSTR returnObjectAsJson);
};
