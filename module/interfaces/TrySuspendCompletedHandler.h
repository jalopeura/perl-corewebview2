/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class TrySuspendCompletedHandler : public HandlerBase {
public:
	TrySuspendCompletedHandler(SV* perl_object);
	virtual ~TrySuspendCompletedHandler();

	TrySuspendCompletedHandler(const TrySuspendCompletedHandler&) = delete;
	TrySuspendCompletedHandler(TrySuspendCompletedHandler&&) = delete;
	TrySuspendCompletedHandler& operator=(const TrySuspendCompletedHandler&) = delete;
	TrySuspendCompletedHandler& operator=(TrySuspendCompletedHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2TrySuspendCompletedHandler
	WRAP_INTERFACE(TrySuspendCompletedHandler1, ICoreWebView2TrySuspendCompletedHandler, TrySuspendCompletedHandler)
	HRESULT Invoke(HRESULT errorCode, BOOL isSuccessful);
};
