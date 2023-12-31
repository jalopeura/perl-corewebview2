/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class GetFaviconCompletedHandler : public HandlerBase {
public:
	GetFaviconCompletedHandler(SV* perl_object);
	virtual ~GetFaviconCompletedHandler();

	GetFaviconCompletedHandler(const GetFaviconCompletedHandler&) = delete;
	GetFaviconCompletedHandler(GetFaviconCompletedHandler&&) = delete;
	GetFaviconCompletedHandler& operator=(const GetFaviconCompletedHandler&) = delete;
	GetFaviconCompletedHandler& operator=(GetFaviconCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2GetFaviconCompletedHandler
	WRAP_INTERFACE(GetFaviconCompletedHandler1, ICoreWebView2GetFaviconCompletedHandler, GetFaviconCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, IStream* faviconStream);
};
