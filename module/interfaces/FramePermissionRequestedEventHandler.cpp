/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FramePermissionRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FramePermissionRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FramePermissionRequestedEventHandler
 */

IUNKNOWN_DEFS(FramePermissionRequestedEventHandler1, ICoreWebView2FramePermissionRequestedEventHandler, FramePermissionRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE FramePermissionRequestedEventHandler_Invoke(ICoreWebView2FramePermissionRequestedEventHandler* This, ICoreWebView2Frame* sender, ICoreWebView2PermissionRequestedEventArgs2* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FramePermissionRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FramePermissionRequestedEventHandler::FramePermissionRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FramePermissionRequestedEventHandlerVtbl FramePermissionRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(FramePermissionRequestedEventHandler1)
	FramePermissionRequestedEventHandler_Invoke,
};

HRESULT FramePermissionRequestedEventHandler::Invoke(ICoreWebView2Frame* sender, ICoreWebView2PermissionRequestedEventArgs2* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::PermissionRequestedEventArgs");

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

	call_method("FramePermissionRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FramePermissionRequestedEventHandler::FramePermissionRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FramePermissionRequestedEventHandler{&FramePermissionRequestedEventHandlerVtbl} {}
FramePermissionRequestedEventHandler::FramePermissionRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FramePermissionRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FramePermissionRequestedEventHandler, (ICoreWebView2FramePermissionRequestedEventHandler*)(new FramePermissionRequestedEventHandler1(this, &FramePermissionRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FramePermissionRequestedEventHandler::~FramePermissionRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FramePermissionRequestedEventHandler1 containing interface ICoreWebView2FramePermissionRequestedEventHandler");
}
#endif // DEBUG
	FramePermissionRequestedEventHandler1* subclass = static_cast<FramePermissionRequestedEventHandler1*>((ICoreWebView2FramePermissionRequestedEventHandler*)GetInterface(IID_ICoreWebView2FramePermissionRequestedEventHandler));
	delete subclass;
}
