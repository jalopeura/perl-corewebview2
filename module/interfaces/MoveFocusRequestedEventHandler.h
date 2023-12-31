/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class MoveFocusRequestedEventHandler : public HandlerBase {
public:
	MoveFocusRequestedEventHandler(SV* perl_object);
	virtual ~MoveFocusRequestedEventHandler();

	MoveFocusRequestedEventHandler(const MoveFocusRequestedEventHandler&) = delete;
	MoveFocusRequestedEventHandler(MoveFocusRequestedEventHandler&&) = delete;
	MoveFocusRequestedEventHandler& operator=(const MoveFocusRequestedEventHandler&) = delete;
	MoveFocusRequestedEventHandler& operator=(MoveFocusRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2MoveFocusRequestedEventHandler
	WRAP_INTERFACE(MoveFocusRequestedEventHandler1, ICoreWebView2MoveFocusRequestedEventHandler, MoveFocusRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2Controller* sender, ICoreWebView2MoveFocusRequestedEventArgs* args);
};
