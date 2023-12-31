/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class LaunchingExternalUriSchemeEventHandler : public HandlerBase {
public:
	LaunchingExternalUriSchemeEventHandler(SV* perl_object);
	virtual ~LaunchingExternalUriSchemeEventHandler();

	LaunchingExternalUriSchemeEventHandler(const LaunchingExternalUriSchemeEventHandler&) = delete;
	LaunchingExternalUriSchemeEventHandler(LaunchingExternalUriSchemeEventHandler&&) = delete;
	LaunchingExternalUriSchemeEventHandler& operator=(const LaunchingExternalUriSchemeEventHandler&) = delete;
	LaunchingExternalUriSchemeEventHandler& operator=(LaunchingExternalUriSchemeEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2LaunchingExternalUriSchemeEventHandler
	WRAP_INTERFACE(LaunchingExternalUriSchemeEventHandler1, ICoreWebView2LaunchingExternalUriSchemeEventHandler, LaunchingExternalUriSchemeEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2LaunchingExternalUriSchemeEventArgs* args);
};
