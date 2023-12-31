/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class BrowserProcessExitedEventHandler : public HandlerBase {
public:
	BrowserProcessExitedEventHandler(SV* perl_object);
	virtual ~BrowserProcessExitedEventHandler();

	BrowserProcessExitedEventHandler(const BrowserProcessExitedEventHandler&) = delete;
	BrowserProcessExitedEventHandler(BrowserProcessExitedEventHandler&&) = delete;
	BrowserProcessExitedEventHandler& operator=(const BrowserProcessExitedEventHandler&) = delete;
	BrowserProcessExitedEventHandler& operator=(BrowserProcessExitedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2BrowserProcessExitedEventHandler
	WRAP_INTERFACE(BrowserProcessExitedEventHandler1, ICoreWebView2BrowserProcessExitedEventHandler, BrowserProcessExitedEventHandler)
	HRESULT Invoke(ICoreWebView2Environment* sender, ICoreWebView2BrowserProcessExitedEventArgs* args);
};
