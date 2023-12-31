/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ContentLoadingEventHandler : public HandlerBase {
public:
	ContentLoadingEventHandler(SV* perl_object);
	virtual ~ContentLoadingEventHandler();

	ContentLoadingEventHandler(const ContentLoadingEventHandler&) = delete;
	ContentLoadingEventHandler(ContentLoadingEventHandler&&) = delete;
	ContentLoadingEventHandler& operator=(const ContentLoadingEventHandler&) = delete;
	ContentLoadingEventHandler& operator=(ContentLoadingEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ContentLoadingEventHandler
	WRAP_INTERFACE(ContentLoadingEventHandler1, ICoreWebView2ContentLoadingEventHandler, ContentLoadingEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2ContentLoadingEventArgs* args);
};
