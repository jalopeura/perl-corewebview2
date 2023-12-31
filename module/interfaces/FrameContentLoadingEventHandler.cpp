/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameContentLoadingEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameContentLoadingEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameContentLoadingEventHandler
 */

IUNKNOWN_DEFS(FrameContentLoadingEventHandler1, ICoreWebView2FrameContentLoadingEventHandler, FrameContentLoadingEventHandler)

static HRESULT STDMETHODCALLTYPE FrameContentLoadingEventHandler_Invoke(ICoreWebView2FrameContentLoadingEventHandler* This, ICoreWebView2Frame* sender, ICoreWebView2ContentLoadingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameContentLoadingEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameContentLoadingEventHandler::FrameContentLoadingEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameContentLoadingEventHandlerVtbl FrameContentLoadingEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameContentLoadingEventHandler1)
	FrameContentLoadingEventHandler_Invoke,
};

HRESULT FrameContentLoadingEventHandler::Invoke(ICoreWebView2Frame* sender, ICoreWebView2ContentLoadingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ContentLoadingEventArgs");

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

	call_method("FrameContentLoading", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameContentLoadingEventHandler::FrameContentLoadingEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameContentLoadingEventHandler{&FrameContentLoadingEventHandlerVtbl} {}
FrameContentLoadingEventHandler::FrameContentLoadingEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameContentLoadingEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameContentLoadingEventHandler, (ICoreWebView2FrameContentLoadingEventHandler*)(new FrameContentLoadingEventHandler1(this, &FrameContentLoadingEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameContentLoadingEventHandler::~FrameContentLoadingEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameContentLoadingEventHandler1 containing interface ICoreWebView2FrameContentLoadingEventHandler");
}
#endif // DEBUG
	FrameContentLoadingEventHandler1* subclass = static_cast<FrameContentLoadingEventHandler1*>((ICoreWebView2FrameContentLoadingEventHandler*)GetInterface(IID_ICoreWebView2FrameContentLoadingEventHandler));
	delete subclass;
}
