/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "WebMessageReceivedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "WebMessageReceivedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2WebMessageReceivedEventHandler
 */

IUNKNOWN_DEFS(WebMessageReceivedEventHandler1, ICoreWebView2WebMessageReceivedEventHandler, WebMessageReceivedEventHandler)

static HRESULT STDMETHODCALLTYPE WebMessageReceivedEventHandler_Invoke(ICoreWebView2WebMessageReceivedEventHandler* This, ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("WebMessageReceivedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<WebMessageReceivedEventHandler::WebMessageReceivedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2WebMessageReceivedEventHandlerVtbl WebMessageReceivedEventHandlerVtbl = {
	IUNKNOWN_INIT(WebMessageReceivedEventHandler1)
	WebMessageReceivedEventHandler_Invoke,
};

HRESULT WebMessageReceivedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::WebMessageReceivedEventArgs");

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

	call_method("WebMessageReceived", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//WebMessageReceivedEventHandler::WebMessageReceivedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2WebMessageReceivedEventHandler{&WebMessageReceivedEventHandlerVtbl} {}
WebMessageReceivedEventHandler::WebMessageReceivedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "WebMessageReceivedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2WebMessageReceivedEventHandler, (ICoreWebView2WebMessageReceivedEventHandler*)(new WebMessageReceivedEventHandler1(this, &WebMessageReceivedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

WebMessageReceivedEventHandler::~WebMessageReceivedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass WebMessageReceivedEventHandler1 containing interface ICoreWebView2WebMessageReceivedEventHandler");
}
#endif // DEBUG
	WebMessageReceivedEventHandler1* subclass = static_cast<WebMessageReceivedEventHandler1*>((ICoreWebView2WebMessageReceivedEventHandler*)GetInterface(IID_ICoreWebView2WebMessageReceivedEventHandler));
	delete subclass;
}
