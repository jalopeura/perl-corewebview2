/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "IsDocumentPlayingAudioChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "IsDocumentPlayingAudioChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2IsDocumentPlayingAudioChangedEventHandler
 */

IUNKNOWN_DEFS(IsDocumentPlayingAudioChangedEventHandler1, ICoreWebView2IsDocumentPlayingAudioChangedEventHandler, IsDocumentPlayingAudioChangedEventHandler)

static HRESULT STDMETHODCALLTYPE IsDocumentPlayingAudioChangedEventHandler_Invoke(ICoreWebView2IsDocumentPlayingAudioChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IsDocumentPlayingAudioChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<IsDocumentPlayingAudioChangedEventHandler::IsDocumentPlayingAudioChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2IsDocumentPlayingAudioChangedEventHandlerVtbl IsDocumentPlayingAudioChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(IsDocumentPlayingAudioChangedEventHandler1)
	IsDocumentPlayingAudioChangedEventHandler_Invoke,
};

HRESULT IsDocumentPlayingAudioChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 3); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(sender_sv);
	// args will be NULL

	PUTBACK;

	call_method("IsDocumentPlayingAudioChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//IsDocumentPlayingAudioChangedEventHandler::IsDocumentPlayingAudioChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2IsDocumentPlayingAudioChangedEventHandler{&IsDocumentPlayingAudioChangedEventHandlerVtbl} {}
IsDocumentPlayingAudioChangedEventHandler::IsDocumentPlayingAudioChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "IsDocumentPlayingAudioChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2IsDocumentPlayingAudioChangedEventHandler, (ICoreWebView2IsDocumentPlayingAudioChangedEventHandler*)(new IsDocumentPlayingAudioChangedEventHandler1(this, &IsDocumentPlayingAudioChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

IsDocumentPlayingAudioChangedEventHandler::~IsDocumentPlayingAudioChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass IsDocumentPlayingAudioChangedEventHandler1 containing interface ICoreWebView2IsDocumentPlayingAudioChangedEventHandler");
}
#endif // DEBUG
	IsDocumentPlayingAudioChangedEventHandler1* subclass = static_cast<IsDocumentPlayingAudioChangedEventHandler1*>((ICoreWebView2IsDocumentPlayingAudioChangedEventHandler*)GetInterface(IID_ICoreWebView2IsDocumentPlayingAudioChangedEventHandler));
	delete subclass;
}
