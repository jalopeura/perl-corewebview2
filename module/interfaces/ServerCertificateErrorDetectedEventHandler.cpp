/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ServerCertificateErrorDetectedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ServerCertificateErrorDetectedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ServerCertificateErrorDetectedEventHandler
 */

IUNKNOWN_DEFS(ServerCertificateErrorDetectedEventHandler1, ICoreWebView2ServerCertificateErrorDetectedEventHandler, ServerCertificateErrorDetectedEventHandler)

static HRESULT STDMETHODCALLTYPE ServerCertificateErrorDetectedEventHandler_Invoke(ICoreWebView2ServerCertificateErrorDetectedEventHandler* This, ICoreWebView2* sender, ICoreWebView2ServerCertificateErrorDetectedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ServerCertificateErrorDetectedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ServerCertificateErrorDetectedEventHandler::ServerCertificateErrorDetectedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ServerCertificateErrorDetectedEventHandlerVtbl ServerCertificateErrorDetectedEventHandlerVtbl = {
	IUNKNOWN_INIT(ServerCertificateErrorDetectedEventHandler1)
	ServerCertificateErrorDetectedEventHandler_Invoke,
};

HRESULT ServerCertificateErrorDetectedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2ServerCertificateErrorDetectedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ServerCertificateErrorDetectedEventArgs");

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

	call_method("ServerCertificateErrorDetected", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ServerCertificateErrorDetectedEventHandler::ServerCertificateErrorDetectedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ServerCertificateErrorDetectedEventHandler{&ServerCertificateErrorDetectedEventHandlerVtbl} {}
ServerCertificateErrorDetectedEventHandler::ServerCertificateErrorDetectedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ServerCertificateErrorDetectedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ServerCertificateErrorDetectedEventHandler, (ICoreWebView2ServerCertificateErrorDetectedEventHandler*)(new ServerCertificateErrorDetectedEventHandler1(this, &ServerCertificateErrorDetectedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ServerCertificateErrorDetectedEventHandler::~ServerCertificateErrorDetectedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ServerCertificateErrorDetectedEventHandler1 containing interface ICoreWebView2ServerCertificateErrorDetectedEventHandler");
}
#endif // DEBUG
	ServerCertificateErrorDetectedEventHandler1* subclass = static_cast<ServerCertificateErrorDetectedEventHandler1*>((ICoreWebView2ServerCertificateErrorDetectedEventHandler*)GetInterface(IID_ICoreWebView2ServerCertificateErrorDetectedEventHandler));
	delete subclass;
}
