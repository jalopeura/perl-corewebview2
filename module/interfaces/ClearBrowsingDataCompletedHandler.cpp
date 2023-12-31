/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ClearBrowsingDataCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ClearBrowsingDataCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ClearBrowsingDataCompletedHandler
 */

IUNKNOWN_DEFS(ClearBrowsingDataCompletedHandler1, ICoreWebView2ClearBrowsingDataCompletedHandler, ClearBrowsingDataCompletedHandler)

static HRESULT STDMETHODCALLTYPE ClearBrowsingDataCompletedHandler_Invoke(ICoreWebView2ClearBrowsingDataCompletedHandler* This, HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ClearBrowsingDataCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ClearBrowsingDataCompletedHandler::ClearBrowsingDataCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode);
}

static ICoreWebView2ClearBrowsingDataCompletedHandlerVtbl ClearBrowsingDataCompletedHandlerVtbl = {
	IUNKNOWN_INIT(ClearBrowsingDataCompletedHandler1)
	ClearBrowsingDataCompletedHandler_Invoke,
};

HRESULT ClearBrowsingDataCompletedHandler::Invoke(HRESULT errorCode) {
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

	call_method("ClearBrowsingDataCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ClearBrowsingDataCompletedHandler::ClearBrowsingDataCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ClearBrowsingDataCompletedHandler{&ClearBrowsingDataCompletedHandlerVtbl} {}
ClearBrowsingDataCompletedHandler::ClearBrowsingDataCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "ClearBrowsingDataCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ClearBrowsingDataCompletedHandler, (ICoreWebView2ClearBrowsingDataCompletedHandler*)(new ClearBrowsingDataCompletedHandler1(this, &ClearBrowsingDataCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ClearBrowsingDataCompletedHandler::~ClearBrowsingDataCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ClearBrowsingDataCompletedHandler1 containing interface ICoreWebView2ClearBrowsingDataCompletedHandler");
}
#endif // DEBUG
	ClearBrowsingDataCompletedHandler1* subclass = static_cast<ClearBrowsingDataCompletedHandler1*>((ICoreWebView2ClearBrowsingDataCompletedHandler*)GetInterface(IID_ICoreWebView2ClearBrowsingDataCompletedHandler));
	delete subclass;
}
