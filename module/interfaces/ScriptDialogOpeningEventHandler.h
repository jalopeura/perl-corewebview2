/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class ScriptDialogOpeningEventHandler : public HandlerBase {
public:
	ScriptDialogOpeningEventHandler(SV* perl_object);
	virtual ~ScriptDialogOpeningEventHandler();

	ScriptDialogOpeningEventHandler(const ScriptDialogOpeningEventHandler&) = delete;
	ScriptDialogOpeningEventHandler(ScriptDialogOpeningEventHandler&&) = delete;
	ScriptDialogOpeningEventHandler& operator=(const ScriptDialogOpeningEventHandler&) = delete;
	ScriptDialogOpeningEventHandler& operator=(ScriptDialogOpeningEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2ScriptDialogOpeningEventHandler
	WRAP_INTERFACE(ScriptDialogOpeningEventHandler1, ICoreWebView2ScriptDialogOpeningEventHandler, ScriptDialogOpeningEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, ICoreWebView2ScriptDialogOpeningEventArgs* args);
};
