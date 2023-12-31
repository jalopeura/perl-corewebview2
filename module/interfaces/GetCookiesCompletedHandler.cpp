/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "GetCookiesCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "GetCookiesCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2GetCookiesCompletedHandler
 */

IUNKNOWN_DEFS(GetCookiesCompletedHandler1, ICoreWebView2GetCookiesCompletedHandler, GetCookiesCompletedHandler)

static HRESULT STDMETHODCALLTYPE GetCookiesCompletedHandler_Invoke(ICoreWebView2GetCookiesCompletedHandler* This, HRESULT result, ICoreWebView2CookieList* cookieList) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetCookiesCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<GetCookiesCompletedHandler::GetCookiesCompletedHandler1*>(This)->Wrapper()->Invoke(result, cookieList);
}

static ICoreWebView2GetCookiesCompletedHandlerVtbl GetCookiesCompletedHandlerVtbl = {
	IUNKNOWN_INIT(GetCookiesCompletedHandler1)
	GetCookiesCompletedHandler_Invoke,
};

HRESULT GetCookiesCompletedHandler::Invoke(HRESULT result, ICoreWebView2CookieList* cookieList) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* result_sv;
	CHECK_ERROR(result, result_sv);
	SV* cookieList_sv = sv_newmortal();
	create_perl_object(cookieList_sv, cookieList, "CoreWebView2::CookieList");

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
	XPUSHs(result_sv);
	XPUSHs(cookieList_sv);

	PUTBACK;

	call_method("GetCookiesCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//GetCookiesCompletedHandler::GetCookiesCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2GetCookiesCompletedHandler{&GetCookiesCompletedHandlerVtbl} {}
GetCookiesCompletedHandler::GetCookiesCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "GetCookiesCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2GetCookiesCompletedHandler, (ICoreWebView2GetCookiesCompletedHandler*)(new GetCookiesCompletedHandler1(this, &GetCookiesCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

GetCookiesCompletedHandler::~GetCookiesCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass GetCookiesCompletedHandler1 containing interface ICoreWebView2GetCookiesCompletedHandler");
}
#endif // DEBUG
	GetCookiesCompletedHandler1* subclass = static_cast<GetCookiesCompletedHandler1*>((ICoreWebView2GetCookiesCompletedHandler*)GetInterface(IID_ICoreWebView2GetCookiesCompletedHandler));
	delete subclass;
}
