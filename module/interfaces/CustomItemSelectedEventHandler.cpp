/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "CustomItemSelectedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "CustomItemSelectedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CustomItemSelectedEventHandler
 */

IUNKNOWN_DEFS(CustomItemSelectedEventHandler1, ICoreWebView2CustomItemSelectedEventHandler, CustomItemSelectedEventHandler)

static HRESULT STDMETHODCALLTYPE CustomItemSelectedEventHandler_Invoke(ICoreWebView2CustomItemSelectedEventHandler* This, ICoreWebView2ContextMenuItem* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CustomItemSelectedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<CustomItemSelectedEventHandler::CustomItemSelectedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2CustomItemSelectedEventHandlerVtbl CustomItemSelectedEventHandlerVtbl = {
	IUNKNOWN_INIT(CustomItemSelectedEventHandler1)
	CustomItemSelectedEventHandler_Invoke,
};

HRESULT CustomItemSelectedEventHandler::Invoke(ICoreWebView2ContextMenuItem* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::ContextMenuItem");

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

	call_method("CustomItemSelected", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//CustomItemSelectedEventHandler::CustomItemSelectedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2CustomItemSelectedEventHandler{&CustomItemSelectedEventHandlerVtbl} {}
CustomItemSelectedEventHandler::CustomItemSelectedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "CustomItemSelectedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CustomItemSelectedEventHandler, (ICoreWebView2CustomItemSelectedEventHandler*)(new CustomItemSelectedEventHandler1(this, &CustomItemSelectedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

CustomItemSelectedEventHandler::~CustomItemSelectedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass CustomItemSelectedEventHandler1 containing interface ICoreWebView2CustomItemSelectedEventHandler");
}
#endif // DEBUG
	CustomItemSelectedEventHandler1* subclass = static_cast<CustomItemSelectedEventHandler1*>((ICoreWebView2CustomItemSelectedEventHandler*)GetInterface(IID_ICoreWebView2CustomItemSelectedEventHandler));
	delete subclass;
}
