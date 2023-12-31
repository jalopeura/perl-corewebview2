/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ProcessFailedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ProcessFailedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ProcessFailedEventHandler
 */

IUNKNOWN_DEFS(ProcessFailedEventHandler1, ICoreWebView2ProcessFailedEventHandler, ProcessFailedEventHandler)

static HRESULT STDMETHODCALLTYPE ProcessFailedEventHandler_Invoke(ICoreWebView2ProcessFailedEventHandler* This, ICoreWebView2* sender, ICoreWebView2ProcessFailedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ProcessFailedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ProcessFailedEventHandler::ProcessFailedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ProcessFailedEventHandlerVtbl ProcessFailedEventHandlerVtbl = {
	IUNKNOWN_INIT(ProcessFailedEventHandler1)
	ProcessFailedEventHandler_Invoke,
};

HRESULT ProcessFailedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2ProcessFailedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ProcessFailedEventArgs");

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

	call_method("ProcessFailed", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ProcessFailedEventHandler::ProcessFailedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ProcessFailedEventHandler{&ProcessFailedEventHandlerVtbl} {}
ProcessFailedEventHandler::ProcessFailedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ProcessFailedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ProcessFailedEventHandler, (ICoreWebView2ProcessFailedEventHandler*)(new ProcessFailedEventHandler1(this, &ProcessFailedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ProcessFailedEventHandler::~ProcessFailedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ProcessFailedEventHandler1 containing interface ICoreWebView2ProcessFailedEventHandler");
}
#endif // DEBUG
	ProcessFailedEventHandler1* subclass = static_cast<ProcessFailedEventHandler1*>((ICoreWebView2ProcessFailedEventHandler*)GetInterface(IID_ICoreWebView2ProcessFailedEventHandler));
	delete subclass;
}
