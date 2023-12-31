/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "HistoryChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "HistoryChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2HistoryChangedEventHandler
 */

IUNKNOWN_DEFS(HistoryChangedEventHandler1, ICoreWebView2HistoryChangedEventHandler, HistoryChangedEventHandler)

static HRESULT STDMETHODCALLTYPE HistoryChangedEventHandler_Invoke(ICoreWebView2HistoryChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("HistoryChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<HistoryChangedEventHandler::HistoryChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2HistoryChangedEventHandlerVtbl HistoryChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(HistoryChangedEventHandler1)
	HistoryChangedEventHandler_Invoke,
};

HRESULT HistoryChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("HistoryChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//HistoryChangedEventHandler::HistoryChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2HistoryChangedEventHandler{&HistoryChangedEventHandlerVtbl} {}
HistoryChangedEventHandler::HistoryChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "HistoryChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2HistoryChangedEventHandler, (ICoreWebView2HistoryChangedEventHandler*)(new HistoryChangedEventHandler1(this, &HistoryChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

HistoryChangedEventHandler::~HistoryChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass HistoryChangedEventHandler1 containing interface ICoreWebView2HistoryChangedEventHandler");
}
#endif // DEBUG
	HistoryChangedEventHandler1* subclass = static_cast<HistoryChangedEventHandler1*>((ICoreWebView2HistoryChangedEventHandler*)GetInterface(IID_ICoreWebView2HistoryChangedEventHandler));
	delete subclass;
}
