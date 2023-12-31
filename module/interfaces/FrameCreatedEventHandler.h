/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameCreatedEventHandler : public HandlerBase {
public:
	FrameCreatedEventHandler(SV* perl_object);
	virtual ~FrameCreatedEventHandler();

	FrameCreatedEventHandler(const FrameCreatedEventHandler&) = delete;
	FrameCreatedEventHandler(FrameCreatedEventHandler&&) = delete;
	FrameCreatedEventHandler& operator=(const FrameCreatedEventHandler&) = delete;
	FrameCreatedEventHandler& operator=(FrameCreatedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameCreatedEventHandler
	WRAP_INTERFACE(FrameCreatedEventHandler1, ICoreWebView2FrameCreatedEventHandler, FrameCreatedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2FrameCreatedEventArgs* args);
};
