/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ClientCertificateRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ClientCertificateRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ClientCertificateRequestedEventHandler
 */

IUNKNOWN_DEFS(ClientCertificateRequestedEventHandler1, ICoreWebView2ClientCertificateRequestedEventHandler, ClientCertificateRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE ClientCertificateRequestedEventHandler_Invoke(ICoreWebView2ClientCertificateRequestedEventHandler* This, ICoreWebView2* sender, ICoreWebView2ClientCertificateRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ClientCertificateRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ClientCertificateRequestedEventHandler::ClientCertificateRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ClientCertificateRequestedEventHandlerVtbl ClientCertificateRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(ClientCertificateRequestedEventHandler1)
	ClientCertificateRequestedEventHandler_Invoke,
};

HRESULT ClientCertificateRequestedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2ClientCertificateRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ClientCertificateRequestedEventArgs");

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

	call_method("ClientCertificateRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ClientCertificateRequestedEventHandler::ClientCertificateRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ClientCertificateRequestedEventHandler{&ClientCertificateRequestedEventHandlerVtbl} {}
ClientCertificateRequestedEventHandler::ClientCertificateRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ClientCertificateRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ClientCertificateRequestedEventHandler, (ICoreWebView2ClientCertificateRequestedEventHandler*)(new ClientCertificateRequestedEventHandler1(this, &ClientCertificateRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ClientCertificateRequestedEventHandler::~ClientCertificateRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ClientCertificateRequestedEventHandler1 containing interface ICoreWebView2ClientCertificateRequestedEventHandler");
}
#endif // DEBUG
	ClientCertificateRequestedEventHandler1* subclass = static_cast<ClientCertificateRequestedEventHandler1*>((ICoreWebView2ClientCertificateRequestedEventHandler*)GetInterface(IID_ICoreWebView2ClientCertificateRequestedEventHandler));
	delete subclass;
}
