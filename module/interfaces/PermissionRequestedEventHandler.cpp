/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "PermissionRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "PermissionRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2PermissionRequestedEventHandler
 */

IUNKNOWN_DEFS(PermissionRequestedEventHandler1, ICoreWebView2PermissionRequestedEventHandler, PermissionRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE PermissionRequestedEventHandler_Invoke(ICoreWebView2PermissionRequestedEventHandler* This, ICoreWebView2* sender, ICoreWebView2PermissionRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("PermissionRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<PermissionRequestedEventHandler::PermissionRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2PermissionRequestedEventHandlerVtbl PermissionRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(PermissionRequestedEventHandler1)
	PermissionRequestedEventHandler_Invoke,
};

HRESULT PermissionRequestedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2PermissionRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
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

	call_method("PermissionRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//PermissionRequestedEventHandler::PermissionRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2PermissionRequestedEventHandler{&PermissionRequestedEventHandlerVtbl} {}
PermissionRequestedEventHandler::PermissionRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "PermissionRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2PermissionRequestedEventHandler, (ICoreWebView2PermissionRequestedEventHandler*)(new PermissionRequestedEventHandler1(this, &PermissionRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

PermissionRequestedEventHandler::~PermissionRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass PermissionRequestedEventHandler1 containing interface ICoreWebView2PermissionRequestedEventHandler");
}
#endif // DEBUG
	PermissionRequestedEventHandler1* subclass = static_cast<PermissionRequestedEventHandler1*>((ICoreWebView2PermissionRequestedEventHandler*)GetInterface(IID_ICoreWebView2PermissionRequestedEventHandler));
	delete subclass;
}
