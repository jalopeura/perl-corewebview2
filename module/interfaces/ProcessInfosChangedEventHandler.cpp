/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ProcessInfosChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ProcessInfosChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ProcessInfosChangedEventHandler
 */

IUNKNOWN_DEFS(ProcessInfosChangedEventHandler1, ICoreWebView2ProcessInfosChangedEventHandler, ProcessInfosChangedEventHandler)

static HRESULT STDMETHODCALLTYPE ProcessInfosChangedEventHandler_Invoke(ICoreWebView2ProcessInfosChangedEventHandler* This, ICoreWebView2Environment* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ProcessInfosChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ProcessInfosChangedEventHandler::ProcessInfosChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ProcessInfosChangedEventHandlerVtbl ProcessInfosChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(ProcessInfosChangedEventHandler1)
	ProcessInfosChangedEventHandler_Invoke,
};

HRESULT ProcessInfosChangedEventHandler::Invoke(ICoreWebView2Environment* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Environment");

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

	call_method("ProcessInfosChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ProcessInfosChangedEventHandler::ProcessInfosChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ProcessInfosChangedEventHandler{&ProcessInfosChangedEventHandlerVtbl} {}
ProcessInfosChangedEventHandler::ProcessInfosChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ProcessInfosChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ProcessInfosChangedEventHandler, (ICoreWebView2ProcessInfosChangedEventHandler*)(new ProcessInfosChangedEventHandler1(this, &ProcessInfosChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ProcessInfosChangedEventHandler::~ProcessInfosChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ProcessInfosChangedEventHandler1 containing interface ICoreWebView2ProcessInfosChangedEventHandler");
}
#endif // DEBUG
	ProcessInfosChangedEventHandler1* subclass = static_cast<ProcessInfosChangedEventHandler1*>((ICoreWebView2ProcessInfosChangedEventHandler*)GetInterface(IID_ICoreWebView2ProcessInfosChangedEventHandler));
	delete subclass;
}
