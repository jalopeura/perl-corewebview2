/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "TrySuspendCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "TrySuspendCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2TrySuspendCompletedHandler
 */

IUNKNOWN_DEFS(TrySuspendCompletedHandler1, ICoreWebView2TrySuspendCompletedHandler, TrySuspendCompletedHandler)

static HRESULT STDMETHODCALLTYPE TrySuspendCompletedHandler_Invoke(ICoreWebView2TrySuspendCompletedHandler* This, HRESULT errorCode, BOOL isSuccessful) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("TrySuspendCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<TrySuspendCompletedHandler::TrySuspendCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, isSuccessful);
}

static ICoreWebView2TrySuspendCompletedHandlerVtbl TrySuspendCompletedHandlerVtbl = {
	IUNKNOWN_INIT(TrySuspendCompletedHandler1)
	TrySuspendCompletedHandler_Invoke,
};

HRESULT TrySuspendCompletedHandler::Invoke(HRESULT errorCode, BOOL isSuccessful) {
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
	//EXTEND(SP, 3); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(errorCode_sv);
	XPUSHs(isSuccessful ? &PL_sv_yes : &PL_sv_no);

	PUTBACK;

	call_method("TrySuspendCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//TrySuspendCompletedHandler::TrySuspendCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2TrySuspendCompletedHandler{&TrySuspendCompletedHandlerVtbl} {}
TrySuspendCompletedHandler::TrySuspendCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "TrySuspendCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2TrySuspendCompletedHandler, (ICoreWebView2TrySuspendCompletedHandler*)(new TrySuspendCompletedHandler1(this, &TrySuspendCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

TrySuspendCompletedHandler::~TrySuspendCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass TrySuspendCompletedHandler1 containing interface ICoreWebView2TrySuspendCompletedHandler");
}
#endif // DEBUG
	TrySuspendCompletedHandler1* subclass = static_cast<TrySuspendCompletedHandler1*>((ICoreWebView2TrySuspendCompletedHandler*)GetInterface(IID_ICoreWebView2TrySuspendCompletedHandler));
	delete subclass;
}
