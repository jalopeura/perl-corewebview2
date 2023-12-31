/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameDestroyedEventHandler : public HandlerBase {
public:
	FrameDestroyedEventHandler(SV* perl_object);
	virtual ~FrameDestroyedEventHandler();

	FrameDestroyedEventHandler(const FrameDestroyedEventHandler&) = delete;
	FrameDestroyedEventHandler(FrameDestroyedEventHandler&&) = delete;
	FrameDestroyedEventHandler& operator=(const FrameDestroyedEventHandler&) = delete;
	FrameDestroyedEventHandler& operator=(FrameDestroyedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameDestroyedEventHandler
	WRAP_INTERFACE(FrameDestroyedEventHandler1, ICoreWebView2FrameDestroyedEventHandler, FrameDestroyedEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, IUnknown* args);
};
