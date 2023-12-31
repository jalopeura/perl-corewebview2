/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class NavigationCompletedEventHandler : public HandlerBase {
public:
	NavigationCompletedEventHandler(SV* perl_object);
	virtual ~NavigationCompletedEventHandler();

	NavigationCompletedEventHandler(const NavigationCompletedEventHandler&) = delete;
	NavigationCompletedEventHandler(NavigationCompletedEventHandler&&) = delete;
	NavigationCompletedEventHandler& operator=(const NavigationCompletedEventHandler&) = delete;
	NavigationCompletedEventHandler& operator=(NavigationCompletedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2NavigationCompletedEventHandler
	WRAP_INTERFACE(NavigationCompletedEventHandler1, ICoreWebView2NavigationCompletedEventHandler, NavigationCompletedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args);
};
