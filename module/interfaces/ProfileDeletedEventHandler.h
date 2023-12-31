/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ProfileDeletedEventHandler : public HandlerBase {
public:
	ProfileDeletedEventHandler(SV* perl_object);
	virtual ~ProfileDeletedEventHandler();

	ProfileDeletedEventHandler(const ProfileDeletedEventHandler&) = delete;
	ProfileDeletedEventHandler(ProfileDeletedEventHandler&&) = delete;
	ProfileDeletedEventHandler& operator=(const ProfileDeletedEventHandler&) = delete;
	ProfileDeletedEventHandler& operator=(ProfileDeletedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ProfileDeletedEventHandler
	WRAP_INTERFACE(ProfileDeletedEventHandler1, ICoreWebView2ProfileDeletedEventHandler, ProfileDeletedEventHandler)
	HRESULT Invoke(ICoreWebView2Profile* sender, IUnknown* args);
};
