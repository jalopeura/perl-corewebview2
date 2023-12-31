/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class GetNonDefaultPermissionSettingsCompletedHandler : public HandlerBase {
public:
	GetNonDefaultPermissionSettingsCompletedHandler(SV* perl_object);
	virtual ~GetNonDefaultPermissionSettingsCompletedHandler();

	GetNonDefaultPermissionSettingsCompletedHandler(const GetNonDefaultPermissionSettingsCompletedHandler&) = delete;
	GetNonDefaultPermissionSettingsCompletedHandler(GetNonDefaultPermissionSettingsCompletedHandler&&) = delete;
	GetNonDefaultPermissionSettingsCompletedHandler& operator=(const GetNonDefaultPermissionSettingsCompletedHandler&) = delete;
	GetNonDefaultPermissionSettingsCompletedHandler& operator=(GetNonDefaultPermissionSettingsCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler
	WRAP_INTERFACE(GetNonDefaultPermissionSettingsCompletedHandler1, ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler, GetNonDefaultPermissionSettingsCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2PermissionSettingCollectionView* collectionView);
};
