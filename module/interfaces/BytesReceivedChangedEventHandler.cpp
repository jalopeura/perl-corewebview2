/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "BytesReceivedChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "BytesReceivedChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2BytesReceivedChangedEventHandler
 */

IUNKNOWN_DEFS(BytesReceivedChangedEventHandler1, ICoreWebView2BytesReceivedChangedEventHandler, BytesReceivedChangedEventHandler)

static HRESULT STDMETHODCALLTYPE BytesReceivedChangedEventHandler_Invoke(ICoreWebView2BytesReceivedChangedEventHandler* This, ICoreWebView2DownloadOperation* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("BytesReceivedChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<BytesReceivedChangedEventHandler::BytesReceivedChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2BytesReceivedChangedEventHandlerVtbl BytesReceivedChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(BytesReceivedChangedEventHandler1)
	BytesReceivedChangedEventHandler_Invoke,
};

HRESULT BytesReceivedChangedEventHandler::Invoke(ICoreWebView2DownloadOperation* sender, IUnknown* args) {
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

	call_method("BytesReceivedChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//BytesReceivedChangedEventHandler::BytesReceivedChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2BytesReceivedChangedEventHandler{&BytesReceivedChangedEventHandlerVtbl} {}
BytesReceivedChangedEventHandler::BytesReceivedChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "BytesReceivedChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2BytesReceivedChangedEventHandler, (ICoreWebView2BytesReceivedChangedEventHandler*)(new BytesReceivedChangedEventHandler1(this, &BytesReceivedChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

BytesReceivedChangedEventHandler::~BytesReceivedChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass BytesReceivedChangedEventHandler1 containing interface ICoreWebView2BytesReceivedChangedEventHandler");
}
#endif // DEBUG
	BytesReceivedChangedEventHandler1* subclass = static_cast<BytesReceivedChangedEventHandler1*>((ICoreWebView2BytesReceivedChangedEventHandler*)GetInterface(IID_ICoreWebView2BytesReceivedChangedEventHandler));
	delete subclass;
}
