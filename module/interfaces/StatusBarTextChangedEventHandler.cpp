/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "StatusBarTextChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "StatusBarTextChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2StatusBarTextChangedEventHandler
 */

IUNKNOWN_DEFS(StatusBarTextChangedEventHandler1, ICoreWebView2StatusBarTextChangedEventHandler, StatusBarTextChangedEventHandler)

static HRESULT STDMETHODCALLTYPE StatusBarTextChangedEventHandler_Invoke(ICoreWebView2StatusBarTextChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("StatusBarTextChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<StatusBarTextChangedEventHandler::StatusBarTextChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2StatusBarTextChangedEventHandlerVtbl StatusBarTextChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(StatusBarTextChangedEventHandler1)
	StatusBarTextChangedEventHandler_Invoke,
};

HRESULT StatusBarTextChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("StatusBarTextChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//StatusBarTextChangedEventHandler::StatusBarTextChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2StatusBarTextChangedEventHandler{&StatusBarTextChangedEventHandlerVtbl} {}
StatusBarTextChangedEventHandler::StatusBarTextChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "StatusBarTextChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2StatusBarTextChangedEventHandler, (ICoreWebView2StatusBarTextChangedEventHandler*)(new StatusBarTextChangedEventHandler1(this, &StatusBarTextChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

StatusBarTextChangedEventHandler::~StatusBarTextChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass StatusBarTextChangedEventHandler1 containing interface ICoreWebView2StatusBarTextChangedEventHandler");
}
#endif // DEBUG
	StatusBarTextChangedEventHandler1* subclass = static_cast<StatusBarTextChangedEventHandler1*>((ICoreWebView2StatusBarTextChangedEventHandler*)GetInterface(IID_ICoreWebView2StatusBarTextChangedEventHandler));
	delete subclass;
}
