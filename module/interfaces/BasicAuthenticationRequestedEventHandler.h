/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class BasicAuthenticationRequestedEventHandler : public HandlerBase {
public:
	BasicAuthenticationRequestedEventHandler(SV* perl_object);
	virtual ~BasicAuthenticationRequestedEventHandler();

	BasicAuthenticationRequestedEventHandler(const BasicAuthenticationRequestedEventHandler&) = delete;
	BasicAuthenticationRequestedEventHandler(BasicAuthenticationRequestedEventHandler&&) = delete;
	BasicAuthenticationRequestedEventHandler& operator=(const BasicAuthenticationRequestedEventHandler&) = delete;
	BasicAuthenticationRequestedEventHandler& operator=(BasicAuthenticationRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2BasicAuthenticationRequestedEventHandler
	WRAP_INTERFACE(BasicAuthenticationRequestedEventHandler1, ICoreWebView2BasicAuthenticationRequestedEventHandler, BasicAuthenticationRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2BasicAuthenticationRequestedEventArgs* args);
};
