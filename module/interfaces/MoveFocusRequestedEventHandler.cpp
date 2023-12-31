/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "MoveFocusRequestedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "MoveFocusRequestedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2MoveFocusRequestedEventHandler
 */

IUNKNOWN_DEFS(MoveFocusRequestedEventHandler1, ICoreWebView2MoveFocusRequestedEventHandler, MoveFocusRequestedEventHandler)

static HRESULT STDMETHODCALLTYPE MoveFocusRequestedEventHandler_Invoke(ICoreWebView2MoveFocusRequestedEventHandler* This, ICoreWebView2Controller* sender, ICoreWebView2MoveFocusRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("MoveFocusRequestedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<MoveFocusRequestedEventHandler::MoveFocusRequestedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2MoveFocusRequestedEventHandlerVtbl MoveFocusRequestedEventHandlerVtbl = {
	IUNKNOWN_INIT(MoveFocusRequestedEventHandler1)
	MoveFocusRequestedEventHandler_Invoke,
};

HRESULT MoveFocusRequestedEventHandler::Invoke(ICoreWebView2Controller* sender, ICoreWebView2MoveFocusRequestedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Controller");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::MoveFocusRequestedEventArgs");

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

	call_method("MoveFocusRequested", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//MoveFocusRequestedEventHandler::MoveFocusRequestedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2MoveFocusRequestedEventHandler{&MoveFocusRequestedEventHandlerVtbl} {}
MoveFocusRequestedEventHandler::MoveFocusRequestedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "MoveFocusRequestedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2MoveFocusRequestedEventHandler, (ICoreWebView2MoveFocusRequestedEventHandler*)(new MoveFocusRequestedEventHandler1(this, &MoveFocusRequestedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

MoveFocusRequestedEventHandler::~MoveFocusRequestedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass MoveFocusRequestedEventHandler1 containing interface ICoreWebView2MoveFocusRequestedEventHandler");
}
#endif // DEBUG
	MoveFocusRequestedEventHandler1* subclass = static_cast<MoveFocusRequestedEventHandler1*>((ICoreWebView2MoveFocusRequestedEventHandler*)GetInterface(IID_ICoreWebView2MoveFocusRequestedEventHandler));
	delete subclass;
}
