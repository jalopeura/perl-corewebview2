#pragma once
#include "HandlerBase.h"

class PerlObjectWrapper : public HandlerBase {
public:
	PerlObjectWrapper(SV* perl_object);
	virtual ~PerlObjectWrapper();

	static SV* GetPerlObjectForDispatch(IDispatch* iface);

	PerlObjectWrapper(const PerlObjectWrapper&) = delete;
	PerlObjectWrapper(PerlObjectWrapper&&) = delete;
	PerlObjectWrapper& operator=(const PerlObjectWrapper&) = delete;
	PerlObjectWrapper& operator=(PerlObjectWrapper&&) = delete;

	// IUnknown and utility methods inherited from HandlerBase

	// IDispatch
	WRAP_INTERFACE(Dispatch, IDispatch, PerlObjectWrapper)

	HRESULT Dispatch_GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId);
	HRESULT Dispatch_Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams,
		VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr);


// JS currently not using the ITypeInfo
//	// ITypeInfo
//	WRAP_INTERFACE(TypeInfo, ITypeInfo, PerlObjectWrapper)
//
//	HRESULT TypeInfo_GetTypeAttr(TYPEATTR** ppTypeAttr);
//	HRESULT TypeInfo_GetTypeComp(ITypeComp** ppTComp);
//	HRESULT TypeInfo_GetFuncDesc(UINT index, FUNCDESC** ppFuncDesc);
//	HRESULT TypeInfo_GetVarDesc(UINT index, VARDESC** ppVarDesc);
//	HRESULT TypeInfo_GetNames(MEMBERID memid, BSTR* rgBstrNames, UINT cMaxNames, UINT* pcNames);
//	HRESULT TypeInfo_GetRefTypeOfImplType(UINT index, HREFTYPE* pRefType);
//	HRESULT TypeInfo_GetImplTypeFlags(UINT index, INT* pImplTypeFlags);
//	HRESULT TypeInfo_GetIDsOfNames(LPOLESTR* rgszNames, UINT cNames, MEMBERID* pMemId);
//	HRESULT TypeInfo_Invoke(PVOID pvInstance, MEMBERID memid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr);
//	HRESULT TypeInfo_GetDocumentation(MEMBERID memid, BSTR* pBstrName, BSTR* pBstrDocString, DWORD* pdwHelpContext, BSTR* pBstrHelpFile);
//	HRESULT TypeInfo_GetDllEntry(MEMBERID memid, INVOKEKIND invKind, BSTR* pBstrDllName, BSTR* pBstrName, WORD* pwOrdinal);
//	HRESULT TypeInfo_GetRefTypeInfo(HREFTYPE hRefType, ITypeInfo** ppTInfo);
//	HRESULT vAddressOfMember(MEMBERID memid, INVOKEKIND invKind, PVOID* ppv);
//	HRESULT TypeInfo_CreateInstance(IUnknown* pUnkOuter, REFIID riid, PVOID* ppvObj);
//	HRESULT TypeInfo_GetMops(MEMBERID memid, BSTR* pBstrMops);
//	HRESULT TypeInfo_GetContainingTypeLib(ITypeLib** ppTLib, UINT* pIndex);
//	void TypeInfo_ReleaseTypeAttr(TYPEATTR* pTypeAttr);
//	void TypeInfo_ReleaseFuncDesc(FUNCDESC* pFuncDesc);
//	void TypeInfo_ReleaseVarDesc(VARDESC* pVarDesc);
};
