/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameContentLoadingEventHandler : public HandlerBase {
public:
	FrameContentLoadingEventHandler(SV* perl_object);
	virtual ~FrameContentLoadingEventHandler();

	FrameContentLoadingEventHandler(const FrameContentLoadingEventHandler&) = delete;
	FrameContentLoadingEventHandler(FrameContentLoadingEventHandler&&) = delete;
	FrameContentLoadingEventHandler& operator=(const FrameContentLoadingEventHandler&) = delete;
	FrameContentLoadingEventHandler& operator=(FrameContentLoadingEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameContentLoadingEventHandler
	WRAP_INTERFACE(FrameContentLoadingEventHandler1, ICoreWebView2FrameContentLoadingEventHandler, FrameContentLoadingEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, ICoreWebView2ContentLoadingEventArgs* args);
};
