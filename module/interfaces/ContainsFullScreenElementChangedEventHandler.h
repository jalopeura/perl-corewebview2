/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ContainsFullScreenElementChangedEventHandler : public HandlerBase {
public:
	ContainsFullScreenElementChangedEventHandler(SV* perl_object);
	virtual ~ContainsFullScreenElementChangedEventHandler();

	ContainsFullScreenElementChangedEventHandler(const ContainsFullScreenElementChangedEventHandler&) = delete;
	ContainsFullScreenElementChangedEventHandler(ContainsFullScreenElementChangedEventHandler&&) = delete;
	ContainsFullScreenElementChangedEventHandler& operator=(const ContainsFullScreenElementChangedEventHandler&) = delete;
	ContainsFullScreenElementChangedEventHandler& operator=(ContainsFullScreenElementChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ContainsFullScreenElementChangedEventHandler
	WRAP_INTERFACE(ContainsFullScreenElementChangedEventHandler1, ICoreWebView2ContainsFullScreenElementChangedEventHandler, ContainsFullScreenElementChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
