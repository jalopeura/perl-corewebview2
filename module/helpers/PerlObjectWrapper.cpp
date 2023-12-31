#include "PerlObjectWrapper.h"
#include "variant.h"

#ifdef DEBUG
#define DEBUG_TAG "PerlObjectWrapper"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * IDispatch
 */

IUNKNOWN_DEFS(Dispatch, IDispatch, PerlObjectWrapper)

static HRESULT STDMETHODCALLTYPE IDispatch_GetTypeInfoCount(IDispatch* This, UINT* pctinfo) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IDispatch_GetTypeInfoCount (%p)", This);
}
#endif // DEBUG
// JS currently not using the ITypeInfo
//	*pctinfo = 1;// 0 or 1
	*pctinfo = 0; // 0 or 1
	return S_OK;
}

static HRESULT STDMETHODCALLTYPE IDispatch_GetTypeInfo(IDispatch* This, UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IDispatch_GetTypeInfo (%p)", This);
}
#endif // DEBUG
// JS currently not using the ITypeInfo
//	*ppTInfo = (ITypeInfo*)static_cast<PerlObjectWrapper::Dispatch*>(This)->Wrapper()->GetInterface(IID_ITypeInfo);
	*ppTInfo = NULL;
	return S_OK;
}

static HRESULT STDMETHODCALLTYPE IDispatch_GetIDsOfNames(IDispatch* This, REFIID riid, LPOLESTR* rgszNames, UINT cNames,
	LCID lcid, DISPID* rgDispId) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IDispatch_GetIDsOfNames (%p)", This);
}
#endif // DEBUG
	return static_cast<PerlObjectWrapper::Dispatch*>(This)->Wrapper()->Dispatch_GetIDsOfNames(riid, rgszNames, cNames, lcid, rgDispId);
}

static HRESULT STDMETHODCALLTYPE IDispatch_Invoke(IDispatch* This, DISPID dispIdMember, REFIID riid, LCID lcid,
	WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("IDispatch_Invoke (%p)", This);
}
#endif // DEBUG
	return static_cast<PerlObjectWrapper::Dispatch*>(This)->Wrapper()->Dispatch_Invoke(dispIdMember, riid, lcid, wFlags, pDispParams,
		pVarResult, pExcepInfo, puArgErr);
}

static IDispatchVtbl PerlObjectWrapper_DispatchVtbl = {
	IUNKNOWN_INIT(Dispatch)
	IDispatch_GetTypeInfoCount,
	IDispatch_GetTypeInfo,
	IDispatch_GetIDsOfNames,
	IDispatch_Invoke
};

HRESULT PerlObjectWrapper::Dispatch_GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Dispatch_GetIDsOfNames in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	LPOLESTR idstr = NULL;
	HRESULT result = StringFromIID(riid, &idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	std::string name = iidname(SHORTEN(idstr));
	WARN("Converted iid to string %s => %s", SHORTEN(idstr), name.c_str());
}
#endif // DEBUG
	SV* riid_sv = wchar_to_scalar(idstr);
	sv_2mortal(riid_sv);

	AV* temp_array = newAV();
	SV* name_sv;
	for (UINT i = 0; i < cNames; i++) {
		name_sv = wchar_to_scalar(rgszNames[i]);
		av_push(temp_array, name_sv);
	}
	SV* rgszNames_sv = newRV_noinc((SV*)temp_array);
	sv_2mortal(rgszNames_sv);

	SV* lcid_sv = newSVuv((UV)lcid);
	sv_2mortal(lcid_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 4);
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(riid_sv);
	XPUSHs(rgszNames_sv);
	XPUSHs(lcid_sv);

	PUTBACK;

	int perl_return_count = call_method("GetIDsOfNames", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	if (retval == S_OK) {
		SV** item;
		AV* temp_array = (AV*)SvRV(retval_sv);
		for (int i = 0; i < cNames; i++) {
			item = av_fetch(temp_array, i, 0);
			if (item == NULL) {
				warn("Missing item %d in aref returned from GetIDsOfNames", i);
				rgDispId[i] = 0;
			}
			else {
				rgDispId[i] = SvUV(*item);
			}
		}
	}

	PUTBACK;
	FREETMPS;
	LEAVE;

	// don't forget to free this one
	CoTaskMemFree(idstr);

	return retval;
}

