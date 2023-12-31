/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class DocumentTitleChangedEventHandler : public HandlerBase {
public:
	DocumentTitleChangedEventHandler(SV* perl_object);
	virtual ~DocumentTitleChangedEventHandler();

	DocumentTitleChangedEventHandler(const DocumentTitleChangedEventHandler&) = delete;
	DocumentTitleChangedEventHandler(DocumentTitleChangedEventHandler&&) = delete;
	DocumentTitleChangedEventHandler& operator=(const DocumentTitleChangedEventHandler&) = delete;
	DocumentTitleChangedEventHandler& operator=(DocumentTitleChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2DocumentTitleChangedEventHandler
	WRAP_INTERFACE(DocumentTitleChangedEventHandler1, ICoreWebView2DocumentTitleChangedEventHandler, DocumentTitleChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
