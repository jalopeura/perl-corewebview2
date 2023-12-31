/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "NavigationStartingEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "NavigationStartingEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2NavigationStartingEventHandler
 */

IUNKNOWN_DEFS(NavigationStartingEventHandler1, ICoreWebView2NavigationStartingEventHandler, NavigationStartingEventHandler)

static HRESULT STDMETHODCALLTYPE NavigationStartingEventHandler_Invoke(ICoreWebView2NavigationStartingEventHandler* This, ICoreWebView2* sender, ICoreWebView2NavigationStartingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("NavigationStartingEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<NavigationStartingEventHandler::NavigationStartingEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2NavigationStartingEventHandlerVtbl NavigationStartingEventHandlerVtbl = {
	IUNKNOWN_INIT(NavigationStartingEventHandler1)
	NavigationStartingEventHandler_Invoke,
};

HRESULT NavigationStartingEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2NavigationStartingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::NavigationStartingEventArgs");

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

	call_method("NavigationStarting", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//NavigationStartingEventHandler::NavigationStartingEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2NavigationStartingEventHandler{&NavigationStartingEventHandlerVtbl} {}
NavigationStartingEventHandler::NavigationStartingEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "NavigationStartingEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2NavigationStartingEventHandler, (ICoreWebView2NavigationStartingEventHandler*)(new NavigationStartingEventHandler1(this, &NavigationStartingEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

NavigationStartingEventHandler::~NavigationStartingEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass NavigationStartingEventHandler1 containing interface ICoreWebView2NavigationStartingEventHandler");
}
#endif // DEBUG
	NavigationStartingEventHandler1* subclass = static_cast<NavigationStartingEventHandler1*>((ICoreWebView2NavigationStartingEventHandler*)GetInterface(IID_ICoreWebView2NavigationStartingEventHandler));
	delete subclass;
}
