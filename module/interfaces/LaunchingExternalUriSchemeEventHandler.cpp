/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "LaunchingExternalUriSchemeEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "LaunchingExternalUriSchemeEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2LaunchingExternalUriSchemeEventHandler
 */

IUNKNOWN_DEFS(LaunchingExternalUriSchemeEventHandler1, ICoreWebView2LaunchingExternalUriSchemeEventHandler, LaunchingExternalUriSchemeEventHandler)

static HRESULT STDMETHODCALLTYPE LaunchingExternalUriSchemeEventHandler_Invoke(ICoreWebView2LaunchingExternalUriSchemeEventHandler* This, ICoreWebView2* sender, ICoreWebView2LaunchingExternalUriSchemeEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("LaunchingExternalUriSchemeEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<LaunchingExternalUriSchemeEventHandler::LaunchingExternalUriSchemeEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2LaunchingExternalUriSchemeEventHandlerVtbl LaunchingExternalUriSchemeEventHandlerVtbl = {
	IUNKNOWN_INIT(LaunchingExternalUriSchemeEventHandler1)
	LaunchingExternalUriSchemeEventHandler_Invoke,
};

HRESULT LaunchingExternalUriSchemeEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2LaunchingExternalUriSchemeEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::LaunchingExternalUriSchemeEventArgs");

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

	call_method("LaunchingExternalUriScheme", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//LaunchingExternalUriSchemeEventHandler::LaunchingExternalUriSchemeEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2LaunchingExternalUriSchemeEventHandler{&LaunchingExternalUriSchemeEventHandlerVtbl} {}
LaunchingExternalUriSchemeEventHandler::LaunchingExternalUriSchemeEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "LaunchingExternalUriSchemeEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2LaunchingExternalUriSchemeEventHandler, (ICoreWebView2LaunchingExternalUriSchemeEventHandler*)(new LaunchingExternalUriSchemeEventHandler1(this, &LaunchingExternalUriSchemeEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

LaunchingExternalUriSchemeEventHandler::~LaunchingExternalUriSchemeEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass LaunchingExternalUriSchemeEventHandler1 containing interface ICoreWebView2LaunchingExternalUriSchemeEventHandler");
}
#endif // DEBUG
	LaunchingExternalUriSchemeEventHandler1* subclass = static_cast<LaunchingExternalUriSchemeEventHandler1*>((ICoreWebView2LaunchingExternalUriSchemeEventHandler*)GetInterface(IID_ICoreWebView2LaunchingExternalUriSchemeEventHandler));
	delete subclass;
}
