/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CapturePreviewCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CapturePreviewCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CapturePreviewCompletedHandler
 */

IUNKNOWN_DEFS(CapturePreviewCompletedHandler1, ICoreWebView2CapturePreviewCompletedHandler, CapturePreviewCompletedHandler)

static HRESULT STDMETHODCALLTYPE CapturePreviewCompletedHandler_Invoke(ICoreWebView2CapturePreviewCompletedHandler* This, HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CapturePreviewCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CapturePreviewCompletedHandler::CapturePreviewCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode);
}

static ICoreWebView2CapturePreviewCompletedHandlerVtbl CapturePreviewCompletedHandlerVtbl = {
	IUNKNOWN_INIT(CapturePreviewCompletedHandler1)
	CapturePreviewCompletedHandler_Invoke,
};

HRESULT CapturePreviewCompletedHandler::Invoke(HRESULT errorCode) {
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

	call_method("CapturePreviewCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CapturePreviewCompletedHandler::CapturePreviewCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CapturePreviewCompletedHandler{&CapturePreviewCompletedHandlerVtbl} {}
CapturePreviewCompletedHandler::CapturePreviewCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "CapturePreviewCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CapturePreviewCompletedHandler, (ICoreWebView2CapturePreviewCompletedHandler*)(new CapturePreviewCompletedHandler1(this, &CapturePreviewCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CapturePreviewCompletedHandler::~CapturePreviewCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CapturePreviewCompletedHandler1 containing interface ICoreWebView2CapturePreviewCompletedHandler");
}
#endif // DEBUG
	CapturePreviewCompletedHandler1* subclass = static_cast<CapturePreviewCompletedHandler1*>((ICoreWebView2CapturePreviewCompletedHandler*)GetInterface(IID_ICoreWebView2CapturePreviewCompletedHandler));
	delete subclass;
}
