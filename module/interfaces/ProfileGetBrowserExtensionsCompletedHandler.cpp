/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ProfileGetBrowserExtensionsCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ProfileGetBrowserExtensionsCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler
 */

IUNKNOWN_DEFS(ProfileGetBrowserExtensionsCompletedHandler1, ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler, ProfileGetBrowserExtensionsCompletedHandler)

static HRESULT STDMETHODCALLTYPE ProfileGetBrowserExtensionsCompletedHandler_Invoke(ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler* This, HRESULT errorCode, ICoreWebView2BrowserExtensionList* extensionList) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ProfileGetBrowserExtensionsCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ProfileGetBrowserExtensionsCompletedHandler::ProfileGetBrowserExtensionsCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, extensionList);
}

static ICoreWebView2ProfileGetBrowserExtensionsCompletedHandlerVtbl ProfileGetBrowserExtensionsCompletedHandlerVtbl = {
	IUNKNOWN_INIT(ProfileGetBrowserExtensionsCompletedHandler1)
	ProfileGetBrowserExtensionsCompletedHandler_Invoke,
};

HRESULT ProfileGetBrowserExtensionsCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2BrowserExtensionList* extensionList) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* extensionList_sv = sv_newmortal();
	create_perl_object(extensionList_sv, extensionList, "CoreWebView2::BrowserExtensionList");

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
	XPUSHs(extensionList_sv);

	PUTBACK;

	call_method("ProfileGetBrowserExtensionsCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ProfileGetBrowserExtensionsCompletedHandler::ProfileGetBrowserExtensionsCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler{&ProfileGetBrowserExtensionsCompletedHandlerVtbl} {}
ProfileGetBrowserExtensionsCompletedHandler::ProfileGetBrowserExtensionsCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "ProfileGetBrowserExtensionsCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler, (ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler*)(new ProfileGetBrowserExtensionsCompletedHandler1(this, &ProfileGetBrowserExtensionsCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ProfileGetBrowserExtensionsCompletedHandler::~ProfileGetBrowserExtensionsCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ProfileGetBrowserExtensionsCompletedHandler1 containing interface ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler");
}
#endif // DEBUG
	ProfileGetBrowserExtensionsCompletedHandler1* subclass = static_cast<ProfileGetBrowserExtensionsCompletedHandler1*>((ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler*)GetInterface(IID_ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler));
	delete subclass;
}
