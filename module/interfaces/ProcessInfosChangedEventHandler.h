/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ProcessInfosChangedEventHandler : public HandlerBase {
public:
	ProcessInfosChangedEventHandler(SV* perl_object);
	virtual ~ProcessInfosChangedEventHandler();

	ProcessInfosChangedEventHandler(const ProcessInfosChangedEventHandler&) = delete;
	ProcessInfosChangedEventHandler(ProcessInfosChangedEventHandler&&) = delete;
	ProcessInfosChangedEventHandler& operator=(const ProcessInfosChangedEventHandler&) = delete;
	ProcessInfosChangedEventHandler& operator=(ProcessInfosChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ProcessInfosChangedEventHandler
	WRAP_INTERFACE(ProcessInfosChangedEventHandler1, ICoreWebView2ProcessInfosChangedEventHandler, ProcessInfosChangedEventHandler)
	HRESULT Invoke(ICoreWebView2Environment* sender, IUnknown* args);
};
