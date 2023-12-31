/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "PrintToPdfStreamCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "PrintToPdfStreamCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2PrintToPdfStreamCompletedHandler
 */

IUNKNOWN_DEFS(PrintToPdfStreamCompletedHandler1, ICoreWebView2PrintToPdfStreamCompletedHandler, PrintToPdfStreamCompletedHandler)

static HRESULT STDMETHODCALLTYPE PrintToPdfStreamCompletedHandler_Invoke(ICoreWebView2PrintToPdfStreamCompletedHandler* This, HRESULT errorCode, IStream* pdfStream) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("PrintToPdfStreamCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<PrintToPdfStreamCompletedHandler::PrintToPdfStreamCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, pdfStream);
}

static ICoreWebView2PrintToPdfStreamCompletedHandlerVtbl PrintToPdfStreamCompletedHandlerVtbl = {
	IUNKNOWN_INIT(PrintToPdfStreamCompletedHandler1)
	PrintToPdfStreamCompletedHandler_Invoke,
};

HRESULT PrintToPdfStreamCompletedHandler::Invoke(HRESULT errorCode, IStream* pdfStream) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* pdfStream_sv = stream_to_scalar(pdfStream);
/*
	SV* pdfStream_sv = sv_newmortal();
WARN("About to call create_perl_object (%p)", pdfStream_sv);
	create_perl_object(pdfStream_sv, pdfStream, "CoreWebView2::Helper::Stream");
WARN("Back from create_perl_object");
*/
	sv_2mortal(pdfStream_sv);

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
	XPUSHs(pdfStream_sv);

	PUTBACK;

	call_method("PrintToPdfStreamCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//PrintToPdfStreamCompletedHandler::PrintToPdfStreamCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2PrintToPdfStreamCompletedHandler{&PrintToPdfStreamCompletedHandlerVtbl} {}
PrintToPdfStreamCompletedHandler::PrintToPdfStreamCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "PrintToPdfStreamCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2PrintToPdfStreamCompletedHandler, (ICoreWebView2PrintToPdfStreamCompletedHandler*)(new PrintToPdfStreamCompletedHandler1(this, &PrintToPdfStreamCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

PrintToPdfStreamCompletedHandler::~PrintToPdfStreamCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass PrintToPdfStreamCompletedHandler1 containing interface ICoreWebView2PrintToPdfStreamCompletedHandler");
}
#endif // DEBUG
	PrintToPdfStreamCompletedHandler1* subclass = static_cast<PrintToPdfStreamCompletedHandler1*>((ICoreWebView2PrintToPdfStreamCompletedHandler*)GetInterface(IID_ICoreWebView2PrintToPdfStreamCompletedHandler));
	delete subclass;
}
