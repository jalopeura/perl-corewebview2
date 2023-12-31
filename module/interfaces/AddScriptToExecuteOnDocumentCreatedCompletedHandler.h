/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class AddScriptToExecuteOnDocumentCreatedCompletedHandler : public HandlerBase {
public:
	AddScriptToExecuteOnDocumentCreatedCompletedHandler(SV* perl_object);
	virtual ~AddScriptToExecuteOnDocumentCreatedCompletedHandler();

	AddScriptToExecuteOnDocumentCreatedCompletedHandler(const AddScriptToExecuteOnDocumentCreatedCompletedHandler&) = delete;
	AddScriptToExecuteOnDocumentCreatedCompletedHandler(AddScriptToExecuteOnDocumentCreatedCompletedHandler&&) = delete;
	AddScriptToExecuteOnDocumentCreatedCompletedHandler& operator=(const AddScriptToExecuteOnDocumentCreatedCompletedHandler&) = delete;
	AddScriptToExecuteOnDocumentCreatedCompletedHandler& operator=(AddScriptToExecuteOnDocumentCreatedCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler
	WRAP_INTERFACE(AddScriptToExecuteOnDocumentCreatedCompletedHandler1, ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler, AddScriptToExecuteOnDocumentCreatedCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, LPCWSTR id);
};
