/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "EstimatedEndTimeChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "EstimatedEndTimeChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2EstimatedEndTimeChangedEventHandler
 */

IUNKNOWN_DEFS(EstimatedEndTimeChangedEventHandler1, ICoreWebView2EstimatedEndTimeChangedEventHandler, EstimatedEndTimeChangedEventHandler)

static HRESULT STDMETHODCALLTYPE EstimatedEndTimeChangedEventHandler_Invoke(ICoreWebView2EstimatedEndTimeChangedEventHandler* This, ICoreWebView2DownloadOperation* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("EstimatedEndTimeChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<EstimatedEndTimeChangedEventHandler::EstimatedEndTimeChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2EstimatedEndTimeChangedEventHandlerVtbl EstimatedEndTimeChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(EstimatedEndTimeChangedEventHandler1)
	EstimatedEndTimeChangedEventHandler_Invoke,
};

HRESULT EstimatedEndTimeChangedEventHandler::Invoke(ICoreWebView2DownloadOperation* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::DownloadOperation");

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

	call_method("EstimatedEndTimeChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//EstimatedEndTimeChangedEventHandler::EstimatedEndTimeChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2EstimatedEndTimeChangedEventHandler{&EstimatedEndTimeChangedEventHandlerVtbl} {}
EstimatedEndTimeChangedEventHandler::EstimatedEndTimeChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "EstimatedEndTimeChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2EstimatedEndTimeChangedEventHandler, (ICoreWebView2EstimatedEndTimeChangedEventHandler*)(new EstimatedEndTimeChangedEventHandler1(this, &EstimatedEndTimeChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

EstimatedEndTimeChangedEventHandler::~EstimatedEndTimeChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass EstimatedEndTimeChangedEventHandler1 containing interface ICoreWebView2EstimatedEndTimeChangedEventHandler");
}
#endif // DEBUG
	EstimatedEndTimeChangedEventHandler1* subclass = static_cast<EstimatedEndTimeChangedEventHandler1*>((ICoreWebView2EstimatedEndTimeChangedEventHandler*)GetInterface(IID_ICoreWebView2EstimatedEndTimeChangedEventHandler));
	delete subclass;
}
