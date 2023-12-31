/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class DownloadStartingEventHandler : public HandlerBase {
public:
	DownloadStartingEventHandler(SV* perl_object);
	virtual ~DownloadStartingEventHandler();

	DownloadStartingEventHandler(const DownloadStartingEventHandler&) = delete;
	DownloadStartingEventHandler(DownloadStartingEventHandler&&) = delete;
	DownloadStartingEventHandler& operator=(const DownloadStartingEventHandler&) = delete;
	DownloadStartingEventHandler& operator=(DownloadStartingEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2DownloadStartingEventHandler
	WRAP_INTERFACE(DownloadStartingEventHandler1, ICoreWebView2DownloadStartingEventHandler, DownloadStartingEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2DownloadStartingEventArgs* args);
};
