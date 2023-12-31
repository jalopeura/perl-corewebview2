/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "PrintCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "PrintCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2PrintCompletedHandler
 */

IUNKNOWN_DEFS(PrintCompletedHandler1, ICoreWebView2PrintCompletedHandler, PrintCompletedHandler)

static HRESULT STDMETHODCALLTYPE PrintCompletedHandler_Invoke(ICoreWebView2PrintCompletedHandler* This, HRESULT errorCode, COREWEBVIEW2_PRINT_STATUS printStatus) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("PrintCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<PrintCompletedHandler::PrintCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, printStatus);
}

static ICoreWebView2PrintCompletedHandlerVtbl PrintCompletedHandlerVtbl = {
	IUNKNOWN_INIT(PrintCompletedHandler1)
	PrintCompletedHandler_Invoke,
};

HRESULT PrintCompletedHandler::Invoke(HRESULT errorCode, COREWEBVIEW2_PRINT_STATUS printStatus) {
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
	mXPUSHu((COREWEBVIEW2_PRINT_STATUS)printStatus);

	PUTBACK;

	call_method("PrintCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//PrintCompletedHandler::PrintCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2PrintCompletedHandler{&PrintCompletedHandlerVtbl} {}
PrintCompletedHandler::PrintCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "PrintCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2PrintCompletedHandler, (ICoreWebView2PrintCompletedHandler*)(new PrintCompletedHandler1(this, &PrintCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

PrintCompletedHandler::~PrintCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass PrintCompletedHandler1 containing interface ICoreWebView2PrintCompletedHandler");
}
#endif // DEBUG
	PrintCompletedHandler1* subclass = static_cast<PrintCompletedHandler1*>((ICoreWebView2PrintCompletedHandler*)GetInterface(IID_ICoreWebView2PrintCompletedHandler));
	delete subclass;
}
