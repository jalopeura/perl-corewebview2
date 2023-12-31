/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class SourceChangedEventHandler : public HandlerBase {
public:
	SourceChangedEventHandler(SV* perl_object);
	virtual ~SourceChangedEventHandler();

	SourceChangedEventHandler(const SourceChangedEventHandler&) = delete;
	SourceChangedEventHandler(SourceChangedEventHandler&&) = delete;
	SourceChangedEventHandler& operator=(const SourceChangedEventHandler&) = delete;
	SourceChangedEventHandler& operator=(SourceChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2SourceChangedEventHandler
	WRAP_INTERFACE(SourceChangedEventHandler1, ICoreWebView2SourceChangedEventHandler, SourceChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2SourceChangedEventArgs* args);
};
