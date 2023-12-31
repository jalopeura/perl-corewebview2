/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class PermissionRequestedEventHandler : public HandlerBase {
public:
	PermissionRequestedEventHandler(SV* perl_object);
	virtual ~PermissionRequestedEventHandler();

	PermissionRequestedEventHandler(const PermissionRequestedEventHandler&) = delete;
	PermissionRequestedEventHandler(PermissionRequestedEventHandler&&) = delete;
	PermissionRequestedEventHandler& operator=(const PermissionRequestedEventHandler&) = delete;
	PermissionRequestedEventHandler& operator=(PermissionRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2PermissionRequestedEventHandler
	WRAP_INTERFACE(PermissionRequestedEventHandler1, ICoreWebView2PermissionRequestedEventHandler, PermissionRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2PermissionRequestedEventArgs* args);
};
