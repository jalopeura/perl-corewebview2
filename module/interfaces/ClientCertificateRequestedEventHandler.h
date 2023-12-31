/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ClientCertificateRequestedEventHandler : public HandlerBase {
public:
	ClientCertificateRequestedEventHandler(SV* perl_object);
	virtual ~ClientCertificateRequestedEventHandler();

	ClientCertificateRequestedEventHandler(const ClientCertificateRequestedEventHandler&) = delete;
	ClientCertificateRequestedEventHandler(ClientCertificateRequestedEventHandler&&) = delete;
	ClientCertificateRequestedEventHandler& operator=(const ClientCertificateRequestedEventHandler&) = delete;
	ClientCertificateRequestedEventHandler& operator=(ClientCertificateRequestedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ClientCertificateRequestedEventHandler
	WRAP_INTERFACE(ClientCertificateRequestedEventHandler1, ICoreWebView2ClientCertificateRequestedEventHandler, ClientCertificateRequestedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2ClientCertificateRequestedEventArgs* args);
};
