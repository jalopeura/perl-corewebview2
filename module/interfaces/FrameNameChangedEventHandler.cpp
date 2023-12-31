/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "FrameNameChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "FrameNameChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2FrameNameChangedEventHandler
 */

IUNKNOWN_DEFS(FrameNameChangedEventHandler1, ICoreWebView2FrameNameChangedEventHandler, FrameNameChangedEventHandler)

static HRESULT STDMETHODCALLTYPE FrameNameChangedEventHandler_Invoke(ICoreWebView2FrameNameChangedEventHandler* This, ICoreWebView2Frame* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("FrameNameChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<FrameNameChangedEventHandler::FrameNameChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2FrameNameChangedEventHandlerVtbl FrameNameChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(FrameNameChangedEventHandler1)
	FrameNameChangedEventHandler_Invoke,
};

HRESULT FrameNameChangedEventHandler::Invoke(ICoreWebView2Frame* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Frame");

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

	call_method("FrameNameChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//FrameNameChangedEventHandler::FrameNameChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2FrameNameChangedEventHandler{&FrameNameChangedEventHandlerVtbl} {}
FrameNameChangedEventHandler::FrameNameChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "FrameNameChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2FrameNameChangedEventHandler, (ICoreWebView2FrameNameChangedEventHandler*)(new FrameNameChangedEventHandler1(this, &FrameNameChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

FrameNameChangedEventHandler::~FrameNameChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass FrameNameChangedEventHandler1 containing interface ICoreWebView2FrameNameChangedEventHandler");
}
#endif // DEBUG
	FrameNameChangedEventHandler1* subclass = static_cast<FrameNameChangedEventHandler1*>((ICoreWebView2FrameNameChangedEventHandler*)GetInterface(IID_ICoreWebView2FrameNameChangedEventHandler));
	delete subclass;
}
