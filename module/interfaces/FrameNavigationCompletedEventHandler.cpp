/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameNavigationCompletedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameNavigationCompletedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameNavigationCompletedEventHandler
 */

IUNKNOWN_DEFS(FrameNavigationCompletedEventHandler1, ICoreWebView2FrameNavigationCompletedEventHandler, FrameNavigationCompletedEventHandler)

static HRESULT STDMETHODCALLTYPE FrameNavigationCompletedEventHandler_Invoke(ICoreWebView2FrameNavigationCompletedEventHandler* This, ICoreWebView2Frame* sender, ICoreWebView2NavigationCompletedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameNavigationCompletedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameNavigationCompletedEventHandler::FrameNavigationCompletedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameNavigationCompletedEventHandlerVtbl FrameNavigationCompletedEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameNavigationCompletedEventHandler1)
	FrameNavigationCompletedEventHandler_Invoke,
};

HRESULT FrameNavigationCompletedEventHandler::Invoke(ICoreWebView2Frame* sender, ICoreWebView2NavigationCompletedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");
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

	call_method("FrameNavigationCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameNavigationCompletedEventHandler::FrameNavigationCompletedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameNavigationCompletedEventHandler{&FrameNavigationCompletedEventHandlerVtbl} {}
FrameNavigationCompletedEventHandler::FrameNavigationCompletedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameNavigationCompletedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameNavigationCompletedEventHandler, (ICoreWebView2FrameNavigationCompletedEventHandler*)(new FrameNavigationCompletedEventHandler1(this, &FrameNavigationCompletedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameNavigationCompletedEventHandler::~FrameNavigationCompletedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameNavigationCompletedEventHandler1 containing interface ICoreWebView2FrameNavigationCompletedEventHandler");
}
#endif // DEBUG
	FrameNavigationCompletedEventHandler1* subclass = static_cast<FrameNavigationCompletedEventHandler1*>((ICoreWebView2FrameNavigationCompletedEventHandler*)GetInterface(IID_ICoreWebView2FrameNavigationCompletedEventHandler));
	delete subclass;
}
