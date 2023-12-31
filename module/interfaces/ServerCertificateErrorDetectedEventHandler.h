/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ServerCertificateErrorDetectedEventHandler : public HandlerBase {
public:
	ServerCertificateErrorDetectedEventHandler(SV* perl_object);
	virtual ~ServerCertificateErrorDetectedEventHandler();

	ServerCertificateErrorDetectedEventHandler(const ServerCertificateErrorDetectedEventHandler&) = delete;
	ServerCertificateErrorDetectedEventHandler(ServerCertificateErrorDetectedEventHandler&&) = delete;
	ServerCertificateErrorDetectedEventHandler& operator=(const ServerCertificateErrorDetectedEventHandler&) = delete;
	ServerCertificateErrorDetectedEventHandler& operator=(ServerCertificateErrorDetectedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ServerCertificateErrorDetectedEventHandler
	WRAP_INTERFACE(ServerCertificateErrorDetectedEventHandler1, ICoreWebView2ServerCertificateErrorDetectedEventHandler, ServerCertificateErrorDetectedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2ServerCertificateErrorDetectedEventArgs* args);
};
