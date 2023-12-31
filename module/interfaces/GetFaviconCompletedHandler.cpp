/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "GetFaviconCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "GetFaviconCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2GetFaviconCompletedHandler
 */

IUNKNOWN_DEFS(GetFaviconCompletedHandler1, ICoreWebView2GetFaviconCompletedHandler, GetFaviconCompletedHandler)

static HRESULT STDMETHODCALLTYPE GetFaviconCompletedHandler_Invoke(ICoreWebView2GetFaviconCompletedHandler* This, HRESULT errorCode, IStream* faviconStream) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetFaviconCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<GetFaviconCompletedHandler::GetFaviconCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, faviconStream);
}

static ICoreWebView2GetFaviconCompletedHandlerVtbl GetFaviconCompletedHandlerVtbl = {
	IUNKNOWN_INIT(GetFaviconCompletedHandler1)
	GetFaviconCompletedHandler_Invoke,
};

HRESULT GetFaviconCompletedHandler::Invoke(HRESULT errorCode, IStream* faviconStream) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* faviconStream_sv = stream_to_scalar(faviconStream);
/*
	SV* faviconStream_sv = sv_newmortal();
WARN("About to call create_perl_object (%p)", faviconStream_sv);
	create_perl_object(faviconStream_sv, faviconStream, "CoreWebView2::Helper::Stream");
WARN("Back from create_perl_object");
*/
	sv_2mortal(faviconStream_sv);

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
	XPUSHs(faviconStream_sv);

	PUTBACK;

	call_method("GetFaviconCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//GetFaviconCompletedHandler::GetFaviconCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2GetFaviconCompletedHandler{&GetFaviconCompletedHandlerVtbl} {}
GetFaviconCompletedHandler::GetFaviconCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "GetFaviconCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2GetFaviconCompletedHandler, (ICoreWebView2GetFaviconCompletedHandler*)(new GetFaviconCompletedHandler1(this, &GetFaviconCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

GetFaviconCompletedHandler::~GetFaviconCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass GetFaviconCompletedHandler1 containing interface ICoreWebView2GetFaviconCompletedHandler");
}
#endif // DEBUG
	GetFaviconCompletedHandler1* subclass = static_cast<GetFaviconCompletedHandler1*>((ICoreWebView2GetFaviconCompletedHandler*)GetInterface(IID_ICoreWebView2GetFaviconCompletedHandler));
	delete subclass;
}
