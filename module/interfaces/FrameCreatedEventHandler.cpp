/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameCreatedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameCreatedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameCreatedEventHandler
 */

IUNKNOWN_DEFS(FrameCreatedEventHandler1, ICoreWebView2FrameCreatedEventHandler, FrameCreatedEventHandler)

static HRESULT STDMETHODCALLTYPE FrameCreatedEventHandler_Invoke(ICoreWebView2FrameCreatedEventHandler* This, ICoreWebView2* sender, ICoreWebView2FrameCreatedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameCreatedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameCreatedEventHandler::FrameCreatedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameCreatedEventHandlerVtbl FrameCreatedEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameCreatedEventHandler1)
	FrameCreatedEventHandler_Invoke,
};

HRESULT FrameCreatedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2FrameCreatedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::FrameCreatedEventArgs");

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

	call_method("FrameCreated", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameCreatedEventHandler::FrameCreatedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameCreatedEventHandler{&FrameCreatedEventHandlerVtbl} {}
FrameCreatedEventHandler::FrameCreatedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameCreatedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameCreatedEventHandler, (ICoreWebView2FrameCreatedEventHandler*)(new FrameCreatedEventHandler1(this, &FrameCreatedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameCreatedEventHandler::~FrameCreatedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameCreatedEventHandler1 containing interface ICoreWebView2FrameCreatedEventHandler");
}
#endif // DEBUG
	FrameCreatedEventHandler1* subclass = static_cast<FrameCreatedEventHandler1*>((ICoreWebView2FrameCreatedEventHandler*)GetInterface(IID_ICoreWebView2FrameCreatedEventHandler));
	delete subclass;
}
