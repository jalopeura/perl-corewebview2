/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CursorChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CursorChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CursorChangedEventHandler
 */

IUNKNOWN_DEFS(CursorChangedEventHandler1, ICoreWebView2CursorChangedEventHandler, CursorChangedEventHandler)

static HRESULT STDMETHODCALLTYPE CursorChangedEventHandler_Invoke(ICoreWebView2CursorChangedEventHandler* This, ICoreWebView2CompositionController* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CursorChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CursorChangedEventHandler::CursorChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2CursorChangedEventHandlerVtbl CursorChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(CursorChangedEventHandler1)
	CursorChangedEventHandler_Invoke,
};

HRESULT CursorChangedEventHandler::Invoke(ICoreWebView2CompositionController* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::CompositionController");

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

	call_method("CursorChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CursorChangedEventHandler::CursorChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CursorChangedEventHandler{&CursorChangedEventHandlerVtbl} {}
CursorChangedEventHandler::CursorChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "CursorChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CursorChangedEventHandler, (ICoreWebView2CursorChangedEventHandler*)(new CursorChangedEventHandler1(this, &CursorChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CursorChangedEventHandler::~CursorChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CursorChangedEventHandler1 containing interface ICoreWebView2CursorChangedEventHandler");
}
#endif // DEBUG
	CursorChangedEventHandler1* subclass = static_cast<CursorChangedEventHandler1*>((ICoreWebView2CursorChangedEventHandler*)GetInterface(IID_ICoreWebView2CursorChangedEventHandler));
	delete subclass;
}
