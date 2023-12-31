/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class PrintToPdfStreamCompletedHandler : public HandlerBase {
public:
	PrintToPdfStreamCompletedHandler(SV* perl_object);
	virtual ~PrintToPdfStreamCompletedHandler();

	PrintToPdfStreamCompletedHandler(const PrintToPdfStreamCompletedHandler&) = delete;
	PrintToPdfStreamCompletedHandler(PrintToPdfStreamCompletedHandler&&) = delete;
	PrintToPdfStreamCompletedHandler& operator=(const PrintToPdfStreamCompletedHandler&) = delete;
	PrintToPdfStreamCompletedHandler& operator=(PrintToPdfStreamCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2PrintToPdfStreamCompletedHandler
	WRAP_INTERFACE(PrintToPdfStreamCompletedHandler1, ICoreWebView2PrintToPdfStreamCompletedHandler, PrintToPdfStreamCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, IStream* pdfStream);
};