HRESULT PerlObjectWrapper::Dispatch_Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,
	VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Dispatch_Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* dispIdMember_sv = newSViv((IV)dispIdMember);
	sv_2mortal(dispIdMember_sv);

	LPOLESTR idstr = NULL;
	HRESULT result = StringFromIID(riid, &idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	std::string name = iidname(SHORTEN(idstr));
	WARN("Converted iid to string %s => %s", SHORTEN(idstr), name.c_str());
}
#endif // DEBUG
	SV* riid_sv = wchar_to_scalar(idstr);
	sv_2mortal(riid_sv);

	SV* lcid_sv = newSVuv((UV)lcid);
	sv_2mortal(lcid_sv);

	SV* wFlags_sv = newSVuv((UV)wFlags);
	sv_2mortal(wFlags_sv);

	AV* temp_array = newAV();
	SV* pDispParams_sv = newRV_noinc((SV*)temp_array);
	if (pDispParams->cArgs > 0) {
		SV* param_sv;
		for (UINT i = 0; i < pDispParams->cArgs; i++) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("%d of %d", i, pDispParams->cArgs);
}
#endif // DEBUG
			VARIANT v; VariantInit(&v);
			HRESULT h = VariantCopyInd(&v, &(pDispParams->rgvarg[i]));
			if (h == S_OK) {
				param_sv = variant_to_scalar(v);
			}
			else {
				errstr = get_error_string(h);
				croak("Unable to copy variant: %d => %s", h, errstr);
			}
			// arguments in pDispParams->rgvarg are in reverse order
			// so we unshift instead of push
			av_unshift(temp_array, 1);
			av_store(temp_array, 0, param_sv);
		}
	}
	sv_2mortal(pDispParams_sv);

	I32 wants_return = pVarResult == NULL ? G_VOID : G_SCALAR;

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	SV_WARN(m_perl_object, "member object before push");
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 6); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(dispIdMember_sv);
	XPUSHs(riid_sv);
	XPUSHs(lcid_sv);
	XPUSHs(wFlags_sv);
	XPUSHs(pDispParams_sv);

	PUTBACK;

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	SV_WARN(m_perl_object, "member object before call");
}
#endif // DEBUG

	int perl_return_count = call_method("Invoke", wants_return);
	SPAGAIN;

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	SV_WARN(m_perl_object, "member object after call");
}
#endif // DEBUG

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

//SV_WARN(retval_sv, "Back from Invoke");
	if (retval == S_OK) {
		*pVarResult = scalar_to_variant(retval_sv);
//SV_WARN(retval_sv, "After conversion");
	}
// NOTE: currently the only error processing we return is returning an integer error value
//       so we can't indicate what kind of exception happened or which argument was bad
	else if (retval == DISP_E_EXCEPTION && pExcepInfo != NULL) {
// TODO: populate pExcepInfo
		croak("Exception occurred in Invoke");
	}
	else if (retval == DISP_E_TYPEMISMATCH || retval == DISP_E_PARAMNOTFOUND) {
// TODO: populate puArgErr
		croak("Invalid argument passed from browser in Invoke");
	}

	PUTBACK;
	FREETMPS;
	LEAVE;
//SV_WARN(retval_sv, "After FREETMPS");

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	SV_WARN(m_perl_object, "member object after FREETMPS");
}
#endif // DEBUG

	return retval;
}

/*
 * ITypeInfo
 */

// JS currently not using the ITypeInfo

