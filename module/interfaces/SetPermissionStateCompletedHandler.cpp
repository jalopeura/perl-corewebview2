/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "SetPermissionStateCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "SetPermissionStateCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2SetPermissionStateCompletedHandler
 */

IUNKNOWN_DEFS(SetPermissionStateCompletedHandler1, ICoreWebView2SetPermissionStateCompletedHandler, SetPermissionStateCompletedHandler)

static HRESULT STDMETHODCALLTYPE SetPermissionStateCompletedHandler_Invoke(ICoreWebView2SetPermissionStateCompletedHandler* This, HRESULT errorCode) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SetPermissionStateCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<SetPermissionStateCompletedHandler::SetPermissionStateCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode);
}

static ICoreWebView2SetPermissionStateCompletedHandlerVtbl SetPermissionStateCompletedHandlerVtbl = {
	IUNKNOWN_INIT(SetPermissionStateCompletedHandler1)
	SetPermissionStateCompletedHandler_Invoke,
};

HRESULT SetPermissionStateCompletedHandler::Invoke(HRESULT errorCode) {
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

	call_method("SetPermissionStateCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//SetPermissionStateCompletedHandler::SetPermissionStateCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2SetPermissionStateCompletedHandler{&SetPermissionStateCompletedHandlerVtbl} {}
SetPermissionStateCompletedHandler::SetPermissionStateCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "SetPermissionStateCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2SetPermissionStateCompletedHandler, (ICoreWebView2SetPermissionStateCompletedHandler*)(new SetPermissionStateCompletedHandler1(this, &SetPermissionStateCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

SetPermissionStateCompletedHandler::~SetPermissionStateCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass SetPermissionStateCompletedHandler1 containing interface ICoreWebView2SetPermissionStateCompletedHandler");
}
#endif // DEBUG
	SetPermissionStateCompletedHandler1* subclass = static_cast<SetPermissionStateCompletedHandler1*>((ICoreWebView2SetPermissionStateCompletedHandler*)GetInterface(IID_ICoreWebView2SetPermissionStateCompletedHandler));
	delete subclass;
}
