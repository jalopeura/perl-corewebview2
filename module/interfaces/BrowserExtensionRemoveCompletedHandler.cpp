/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "BrowserExtensionRemoveCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "BrowserExtensionRemoveCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2BrowserExtensionRemoveCompletedHandler
 */

IUNKNOWN_DEFS(BrowserExtensionRemoveCompletedHandler1, ICoreWebView2BrowserExtensionRemoveCompletedHandler, BrowserExtensionRemoveCompletedHandler)

static HRESULT STDMETHODCALLTYPE BrowserExtensionRemoveCompletedHandler_Invoke(ICoreWebView2BrowserExtensionRemoveCompletedHandler* This, HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("BrowserExtensionRemoveCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<BrowserExtensionRemoveCompletedHandler::BrowserExtensionRemoveCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode);
}

static ICoreWebView2BrowserExtensionRemoveCompletedHandlerVtbl BrowserExtensionRemoveCompletedHandlerVtbl = {
	IUNKNOWN_INIT(BrowserExtensionRemoveCompletedHandler1)
	BrowserExtensionRemoveCompletedHandler_Invoke,
};

HRESULT BrowserExtensionRemoveCompletedHandler::Invoke(HRESULT errorCode) {
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

	call_method("BrowserExtensionRemoveCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//BrowserExtensionRemoveCompletedHandler::BrowserExtensionRemoveCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2BrowserExtensionRemoveCompletedHandler{&BrowserExtensionRemoveCompletedHandlerVtbl} {}
BrowserExtensionRemoveCompletedHandler::BrowserExtensionRemoveCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "BrowserExtensionRemoveCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2BrowserExtensionRemoveCompletedHandler, (ICoreWebView2BrowserExtensionRemoveCompletedHandler*)(new BrowserExtensionRemoveCompletedHandler1(this, &BrowserExtensionRemoveCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

BrowserExtensionRemoveCompletedHandler::~BrowserExtensionRemoveCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass BrowserExtensionRemoveCompletedHandler1 containing interface ICoreWebView2BrowserExtensionRemoveCompletedHandler");
}
#endif // DEBUG
	BrowserExtensionRemoveCompletedHandler1* subclass = static_cast<BrowserExtensionRemoveCompletedHandler1*>((ICoreWebView2BrowserExtensionRemoveCompletedHandler*)GetInterface(IID_ICoreWebView2BrowserExtensionRemoveCompletedHandler));
	delete subclass;
}
