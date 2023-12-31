/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "NewBrowserVersionAvailableEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "NewBrowserVersionAvailableEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2NewBrowserVersionAvailableEventHandler
 */

IUNKNOWN_DEFS(NewBrowserVersionAvailableEventHandler1, ICoreWebView2NewBrowserVersionAvailableEventHandler, NewBrowserVersionAvailableEventHandler)

static HRESULT STDMETHODCALLTYPE NewBrowserVersionAvailableEventHandler_Invoke(ICoreWebView2NewBrowserVersionAvailableEventHandler* This, ICoreWebView2Environment* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("NewBrowserVersionAvailableEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<NewBrowserVersionAvailableEventHandler::NewBrowserVersionAvailableEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2NewBrowserVersionAvailableEventHandlerVtbl NewBrowserVersionAvailableEventHandlerVtbl = {
	IUNKNOWN_INIT(NewBrowserVersionAvailableEventHandler1)
	NewBrowserVersionAvailableEventHandler_Invoke,
};

HRESULT NewBrowserVersionAvailableEventHandler::Invoke(ICoreWebView2Environment* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Environment");

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

	call_method("NewBrowserVersionAvailable", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//NewBrowserVersionAvailableEventHandler::NewBrowserVersionAvailableEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2NewBrowserVersionAvailableEventHandler{&NewBrowserVersionAvailableEventHandlerVtbl} {}
NewBrowserVersionAvailableEventHandler::NewBrowserVersionAvailableEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "NewBrowserVersionAvailableEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2NewBrowserVersionAvailableEventHandler, (ICoreWebView2NewBrowserVersionAvailableEventHandler*)(new NewBrowserVersionAvailableEventHandler1(this, &NewBrowserVersionAvailableEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

NewBrowserVersionAvailableEventHandler::~NewBrowserVersionAvailableEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass NewBrowserVersionAvailableEventHandler1 containing interface ICoreWebView2NewBrowserVersionAvailableEventHandler");
}
#endif // DEBUG
	NewBrowserVersionAvailableEventHandler1* subclass = static_cast<NewBrowserVersionAvailableEventHandler1*>((ICoreWebView2NewBrowserVersionAvailableEventHandler*)GetInterface(IID_ICoreWebView2NewBrowserVersionAvailableEventHandler));
	delete subclass;
}
