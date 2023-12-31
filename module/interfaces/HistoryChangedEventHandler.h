/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class HistoryChangedEventHandler : public HandlerBase {
public:
	HistoryChangedEventHandler(SV* perl_object);
	virtual ~HistoryChangedEventHandler();

	HistoryChangedEventHandler(const HistoryChangedEventHandler&) = delete;
	HistoryChangedEventHandler(HistoryChangedEventHandler&&) = delete;
	HistoryChangedEventHandler& operator=(const HistoryChangedEventHandler&) = delete;
	HistoryChangedEventHandler& operator=(HistoryChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2HistoryChangedEventHandler
	WRAP_INTERFACE(HistoryChangedEventHandler1, ICoreWebView2HistoryChangedEventHandler, HistoryChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
