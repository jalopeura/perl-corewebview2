/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CallDevToolsProtocolMethodCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CallDevToolsProtocolMethodCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CallDevToolsProtocolMethodCompletedHandler
 */

IUNKNOWN_DEFS(CallDevToolsProtocolMethodCompletedHandler1, ICoreWebView2CallDevToolsProtocolMethodCompletedHandler, CallDevToolsProtocolMethodCompletedHandler)

static HRESULT STDMETHODCALLTYPE CallDevToolsProtocolMethodCompletedHandler_Invoke(ICoreWebView2CallDevToolsProtocolMethodCompletedHandler* This, HRESULT errorCode, LPCWSTR returnObjectAsJson) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CallDevToolsProtocolMethodCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CallDevToolsProtocolMethodCompletedHandler::CallDevToolsProtocolMethodCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, returnObjectAsJson);
}

static ICoreWebView2CallDevToolsProtocolMethodCompletedHandlerVtbl CallDevToolsProtocolMethodCompletedHandlerVtbl = {
	IUNKNOWN_INIT(CallDevToolsProtocolMethodCompletedHandler1)
	CallDevToolsProtocolMethodCompletedHandler_Invoke,
};

HRESULT CallDevToolsProtocolMethodCompletedHandler::Invoke(HRESULT errorCode, LPCWSTR returnObjectAsJson) {
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
	XPUSHs(wchar_to_scalar(returnObjectAsJson));

	PUTBACK;

	call_method("CallDevToolsProtocolMethodCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CallDevToolsProtocolMethodCompletedHandler::CallDevToolsProtocolMethodCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CallDevToolsProtocolMethodCompletedHandler{&CallDevToolsProtocolMethodCompletedHandlerVtbl} {}
CallDevToolsProtocolMethodCompletedHandler::CallDevToolsProtocolMethodCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "CallDevToolsProtocolMethodCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CallDevToolsProtocolMethodCompletedHandler, (ICoreWebView2CallDevToolsProtocolMethodCompletedHandler*)(new CallDevToolsProtocolMethodCompletedHandler1(this, &CallDevToolsProtocolMethodCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CallDevToolsProtocolMethodCompletedHandler::~CallDevToolsProtocolMethodCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CallDevToolsProtocolMethodCompletedHandler1 containing interface ICoreWebView2CallDevToolsProtocolMethodCompletedHandler");
}
#endif // DEBUG
	CallDevToolsProtocolMethodCompletedHandler1* subclass = static_cast<CallDevToolsProtocolMethodCompletedHandler1*>((ICoreWebView2CallDevToolsProtocolMethodCompletedHandler*)GetInterface(IID_ICoreWebView2CallDevToolsProtocolMethodCompletedHandler));
	delete subclass;
}
