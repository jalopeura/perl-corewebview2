/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "DownloadStartingEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "DownloadStartingEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2DownloadStartingEventHandler
 */

IUNKNOWN_DEFS(DownloadStartingEventHandler1, ICoreWebView2DownloadStartingEventHandler, DownloadStartingEventHandler)

static HRESULT STDMETHODCALLTYPE DownloadStartingEventHandler_Invoke(ICoreWebView2DownloadStartingEventHandler* This, ICoreWebView2* sender, ICoreWebView2DownloadStartingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("DownloadStartingEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<DownloadStartingEventHandler::DownloadStartingEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2DownloadStartingEventHandlerVtbl DownloadStartingEventHandlerVtbl = {
	IUNKNOWN_INIT(DownloadStartingEventHandler1)
	DownloadStartingEventHandler_Invoke,
};

HRESULT DownloadStartingEventHandler::Invoke(ICoreWebView2* sender, ICoreWebView2DownloadStartingEventArgs* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2");
	SV* args_sv = sv_newmortal();
	create_perl_object(args_sv, args, "CoreWebView2::DownloadStartingEventArgs");

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

	call_method("DownloadStarting", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//DownloadStartingEventHandler::DownloadStartingEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2DownloadStartingEventHandler{&DownloadStartingEventHandlerVtbl} {}
DownloadStartingEventHandler::DownloadStartingEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "DownloadStartingEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2DownloadStartingEventHandler, (ICoreWebView2DownloadStartingEventHandler*)(new DownloadStartingEventHandler1(this, &DownloadStartingEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

DownloadStartingEventHandler::~DownloadStartingEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass DownloadStartingEventHandler1 containing interface ICoreWebView2DownloadStartingEventHandler");
}
#endif // DEBUG
	DownloadStartingEventHandler1* subclass = static_cast<DownloadStartingEventHandler1*>((ICoreWebView2DownloadStartingEventHandler*)GetInterface(IID_ICoreWebView2DownloadStartingEventHandler));
	delete subclass;
}
