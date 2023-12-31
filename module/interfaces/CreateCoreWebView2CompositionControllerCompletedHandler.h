/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CreateCoreWebView2CompositionControllerCompletedHandler : public HandlerBase {
public:
	CreateCoreWebView2CompositionControllerCompletedHandler(SV* perl_object);
	virtual ~CreateCoreWebView2CompositionControllerCompletedHandler();

	CreateCoreWebView2CompositionControllerCompletedHandler(const CreateCoreWebView2CompositionControllerCompletedHandler&) = delete;
	CreateCoreWebView2CompositionControllerCompletedHandler(CreateCoreWebView2CompositionControllerCompletedHandler&&) = delete;
	CreateCoreWebView2CompositionControllerCompletedHandler& operator=(const CreateCoreWebView2CompositionControllerCompletedHandler&) = delete;
	CreateCoreWebView2CompositionControllerCompletedHandler& operator=(CreateCoreWebView2CompositionControllerCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler
	WRAP_INTERFACE(CreateCoreWebView2CompositionControllerCompletedHandler1, ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler, CreateCoreWebView2CompositionControllerCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2CompositionController* webView);
};
