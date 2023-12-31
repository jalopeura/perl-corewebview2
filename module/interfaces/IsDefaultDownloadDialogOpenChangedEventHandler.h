/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class IsDefaultDownloadDialogOpenChangedEventHandler : public HandlerBase {
public:
	IsDefaultDownloadDialogOpenChangedEventHandler(SV* perl_object);
	virtual ~IsDefaultDownloadDialogOpenChangedEventHandler();

	IsDefaultDownloadDialogOpenChangedEventHandler(const IsDefaultDownloadDialogOpenChangedEventHandler&) = delete;
	IsDefaultDownloadDialogOpenChangedEventHandler(IsDefaultDownloadDialogOpenChangedEventHandler&&) = delete;
	IsDefaultDownloadDialogOpenChangedEventHandler& operator=(const IsDefaultDownloadDialogOpenChangedEventHandler&) = delete;
	IsDefaultDownloadDialogOpenChangedEventHandler& operator=(IsDefaultDownloadDialogOpenChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler
	WRAP_INTERFACE(IsDefaultDownloadDialogOpenChangedEventHandler1, ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler, IsDefaultDownloadDialogOpenChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
