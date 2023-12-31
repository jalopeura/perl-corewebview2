/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "RasterizationScaleChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "RasterizationScaleChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2RasterizationScaleChangedEventHandler
 */

IUNKNOWN_DEFS(RasterizationScaleChangedEventHandler1, ICoreWebView2RasterizationScaleChangedEventHandler, RasterizationScaleChangedEventHandler)

static HRESULT STDMETHODCALLTYPE RasterizationScaleChangedEventHandler_Invoke(ICoreWebView2RasterizationScaleChangedEventHandler* This, ICoreWebView2Controller* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("RasterizationScaleChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<RasterizationScaleChangedEventHandler::RasterizationScaleChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2RasterizationScaleChangedEventHandlerVtbl RasterizationScaleChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(RasterizationScaleChangedEventHandler1)
	RasterizationScaleChangedEventHandler_Invoke,
};

HRESULT RasterizationScaleChangedEventHandler::Invoke(ICoreWebView2Controller* sender, IUnknown* args) {
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

	call_method("RasterizationScaleChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//RasterizationScaleChangedEventHandler::RasterizationScaleChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2RasterizationScaleChangedEventHandler{&RasterizationScaleChangedEventHandlerVtbl} {}
RasterizationScaleChangedEventHandler::RasterizationScaleChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "RasterizationScaleChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2RasterizationScaleChangedEventHandler, (ICoreWebView2RasterizationScaleChangedEventHandler*)(new RasterizationScaleChangedEventHandler1(this, &RasterizationScaleChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

RasterizationScaleChangedEventHandler::~RasterizationScaleChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass RasterizationScaleChangedEventHandler1 containing interface ICoreWebView2RasterizationScaleChangedEventHandler");
}
#endif // DEBUG
	RasterizationScaleChangedEventHandler1* subclass = static_cast<RasterizationScaleChangedEventHandler1*>((ICoreWebView2RasterizationScaleChangedEventHandler*)GetInterface(IID_ICoreWebView2RasterizationScaleChangedEventHandler));
	delete subclass;
}
