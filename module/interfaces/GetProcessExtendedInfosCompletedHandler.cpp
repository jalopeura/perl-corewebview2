/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "GetProcessExtendedInfosCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "GetProcessExtendedInfosCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2GetProcessExtendedInfosCompletedHandler
 */

IUNKNOWN_DEFS(GetProcessExtendedInfosCompletedHandler1, ICoreWebView2GetProcessExtendedInfosCompletedHandler, GetProcessExtendedInfosCompletedHandler)

static HRESULT STDMETHODCALLTYPE GetProcessExtendedInfosCompletedHandler_Invoke(ICoreWebView2GetProcessExtendedInfosCompletedHandler* This, HRESULT errorCode, ICoreWebView2ProcessExtendedInfoCollection* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetProcessExtendedInfosCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<GetProcessExtendedInfosCompletedHandler::GetProcessExtendedInfosCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, value);
}

static ICoreWebView2GetProcessExtendedInfosCompletedHandlerVtbl GetProcessExtendedInfosCompletedHandlerVtbl = {
	IUNKNOWN_INIT(GetProcessExtendedInfosCompletedHandler1)
	GetProcessExtendedInfosCompletedHandler_Invoke,
};

HRESULT GetProcessExtendedInfosCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2ProcessExtendedInfoCollection* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* value_sv = sv_newmortal();
	create_perl_object(value_sv, value, "CoreWebView2::ProcessExtendedInfoCollection");

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
	XPUSHs(value_sv);

	PUTBACK;

	call_method("GetProcessExtendedInfosCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//GetProcessExtendedInfosCompletedHandler::GetProcessExtendedInfosCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2GetProcessExtendedInfosCompletedHandler{&GetProcessExtendedInfosCompletedHandlerVtbl} {}
GetProcessExtendedInfosCompletedHandler::GetProcessExtendedInfosCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "GetProcessExtendedInfosCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2GetProcessExtendedInfosCompletedHandler, (ICoreWebView2GetProcessExtendedInfosCompletedHandler*)(new GetProcessExtendedInfosCompletedHandler1(this, &GetProcessExtendedInfosCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

GetProcessExtendedInfosCompletedHandler::~GetProcessExtendedInfosCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass GetProcessExtendedInfosCompletedHandler1 containing interface ICoreWebView2GetProcessExtendedInfosCompletedHandler");
}
#endif // DEBUG
	GetProcessExtendedInfosCompletedHandler1* subclass = static_cast<GetProcessExtendedInfosCompletedHandler1*>((ICoreWebView2GetProcessExtendedInfosCompletedHandler*)GetInterface(IID_ICoreWebView2GetProcessExtendedInfosCompletedHandler));
	delete subclass;
}