/*

IUNKNOWN_DEFS(TypeInfo, ITypeInfo, PerlObjectWrapper)

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetTypeAttr(ITypeInfo* This, TYPEATTR** ppTypeAttr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetTypeAttr (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetTypeAttr(ppTypeAttr);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetTypeComp(ITypeInfo* This, ITypeComp** ppTComp) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetTypeComp (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetTypeComp(ppTComp);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetFuncDesc(ITypeInfo* This, UINT index, FUNCDESC** ppFuncDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetFuncDesc (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetFuncDesc(index, ppFuncDesc);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetVarDesc(ITypeInfo* This, UINT index, VARDESC** ppVarDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetVarDesc (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetVarDesc(index, ppVarDesc);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetNames(ITypeInfo* This, MEMBERID memid, BSTR* rgBstrNames, UINT cMaxNames, UINT* pcNames) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetNames (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetNames(memid, rgBstrNames, cMaxNames, pcNames);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetRefTypeOfImplType(ITypeInfo* This, UINT index, HREFTYPE* pRefType) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetRefTypeOfImplType (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetRefTypeOfImplType(index, pRefType);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetImplTypeFlags(ITypeInfo* This, UINT index, INT* pImplTypeFlags) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetImplTypeFlags (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetImplTypeFlags(index, pImplTypeFlags);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetIDsOfNames(ITypeInfo* This, LPOLESTR* rgszNames, UINT cNames, MEMBERID* pMemId) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetIDsOfNames (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetIDsOfNames(rgszNames, cNames, pMemId);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_Invoke(ITypeInfo* This, PVOID pvInstance, MEMBERID memid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_Invoke (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_Invoke(pvInstance, memid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetDocumentation(ITypeInfo* This, MEMBERID memid, BSTR* pBstrName, BSTR* pBstrDocString, DWORD* pdwHelpContext, BSTR* pBstrHelpFile) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetDocumentation (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetDocumentation(memid, pBstrName, pBstrDocString, pdwHelpContext, pBstrHelpFile);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetDllEntry(ITypeInfo* This, MEMBERID memid, INVOKEKIND invKind, BSTR* pBstrDllName, BSTR* pBstrName, WORD* pwOrdinal) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetDllEntry (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetDllEntry(memid, invKind, pBstrDllName, pBstrName, pwOrdinal);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetRefTypeInfo(ITypeInfo* This, HREFTYPE hRefType, ITypeInfo** ppTInfo) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetRefTypeInfo (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetRefTypeInfo(hRefType, ppTInfo);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_AddressOfMember(ITypeInfo* This, MEMBERID memid, INVOKEKIND invKind, PVOID* ppv) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_AddressOfMember (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_AddressOfMember(memid, invKind, ppv);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_CreateInstance(ITypeInfo* This, IUnknown* pUnkOuter, REFIID riid, PVOID* ppvObj) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_CreateInstance (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_CreateInstance(pUnkOuter, riid, ppvObj);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetMops(ITypeInfo* This, MEMBERID memid, BSTR* pBstrMops) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetMops (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetMops(memid, pBstrMops);
}

static HRESULT STDMETHODCALLTYPE ITypeInfo_GetContainingTypeLib(ITypeInfo* This, ITypeLib** ppTLib, UINT* pIndex) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_GetContainingTypeLib (%p)", This);
}
#endif // DEBUG
return S_OK;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_GetContainingTypeLib(ppTLib, pIndex);
}

static void STDMETHODCALLTYPE ITypeInfo_ReleaseTypeAttr(ITypeInfo* This, TYPEATTR* pTypeAttr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_ReleaseTypeAttr (%p)", This);
}
#endif // DEBUG
return;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_ReleaseTypeAttr(pTypeAttr);
}

static void STDMETHODCALLTYPE ITypeInfo_ReleaseFuncDesc(ITypeInfo* This, FUNCDESC* pFuncDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_ReleaseFuncDesc (%p)", This);
}
#endif // DEBUG
return;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_ReleaseFuncDesc(pFuncDesc);
}

static void STDMETHODCALLTYPE ITypeInfo_ReleaseVarDesc(ITypeInfo* This, VARDESC* pVarDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ITypeInfo_ReleaseVarDesc (%p)", This);
}
#endif // DEBUG
return;
//	return static_cast<PerlObjectWrapper::TypeInfo*>(This)->Wrapper()->TypeInfo_ReleaseVarDesc(pVarDesc);
}

static ITypeInfoVtbl PerlObjectWrapper_TypeInfoVtbl = {
	IUNKNOWN_INIT(TypeInfo)
	ITypeInfo_GetTypeAttr,
	ITypeInfo_GetTypeComp,
	ITypeInfo_GetFuncDesc,
	ITypeInfo_GetVarDesc,
	ITypeInfo_GetNames,
	ITypeInfo_GetRefTypeOfImplType,
	ITypeInfo_GetImplTypeFlags,
	ITypeInfo_GetIDsOfNames,
	ITypeInfo_Invoke,
	ITypeInfo_GetDocumentation,
	ITypeInfo_GetDllEntry,
	ITypeInfo_GetRefTypeInfo,
	ITypeInfo_AddressOfMember,
	ITypeInfo_CreateInstance,
	ITypeInfo_GetMops,
	ITypeInfo_GetContainingTypeLib,
	ITypeInfo_ReleaseTypeAttr,
	ITypeInfo_ReleaseFuncDesc,
	ITypeInfo_ReleaseVarDesc,
};

HRESULT PerlObjectWrapper::TypeInfo_GetTypeAttr(TYPEATTR** ppTypeAttr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetTypeAttr in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// ppTypeAttr

	PUTBACK;

	call_method("GetTypeAttr", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetTypeComp(ITypeComp** ppTComp) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetTypeComp in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// ppTComp

	PUTBACK;

	call_method("GetTypeComp", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetFuncDesc(UINT index, FUNCDESC** ppFuncDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetFuncDesc in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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
	mXPUSHu((UV)index);

// ppFuncDesc

	PUTBACK;

	call_method("GetFuncDesc", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetVarDesc(UINT index, VARDESC** ppVarDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetVarDesc in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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
	mXPUSHu((UV)index);

// ppVarDesc

	PUTBACK;

	call_method("GetVarDesc", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetNames(MEMBERID memid, BSTR* rgBstrNames, UINT cMaxNames, UINT* pcNames) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetNames in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 5); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	mXPUSHu((UV)cMaxNames);
	mXPUSHu((UV)pcNames);

	PUTBACK;

	call_method("GetNames", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetRefTypeOfImplType(UINT index, HREFTYPE* pRefType) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetRefTypeOfImplType in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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
	mXPUSHu((UV)index);

// pRefType

	PUTBACK;

	call_method("GetRefTypeOfImplType", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetImplTypeFlags(UINT index, INT* pImplTypeFlags) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetImplTypeFlags in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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
	mXPUSHu((UV)index);
	mXPUSHu((IV)pImplTypeFlags);

	PUTBACK;

	call_method("GetImplTypeFlags", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetIDsOfNames(LPOLESTR* rgszNames, UINT cNames, MEMBERID* pMemId) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetIDsOfNames in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 4); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	mXPUSHu((UV)cNames);

// pMemId

	PUTBACK;

	call_method("GetIDsOfNames", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_Invoke(PVOID pvInstance, MEMBERID memid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Invoke in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 8); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	mXPUSHu((UV)puArgErr);

// pvInstance
// memid
// wFlags
// pDispParams
// pVarResult
// pExcepInfo
// puArgErr

	PUTBACK;

	call_method("Invoke", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetDocumentation(MEMBERID memid, BSTR* pBstrName, BSTR* pBstrDocString, DWORD* pdwHelpContext, BSTR* pBstrHelpFile) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetDocumentation in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 6); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	mXPUSHu((UV)pdwHelpContext);

// memid
// pBstrName
// pBstrDocString
// pBstrHelpFile

	PUTBACK;

	call_method("GetDocumentation", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetDllEntry(MEMBERID memid, INVOKEKIND invKind, BSTR* pBstrDllName, BSTR* pBstrName, WORD* pwOrdinal) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetDllEntry in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 6); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// memid
// invKind
// pBstrDllName
// pBstrName
// pwOrdinal

	PUTBACK;

	call_method("GetDllEntry", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetRefTypeInfo(HREFTYPE hRefType, ITypeInfo** ppTInfo) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetRefTypeInfo in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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

// ppTInfo

	PUTBACK;

	call_method("GetRefTypeInfo", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_AddressOfMember(MEMBERID memid, INVOKEKIND invKind, PVOID* ppv) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("AddressOfMember in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 4); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// memid
// invKind
// ppv

	PUTBACK;

	call_method("AddressOfMember", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_CreateInstance(IUnknown* pUnkOuter, REFIID riid, PVOID* ppvObj) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CreateInstance in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 4); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	// pUnkOuter will be NULL

// riid
// ppvObj

	PUTBACK;

	call_method("CreateInstance", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetMops(MEMBERID memid, BSTR* pBstrMops) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetMops in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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

// memid
// pBstrMops

	PUTBACK;

	call_method("GetMops", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

HRESULT PerlObjectWrapper::TypeInfo_GetContainingTypeLib(ITypeLib** ppTLib, UINT* pIndex) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetContainingTypeLib in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
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
	mXPUSHu((UV)pIndex);

// ppTLib

	PUTBACK;

	call_method("GetContainingTypeLib", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

void PerlObjectWrapper::TypeInfo_ReleaseTypeAttr(TYPEATTR* pTypeAttr) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ReleaseTypeAttr in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// pTypeAttr

	PUTBACK;

	call_method("ReleaseTypeAttr", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

void PerlObjectWrapper::TypeInfo_ReleaseFuncDesc(FUNCDESC* pFuncDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ReleaseFuncDesc in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// pFuncDesc

	PUTBACK;

	call_method("ReleaseFuncDesc", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

void PerlObjectWrapper::TypeInfo_ReleaseVarDesc(VARDESC* pVarDesc) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ReleaseVarDesc in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

// pVarDesc

	PUTBACK;

	call_method("ReleaseVarDesc", G_DISCARD);
	SPAGAIN;

	FREETMPS;
	LEAVE;

	return S_OK;
}

*/

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

