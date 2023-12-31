/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class IsDocumentPlayingAudioChangedEventHandler : public HandlerBase {
public:
	IsDocumentPlayingAudioChangedEventHandler(SV* perl_object);
	virtual ~IsDocumentPlayingAudioChangedEventHandler();

	IsDocumentPlayingAudioChangedEventHandler(const IsDocumentPlayingAudioChangedEventHandler&) = delete;
	IsDocumentPlayingAudioChangedEventHandler(IsDocumentPlayingAudioChangedEventHandler&&) = delete;
	IsDocumentPlayingAudioChangedEventHandler& operator=(const IsDocumentPlayingAudioChangedEventHandler&) = delete;
	IsDocumentPlayingAudioChangedEventHandler& operator=(IsDocumentPlayingAudioChangedEventHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2IsDocumentPlayingAudioChangedEventHandler
	WRAP_INTERFACE(IsDocumentPlayingAudioChangedEventHandler1, ICoreWebView2IsDocumentPlayingAudioChangedEventHandler, IsDocumentPlayingAudioChangedEventHandler)
	HRESULT Invoke(ICoreWebView2* sender, IUnknown* args);
};
