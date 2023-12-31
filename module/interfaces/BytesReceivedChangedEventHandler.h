/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class BytesReceivedChangedEventHandler : public HandlerBase {
public:
	BytesReceivedChangedEventHandler(SV* perl_object);
	virtual ~BytesReceivedChangedEventHandler();

	BytesReceivedChangedEventHandler(const BytesReceivedChangedEventHandler&) = delete;
	BytesReceivedChangedEventHandler(BytesReceivedChangedEventHandler&&) = delete;
	BytesReceivedChangedEventHandler& operator=(const BytesReceivedChangedEventHandler&) = delete;
	BytesReceivedChangedEventHandler& operator=(BytesReceivedChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2BytesReceivedChangedEventHandler
	WRAP_INTERFACE(BytesReceivedChangedEventHandler1, ICoreWebView2BytesReceivedChangedEventHandler, BytesReceivedChangedEventHandler)
	HRESULT Invoke(ICoreWebView2DownloadOperation* sender, IUnknown* args);
};
