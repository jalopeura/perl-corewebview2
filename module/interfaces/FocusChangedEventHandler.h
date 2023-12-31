/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FocusChangedEventHandler : public HandlerBase {
public:
	FocusChangedEventHandler(SV* perl_object);
	virtual ~FocusChangedEventHandler();

	FocusChangedEventHandler(const FocusChangedEventHandler&) = delete;
	FocusChangedEventHandler(FocusChangedEventHandler&&) = delete;
	FocusChangedEventHandler& operator=(const FocusChangedEventHandler&) = delete;
	FocusChangedEventHandler& operator=(FocusChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FocusChangedEventHandler
	WRAP_INTERFACE(FocusChangedEventHandler1, ICoreWebView2FocusChangedEventHandler, FocusChangedEventHandler)
	HRESULT Invoke(ICoreWebView2Controller* sender, IUnknown* args);
};