static std::map<IDispatch*, PerlObjectWrapper*> s_dispatch;

PerlObjectWrapper::PerlObjectWrapper(SV* perl_object) :
	HandlerBase(perl_object, "PerlObjectWrapper") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Creating object %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_IDispatch, (IDispatch*)(new Dispatch(this, &PerlObjectWrapper_DispatchVtbl)));
// JS currently not using the ITypeInfo
//	AddInterface(IID_ITypeInfo, (ITypeInfo*)(new TypeInfo(this, &PerlObjectWrapper_TypeInfoVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
//	Mortalize();

	s_dispatch[ (IDispatch*)GetInterface(IID_IDispatch) ] = this;
}

PerlObjectWrapper::~PerlObjectWrapper() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Destroying object %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
	s_dispatch.erase( (IDispatch*)GetInterface(IID_IDispatch) );

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass Dispatch containing interface IDispatch");
}
#endif // DEBUG
	Dispatch* dispatch = static_cast<Dispatch*>((IDispatch*)GetInterface(IID_IDispatch));
	delete dispatch;
}

SV* PerlObjectWrapper::GetPerlObjectForDispatch(IDispatch* iface) {
	if (s_dispatch.count(iface)) {
		PerlObjectWrapper* wrapper = s_dispatch[iface];
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Fetching wrapped object %p / %p from IDispatch %p", wrapper, wrapper->m_perl_object, iface);
}
#endif // DEBUG
		return wrapper->m_perl_object;
	}
	return NULL;
}
