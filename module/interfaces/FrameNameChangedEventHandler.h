/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameNameChangedEventHandler : public HandlerBase {
public:
	FrameNameChangedEventHandler(SV* perl_object);
	virtual ~FrameNameChangedEventHandler();

	FrameNameChangedEventHandler(const FrameNameChangedEventHandler&) = delete;
	FrameNameChangedEventHandler(FrameNameChangedEventHandler&&) = delete;
	FrameNameChangedEventHandler& operator=(const FrameNameChangedEventHandler&) = delete;
	FrameNameChangedEventHandler& operator=(FrameNameChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameNameChangedEventHandler
	WRAP_INTERFACE(FrameNameChangedEventHandler1, ICoreWebView2FrameNameChangedEventHandler, FrameNameChangedEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, IUnknown* args);
};
