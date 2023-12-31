/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CreateCoreWebView2EnvironmentCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CreateCoreWebView2EnvironmentCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler
 */

IUNKNOWN_DEFS(CreateCoreWebView2EnvironmentCompletedHandler1, ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler, CreateCoreWebView2EnvironmentCompletedHandler)

static HRESULT STDMETHODCALLTYPE CreateCoreWebView2EnvironmentCompletedHandler_Invoke(ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* This, HRESULT errorCode, ICoreWebView2Environment* createdEnvironment) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CreateCoreWebView2EnvironmentCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CreateCoreWebView2EnvironmentCompletedHandler::CreateCoreWebView2EnvironmentCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, createdEnvironment);
}

static ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandlerVtbl CreateCoreWebView2EnvironmentCompletedHandlerVtbl = {
	IUNKNOWN_INIT(CreateCoreWebView2EnvironmentCompletedHandler1)
	CreateCoreWebView2EnvironmentCompletedHandler_Invoke,
};

HRESULT CreateCoreWebView2EnvironmentCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2Environment* createdEnvironment) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* createdEnvironment_sv = sv_newmortal();
	create_perl_object(createdEnvironment_sv, createdEnvironment, "CoreWebView2::Environment");

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
	XPUSHs(createdEnvironment_sv);

	PUTBACK;

	call_method("CreateCoreWebView2EnvironmentCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CreateCoreWebView2EnvironmentCompletedHandler::CreateCoreWebView2EnvironmentCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler{&CreateCoreWebView2EnvironmentCompletedHandlerVtbl} {}
CreateCoreWebView2EnvironmentCompletedHandler::CreateCoreWebView2EnvironmentCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "CreateCoreWebView2EnvironmentCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler, (ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler*)(new CreateCoreWebView2EnvironmentCompletedHandler1(this, &CreateCoreWebView2EnvironmentCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CreateCoreWebView2EnvironmentCompletedHandler::~CreateCoreWebView2EnvironmentCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CreateCoreWebView2EnvironmentCompletedHandler1 containing interface ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler");
}
#endif // DEBUG
	CreateCoreWebView2EnvironmentCompletedHandler1* subclass = static_cast<CreateCoreWebView2EnvironmentCompletedHandler1*>((ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler*)GetInterface(IID_ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler));
	delete subclass;
}
