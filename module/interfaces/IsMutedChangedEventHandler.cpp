/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "IsMutedChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "IsMutedChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2IsMutedChangedEventHandler
 */

IUNKNOWN_DEFS(IsMutedChangedEventHandler1, ICoreWebView2IsMutedChangedEventHandler, IsMutedChangedEventHandler)

static HRESULT STDMETHODCALLTYPE IsMutedChangedEventHandler_Invoke(ICoreWebView2IsMutedChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IsMutedChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<IsMutedChangedEventHandler::IsMutedChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2IsMutedChangedEventHandlerVtbl IsMutedChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(IsMutedChangedEventHandler1)
	IsMutedChangedEventHandler_Invoke,
};

HRESULT IsMutedChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("IsMutedChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//IsMutedChangedEventHandler::IsMutedChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2IsMutedChangedEventHandler{&IsMutedChangedEventHandlerVtbl} {}
IsMutedChangedEventHandler::IsMutedChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "IsMutedChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2IsMutedChangedEventHandler, (ICoreWebView2IsMutedChangedEventHandler*)(new IsMutedChangedEventHandler1(this, &IsMutedChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

IsMutedChangedEventHandler::~IsMutedChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass IsMutedChangedEventHandler1 containing interface ICoreWebView2IsMutedChangedEventHandler");
}
#endif // DEBUG
	IsMutedChangedEventHandler1* subclass = static_cast<IsMutedChangedEventHandler1*>((ICoreWebView2IsMutedChangedEventHandler*)GetInterface(IID_ICoreWebView2IsMutedChangedEventHandler));
	delete subclass;
}
