/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameWebMessageReceivedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameWebMessageReceivedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameWebMessageReceivedEventHandler
 */

IUNKNOWN_DEFS(FrameWebMessageReceivedEventHandler1, ICoreWebView2FrameWebMessageReceivedEventHandler, FrameWebMessageReceivedEventHandler)

static HRESULT STDMETHODCALLTYPE FrameWebMessageReceivedEventHandler_Invoke(ICoreWebView2FrameWebMessageReceivedEventHandler* This, ICoreWebView2Frame* sender, ICoreWebView2WebMessageReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameWebMessageReceivedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameWebMessageReceivedEventHandler::FrameWebMessageReceivedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameWebMessageReceivedEventHandlerVtbl FrameWebMessageReceivedEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameWebMessageReceivedEventHandler1)
	FrameWebMessageReceivedEventHandler_Invoke,
};

HRESULT FrameWebMessageReceivedEventHandler::Invoke(ICoreWebView2Frame* sender, ICoreWebView2WebMessageReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::WebMessageReceivedEventArgs");

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

	call_method("FrameWebMessageReceived", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameWebMessageReceivedEventHandler::FrameWebMessageReceivedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameWebMessageReceivedEventHandler{&FrameWebMessageReceivedEventHandlerVtbl} {}
FrameWebMessageReceivedEventHandler::FrameWebMessageReceivedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameWebMessageReceivedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameWebMessageReceivedEventHandler, (ICoreWebView2FrameWebMessageReceivedEventHandler*)(new FrameWebMessageReceivedEventHandler1(this, &FrameWebMessageReceivedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameWebMessageReceivedEventHandler::~FrameWebMessageReceivedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameWebMessageReceivedEventHandler1 containing interface ICoreWebView2FrameWebMessageReceivedEventHandler");
}
#endif // DEBUG
	FrameWebMessageReceivedEventHandler1* subclass = static_cast<FrameWebMessageReceivedEventHandler1*>((ICoreWebView2FrameWebMessageReceivedEventHandler*)GetInterface(IID_ICoreWebView2FrameWebMessageReceivedEventHandler));
	delete subclass;
}
