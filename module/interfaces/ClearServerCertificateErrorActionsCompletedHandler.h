/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ClearServerCertificateErrorActionsCompletedHandler : public HandlerBase {
public:
	ClearServerCertificateErrorActionsCompletedHandler(SV* perl_object);
	virtual ~ClearServerCertificateErrorActionsCompletedHandler();

	ClearServerCertificateErrorActionsCompletedHandler(const ClearServerCertificateErrorActionsCompletedHandler&) = delete;
	ClearServerCertificateErrorActionsCompletedHandler(ClearServerCertificateErrorActionsCompletedHandler&&) = delete;
	ClearServerCertificateErrorActionsCompletedHandler& operator=(const ClearServerCertificateErrorActionsCompletedHandler&) = delete;
	ClearServerCertificateErrorActionsCompletedHandler& operator=(ClearServerCertificateErrorActionsCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler
	WRAP_INTERFACE(ClearServerCertificateErrorActionsCompletedHandler1, ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler, ClearServerCertificateErrorActionsCompletedHandler)
	HRESULT Invoke(HRESULT errorCode);
};
