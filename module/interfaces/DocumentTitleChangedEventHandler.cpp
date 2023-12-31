/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "DocumentTitleChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "DocumentTitleChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2DocumentTitleChangedEventHandler
 */

IUNKNOWN_DEFS(DocumentTitleChangedEventHandler1, ICoreWebView2DocumentTitleChangedEventHandler, DocumentTitleChangedEventHandler)

static HRESULT STDMETHODCALLTYPE DocumentTitleChangedEventHandler_Invoke(ICoreWebView2DocumentTitleChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("DocumentTitleChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<DocumentTitleChangedEventHandler::DocumentTitleChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2DocumentTitleChangedEventHandlerVtbl DocumentTitleChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(DocumentTitleChangedEventHandler1)
	DocumentTitleChangedEventHandler_Invoke,
};

HRESULT DocumentTitleChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("DocumentTitleChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//DocumentTitleChangedEventHandler::DocumentTitleChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2DocumentTitleChangedEventHandler{&DocumentTitleChangedEventHandlerVtbl} {}
DocumentTitleChangedEventHandler::DocumentTitleChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "DocumentTitleChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2DocumentTitleChangedEventHandler, (ICoreWebView2DocumentTitleChangedEventHandler*)(new DocumentTitleChangedEventHandler1(this, &DocumentTitleChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

DocumentTitleChangedEventHandler::~DocumentTitleChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass DocumentTitleChangedEventHandler1 containing interface ICoreWebView2DocumentTitleChangedEventHandler");
}
#endif // DEBUG
	DocumentTitleChangedEventHandler1* subclass = static_cast<DocumentTitleChangedEventHandler1*>((ICoreWebView2DocumentTitleChangedEventHandler*)GetInterface(IID_ICoreWebView2DocumentTitleChangedEventHandler));
	delete subclass;
}
