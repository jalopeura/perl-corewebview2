/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameDOMContentLoadedEventHandler : public HandlerBase {
public:
	FrameDOMContentLoadedEventHandler(SV* perl_object);
	virtual ~FrameDOMContentLoadedEventHandler();

	FrameDOMContentLoadedEventHandler(const FrameDOMContentLoadedEventHandler&) = delete;
	FrameDOMContentLoadedEventHandler(FrameDOMContentLoadedEventHandler&&) = delete;
	FrameDOMContentLoadedEventHandler& operator=(const FrameDOMContentLoadedEventHandler&) = delete;
	FrameDOMContentLoadedEventHandler& operator=(FrameDOMContentLoadedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameDOMContentLoadedEventHandler
	WRAP_INTERFACE(FrameDOMContentLoadedEventHandler1, ICoreWebView2FrameDOMContentLoadedEventHandler, FrameDOMContentLoadedEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, ICoreWebView2DOMContentLoadedEventArgs* args);
};
