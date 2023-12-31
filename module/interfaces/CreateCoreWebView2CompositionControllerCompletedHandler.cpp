/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CreateCoreWebView2CompositionControllerCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CreateCoreWebView2CompositionControllerCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler
 */

IUNKNOWN_DEFS(CreateCoreWebView2CompositionControllerCompletedHandler1, ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler, CreateCoreWebView2CompositionControllerCompletedHandler)

static HRESULT STDMETHODCALLTYPE CreateCoreWebView2CompositionControllerCompletedHandler_Invoke(ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler* This, HRESULT errorCode, ICoreWebView2CompositionController* webView) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CreateCoreWebView2CompositionControllerCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CreateCoreWebView2CompositionControllerCompletedHandler::CreateCoreWebView2CompositionControllerCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, webView);
}

static ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandlerVtbl CreateCoreWebView2CompositionControllerCompletedHandlerVtbl = {
	IUNKNOWN_INIT(CreateCoreWebView2CompositionControllerCompletedHandler1)
	CreateCoreWebView2CompositionControllerCompletedHandler_Invoke,
};

HRESULT CreateCoreWebView2CompositionControllerCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2CompositionController* webView) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* webView_sv = sv_newmortal();
	create_perl_object(webView_sv, webView, "CoreWebView2::CompositionController");

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
	XPUSHs(webView_sv);

	PUTBACK;

	call_method("CreateCoreWebView2CompositionControllerCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CreateCoreWebView2CompositionControllerCompletedHandler::CreateCoreWebView2CompositionControllerCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler{&CreateCoreWebView2CompositionControllerCompletedHandlerVtbl} {}
CreateCoreWebView2CompositionControllerCompletedHandler::CreateCoreWebView2CompositionControllerCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "CreateCoreWebView2CompositionControllerCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler, (ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler*)(new CreateCoreWebView2CompositionControllerCompletedHandler1(this, &CreateCoreWebView2CompositionControllerCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CreateCoreWebView2CompositionControllerCompletedHandler::~CreateCoreWebView2CompositionControllerCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CreateCoreWebView2CompositionControllerCompletedHandler1 containing interface ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler");
}
#endif // DEBUG
	CreateCoreWebView2CompositionControllerCompletedHandler1* subclass = static_cast<CreateCoreWebView2CompositionControllerCompletedHandler1*>((ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler*)GetInterface(IID_ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler));
	delete subclass;
}
