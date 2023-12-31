/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "WebResourceResponseViewGetContentCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "WebResourceResponseViewGetContentCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2WebResourceResponseViewGetContentCompletedHandler
 */

IUNKNOWN_DEFS(WebResourceResponseViewGetContentCompletedHandler1, ICoreWebView2WebResourceResponseViewGetContentCompletedHandler, WebResourceResponseViewGetContentCompletedHandler)

static HRESULT STDMETHODCALLTYPE WebResourceResponseViewGetContentCompletedHandler_Invoke(ICoreWebView2WebResourceResponseViewGetContentCompletedHandler* This, HRESULT errorCode, IStream* content) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("WebResourceResponseViewGetContentCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<WebResourceResponseViewGetContentCompletedHandler::WebResourceResponseViewGetContentCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, content);
}

static ICoreWebView2WebResourceResponseViewGetContentCompletedHandlerVtbl WebResourceResponseViewGetContentCompletedHandlerVtbl = {
	IUNKNOWN_INIT(WebResourceResponseViewGetContentCompletedHandler1)
	WebResourceResponseViewGetContentCompletedHandler_Invoke,
};

HRESULT WebResourceResponseViewGetContentCompletedHandler::Invoke(HRESULT errorCode, IStream* content) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* content_sv = stream_to_scalar(content);
/*
	SV* content_sv = sv_newmortal();
WARN("About to call create_perl_object (%p)", content_sv);
	create_perl_object(content_sv, content, "CoreWebView2::Helper::Stream");
WARN("Back from create_perl_object");
*/
	sv_2mortal(content_sv);

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
	XPUSHs(content_sv);

	PUTBACK;

	call_method("WebResourceResponseViewGetContentCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//WebResourceResponseViewGetContentCompletedHandler::WebResourceResponseViewGetContentCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2WebResourceResponseViewGetContentCompletedHandler{&WebResourceResponseViewGetContentCompletedHandlerVtbl} {}
WebResourceResponseViewGetContentCompletedHandler::WebResourceResponseViewGetContentCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "WebResourceResponseViewGetContentCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2WebResourceResponseViewGetContentCompletedHandler, (ICoreWebView2WebResourceResponseViewGetContentCompletedHandler*)(new WebResourceResponseViewGetContentCompletedHandler1(this, &WebResourceResponseViewGetContentCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

WebResourceResponseViewGetContentCompletedHandler::~WebResourceResponseViewGetContentCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass WebResourceResponseViewGetContentCompletedHandler1 containing interface ICoreWebView2WebResourceResponseViewGetContentCompletedHandler");
}
#endif // DEBUG
	WebResourceResponseViewGetContentCompletedHandler1* subclass = static_cast<WebResourceResponseViewGetContentCompletedHandler1*>((ICoreWebView2WebResourceResponseViewGetContentCompletedHandler*)GetInterface(IID_ICoreWebView2WebResourceResponseViewGetContentCompletedHandler));
	delete subclass;
}
