/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "AddScriptToExecuteOnDocumentCreatedCompletedHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "AddScriptToExecuteOnDocumentCreatedCompletedHandler"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler
 */

IUNKNOWN_DEFS(AddScriptToExecuteOnDocumentCreatedCompletedHandler1, ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler, AddScriptToExecuteOnDocumentCreatedCompletedHandler)

static HRESULT STDMETHODCALLTYPE AddScriptToExecuteOnDocumentCreatedCompletedHandler_Invoke(ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler* This, HRESULT errorCode, LPCWSTR id) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("AddScriptToExecuteOnDocumentCreatedCompletedHandler_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<AddScriptToExecuteOnDocumentCreatedCompletedHandler::AddScriptToExecuteOnDocumentCreatedCompletedHandler1*>(This)->Wrapper()->Invoke(errorCode, id);
}

static ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandlerVtbl AddScriptToExecuteOnDocumentCreatedCompletedHandlerVtbl = {
	IUNKNOWN_INIT(AddScriptToExecuteOnDocumentCreatedCompletedHandler1)
	AddScriptToExecuteOnDocumentCreatedCompletedHandler_Invoke,
};

HRESULT AddScriptToExecuteOnDocumentCreatedCompletedHandler::Invoke(HRESULT errorCode, LPCWSTR id) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	SV* errorCode_sv;
	CHECK_ERROR(errorCode, errorCode_sv);
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
	XPUSHs(wchar_to_scalar(id));

	PUTBACK;

	call_method("AddScriptToExecuteOnDocumentCreatedCompleted", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//AddScriptToExecuteOnDocumentCreatedCompletedHandler::AddScriptToExecuteOnDocumentCreatedCompletedHandler(SV* perl_object) : HandlerBase(perl_object), ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler{&AddScriptToExecuteOnDocumentCreatedCompletedHandlerVtbl} {}
AddScriptToExecuteOnDocumentCreatedCompletedHandler::AddScriptToExecuteOnDocumentCreatedCompletedHandler(SV* perl_object) :
	HandlerBase(perl_object, "AddScriptToExecuteOnDocumentCreatedCompletedHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler, (ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler*)(new AddScriptToExecuteOnDocumentCreatedCompletedHandler1(this, &AddScriptToExecuteOnDocumentCreatedCompletedHandlerVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

AddScriptToExecuteOnDocumentCreatedCompletedHandler::~AddScriptToExecuteOnDocumentCreatedCompletedHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass AddScriptToExecuteOnDocumentCreatedCompletedHandler1 containing interface ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler");
}
#endif // DEBUG
	AddScriptToExecuteOnDocumentCreatedCompletedHandler1* subclass = static_cast<AddScriptToExecuteOnDocumentCreatedCompletedHandler1*>((ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler*)GetInterface(IID_ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler));
	delete subclass;
}
