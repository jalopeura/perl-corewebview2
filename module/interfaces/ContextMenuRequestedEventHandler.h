/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ContextMenuRequestedEventHandler : public HandlerBase {
public:
	ContextMenuRequestedEventHandler(SV* perl_object);
	virtual ~ContextMenuRequestedEventHandler();

	ContextMenuRequestedEventHandler(const ContextMenuRequestedEventHandler&) = delete;
	ContextMenuRequestedEventHandler(ContextMenuRequestedEventHandler&&) = delete;
	ContextMenuRequestedEventHandler& operator=(const ContextMenuRequestedEventHandler&) = delete;
	ContextMenuRequestedEventHandler& operator=(ContextMenuRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ContextMenuRequestedEventHandler
	WRAP_INTERFACE(ContextMenuRequestedEventHandler1, ICoreWebView2ContextMenuRequestedEventHandler, ContextMenuRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2ContextMenuRequestedEventArgs* args);
};
