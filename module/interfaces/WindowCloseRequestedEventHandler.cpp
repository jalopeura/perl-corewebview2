/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "WindowCloseRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "WindowCloseRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2WindowCloseRequestedEventHandler
 */

IUNKNOWN_DEFS(WindowCloseRequestedEventHandler1, ICoreWebView2WindowCloseRequestedEventHandler, WindowCloseRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE WindowCloseRequestedEventHandler_Invoke(ICoreWebView2WindowCloseRequestedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("WindowCloseRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<WindowCloseRequestedEventHandler::WindowCloseRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2WindowCloseRequestedEventHandlerVtbl WindowCloseRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(WindowCloseRequestedEventHandler1)
	WindowCloseRequestedEventHandler_Invoke,
};

HRESULT WindowCloseRequestedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");

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
	// args will be NULL

	PUTBACK;

	call_method("WindowCloseRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//WindowCloseRequestedEventHandler::WindowCloseRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2WindowCloseRequestedEventHandler{&WindowCloseRequestedEventHandlerVtbl} {}
WindowCloseRequestedEventHandler::WindowCloseRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "WindowCloseRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2WindowCloseRequestedEventHandler, (ICoreWebView2WindowCloseRequestedEventHandler*)(new WindowCloseRequestedEventHandler1(this, &WindowCloseRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

WindowCloseRequestedEventHandler::~WindowCloseRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass WindowCloseRequestedEventHandler1 containing interface ICoreWebView2WindowCloseRequestedEventHandler");
}
#endif // DEBUG
	WindowCloseRequestedEventHandler1* subclass = static_cast<WindowCloseRequestedEventHandler1*>((ICoreWebView2WindowCloseRequestedEventHandler*)GetInterface(IID_ICoreWebView2WindowCloseRequestedEventHandler));
	delete subclass;
}
