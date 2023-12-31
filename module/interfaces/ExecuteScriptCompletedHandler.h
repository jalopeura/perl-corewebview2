/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ExecuteScriptCompletedHandler : public HandlerBase {
public:
	ExecuteScriptCompletedHandler(SV* perl_object);
	virtual ~ExecuteScriptCompletedHandler();

	ExecuteScriptCompletedHandler(const ExecuteScriptCompletedHandler&) = delete;
	ExecuteScriptCompletedHandler(ExecuteScriptCompletedHandler&&) = delete;
	ExecuteScriptCompletedHandler& operator=(const ExecuteScriptCompletedHandler&) = delete;
	ExecuteScriptCompletedHandler& operator=(ExecuteScriptCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ExecuteScriptCompletedHandler
	WRAP_INTERFACE(ExecuteScriptCompletedHandler1, ICoreWebView2ExecuteScriptCompletedHandler, ExecuteScriptCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, LPCWSTR resultObjectAsJson);
};
