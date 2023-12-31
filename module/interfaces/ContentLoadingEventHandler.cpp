/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ContentLoadingEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ContentLoadingEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ContentLoadingEventHandler
 */

IUNKNOWN_DEFS(ContentLoadingEventHandler1, ICoreWebView2ContentLoadingEventHandler, ContentLoadingEventHandler)

static HRESULT STDMETHODCALLTYPE ContentLoadingEventHandler_Invoke(ICoreWebView2ContentLoadingEventHandler* This, ICoreWebView2* sender, ICoreWebView2ContentLoadingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ContentLoadingEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ContentLoadingEventHandler::ContentLoadingEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ContentLoadingEventHandlerVtbl ContentLoadingEventHandlerVtbl = {
	IUNKNOWN_INIT(ContentLoadingEventHandler1)
	ContentLoadingEventHandler_Invoke,
};

HRESULT ContentLoadingEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2ContentLoadingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::ContentLoadingEventArgs");

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

	call_method("ContentLoading", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ContentLoadingEventHandler::ContentLoadingEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ContentLoadingEventHandler{&ContentLoadingEventHandlerVtbl} {}
ContentLoadingEventHandler::ContentLoadingEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ContentLoadingEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ContentLoadingEventHandler, (ICoreWebView2ContentLoadingEventHandler*)(new ContentLoadingEventHandler1(this, &ContentLoadingEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ContentLoadingEventHandler::~ContentLoadingEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ContentLoadingEventHandler1 containing interface ICoreWebView2ContentLoadingEventHandler");
}
#endif // DEBUG
	ContentLoadingEventHandler1* subclass = static_cast<ContentLoadingEventHandler1*>((ICoreWebView2ContentLoadingEventHandler*)GetInterface(IID_ICoreWebView2ContentLoadingEventHandler));
	delete subclass;
}
