/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "BrowserProcessExitedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "BrowserProcessExitedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2BrowserProcessExitedEventHandler
 */

IUNKNOWN_DEFS(BrowserProcessExitedEventHandler1, ICoreWebView2BrowserProcessExitedEventHandler, BrowserProcessExitedEventHandler)

static HRESULT STDMETHODCALLTYPE BrowserProcessExitedEventHandler_Invoke(ICoreWebView2BrowserProcessExitedEventHandler* This, ICoreWebView2Environment* sender, ICoreWebView2BrowserProcessExitedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("BrowserProcessExitedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<BrowserProcessExitedEventHandler::BrowserProcessExitedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2BrowserProcessExitedEventHandlerVtbl BrowserProcessExitedEventHandlerVtbl = {
	IUNKNOWN_INIT(BrowserProcessExitedEventHandler1)
	BrowserProcessExitedEventHandler_Invoke,
};

HRESULT BrowserProcessExitedEventHandler::Invoke(ICoreWebView2Environment* sender, ICoreWebView2BrowserProcessExitedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Environment");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::BrowserProcessExitedEventArgs");

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

	call_method("BrowserProcessExited", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//BrowserProcessExitedEventHandler::BrowserProcessExitedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2BrowserProcessExitedEventHandler{&BrowserProcessExitedEventHandlerVtbl} {}
BrowserProcessExitedEventHandler::BrowserProcessExitedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "BrowserProcessExitedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2BrowserProcessExitedEventHandler, (ICoreWebView2BrowserProcessExitedEventHandler*)(new BrowserProcessExitedEventHandler1(this, &BrowserProcessExitedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

BrowserProcessExitedEventHandler::~BrowserProcessExitedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass BrowserProcessExitedEventHandler1 containing interface ICoreWebView2BrowserProcessExitedEventHandler");
}
#endif // DEBUG
	BrowserProcessExitedEventHandler1* subclass = static_cast<BrowserProcessExitedEventHandler1*>((ICoreWebView2BrowserProcessExitedEventHandler*)GetInterface(IID_ICoreWebView2BrowserProcessExitedEventHandler));
	delete subclass;
}
