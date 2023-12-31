/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class StatusBarTextChangedEventHandler : public HandlerBase {
public:
	StatusBarTextChangedEventHandler(SV* perl_object);
	virtual ~StatusBarTextChangedEventHandler();

	StatusBarTextChangedEventHandler(const StatusBarTextChangedEventHandler&) = delete;
	StatusBarTextChangedEventHandler(StatusBarTextChangedEventHandler&&) = delete;
	StatusBarTextChangedEventHandler& operator=(const StatusBarTextChangedEventHandler&) = delete;
	StatusBarTextChangedEventHandler& operator=(StatusBarTextChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2StatusBarTextChangedEventHandler
	WRAP_INTERFACE(StatusBarTextChangedEventHandler1, ICoreWebView2StatusBarTextChangedEventHandler, StatusBarTextChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
