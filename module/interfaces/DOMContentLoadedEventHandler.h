/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class DOMContentLoadedEventHandler : public HandlerBase {
public:
	DOMContentLoadedEventHandler(SV* perl_object);
	virtual ~DOMContentLoadedEventHandler();

	DOMContentLoadedEventHandler(const DOMContentLoadedEventHandler&) = delete;
	DOMContentLoadedEventHandler(DOMContentLoadedEventHandler&&) = delete;
	DOMContentLoadedEventHandler& operator=(const DOMContentLoadedEventHandler&) = delete;
	DOMContentLoadedEventHandler& operator=(DOMContentLoadedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2DOMContentLoadedEventHandler
	WRAP_INTERFACE(DOMContentLoadedEventHandler1, ICoreWebView2DOMContentLoadedEventHandler, DOMContentLoadedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2DOMContentLoadedEventArgs* args);
};
