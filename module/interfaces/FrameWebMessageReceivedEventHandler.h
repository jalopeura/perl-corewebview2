/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameWebMessageReceivedEventHandler : public HandlerBase {
public:
	FrameWebMessageReceivedEventHandler(SV* perl_object);
	virtual ~FrameWebMessageReceivedEventHandler();

	FrameWebMessageReceivedEventHandler(const FrameWebMessageReceivedEventHandler&) = delete;
	FrameWebMessageReceivedEventHandler(FrameWebMessageReceivedEventHandler&&) = delete;
	FrameWebMessageReceivedEventHandler& operator=(const FrameWebMessageReceivedEventHandler&) = delete;
	FrameWebMessageReceivedEventHandler& operator=(FrameWebMessageReceivedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameWebMessageReceivedEventHandler
	WRAP_INTERFACE(FrameWebMessageReceivedEventHandler1, ICoreWebView2FrameWebMessageReceivedEventHandler, FrameWebMessageReceivedEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, ICoreWebView2WebMessageReceivedEventArgs* args);
};
