/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FramePermissionRequestedEventHandler : public HandlerBase {
public:
	FramePermissionRequestedEventHandler(SV* perl_object);
	virtual ~FramePermissionRequestedEventHandler();

	FramePermissionRequestedEventHandler(const FramePermissionRequestedEventHandler&) = delete;
	FramePermissionRequestedEventHandler(FramePermissionRequestedEventHandler&&) = delete;
	FramePermissionRequestedEventHandler& operator=(const FramePermissionRequestedEventHandler&) = delete;
	FramePermissionRequestedEventHandler& operator=(FramePermissionRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FramePermissionRequestedEventHandler
	WRAP_INTERFACE(FramePermissionRequestedEventHandler1, ICoreWebView2FramePermissionRequestedEventHandler, FramePermissionRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2Frame* sender, ICoreWebView2PermissionRequestedEventArgs2* args);
};
