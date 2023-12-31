/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class StateChangedEventHandler : public HandlerBase {
public:
	StateChangedEventHandler(SV* perl_object);
	virtual ~StateChangedEventHandler();

	StateChangedEventHandler(const StateChangedEventHandler&) = delete;
	StateChangedEventHandler(StateChangedEventHandler&&) = delete;
	StateChangedEventHandler& operator=(const StateChangedEventHandler&) = delete;
	StateChangedEventHandler& operator=(StateChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2StateChangedEventHandler
	WRAP_INTERFACE(StateChangedEventHandler1, ICoreWebView2StateChangedEventHandler, StateChangedEventHandler)
	HRESULT Invoke(ICoreWebView2DownloadOperation* sender, IUnknown* args);
};
