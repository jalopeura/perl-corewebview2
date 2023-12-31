/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameDOMContentLoadedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameDOMContentLoadedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameDOMContentLoadedEventHandler
 */

IUNKNOWN_DEFS(FrameDOMContentLoadedEventHandler1, ICoreWebView2FrameDOMContentLoadedEventHandler, FrameDOMContentLoadedEventHandler)

static HRESULT STDMETHODCALLTYPE FrameDOMContentLoadedEventHandler_Invoke(ICoreWebView2FrameDOMContentLoadedEventHandler* This, ICoreWebView2Frame* sender, ICoreWebView2DOMContentLoadedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameDOMContentLoadedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameDOMContentLoadedEventHandler::FrameDOMContentLoadedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameDOMContentLoadedEventHandlerVtbl FrameDOMContentLoadedEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameDOMContentLoadedEventHandler1)
	FrameDOMContentLoadedEventHandler_Invoke,
};

HRESULT FrameDOMContentLoadedEventHandler::Invoke(ICoreWebView2Frame* sender, ICoreWebView2DOMContentLoadedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::DOMContentLoadedEventArgs");

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
	XPUSHs(args_sv);

	PUTBACK;

	call_method("FrameDOMContentLoaded", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameDOMContentLoadedEventHandler::FrameDOMContentLoadedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameDOMContentLoadedEventHandler{&FrameDOMContentLoadedEventHandlerVtbl} {}
FrameDOMContentLoadedEventHandler::FrameDOMContentLoadedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameDOMContentLoadedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameDOMContentLoadedEventHandler, (ICoreWebView2FrameDOMContentLoadedEventHandler*)(new FrameDOMContentLoadedEventHandler1(this, &FrameDOMContentLoadedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameDOMContentLoadedEventHandler::~FrameDOMContentLoadedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameDOMContentLoadedEventHandler1 containing interface ICoreWebView2FrameDOMContentLoadedEventHandler");
}
#endif // DEBUG
	FrameDOMContentLoadedEventHandler1* subclass = static_cast<FrameDOMContentLoadedEventHandler1*>((ICoreWebView2FrameDOMContentLoadedEventHandler*)GetInterface(IID_ICoreWebView2FrameDOMContentLoadedEventHandler));
	delete subclass;
}
