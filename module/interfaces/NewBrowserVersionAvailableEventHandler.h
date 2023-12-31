/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class NewBrowserVersionAvailableEventHandler : public HandlerBase {
public:
	NewBrowserVersionAvailableEventHandler(SV* perl_object);
	virtual ~NewBrowserVersionAvailableEventHandler();

	NewBrowserVersionAvailableEventHandler(const NewBrowserVersionAvailableEventHandler&) = delete;
	NewBrowserVersionAvailableEventHandler(NewBrowserVersionAvailableEventHandler&&) = delete;
	NewBrowserVersionAvailableEventHandler& operator=(const NewBrowserVersionAvailableEventHandler&) = delete;
	NewBrowserVersionAvailableEventHandler& operator=(NewBrowserVersionAvailableEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2NewBrowserVersionAvailableEventHandler
	WRAP_INTERFACE(NewBrowserVersionAvailableEventHandler1, ICoreWebView2NewBrowserVersionAvailableEventHandler, NewBrowserVersionAvailableEventHandler)
	HRESULT Invoke(ICoreWebView2Environment* sender, IUnknown* args);
};
