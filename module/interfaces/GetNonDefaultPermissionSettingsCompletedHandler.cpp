/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "GetNonDefaultPermissionSettingsCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "GetNonDefaultPermissionSettingsCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler
 */

IUNKNOWN_DEFS(GetNonDefaultPermissionSettingsCompletedHandler1, ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler, GetNonDefaultPermissionSettingsCompletedHandler)

static HRESULT STDMETHODCALLTYPE GetNonDefaultPermissionSettingsCompletedHandler_Invoke(ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler* This, HRESULT errorCode, ICoreWebView2PermissionSettingCollectionView* collectionView) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetNonDefaultPermissionSettingsCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<GetNonDefaultPermissionSettingsCompletedHandler::GetNonDefaultPermissionSettingsCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, collectionView);
}

static ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandlerVtbl GetNonDefaultPermissionSettingsCompletedHandlerVtbl = {
	IUNKNOWN_INIT(GetNonDefaultPermissionSettingsCompletedHandler1)
	GetNonDefaultPermissionSettingsCompletedHandler_Invoke,
};

HRESULT GetNonDefaultPermissionSettingsCompletedHandler::Invoke(HRESULT errorCode, ICoreWebView2PermissionSettingCollectionView* collectionView) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
	SV* collectionView_sv = sv_newmortal();
	create_perl_object(collectionView_sv, collectionView, "CoreWebView2::PermissionSettingCollectionView");

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
	XPUSHs(collectionView_sv);

	PUTBACK;

	call_method("GetNonDefaultPermissionSettingsCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//GetNonDefaultPermissionSettingsCompletedHandler::GetNonDefaultPermissionSettingsCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler{&GetNonDefaultPermissionSettingsCompletedHandlerVtbl} {}
GetNonDefaultPermissionSettingsCompletedHandler::GetNonDefaultPermissionSettingsCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "GetNonDefaultPermissionSettingsCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler, (ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler*)(new GetNonDefaultPermissionSettingsCompletedHandler1(this, &GetNonDefaultPermissionSettingsCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

GetNonDefaultPermissionSettingsCompletedHandler::~GetNonDefaultPermissionSettingsCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass GetNonDefaultPermissionSettingsCompletedHandler1 containing interface ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler");
}
#endif // DEBUG
	GetNonDefaultPermissionSettingsCompletedHandler1* subclass = static_cast<GetNonDefaultPermissionSettingsCompletedHandler1*>((ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler*)GetInterface(IID_ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler));
	delete subclass;
}
