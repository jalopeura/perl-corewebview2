/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class IsMutedChangedEventHandler : public HandlerBase {
public:
	IsMutedChangedEventHandler(SV* perl_object);
	virtual ~IsMutedChangedEventHandler();

	IsMutedChangedEventHandler(const IsMutedChangedEventHandler&) = delete;
	IsMutedChangedEventHandler(IsMutedChangedEventHandler&&) = delete;
	IsMutedChangedEventHandler& operator=(const IsMutedChangedEventHandler&) = delete;
	IsMutedChangedEventHandler& operator=(IsMutedChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2IsMutedChangedEventHandler
	WRAP_INTERFACE(IsMutedChangedEventHandler1, ICoreWebView2IsMutedChangedEventHandler, IsMutedChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
