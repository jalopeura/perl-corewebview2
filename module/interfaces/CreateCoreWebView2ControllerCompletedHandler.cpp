/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CreateCoreWebView2ControllerCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CreateCoreWebView2ControllerCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CreateCoreWebView2ControllerCompletedHandler
 */

IUNKNOWN_DEFS(CreateCoreWebView2ControllerCompletedHandler1, ICoreWebView2CreateCoreWebView2ControllerCompletedHandler, CreateCoreWebView2ControllerCompletedHandler)

static HRESULT STDMETHODCALLTYPE CreateCoreWebView2ControllerCompletedHandler_Invoke(ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* This, HRESULT errorCode, ICoreWebView2Controller* createdController) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CreateCoreWebView2ControllerCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CreateCoreWebView2ControllerCompletedHandler::CreateCoreWebView2ControllerCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, createdController);
}

static ICoreWebView2CreateCoreWebView2ControllerCompletedHandlerVtbl CreateCoreWebView2ControllerCompletedHandlerVtbl = {
	IUNKNOWN_INIT(CreateCoreWebView2ControllerCompletedHandler1)
	CreateCoreWebView2ControllerCompletedHandler_Invoke,
};

HRESULT CreateCoreWebView2ControllerCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2Controller* createdController) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* createdController_sv = sv_newmortal();
	create_perl_object(createdController_sv, createdController, "CoreWebView2::Controller");

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
	XPUSHs(createdController_sv);

	PUTBACK;

	call_method("CreateCoreWebView2ControllerCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CreateCoreWebView2ControllerCompletedHandler::CreateCoreWebView2ControllerCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CreateCoreWebView2ControllerCompletedHandler{&CreateCoreWebView2ControllerCompletedHandlerVtbl} {}
CreateCoreWebView2ControllerCompletedHandler::CreateCoreWebView2ControllerCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "CreateCoreWebView2ControllerCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CreateCoreWebView2ControllerCompletedHandler, (ICoreWebView2CreateCoreWebView2ControllerCompletedHandler*)(new CreateCoreWebView2ControllerCompletedHandler1(this, &CreateCoreWebView2ControllerCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CreateCoreWebView2ControllerCompletedHandler::~CreateCoreWebView2ControllerCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CreateCoreWebView2ControllerCompletedHandler1 containing interface ICoreWebView2CreateCoreWebView2ControllerCompletedHandler");
}
#endif // DEBUG
	CreateCoreWebView2ControllerCompletedHandler1* subclass = static_cast<CreateCoreWebView2ControllerCompletedHandler1*>((ICoreWebView2CreateCoreWebView2ControllerCompletedHandler*)GetInterface(IID_ICoreWebView2CreateCoreWebView2ControllerCompletedHandler));
	delete subclass;
}
