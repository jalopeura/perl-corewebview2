/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ZoomFactorChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ZoomFactorChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ZoomFactorChangedEventHandler
 */

IUNKNOWN_DEFS(ZoomFactorChangedEventHandler1, ICoreWebView2ZoomFactorChangedEventHandler, ZoomFactorChangedEventHandler)

static HRESULT STDMETHODCALLTYPE ZoomFactorChangedEventHandler_Invoke(ICoreWebView2ZoomFactorChangedEventHandler* This, ICoreWebView2Controller* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ZoomFactorChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ZoomFactorChangedEventHandler::ZoomFactorChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ZoomFactorChangedEventHandlerVtbl ZoomFactorChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(ZoomFactorChangedEventHandler1)
	ZoomFactorChangedEventHandler_Invoke,
};

HRESULT ZoomFactorChangedEventHandler::Invoke(ICoreWebView2Controller* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Controller");

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

	call_method("ZoomFactorChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ZoomFactorChangedEventHandler::ZoomFactorChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ZoomFactorChangedEventHandler{&ZoomFactorChangedEventHandlerVtbl} {}
ZoomFactorChangedEventHandler::ZoomFactorChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ZoomFactorChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ZoomFactorChangedEventHandler, (ICoreWebView2ZoomFactorChangedEventHandler*)(new ZoomFactorChangedEventHandler1(this, &ZoomFactorChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ZoomFactorChangedEventHandler::~ZoomFactorChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ZoomFactorChangedEventHandler1 containing interface ICoreWebView2ZoomFactorChangedEventHandler");
}
#endif // DEBUG
	ZoomFactorChangedEventHandler1* subclass = static_cast<ZoomFactorChangedEventHandler1*>((ICoreWebView2ZoomFactorChangedEventHandler*)GetInterface(IID_ICoreWebView2ZoomFactorChangedEventHandler));
	delete subclass;
}
