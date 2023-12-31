/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ExecuteScriptCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ExecuteScriptCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ExecuteScriptCompletedHandler
 */

IUNKNOWN_DEFS(ExecuteScriptCompletedHandler1, ICoreWebView2ExecuteScriptCompletedHandler, ExecuteScriptCompletedHandler)

static HRESULT STDMETHODCALLTYPE ExecuteScriptCompletedHandler_Invoke(ICoreWebView2ExecuteScriptCompletedHandler* This, HRESULT errorCode, LPCWSTR resultObjectAsJson) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ExecuteScriptCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ExecuteScriptCompletedHandler::ExecuteScriptCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, resultObjectAsJson);
}

static ICoreWebView2ExecuteScriptCompletedHandlerVtbl ExecuteScriptCompletedHandlerVtbl = {
	IUNKNOWN_INIT(ExecuteScriptCompletedHandler1)
	ExecuteScriptCompletedHandler_Invoke,
};

HRESULT ExecuteScriptCompletedHandler::Invoke(HRESULT errorCode, LPCWSTR resultObjectAsJson) {
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
	XPUSHs(wchar_to_scalar(resultObjectAsJson));

	PUTBACK;

	call_method("ExecuteScriptCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ExecuteScriptCompletedHandler::ExecuteScriptCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ExecuteScriptCompletedHandler{&ExecuteScriptCompletedHandlerVtbl} {}
ExecuteScriptCompletedHandler::ExecuteScriptCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "ExecuteScriptCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ExecuteScriptCompletedHandler, (ICoreWebView2ExecuteScriptCompletedHandler*)(new ExecuteScriptCompletedHandler1(this, &ExecuteScriptCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ExecuteScriptCompletedHandler::~ExecuteScriptCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ExecuteScriptCompletedHandler1 containing interface ICoreWebView2ExecuteScriptCompletedHandler");
}
#endif // DEBUG
	ExecuteScriptCompletedHandler1* subclass = static_cast<ExecuteScriptCompletedHandler1*>((ICoreWebView2ExecuteScriptCompletedHandler*)GetInterface(IID_ICoreWebView2ExecuteScriptCompletedHandler));
	delete subclass;
}
