/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ProcessFailedEventHandler : public HandlerBase {
public:
	ProcessFailedEventHandler(SV* perl_object);
	virtual ~ProcessFailedEventHandler();

	ProcessFailedEventHandler(const ProcessFailedEventHandler&) = delete;
	ProcessFailedEventHandler(ProcessFailedEventHandler&&) = delete;
	ProcessFailedEventHandler& operator=(const ProcessFailedEventHandler&) = delete;
	ProcessFailedEventHandler& operator=(ProcessFailedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ProcessFailedEventHandler
	WRAP_INTERFACE(ProcessFailedEventHandler1, ICoreWebView2ProcessFailedEventHandler, ProcessFailedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2ProcessFailedEventArgs* args);
};
