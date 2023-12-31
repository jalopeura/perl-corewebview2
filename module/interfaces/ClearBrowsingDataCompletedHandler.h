/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ClearBrowsingDataCompletedHandler : public HandlerBase {
public:
	ClearBrowsingDataCompletedHandler(SV* perl_object);
	virtual ~ClearBrowsingDataCompletedHandler();

	ClearBrowsingDataCompletedHandler(const ClearBrowsingDataCompletedHandler&) = delete;
	ClearBrowsingDataCompletedHandler(ClearBrowsingDataCompletedHandler&&) = delete;
	ClearBrowsingDataCompletedHandler& operator=(const ClearBrowsingDataCompletedHandler&) = delete;
	ClearBrowsingDataCompletedHandler& operator=(ClearBrowsingDataCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ClearBrowsingDataCompletedHandler
	WRAP_INTERFACE(ClearBrowsingDataCompletedHandler1, ICoreWebView2ClearBrowsingDataCompletedHandler, ClearBrowsingDataCompletedHandler)
	HRESULT Invoke(HRESULT errorCode);
};
