/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class WindowCloseRequestedEventHandler : public HandlerBase {
public:
	WindowCloseRequestedEventHandler(SV* perl_object);
	virtual ~WindowCloseRequestedEventHandler();

	WindowCloseRequestedEventHandler(const WindowCloseRequestedEventHandler&) = delete;
	WindowCloseRequestedEventHandler(WindowCloseRequestedEventHandler&&) = delete;
	WindowCloseRequestedEventHandler& operator=(const WindowCloseRequestedEventHandler&) = delete;
	WindowCloseRequestedEventHandler& operator=(WindowCloseRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2WindowCloseRequestedEventHandler
	WRAP_INTERFACE(WindowCloseRequestedEventHandler1, ICoreWebView2WindowCloseRequestedEventHandler, WindowCloseRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
