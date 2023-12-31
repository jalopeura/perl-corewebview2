/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "BasicAuthenticationRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "BasicAuthenticationRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2BasicAuthenticationRequestedEventHandler
 */

IUNKNOWN_DEFS(BasicAuthenticationRequestedEventHandler1, ICoreWebView2BasicAuthenticationRequestedEventHandler, BasicAuthenticationRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE BasicAuthenticationRequestedEventHandler_Invoke(ICoreWebView2BasicAuthenticationRequestedEventHandler* This, ICoreWebView2* sender, ICoreWebView2BasicAuthenticationRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("BasicAuthenticationRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<BasicAuthenticationRequestedEventHandler::BasicAuthenticationRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2BasicAuthenticationRequestedEventHandlerVtbl BasicAuthenticationRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(BasicAuthenticationRequestedEventHandler1)
	BasicAuthenticationRequestedEventHandler_Invoke,
};

HRESULT BasicAuthenticationRequestedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2BasicAuthenticationRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::BasicAuthenticationRequestedEventArgs");

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

	call_method("BasicAuthenticationRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//BasicAuthenticationRequestedEventHandler::BasicAuthenticationRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2BasicAuthenticationRequestedEventHandler{&BasicAuthenticationRequestedEventHandlerVtbl} {}
BasicAuthenticationRequestedEventHandler::BasicAuthenticationRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "BasicAuthenticationRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2BasicAuthenticationRequestedEventHandler, (ICoreWebView2BasicAuthenticationRequestedEventHandler*)(new BasicAuthenticationRequestedEventHandler1(this, &BasicAuthenticationRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

BasicAuthenticationRequestedEventHandler::~BasicAuthenticationRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass BasicAuthenticationRequestedEventHandler1 containing interface ICoreWebView2BasicAuthenticationRequestedEventHandler");
}
#endif // DEBUG
	BasicAuthenticationRequestedEventHandler1* subclass = static_cast<BasicAuthenticationRequestedEventHandler1*>((ICoreWebView2BasicAuthenticationRequestedEventHandler*)GetInterface(IID_ICoreWebView2BasicAuthenticationRequestedEventHandler));
	delete subclass;
}
