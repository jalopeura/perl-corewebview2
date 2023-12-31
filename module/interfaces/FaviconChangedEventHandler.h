/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class FaviconChangedEventHandler : public HandlerBase {
public:
	FaviconChangedEventHandler(SV* perl_object);
	virtual ~FaviconChangedEventHandler();

	FaviconChangedEventHandler(const FaviconChangedEventHandler&) = delete;
	FaviconChangedEventHandler(FaviconChangedEventHandler&&) = delete;
	FaviconChangedEventHandler& operator=(const FaviconChangedEventHandler&) = delete;
	FaviconChangedEventHandler& operator=(FaviconChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2FaviconChangedEventHandler
	WRAP_INTERFACE(FaviconChangedEventHandler1, ICoreWebView2FaviconChangedEventHandler, FaviconChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
