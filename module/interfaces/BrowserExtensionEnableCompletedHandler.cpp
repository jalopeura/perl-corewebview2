/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "BrowserExtensionEnableCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "BrowserExtensionEnableCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2BrowserExtensionEnableCompletedHandler
 */

IUNKNOWN_DEFS(BrowserExtensionEnableCompletedHandler1, ICoreWebView2BrowserExtensionEnableCompletedHandler, BrowserExtensionEnableCompletedHandler)

static HRESULT STDMETHODCALLTYPE BrowserExtensionEnableCompletedHandler_Invoke(ICoreWebView2BrowserExtensionEnableCompletedHandler* This, HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("BrowserExtensionEnableCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<BrowserExtensionEnableCompletedHandler::BrowserExtensionEnableCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode);
}

static ICoreWebView2BrowserExtensionEnableCompletedHandlerVtbl BrowserExtensionEnableCompletedHandlerVtbl = {
	IUNKNOWN_INIT(BrowserExtensionEnableCompletedHandler1)
	BrowserExtensionEnableCompletedHandler_Invoke,
};

HRESULT BrowserExtensionEnableCompletedHandler::Invoke(HRESULT errorCode) {
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

	call_method("BrowserExtensionEnableCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//BrowserExtensionEnableCompletedHandler::BrowserExtensionEnableCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2BrowserExtensionEnableCompletedHandler{&BrowserExtensionEnableCompletedHandlerVtbl} {}
BrowserExtensionEnableCompletedHandler::BrowserExtensionEnableCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "BrowserExtensionEnableCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2BrowserExtensionEnableCompletedHandler, (ICoreWebView2BrowserExtensionEnableCompletedHandler*)(new BrowserExtensionEnableCompletedHandler1(this, &BrowserExtensionEnableCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

BrowserExtensionEnableCompletedHandler::~BrowserExtensionEnableCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass BrowserExtensionEnableCompletedHandler1 containing interface ICoreWebView2BrowserExtensionEnableCompletedHandler");
}
#endif // DEBUG
	BrowserExtensionEnableCompletedHandler1* subclass = static_cast<BrowserExtensionEnableCompletedHandler1*>((ICoreWebView2BrowserExtensionEnableCompletedHandler*)GetInterface(IID_ICoreWebView2BrowserExtensionEnableCompletedHandler));
	delete subclass;
}
