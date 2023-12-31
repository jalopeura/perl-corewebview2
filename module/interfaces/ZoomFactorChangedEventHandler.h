/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ZoomFactorChangedEventHandler : public HandlerBase {
public:
	ZoomFactorChangedEventHandler(SV* perl_object);
	virtual ~ZoomFactorChangedEventHandler();

	ZoomFactorChangedEventHandler(const ZoomFactorChangedEventHandler&) = delete;
	ZoomFactorChangedEventHandler(ZoomFactorChangedEventHandler&&) = delete;
	ZoomFactorChangedEventHandler& operator=(const ZoomFactorChangedEventHandler&) = delete;
	ZoomFactorChangedEventHandler& operator=(ZoomFactorChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ZoomFactorChangedEventHandler
	WRAP_INTERFACE(ZoomFactorChangedEventHandler1, ICoreWebView2ZoomFactorChangedEventHandler, ZoomFactorChangedEventHandler)
	HRESULT Invoke(ICoreWebView2Controller* sender, IUnknown* args);
};
