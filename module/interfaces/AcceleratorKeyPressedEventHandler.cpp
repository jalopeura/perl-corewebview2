/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "AcceleratorKeyPressedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "AcceleratorKeyPressedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2AcceleratorKeyPressedEventHandler
 */

IUNKNOWN_DEFS(AcceleratorKeyPressedEventHandler1, ICoreWebView2AcceleratorKeyPressedEventHandler, AcceleratorKeyPressedEventHandler)

static HRESULT STDMETHODCALLTYPE AcceleratorKeyPressedEventHandler_Invoke(ICoreWebView2AcceleratorKeyPressedEventHandler* This, ICoreWebView2Controller* sender, ICoreWebView2AcceleratorKeyPressedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("AcceleratorKeyPressedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<AcceleratorKeyPressedEventHandler::AcceleratorKeyPressedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2AcceleratorKeyPressedEventHandlerVtbl AcceleratorKeyPressedEventHandlerVtbl = {
	IUNKNOWN_INIT(AcceleratorKeyPressedEventHandler1)
	AcceleratorKeyPressedEventHandler_Invoke,
};

HRESULT AcceleratorKeyPressedEventHandler::Invoke(ICoreWebView2Controller* sender, ICoreWebView2AcceleratorKeyPressedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Controller");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::AcceleratorKeyPressedEventArgs");

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

	call_method("AcceleratorKeyPressed", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//AcceleratorKeyPressedEventHandler::AcceleratorKeyPressedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2AcceleratorKeyPressedEventHandler{&AcceleratorKeyPressedEventHandlerVtbl} {}
AcceleratorKeyPressedEventHandler::AcceleratorKeyPressedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "AcceleratorKeyPressedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2AcceleratorKeyPressedEventHandler, (ICoreWebView2AcceleratorKeyPressedEventHandler*)(new AcceleratorKeyPressedEventHandler1(this, &AcceleratorKeyPressedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

AcceleratorKeyPressedEventHandler::~AcceleratorKeyPressedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass AcceleratorKeyPressedEventHandler1 containing interface ICoreWebView2AcceleratorKeyPressedEventHandler");
}
#endif // DEBUG
	AcceleratorKeyPressedEventHandler1* subclass = static_cast<AcceleratorKeyPressedEventHandler1*>((ICoreWebView2AcceleratorKeyPressedEventHandler*)GetInterface(IID_ICoreWebView2AcceleratorKeyPressedEventHandler));
	delete subclass;
}
