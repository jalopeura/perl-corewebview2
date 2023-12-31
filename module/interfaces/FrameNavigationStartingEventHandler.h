/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FrameNavigationStartingEventHandler : public HandlerBase {
public:
	FrameNavigationStartingEventHandler(SV* perl_object);
	virtual ~FrameNavigationStartingEventHandler();

	FrameNavigationStartingEventHandler(const FrameNavigationStartingEventHandler&) = delete;
	FrameNavigationStartingEventHandler(FrameNavigationStartingEventHandler&&) = delete;
	FrameNavigationStartingEventHandler& operator=(const FrameNavigationStartingEventHandler&) = delete;
	FrameNavigationStartingEventHandler& operator=(FrameNavigationStartingEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FrameNavigationStartingEventHandler
	WRAP_INTERFACE(FrameNavigationStartingEventHandler1, ICoreWebView2FrameNavigationStartingEventHandler, FrameNavigationStartingEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, ICoreWebView2NavigationStartingEventArgs* args);
};
