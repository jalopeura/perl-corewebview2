/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "ProfileDeletedEventHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "ProfileDeletedEventHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2ProfileDeletedEventHandler
 */

IUNKNOWN_DEFS(ProfileDeletedEventHandler1, ICoreWebView2ProfileDeletedEventHandler, ProfileDeletedEventHandler)

static HRESULT STDMETHODCALLTYPE ProfileDeletedEventHandler_Invoke(ICoreWebView2ProfileDeletedEventHandler* This, ICoreWebView2Profile* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ProfileDeletedEventHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<ProfileDeletedEventHandler::ProfileDeletedEventHandler1*>(This)->Wrapper()->Invoke(sender, args);
}

static ICoreWebView2ProfileDeletedEventHandlerVtbl ProfileDeletedEventHandlerVtbl = {
	IUNKNOWN_INIT(ProfileDeletedEventHandler1)
	ProfileDeletedEventHandler_Invoke,
};

HRESULT ProfileDeletedEventHandler::Invoke(ICoreWebView2Profile* sender, IUnknown* args) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* sender_sv = sv_newmortal();
	create_perl_object(sender_sv, sender, "CoreWebView2::Profile");

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

	call_method("ProfileDeleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//ProfileDeletedEventHandler::ProfileDeletedEventHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2ProfileDeletedEventHandler{&ProfileDeletedEventHandlerVtbl} {}
ProfileDeletedEventHandler::ProfileDeletedEventHandler(SV* perl_object) :
	HandlerBase(perl_object, "ProfileDeletedEventHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2ProfileDeletedEventHandler, (ICoreWebView2ProfileDeletedEventHandler*)(new ProfileDeletedEventHandler1(this, &ProfileDeletedEventHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

ProfileDeletedEventHandler::~ProfileDeletedEventHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass ProfileDeletedEventHandler1 containing interface ICoreWebView2ProfileDeletedEventHandler");
}
#endif // DEBUG
	ProfileDeletedEventHandler1* subclass = static_cast<ProfileDeletedEventHandler1*>((ICoreWebView2ProfileDeletedEventHandler*)GetInterface(IID_ICoreWebView2ProfileDeletedEventHandler));
	delete subclass;
}
