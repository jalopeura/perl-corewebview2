/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "IsDefaultDownloadDialogOpenChangedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "IsDefaultDownloadDialogOpenChangedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler
 */

IUNKNOWN_DEFS(IsDefaultDownloadDialogOpenChangedEventHandler1, ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler, IsDefaultDownloadDialogOpenChangedEventHandler)

static HRESULT STDMETHODCALLTYPE IsDefaultDownloadDialogOpenChangedEventHandler_Invoke(ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler* This, ICoreWebView2* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IsDefaultDownloadDialogOpenChangedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<IsDefaultDownloadDialogOpenChangedEventHandler::IsDefaultDownloadDialogOpenChangedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandlerVtbl IsDefaultDownloadDialogOpenChangedEventHandlerVtbl = {
	IUNKNOWN_INIT(IsDefaultDownloadDialogOpenChangedEventHandler1)
	IsDefaultDownloadDialogOpenChangedEventHandler_Invoke,
};

HRESULT IsDefaultDownloadDialogOpenChangedEventHandler::Invoke(ICoreWebView2* sender, IUnknown* args) {
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

	call_method("IsDefaultDownloadDialogOpenChanged", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//IsDefaultDownloadDialogOpenChangedEventHandler::IsDefaultDownloadDialogOpenChangedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler{&IsDefaultDownloadDialogOpenChangedEventHandlerVtbl} {}
IsDefaultDownloadDialogOpenChangedEventHandler::IsDefaultDownloadDialogOpenChangedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "IsDefaultDownloadDialogOpenChangedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler, (ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler*)(new IsDefaultDownloadDialogOpenChangedEventHandler1(this, &IsDefaultDownloadDialogOpenChangedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

IsDefaultDownloadDialogOpenChangedEventHandler::~IsDefaultDownloadDialogOpenChangedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass IsDefaultDownloadDialogOpenChangedEventHandler1 containing interface ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler");
}
#endif // DEBUG
	IsDefaultDownloadDialogOpenChangedEventHandler1* subclass = static_cast<IsDefaultDownloadDialogOpenChangedEventHandler1*>((ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler*)GetInterface(IID_ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler));
	delete subclass;
}
