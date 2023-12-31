/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class NewWindowRequestedEventHandler : public HandlerBase {
public:
	NewWindowRequestedEventHandler(SV* perl_object);
	virtual ~NewWindowRequestedEventHandler();

	NewWindowRequestedEventHandler(const NewWindowRequestedEventHandler&) = delete;
	NewWindowRequestedEventHandler(NewWindowRequestedEventHandler&&) = delete;
	NewWindowRequestedEventHandler& operator=(const NewWindowRequestedEventHandler&) = delete;
	NewWindowRequestedEventHandler& operator=(NewWindowRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2NewWindowRequestedEventHandler
	WRAP_INTERFACE(NewWindowRequestedEventHandler1, ICoreWebView2NewWindowRequestedEventHandler, NewWindowRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2NewWindowRequestedEventArgs* args);
};
