/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class PrintCompletedHandler : public HandlerBase {
public:
	PrintCompletedHandler(SV* perl_object);
	virtual ~PrintCompletedHandler();

	PrintCompletedHandler(const PrintCompletedHandler&) = delete;
	PrintCompletedHandler(PrintCompletedHandler&&) = delete;
	PrintCompletedHandler& operator=(const PrintCompletedHandler&) = delete;
	PrintCompletedHandler& operator=(PrintCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2PrintCompletedHandler
	WRAP_INTERFACE(PrintCompletedHandler1, ICoreWebView2PrintCompletedHandler, PrintCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, COREWEBVIEW2_PRINT_STATUS printStatus);
};
