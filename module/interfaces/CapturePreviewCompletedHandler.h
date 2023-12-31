/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class CapturePreviewCompletedHandler : public HandlerBase {
public:
	CapturePreviewCompletedHandler(SV* perl_object);
	virtual ~CapturePreviewCompletedHandler();

	CapturePreviewCompletedHandler(const CapturePreviewCompletedHandler&) = delete;
	CapturePreviewCompletedHandler(CapturePreviewCompletedHandler&&) = delete;
	CapturePreviewCompletedHandler& operator=(const CapturePreviewCompletedHandler&) = delete;
	CapturePreviewCompletedHandler& operator=(CapturePreviewCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CapturePreviewCompletedHandler
	WRAP_INTERFACE(CapturePreviewCompletedHandler1, ICoreWebView2CapturePreviewCompletedHandler, CapturePreviewCompletedHandler)
	HRESULT Invoke(HRESULT errorCode);
};
