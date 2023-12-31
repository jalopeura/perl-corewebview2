/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ContainsFullScreenElementChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ContainsFullScreenElementChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ContainsFullScreenElementChangedEventHandler
 */

IUNKNOWN_DEFS(ContainsFullScreenElementChangedEventHandler1, ICoreWebView2ContainsFullScreenElementChangedEventHandler, ContainsFullScreenElementChangedEventHandler)

static HRESULT STDMETHODCALLTYPE ContainsFullScreenElementChangedEventHandler_Invoke(ICoreWebView2ContainsFullScreenElementChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ContainsFullScreenElementChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ContainsFullScreenElementChangedEventHandler::ContainsFullScreenElementChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ContainsFullScreenElementChangedEventHandlerVtbl ContainsFullScreenElementChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(ContainsFullScreenElementChangedEventHandler1)
	ContainsFullScreenElementChangedEventHandler_Invoke,
};

HRESULT ContainsFullScreenElementChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("ContainsFullScreenElementChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ContainsFullScreenElementChangedEventHandler::ContainsFullScreenElementChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ContainsFullScreenElementChangedEventHandler{&ContainsFullScreenElementChangedEventHandlerVtbl} {}
ContainsFullScreenElementChangedEventHandler::ContainsFullScreenElementChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ContainsFullScreenElementChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ContainsFullScreenElementChangedEventHandler, (ICoreWebView2ContainsFullScreenElementChangedEventHandler*)(new ContainsFullScreenElementChangedEventHandler1(this, &ContainsFullScreenElementChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ContainsFullScreenElementChangedEventHandler::~ContainsFullScreenElementChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ContainsFullScreenElementChangedEventHandler1 containing interface ICoreWebView2ContainsFullScreenElementChangedEventHandler");
}
#endif // DEBUG
	ContainsFullScreenElementChangedEventHandler1* subclass = static_cast<ContainsFullScreenElementChangedEventHandler1*>((ICoreWebView2ContainsFullScreenElementChangedEventHandler*)GetInterface(IID_ICoreWebView2ContainsFullScreenElementChangedEventHandler));
	delete subclass;
}
