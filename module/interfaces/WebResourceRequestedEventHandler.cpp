/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "WebResourceRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "WebResourceRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2WebResourceRequestedEventHandler
 */

IUNKNOWN_DEFS(WebResourceRequestedEventHandler1, ICoreWebView2WebResourceRequestedEventHandler, WebResourceRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE WebResourceRequestedEventHandler_Invoke(ICoreWebView2WebResourceRequestedEventHandler* This, ICoreWebView2* sender, ICoreWebView2WebResourceRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("WebResourceRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<WebResourceRequestedEventHandler::WebResourceRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2WebResourceRequestedEventHandlerVtbl WebResourceRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(WebResourceRequestedEventHandler1)
	WebResourceRequestedEventHandler_Invoke,
};

HRESULT WebResourceRequestedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2WebResourceRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::WebResourceRequestedEventArgs");

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

	call_method("WebResourceRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//WebResourceRequestedEventHandler::WebResourceRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2WebResourceRequestedEventHandler{&WebResourceRequestedEventHandlerVtbl} {}
WebResourceRequestedEventHandler::WebResourceRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "WebResourceRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2WebResourceRequestedEventHandler, (ICoreWebView2WebResourceRequestedEventHandler*)(new WebResourceRequestedEventHandler1(this, &WebResourceRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

WebResourceRequestedEventHandler::~WebResourceRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass WebResourceRequestedEventHandler1 containing interface ICoreWebView2WebResourceRequestedEventHandler");
}
#endif // DEBUG
	WebResourceRequestedEventHandler1* subclass = static_cast<WebResourceRequestedEventHandler1*>((ICoreWebView2WebResourceRequestedEventHandler*)GetInterface(IID_ICoreWebView2WebResourceRequestedEventHandler));
	delete subclass;
}
