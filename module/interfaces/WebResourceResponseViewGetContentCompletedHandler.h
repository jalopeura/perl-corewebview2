/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class WebResourceResponseViewGetContentCompletedHandler : public HandlerBase {
public:
	WebResourceResponseViewGetContentCompletedHandler(SV* perl_object);
	virtual ~WebResourceResponseViewGetContentCompletedHandler();

	WebResourceResponseViewGetContentCompletedHandler(const WebResourceResponseViewGetContentCompletedHandler&) = delete;
	WebResourceResponseViewGetContentCompletedHandler(WebResourceResponseViewGetContentCompletedHandler&&) = delete;
	WebResourceResponseViewGetContentCompletedHandler& operator=(const WebResourceResponseViewGetContentCompletedHandler&) = delete;
	WebResourceResponseViewGetContentCompletedHandler& operator=(WebResourceResponseViewGetContentCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2WebResourceResponseViewGetContentCompletedHandler
	WRAP_INTERFACE(WebResourceResponseViewGetContentCompletedHandler1, ICoreWebView2WebResourceResponseViewGetContentCompletedHandler, WebResourceResponseViewGetContentCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, IStream* content);
};
