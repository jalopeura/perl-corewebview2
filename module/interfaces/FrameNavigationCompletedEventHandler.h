/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameNavigationCompletedEventHandler : public HandlerBase {
public:
	FrameNavigationCompletedEventHandler(SV* perl_object);
	virtual ~FrameNavigationCompletedEventHandler();

	FrameNavigationCompletedEventHandler(const FrameNavigationCompletedEventHandler&) = delete;
	FrameNavigationCompletedEventHandler(FrameNavigationCompletedEventHandler&&) = delete;
	FrameNavigationCompletedEventHandler& operator=(const FrameNavigationCompletedEventHandler&) = delete;
	FrameNavigationCompletedEventHandler& operator=(FrameNavigationCompletedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameNavigationCompletedEventHandler
	WRAP_INTERFACE(FrameNavigationCompletedEventHandler1, ICoreWebView2FrameNavigationCompletedEventHandler, FrameNavigationCompletedEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, ICoreWebView2NavigationCompletedEventArgs* args);
};
