/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class PrintToPdfCompletedHandler : public HandlerBase {
public:
	PrintToPdfCompletedHandler(SV* perl_object);
	virtual ~PrintToPdfCompletedHandler();

	PrintToPdfCompletedHandler(const PrintToPdfCompletedHandler&) = delete;
	PrintToPdfCompletedHandler(PrintToPdfCompletedHandler&&) = delete;
	PrintToPdfCompletedHandler& operator=(const PrintToPdfCompletedHandler&) = delete;
	PrintToPdfCompletedHandler& operator=(PrintToPdfCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2PrintToPdfCompletedHandler
	WRAP_INTERFACE(PrintToPdfCompletedHandler1, ICoreWebView2PrintToPdfCompletedHandler, PrintToPdfCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, BOOL isSuccessful);
};
