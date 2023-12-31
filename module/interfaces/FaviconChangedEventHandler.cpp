/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FaviconChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FaviconChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FaviconChangedEventHandler
 */

IUNKNOWN_DEFS(FaviconChangedEventHandler1, ICoreWebView2FaviconChangedEventHandler, FaviconChangedEventHandler)

static HRESULT STDMETHODCALLTYPE FaviconChangedEventHandler_Invoke(ICoreWebView2FaviconChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FaviconChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FaviconChangedEventHandler::FaviconChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FaviconChangedEventHandlerVtbl FaviconChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(FaviconChangedEventHandler1)
	FaviconChangedEventHandler_Invoke,
};

HRESULT FaviconChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("FaviconChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FaviconChangedEventHandler::FaviconChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FaviconChangedEventHandler{&FaviconChangedEventHandlerVtbl} {}
FaviconChangedEventHandler::FaviconChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FaviconChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FaviconChangedEventHandler, (ICoreWebView2FaviconChangedEventHandler*)(new FaviconChangedEventHandler1(this, &FaviconChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FaviconChangedEventHandler::~FaviconChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FaviconChangedEventHandler1 containing interface ICoreWebView2FaviconChangedEventHandler");
}
#endif // DEBUG
	FaviconChangedEventHandler1* subclass = static_cast<FaviconChangedEventHandler1*>((ICoreWebView2FaviconChangedEventHandler*)GetInterface(IID_ICoreWebView2FaviconChangedEventHandler));
	delete subclass;
}
