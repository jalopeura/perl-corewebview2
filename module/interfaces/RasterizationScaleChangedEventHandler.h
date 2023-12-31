/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class RasterizationScaleChangedEventHandler : public HandlerBase {
public:
	RasterizationScaleChangedEventHandler(SV* perl_object);
	virtual ~RasterizationScaleChangedEventHandler();

	RasterizationScaleChangedEventHandler(const RasterizationScaleChangedEventHandler&) = delete;
	RasterizationScaleChangedEventHandler(RasterizationScaleChangedEventHandler&&) = delete;
	RasterizationScaleChangedEventHandler& operator=(const RasterizationScaleChangedEventHandler&) = delete;
	RasterizationScaleChangedEventHandler& operator=(RasterizationScaleChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2RasterizationScaleChangedEventHandler
	WRAP_INTERFACE(RasterizationScaleChangedEventHandler1, ICoreWebView2RasterizationScaleChangedEventHandler, RasterizationScaleChangedEventHandler)
	HRESULT Invoke(ICoreWebView2Controller* sender, IUnknown* args);
};
