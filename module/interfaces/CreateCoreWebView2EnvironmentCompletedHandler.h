/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CreateCoreWebView2EnvironmentCompletedHandler : public HandlerBase {
public:
	CreateCoreWebView2EnvironmentCompletedHandler(SV* perl_object);
	virtual ~CreateCoreWebView2EnvironmentCompletedHandler();

	CreateCoreWebView2EnvironmentCompletedHandler(const CreateCoreWebView2EnvironmentCompletedHandler&) = delete;
	CreateCoreWebView2EnvironmentCompletedHandler(CreateCoreWebView2EnvironmentCompletedHandler&&) = delete;
	CreateCoreWebView2EnvironmentCompletedHandler& operator=(const CreateCoreWebView2EnvironmentCompletedHandler&) = delete;
	CreateCoreWebView2EnvironmentCompletedHandler& operator=(CreateCoreWebView2EnvironmentCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler
	WRAP_INTERFACE(CreateCoreWebView2EnvironmentCompletedHandler1, ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler, CreateCoreWebView2EnvironmentCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2Environment* createdEnvironment);
};
