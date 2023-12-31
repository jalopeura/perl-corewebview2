/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "SourceChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "SourceChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2SourceChangedEventHandler
 */

IUNKNOWN_DEFS(SourceChangedEventHandler1, ICoreWebView2SourceChangedEventHandler, SourceChangedEventHandler)

static HRESULT STDMETHODCALLTYPE SourceChangedEventHandler_Invoke(ICoreWebView2SourceChangedEventHandler* This, ICoreWebView2* sender, ICoreWebView2SourceChangedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SourceChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<SourceChangedEventHandler::SourceChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2SourceChangedEventHandlerVtbl SourceChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(SourceChangedEventHandler1)
	SourceChangedEventHandler_Invoke,
};

HRESULT SourceChangedEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2SourceChangedEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::SourceChangedEventArgs");

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

	call_method("SourceChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//SourceChangedEventHandler::SourceChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2SourceChangedEventHandler{&SourceChangedEventHandlerVtbl} {}
SourceChangedEventHandler::SourceChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "SourceChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2SourceChangedEventHandler, (ICoreWebView2SourceChangedEventHandler*)(new SourceChangedEventHandler1(this, &SourceChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

SourceChangedEventHandler::~SourceChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass SourceChangedEventHandler1 containing interface ICoreWebView2SourceChangedEventHandler");
}
#endif // DEBUG
	SourceChangedEventHandler1* subclass = static_cast<SourceChangedEventHandler1*>((ICoreWebView2SourceChangedEventHandler*)GetInterface(IID_ICoreWebView2SourceChangedEventHandler));
	delete subclass;
}
