/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "NavigationCompletedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "NavigationCompletedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2NavigationCompletedEventHandler
 */

IUNKNOWN_DEFS(NavigationCompletedEventHandler1, ICoreWebView2NavigationCompletedEventHandler, NavigationCompletedEventHandler)

static HRESULT STDMETHODCALLTYPE NavigationCompletedEventHandler_Invoke(ICoreWebView2NavigationCompletedEventHandler* This, ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("NavigationCompletedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<NavigationCompletedEventHandler::NavigationCompletedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2NavigationCompletedEventHandlerVtbl NavigationCompletedEventHandlerVtbl = {
	IUNKNOWN_INIT(NavigationCompletedEventHandler1)
	NavigationCompletedEventHandler_Invoke,
};

HRESULT NavigationCompletedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::NavigationCompletedEventArgs");

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

	call_method("NavigationCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//NavigationCompletedEventHandler::NavigationCompletedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2NavigationCompletedEventHandler{&NavigationCompletedEventHandlerVtbl} {}
NavigationCompletedEventHandler::NavigationCompletedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "NavigationCompletedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2NavigationCompletedEventHandler, (ICoreWebView2NavigationCompletedEventHandler*)(new NavigationCompletedEventHandler1(this, &NavigationCompletedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

NavigationCompletedEventHandler::~NavigationCompletedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass NavigationCompletedEventHandler1 containing interface ICoreWebView2NavigationCompletedEventHandler");
}
#endif // DEBUG
	NavigationCompletedEventHandler1* subclass = static_cast<NavigationCompletedEventHandler1*>((ICoreWebView2NavigationCompletedEventHandler*)GetInterface(IID_ICoreWebView2NavigationCompletedEventHandler));
	delete subclass;
}
