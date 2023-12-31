/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "PrintToPdfCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "PrintToPdfCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2PrintToPdfCompletedHandler
 */

IUNKNOWN_DEFS(PrintToPdfCompletedHandler1, ICoreWebView2PrintToPdfCompletedHandler, PrintToPdfCompletedHandler)

static HRESULT STDMETHODCALLTYPE PrintToPdfCompletedHandler_Invoke(ICoreWebView2PrintToPdfCompletedHandler* This, HRESULT errorCode, BOOL isSuccessful) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("PrintToPdfCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<PrintToPdfCompletedHandler::PrintToPdfCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, isSuccessful);
}

static ICoreWebView2PrintToPdfCompletedHandlerVtbl PrintToPdfCompletedHandlerVtbl = {
	IUNKNOWN_INIT(PrintToPdfCompletedHandler1)
	PrintToPdfCompletedHandler_Invoke,
};

HRESULT PrintToPdfCompletedHandler::Invoke(HRESULT errorCode, BOOL isSuccessful) {
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

	call_method("PrintToPdfCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//PrintToPdfCompletedHandler::PrintToPdfCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2PrintToPdfCompletedHandler{&PrintToPdfCompletedHandlerVtbl} {}
PrintToPdfCompletedHandler::PrintToPdfCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "PrintToPdfCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2PrintToPdfCompletedHandler, (ICoreWebView2PrintToPdfCompletedHandler*)(new PrintToPdfCompletedHandler1(this, &PrintToPdfCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

PrintToPdfCompletedHandler::~PrintToPdfCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass PrintToPdfCompletedHandler1 containing interface ICoreWebView2PrintToPdfCompletedHandler");
}
#endif // DEBUG
	PrintToPdfCompletedHandler1* subclass = static_cast<PrintToPdfCompletedHandler1*>((ICoreWebView2PrintToPdfCompletedHandler*)GetInterface(IID_ICoreWebView2PrintToPdfCompletedHandler));
	delete subclass;
}
