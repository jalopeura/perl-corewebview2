/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "NewWindowRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "NewWindowRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2NewWindowRequestedEventHandler
 */

IUNKNOWN_DEFS(NewWindowRequestedEventHandler1, ICoreWebView2NewWindowRequestedEventHandler, NewWindowRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE NewWindowRequestedEventHandler_Invoke(ICoreWebView2NewWindowRequestedEventHandler* This, ICoreWebView2* sender, ICoreWebView2NewWindowRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("NewWindowRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<NewWindowRequestedEventHandler::NewWindowRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2NewWindowRequestedEventHandlerVtbl NewWindowRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(NewWindowRequestedEventHandler1)
	NewWindowRequestedEventHandler_Invoke,
};

HRESULT NewWindowRequestedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2NewWindowRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::NewWindowRequestedEventArgs");

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

	call_method("NewWindowRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//NewWindowRequestedEventHandler::NewWindowRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2NewWindowRequestedEventHandler{&NewWindowRequestedEventHandlerVtbl} {}
NewWindowRequestedEventHandler::NewWindowRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "NewWindowRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2NewWindowRequestedEventHandler, (ICoreWebView2NewWindowRequestedEventHandler*)(new NewWindowRequestedEventHandler1(this, &NewWindowRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

NewWindowRequestedEventHandler::~NewWindowRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass NewWindowRequestedEventHandler1 containing interface ICoreWebView2NewWindowRequestedEventHandler");
}
#endif // DEBUG
	NewWindowRequestedEventHandler1* subclass = static_cast<NewWindowRequestedEventHandler1*>((ICoreWebView2NewWindowRequestedEventHandler*)GetInterface(IID_ICoreWebView2NewWindowRequestedEventHandler));
	delete subclass;
}
