/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ContextMenuRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ContextMenuRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ContextMenuRequestedEventHandler
 */

IUNKNOWN_DEFS(ContextMenuRequestedEventHandler1, ICoreWebView2ContextMenuRequestedEventHandler, ContextMenuRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE ContextMenuRequestedEventHandler_Invoke(ICoreWebView2ContextMenuRequestedEventHandler* This, ICoreWebView2* sender, ICoreWebView2ContextMenuRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ContextMenuRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ContextMenuRequestedEventHandler::ContextMenuRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ContextMenuRequestedEventHandlerVtbl ContextMenuRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(ContextMenuRequestedEventHandler1)
	ContextMenuRequestedEventHandler_Invoke,
};

HRESULT ContextMenuRequestedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2ContextMenuRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ContextMenuRequestedEventArgs");

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

	call_method("ContextMenuRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ContextMenuRequestedEventHandler::ContextMenuRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ContextMenuRequestedEventHandler{&ContextMenuRequestedEventHandlerVtbl} {}
ContextMenuRequestedEventHandler::ContextMenuRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ContextMenuRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ContextMenuRequestedEventHandler, (ICoreWebView2ContextMenuRequestedEventHandler*)(new ContextMenuRequestedEventHandler1(this, &ContextMenuRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ContextMenuRequestedEventHandler::~ContextMenuRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ContextMenuRequestedEventHandler1 containing interface ICoreWebView2ContextMenuRequestedEventHandler");
}
#endif // DEBUG
	ContextMenuRequestedEventHandler1* subclass = static_cast<ContextMenuRequestedEventHandler1*>((ICoreWebView2ContextMenuRequestedEventHandler*)GetInterface(IID_ICoreWebView2ContextMenuRequestedEventHandler));
	delete subclass;
}
