/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "StateChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "StateChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2StateChangedEventHandler
 */

IUNKNOWN_DEFS(StateChangedEventHandler1, ICoreWebView2StateChangedEventHandler, StateChangedEventHandler)

static HRESULT STDMETHODCALLTYPE StateChangedEventHandler_Invoke(ICoreWebView2StateChangedEventHandler* This, ICoreWebView2DownloadOperation* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("StateChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<StateChangedEventHandler::StateChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2StateChangedEventHandlerVtbl StateChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(StateChangedEventHandler1)
	StateChangedEventHandler_Invoke,
};

HRESULT StateChangedEventHandler::Invoke(ICoreWebView2DownloadOperation* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::DownloadOperation");

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

	call_method("StateChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//StateChangedEventHandler::StateChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2StateChangedEventHandler{&StateChangedEventHandlerVtbl} {}
StateChangedEventHandler::StateChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "StateChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2StateChangedEventHandler, (ICoreWebView2StateChangedEventHandler*)(new StateChangedEventHandler1(this, &StateChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

StateChangedEventHandler::~StateChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass StateChangedEventHandler1 containing interface ICoreWebView2StateChangedEventHandler");
}
#endif // DEBUG
	StateChangedEventHandler1* subclass = static_cast<StateChangedEventHandler1*>((ICoreWebView2StateChangedEventHandler*)GetInterface(IID_ICoreWebView2StateChangedEventHandler));
	delete subclass;
}
