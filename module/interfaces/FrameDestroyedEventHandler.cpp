/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameDestroyedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameDestroyedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameDestroyedEventHandler
 */

IUNKNOWN_DEFS(FrameDestroyedEventHandler1, ICoreWebView2FrameDestroyedEventHandler, FrameDestroyedEventHandler)

static HRESULT STDMETHODCALLTYPE FrameDestroyedEventHandler_Invoke(ICoreWebView2FrameDestroyedEventHandler* This, ICoreWebView2Frame* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameDestroyedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameDestroyedEventHandler::FrameDestroyedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameDestroyedEventHandlerVtbl FrameDestroyedEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameDestroyedEventHandler1)
	FrameDestroyedEventHandler_Invoke,
};

HRESULT FrameDestroyedEventHandler::Invoke(ICoreWebView2Frame* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");

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

	call_method("FrameDestroyed", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameDestroyedEventHandler::FrameDestroyedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameDestroyedEventHandler{&FrameDestroyedEventHandlerVtbl} {}
FrameDestroyedEventHandler::FrameDestroyedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameDestroyedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameDestroyedEventHandler, (ICoreWebView2FrameDestroyedEventHandler*)(new FrameDestroyedEventHandler1(this, &FrameDestroyedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameDestroyedEventHandler::~FrameDestroyedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameDestroyedEventHandler1 containing interface ICoreWebView2FrameDestroyedEventHandler");
}
#endif // DEBUG
	FrameDestroyedEventHandler1* subclass = static_cast<FrameDestroyedEventHandler1*>((ICoreWebView2FrameDestroyedEventHandler*)GetInterface(IID_ICoreWebView2FrameDestroyedEventHandler));
	delete subclass;
}
