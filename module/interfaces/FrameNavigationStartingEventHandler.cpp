/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameNavigationStartingEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameNavigationStartingEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameNavigationStartingEventHandler
 */

IUNKNOWN_DEFS(FrameNavigationStartingEventHandler1, ICoreWebView2FrameNavigationStartingEventHandler, FrameNavigationStartingEventHandler)

static HRESULT STDMETHODCALLTYPE FrameNavigationStartingEventHandler_Invoke(ICoreWebView2FrameNavigationStartingEventHandler* This, ICoreWebView2Frame* sender, ICoreWebView2NavigationStartingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameNavigationStartingEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameNavigationStartingEventHandler::FrameNavigationStartingEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameNavigationStartingEventHandlerVtbl FrameNavigationStartingEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameNavigationStartingEventHandler1)
	FrameNavigationStartingEventHandler_Invoke,
};

HRESULT FrameNavigationStartingEventHandler::Invoke(ICoreWebView2Frame* sender, ICoreWebView2NavigationStartingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");
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

	call_method("FrameNavigationStarting", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameNavigationStartingEventHandler::FrameNavigationStartingEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameNavigationStartingEventHandler{&FrameNavigationStartingEventHandlerVtbl} {}
FrameNavigationStartingEventHandler::FrameNavigationStartingEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameNavigationStartingEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameNavigationStartingEventHandler, (ICoreWebView2FrameNavigationStartingEventHandler*)(new FrameNavigationStartingEventHandler1(this, &FrameNavigationStartingEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameNavigationStartingEventHandler::~FrameNavigationStartingEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameNavigationStartingEventHandler1 containing interface ICoreWebView2FrameNavigationStartingEventHandler");
}
#endif // DEBUG
	FrameNavigationStartingEventHandler1* subclass = static_cast<FrameNavigationStartingEventHandler1*>((ICoreWebView2FrameNavigationStartingEventHandler*)GetInterface(IID_ICoreWebView2FrameNavigationStartingEventHandler));
	delete subclass;
}
