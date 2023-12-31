/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FocusChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FocusChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FocusChangedEventHandler
 */

IUNKNOWN_DEFS(FocusChangedEventHandler1, ICoreWebView2FocusChangedEventHandler, FocusChangedEventHandler)

static HRESULT STDMETHODCALLTYPE FocusChangedEventHandler_Invoke(ICoreWebView2FocusChangedEventHandler* This, ICoreWebView2Controller* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FocusChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FocusChangedEventHandler::FocusChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FocusChangedEventHandlerVtbl FocusChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(FocusChangedEventHandler1)
	FocusChangedEventHandler_Invoke,
};

HRESULT FocusChangedEventHandler::Invoke(ICoreWebView2Controller* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Controller");

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

	call_method("FocusChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FocusChangedEventHandler::FocusChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FocusChangedEventHandler{&FocusChangedEventHandlerVtbl} {}
FocusChangedEventHandler::FocusChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FocusChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FocusChangedEventHandler, (ICoreWebView2FocusChangedEventHandler*)(new FocusChangedEventHandler1(this, &FocusChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FocusChangedEventHandler::~FocusChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FocusChangedEventHandler1 containing interface ICoreWebView2FocusChangedEventHandler");
}
#endif // DEBUG
	FocusChangedEventHandler1* subclass = static_cast<FocusChangedEventHandler1*>((ICoreWebView2FocusChangedEventHandler*)GetInterface(IID_ICoreWebView2FocusChangedEventHandler));
	delete subclass;
}
