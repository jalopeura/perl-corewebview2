/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ClearServerCertificateErrorActionsCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ClearServerCertificateErrorActionsCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler
 */

IUNKNOWN_DEFS(ClearServerCertificateErrorActionsCompletedHandler1, ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler, ClearServerCertificateErrorActionsCompletedHandler)

static HRESULT STDMETHODCALLTYPE ClearServerCertificateErrorActionsCompletedHandler_Invoke(ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler* This, HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ClearServerCertificateErrorActionsCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ClearServerCertificateErrorActionsCompletedHandler::ClearServerCertificateErrorActionsCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode);
}

static ICoreWebView2ClearServerCertificateErrorActionsCompletedHandlerVtbl ClearServerCertificateErrorActionsCompletedHandlerVtbl = {
	IUNKNOWN_INIT(ClearServerCertificateErrorActionsCompletedHandler1)
	ClearServerCertificateErrorActionsCompletedHandler_Invoke,
};

HRESULT ClearServerCertificateErrorActionsCompletedHandler::Invoke(HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(errorCode_sv);

	PUTBACK;

	call_method("ClearServerCertificateErrorActionsCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ClearServerCertificateErrorActionsCompletedHandler::ClearServerCertificateErrorActionsCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler{&ClearServerCertificateErrorActionsCompletedHandlerVtbl} {}
ClearServerCertificateErrorActionsCompletedHandler::ClearServerCertificateErrorActionsCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "ClearServerCertificateErrorActionsCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler, (ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler*)(new ClearServerCertificateErrorActionsCompletedHandler1(this, &ClearServerCertificateErrorActionsCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ClearServerCertificateErrorActionsCompletedHandler::~ClearServerCertificateErrorActionsCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ClearServerCertificateErrorActionsCompletedHandler1 containing interface ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler");
}
#endif // DEBUG
	ClearServerCertificateErrorActionsCompletedHandler1* subclass = static_cast<ClearServerCertificateErrorActionsCompletedHandler1*>((ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler*)GetInterface(IID_ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler));
	delete subclass;
}
