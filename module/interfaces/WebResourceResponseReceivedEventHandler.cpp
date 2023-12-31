/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "WebResourceResponseReceivedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "WebResourceResponseReceivedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2WebResourceResponseReceivedEventHandler
 */

IUNKNOWN_DEFS(WebResourceResponseReceivedEventHandler1, ICoreWebView2WebResourceResponseReceivedEventHandler, WebResourceResponseReceivedEventHandler)

static HRESULT STDMETHODCALLTYPE WebResourceResponseReceivedEventHandler_Invoke(ICoreWebView2WebResourceResponseReceivedEventHandler* This, ICoreWebView2* sender, ICoreWebView2WebResourceResponseReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("WebResourceResponseReceivedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<WebResourceResponseReceivedEventHandler::WebResourceResponseReceivedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2WebResourceResponseReceivedEventHandlerVtbl WebResourceResponseReceivedEventHandlerVtbl = {
	IUNKNOWN_INIT(WebResourceResponseReceivedEventHandler1)
	WebResourceResponseReceivedEventHandler_Invoke,
};

HRESULT WebResourceResponseReceivedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2WebResourceResponseReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::WebResourceResponseReceivedEventArgs");

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
	XPUSHs(sender_sv);
	XPUSHs(args_sv);

	PUTBACK;

	call_method("WebResourceResponseReceived", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//WebResourceResponseReceivedEventHandler::WebResourceResponseReceivedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2WebResourceResponseReceivedEventHandler{&WebResourceResponseReceivedEventHandlerVtbl} {}
WebResourceResponseReceivedEventHandler::WebResourceResponseReceivedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "WebResourceResponseReceivedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2WebResourceResponseReceivedEventHandler, (ICoreWebView2WebResourceResponseReceivedEventHandler*)(new WebResourceResponseReceivedEventHandler1(this, &WebResourceResponseReceivedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

WebResourceResponseReceivedEventHandler::~WebResourceResponseReceivedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass WebResourceResponseReceivedEventHandler1 containing interface ICoreWebView2WebResourceResponseReceivedEventHandler");
}
#endif // DEBUG
	WebResourceResponseReceivedEventHandler1* subclass = static_cast<WebResourceResponseReceivedEventHandler1*>((ICoreWebView2WebResourceResponseReceivedEventHandler*)GetInterface(IID_ICoreWebView2WebResourceResponseReceivedEventHandler));
	delete subclass;
}
