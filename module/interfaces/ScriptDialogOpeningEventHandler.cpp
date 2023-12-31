/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ScriptDialogOpeningEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ScriptDialogOpeningEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ScriptDialogOpeningEventHandler
 */

IUNKNOWN_DEFS(ScriptDialogOpeningEventHandler1, ICoreWebView2ScriptDialogOpeningEventHandler, ScriptDialogOpeningEventHandler)

static HRESULT STDMETHODCALLTYPE ScriptDialogOpeningEventHandler_Invoke(ICoreWebView2ScriptDialogOpeningEventHandler* This, ICoreWebView2* sender, ICoreWebView2ScriptDialogOpeningEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ScriptDialogOpeningEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ScriptDialogOpeningEventHandler::ScriptDialogOpeningEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ScriptDialogOpeningEventHandlerVtbl ScriptDialogOpeningEventHandlerVtbl = {
	IUNKNOWN_INIT(ScriptDialogOpeningEventHandler1)
	ScriptDialogOpeningEventHandler_Invoke,
};

HRESULT ScriptDialogOpeningEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2ScriptDialogOpeningEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ScriptDialogOpeningEventArgs");

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

	call_method("ScriptDialogOpening", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ScriptDialogOpeningEventHandler::ScriptDialogOpeningEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ScriptDialogOpeningEventHandler{&ScriptDialogOpeningEventHandlerVtbl} {}
ScriptDialogOpeningEventHandler::ScriptDialogOpeningEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ScriptDialogOpeningEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ScriptDialogOpeningEventHandler, (ICoreWebView2ScriptDialogOpeningEventHandler*)(new ScriptDialogOpeningEventHandler1(this, &ScriptDialogOpeningEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ScriptDialogOpeningEventHandler::~ScriptDialogOpeningEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ScriptDialogOpeningEventHandler1 containing interface ICoreWebView2ScriptDialogOpeningEventHandler");
}
#endif // DEBUG
	ScriptDialogOpeningEventHandler1* subclass = static_cast<ScriptDialogOpeningEventHandler1*>((ICoreWebView2ScriptDialogOpeningEventHandler*)GetInterface(IID_ICoreWebView2ScriptDialogOpeningEventHandler));
	delete subclass;
}
