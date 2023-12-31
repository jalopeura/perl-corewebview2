/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class GetProcessExtendedInfosCompletedHandler : public HandlerBase {
public:
	GetProcessExtendedInfosCompletedHandler(SV* perl_object);
	virtual ~GetProcessExtendedInfosCompletedHandler();

	GetProcessExtendedInfosCompletedHandler(const GetProcessExtendedInfosCompletedHandler&) = delete;
	GetProcessExtendedInfosCompletedHandler(GetProcessExtendedInfosCompletedHandler&&) = delete;
	GetProcessExtendedInfosCompletedHandler& operator=(const GetProcessExtendedInfosCompletedHandler&) = delete;
	GetProcessExtendedInfosCompletedHandler& operator=(GetProcessExtendedInfosCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2GetProcessExtendedInfosCompletedHandler
	WRAP_INTERFACE(GetProcessExtendedInfosCompletedHandler1, ICoreWebView2GetProcessExtendedInfosCompletedHandler, GetProcessExtendedInfosCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, ICoreWebView2ProcessExtendedInfoCollection* value);
};
