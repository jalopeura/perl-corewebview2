/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class AcceleratorKeyPressedEventHandler : public HandlerBase {
public:
	AcceleratorKeyPressedEventHandler(SV* perl_object);
	virtual ~AcceleratorKeyPressedEventHandler();

	AcceleratorKeyPressedEventHandler(const AcceleratorKeyPressedEventHandler&) = delete;
	AcceleratorKeyPressedEventHandler(AcceleratorKeyPressedEventHandler&&) = delete;
	AcceleratorKeyPressedEventHandler& operator=(const AcceleratorKeyPressedEventHandler&) = delete;
	AcceleratorKeyPressedEventHandler& operator=(AcceleratorKeyPressedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2AcceleratorKeyPressedEventHandler
	WRAP_INTERFACE(AcceleratorKeyPressedEventHandler1, ICoreWebView2AcceleratorKeyPressedEventHandler, AcceleratorKeyPressedEventHandler)
	HRESULT Invoke(ICoreWebView2Controller* sender, ICoreWebView2AcceleratorKeyPressedEventArgs* args);
};
