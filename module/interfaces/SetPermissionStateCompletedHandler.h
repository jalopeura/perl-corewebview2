/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class SetPermissionStateCompletedHandler : public HandlerBase {
public:
	SetPermissionStateCompletedHandler(SV* perl_object);
	virtual ~SetPermissionStateCompletedHandler();

	SetPermissionStateCompletedHandler(const SetPermissionStateCompletedHandler&) = delete;
	SetPermissionStateCompletedHandler(SetPermissionStateCompletedHandler&&) = delete;
	SetPermissionStateCompletedHandler& operator=(const SetPermissionStateCompletedHandler&) = delete;
	SetPermissionStateCompletedHandler& operator=(SetPermissionStateCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2SetPermissionStateCompletedHandler
	WRAP_INTERFACE(SetPermissionStateCompletedHandler1, ICoreWebView2SetPermissionStateCompletedHandler, SetPermissionStateCompletedHandler)
	HRESULT Invoke(HRESULT errorCode);
};
