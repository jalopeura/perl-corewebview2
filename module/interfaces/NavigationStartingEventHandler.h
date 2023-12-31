/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class NavigationStartingEventHandler : public HandlerBase {
public:
	NavigationStartingEventHandler(SV* perl_object);
	virtual ~NavigationStartingEventHandler();

	NavigationStartingEventHandler(const NavigationStartingEventHandler&) = delete;
	NavigationStartingEventHandler(NavigationStartingEventHandler&&) = delete;
	NavigationStartingEventHandler& operator=(const NavigationStartingEventHandler&) = delete;
	NavigationStartingEventHandler& operator=(NavigationStartingEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2NavigationStartingEventHandler
	WRAP_INTERFACE(NavigationStartingEventHandler1, ICoreWebView2NavigationStartingEventHandler, NavigationStartingEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2NavigationStartingEventArgs* args);
};
