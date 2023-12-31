/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CreateCoreWebView2ControllerCompletedHandler : public HandlerBase {
public:
	CreateCoreWebView2ControllerCompletedHandler(SV* perl_object);
	virtual ~CreateCoreWebView2ControllerCompletedHandler();

	CreateCoreWebView2ControllerCompletedHandler(const CreateCoreWebView2ControllerCompletedHandler&) = delete;
	CreateCoreWebView2ControllerCompletedHandler(CreateCoreWebView2ControllerCompletedHandler&&) = delete;
	CreateCoreWebView2ControllerCompletedHandler& operator=(const CreateCoreWebView2ControllerCompletedHandler&) = delete;
	CreateCoreWebView2ControllerCompletedHandler& operator=(CreateCoreWebView2ControllerCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CreateCoreWebView2ControllerCompletedHandler
	WRAP_INTERFACE(CreateCoreWebView2ControllerCompletedHandler1, ICoreWebView2CreateCoreWebView2ControllerCompletedHandler, CreateCoreWebView2ControllerCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2Controller* createdController);
};
