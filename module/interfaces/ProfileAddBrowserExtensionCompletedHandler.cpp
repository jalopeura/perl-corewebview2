/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ProfileAddBrowserExtensionCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ProfileAddBrowserExtensionCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ProfileAddBrowserExtensionCompletedHandler
 */

IUNKNOWN_DEFS(ProfileAddBrowserExtensionCompletedHandler1, ICoreWebView2ProfileAddBrowserExtensionCompletedHandler, ProfileAddBrowserExtensionCompletedHandler)

static HRESULT STDMETHODCALLTYPE ProfileAddBrowserExtensionCompletedHandler_Invoke(ICoreWebView2ProfileAddBrowserExtensionCompletedHandler* This, HRESULT errorCode, ICoreWebView2BrowserExtension* extension) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ProfileAddBrowserExtensionCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ProfileAddBrowserExtensionCompletedHandler::ProfileAddBrowserExtensionCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, extension);
}

static ICoreWebView2ProfileAddBrowserExtensionCompletedHandlerVtbl ProfileAddBrowserExtensionCompletedHandlerVtbl = {
	IUNKNOWN_INIT(ProfileAddBrowserExtensionCompletedHandler1)
	ProfileAddBrowserExtensionCompletedHandler_Invoke,
};

HRESULT ProfileAddBrowserExtensionCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2BrowserExtension* extension) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* extension_sv = sv_newmortal();
	create_perl_object(extension_sv, extension, "CoreWebView2::BrowserExtension");

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
	XPUSHs(errorCode_sv);
	XPUSHs(extension_sv);

	PUTBACK;

	call_method("ProfileAddBrowserExtensionCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ProfileAddBrowserExtensionCompletedHandler::ProfileAddBrowserExtensionCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ProfileAddBrowserExtensionCompletedHandler{&ProfileAddBrowserExtensionCompletedHandlerVtbl} {}
ProfileAddBrowserExtensionCompletedHandler::ProfileAddBrowserExtensionCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "ProfileAddBrowserExtensionCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ProfileAddBrowserExtensionCompletedHandler, (ICoreWebView2ProfileAddBrowserExtensionCompletedHandler*)(new ProfileAddBrowserExtensionCompletedHandler1(this, &ProfileAddBrowserExtensionCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ProfileAddBrowserExtensionCompletedHandler::~ProfileAddBrowserExtensionCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ProfileAddBrowserExtensionCompletedHandler1 containing interface ICoreWebView2ProfileAddBrowserExtensionCompletedHandler");
}
#endif // DEBUG
	ProfileAddBrowserExtensionCompletedHandler1* subclass = static_cast<ProfileAddBrowserExtensionCompletedHandler1*>((ICoreWebView2ProfileAddBrowserExtensionCompletedHandler*)GetInterface(IID_ICoreWebView2ProfileAddBrowserExtensionCompletedHandler));
	delete subclass;
}
