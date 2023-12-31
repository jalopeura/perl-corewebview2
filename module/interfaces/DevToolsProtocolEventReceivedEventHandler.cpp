/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "DevToolsProtocolEventReceivedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "DevToolsProtocolEventReceivedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2DevToolsProtocolEventReceivedEventHandler
 */

IUNKNOWN_DEFS(DevToolsProtocolEventReceivedEventHandler1, ICoreWebView2DevToolsProtocolEventReceivedEventHandler, DevToolsProtocolEventReceivedEventHandler)

static HRESULT STDMETHODCALLTYPE DevToolsProtocolEventReceivedEventHandler_Invoke(ICoreWebView2DevToolsProtocolEventReceivedEventHandler* This, ICoreWebView2* sender, ICoreWebView2DevToolsProtocolEventReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("DevToolsProtocolEventReceivedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<DevToolsProtocolEventReceivedEventHandler::DevToolsProtocolEventReceivedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2DevToolsProtocolEventReceivedEventHandlerVtbl DevToolsProtocolEventReceivedEventHandlerVtbl = {
	IUNKNOWN_INIT(DevToolsProtocolEventReceivedEventHandler1)
	DevToolsProtocolEventReceivedEventHandler_Invoke,
};

HRESULT DevToolsProtocolEventReceivedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2DevToolsProtocolEventReceivedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::DevToolsProtocolEventReceivedEventArgs");

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

	call_method("DevToolsProtocolEventReceived", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//DevToolsProtocolEventReceivedEventHandler::DevToolsProtocolEventReceivedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2DevToolsProtocolEventReceivedEventHandler{&DevToolsProtocolEventReceivedEventHandlerVtbl} {}
DevToolsProtocolEventReceivedEventHandler::DevToolsProtocolEventReceivedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "DevToolsProtocolEventReceivedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2DevToolsProtocolEventReceivedEventHandler, (ICoreWebView2DevToolsProtocolEventReceivedEventHandler*)(new DevToolsProtocolEventReceivedEventHandler1(this, &DevToolsProtocolEventReceivedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

DevToolsProtocolEventReceivedEventHandler::~DevToolsProtocolEventReceivedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass DevToolsProtocolEventReceivedEventHandler1 containing interface ICoreWebView2DevToolsProtocolEventReceivedEventHandler");
}
#endif // DEBUG
	DevToolsProtocolEventReceivedEventHandler1* subclass = static_cast<DevToolsProtocolEventReceivedEventHandler1*>((ICoreWebView2DevToolsProtocolEventReceivedEventHandler*)GetInterface(IID_ICoreWebView2DevToolsProtocolEventReceivedEventHandler));
	delete subclass;
}
