/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class EstimatedEndTimeChangedEventHandler : public HandlerBase {
public:
	EstimatedEndTimeChangedEventHandler(SV* perl_object);
	virtual ~EstimatedEndTimeChangedEventHandler();

	EstimatedEndTimeChangedEventHandler(const EstimatedEndTimeChangedEventHandler&) = delete;
	EstimatedEndTimeChangedEventHandler(EstimatedEndTimeChangedEventHandler&&) = delete;
	EstimatedEndTimeChangedEventHandler& operator=(const EstimatedEndTimeChangedEventHandler&) = delete;
	EstimatedEndTimeChangedEventHandler& operator=(EstimatedEndTimeChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2EstimatedEndTimeChangedEventHandler
	WRAP_INTERFACE(EstimatedEndTimeChangedEventHandler1, ICoreWebView2EstimatedEndTimeChangedEventHandler, EstimatedEndTimeChangedEventHandler)
	HRESULT Invoke(ICoreWebView2DownloadOperation* sender, IUnknown* args);
};
