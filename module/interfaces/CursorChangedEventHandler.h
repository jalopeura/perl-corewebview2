/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CursorChangedEventHandler : public HandlerBase {
public:
	CursorChangedEventHandler(SV* perl_object);
	virtual ~CursorChangedEventHandler();

	CursorChangedEventHandler(const CursorChangedEventHandler&) = delete;
	CursorChangedEventHandler(CursorChangedEventHandler&&) = delete;
	CursorChangedEventHandler& operator=(const CursorChangedEventHandler&) = delete;
	CursorChangedEventHandler& operator=(CursorChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CursorChangedEventHandler
	WRAP_INTERFACE(CursorChangedEventHandler1, ICoreWebView2CursorChangedEventHandler, CursorChangedEventHandler)
	HRESULT Invoke(ICoreWebView2CompositionController* sender, IUnknown* args);
};
