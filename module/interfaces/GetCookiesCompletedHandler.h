/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class GetCookiesCompletedHandler : public HandlerBase {
public:
	GetCookiesCompletedHandler(SV* perl_object);
	virtual ~GetCookiesCompletedHandler();

	GetCookiesCompletedHandler(const GetCookiesCompletedHandler&) = delete;
	GetCookiesCompletedHandler(GetCookiesCompletedHandler&&) = delete;
	GetCookiesCompletedHandler& operator=(const GetCookiesCompletedHandler&) = delete;
	GetCookiesCompletedHandler& operator=(GetCookiesCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2GetCookiesCompletedHandler
	WRAP_INTERFACE(GetCookiesCompletedHandler1, ICoreWebView2GetCookiesCompletedHandler, GetCookiesCompletedHandler)
	HRESULT Invoke(HRESULT result, ICoreWebView2CookieList* cookieList);
};
