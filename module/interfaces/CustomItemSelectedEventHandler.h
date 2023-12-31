/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CustomItemSelectedEventHandler : public HandlerBase {
public:
	CustomItemSelectedEventHandler(SV* perl_object);
	virtual ~CustomItemSelectedEventHandler();

	CustomItemSelectedEventHandler(const CustomItemSelectedEventHandler&) = delete;
	CustomItemSelectedEventHandler(CustomItemSelectedEventHandler&&) = delete;
	CustomItemSelectedEventHandler& operator=(const CustomItemSelectedEventHandler&) = delete;
	CustomItemSelectedEventHandler& operator=(CustomItemSelectedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CustomItemSelectedEventHandler
	WRAP_INTERFACE(CustomItemSelectedEventHandler1, ICoreWebView2CustomItemSelectedEventHandler, CustomItemSelectedEventHandler)
	HRESULT Invoke(ICoreWebView2ContextMenuItem* sender, IUnknown* args);
};
