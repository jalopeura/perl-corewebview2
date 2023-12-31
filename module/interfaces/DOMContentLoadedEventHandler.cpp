/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "DOMContentLoadedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "DOMContentLoadedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2DOMContentLoadedEventHandler
 */

IUNKNOWN_DEFS(DOMContentLoadedEventHandler1, ICoreWebView2DOMContentLoadedEventHandler, DOMContentLoadedEventHandler)

static HRESULT STDMETHODCALLTYPE DOMContentLoadedEventHandler_Invoke(ICoreWebView2DOMContentLoadedEventHandler* This, ICoreWebView2* sender, ICoreWebView2DOMContentLoadedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("DOMContentLoadedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<DOMContentLoadedEventHandler::DOMContentLoadedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2DOMContentLoadedEventHandlerVtbl DOMContentLoadedEventHandlerVtbl = {
	IUNKNOWN_INIT(DOMContentLoadedEventHandler1)
	DOMContentLoadedEventHandler_Invoke,
};

HRESULT DOMContentLoadedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2DOMContentLoadedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
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

	call_method("DOMContentLoaded", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//DOMContentLoadedEventHandler::DOMContentLoadedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2DOMContentLoadedEventHandler{&DOMContentLoadedEventHandlerVtbl} {}
DOMContentLoadedEventHandler::DOMContentLoadedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "DOMContentLoadedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2DOMContentLoadedEventHandler, (ICoreWebView2DOMContentLoadedEventHandler*)(new DOMContentLoadedEventHandler1(this, &DOMContentLoadedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

DOMContentLoadedEventHandler::~DOMContentLoadedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass DOMContentLoadedEventHandler1 containing interface ICoreWebView2DOMContentLoadedEventHandler");
}
#endif // DEBUG
	DOMContentLoadedEventHandler1* subclass = static_cast<DOMContentLoadedEventHandler1*>((ICoreWebView2DOMContentLoadedEventHandler*)GetInterface(IID_ICoreWebView2DOMContentLoadedEventHandler));
	delete subclass;
}
