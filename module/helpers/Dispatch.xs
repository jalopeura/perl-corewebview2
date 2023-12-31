MODULE = CoreWebView2	PACKAGE = CoreWebView2::Helper::Dispatch

PROTOTYPES: DISABLE

# new not needed; utils.cpp will call create_perl_object() directly

SV*
IDispatch::GetIDsOfNames(rgszNames_sv, lcid = LOCALE_USER_DEFAULT, iid_sv = NULL)
	INPUT:
		SV* rgszNames_sv;
		LCID lcid;
		SV* iid_sv;
	INIT:
		IID iid = IID_NULL;
		LPOLESTR* rgszNames;
		UINT cNames;
		DISPID* rgDispId;
		HRESULT result;
		SV* error_sv;
	CODE:
		if (iid_sv && SvOK(iid_sv)) {
			std::wstring s = scalar_to_wstring(iid_sv);
			result = IIDFromString(s.c_str(), &iid);
			CHECK_ERROR(result, error_sv);
		}

		AV* temp_array = (AV*)SvRV(rgszNames_sv);
		cNames = av_top_index(temp_array) + 1;
		rgszNames = (LPOLESTR*)CoTaskMemAlloc(cNames * sizeof(LPOLESTR));
		rgDispId = (DISPID*)CoTaskMemAlloc(cNames * sizeof(DISPID));

		SV** item;
		for (int i = 0; i < cNames; i++) {
			item = av_fetch(temp_array, i, 0);
			if (item == NULL) {
				warn("Missing item %d in aref passed to GetIDsOfNames", i);
				rgszNames[i] = NULL;
			}
			else {
				std::wstring s = scalar_to_wstring(*item);
				rgszNames[i] = (LPOLESTR)CoTaskMemAlloc((s.length() + 1) * 2);
				CopyMemory(rgszNames[i], s.c_str(), (s.length() + 1) * 2);
			}
		}

		result = ((IDispatch*)THIS)->lpVtbl->GetIDsOfNames(THIS, iid, rgszNames, cNames, lcid, rgDispId);
		CHECK_ERROR(result, error_sv);

		AV* out_array = newAV();
		for (int i = 0; i < cNames; i++) {
			av_push(out_array, newSVuv((UV)rgDispId[i]));
			CoTaskMemFree(rgszNames[i]);
		}
		RETVAL = newRV_noinc((SV*)out_array);
		CoTaskMemFree(rgszNames);

	OUTPUT:
		RETVAL

SV*
IDispatch::Invoke(dispIdMember, wFlags, wants_return = false, params_sv = NULL, lcid = LOCALE_USER_DEFAULT, iid_sv = NULL)
	INPUT:
		DISPID dispIdMember;
		WORD wFlags;
		BOOL wants_return;
		SV* params_sv;
		LCID lcid;
		SV* iid_sv;
	INIT:
		IID iid = IID_NULL;
		DISPPARAMS dispParams;
		VARIANT varResult;
		EXCEPINFO excepInfo;
		UINT uArgErr;
		HRESULT result;
		SV* error_sv;
	CODE:
		if (iid_sv && SvOK(iid_sv)) {
			std::wstring s = scalar_to_wstring(iid_sv);
			result = IIDFromString(s.c_str(), &iid);
			CHECK_ERROR(result, error_sv);
		}

		// pDispParams
		dispParams.cArgs = 0;
		dispParams.rgvarg = NULL;
		dispParams.cNamedArgs = 0;
		dispParams.rgdispidNamedArgs = NULL;
		if (params_sv) {
			// PROPERTYPUT must be passed by name
			// (where "name" is the integer id)
			if (wFlags & DISPATCH_PROPERTYPUT) {
				DISPID dispidNamedArg = DISPID_PROPERTYPUT;
				dispParams.cNamedArgs = 1;
				dispParams.rgdispidNamedArgs = &dispidNamedArg;
			}

			AV* temp_array = (AV*)SvRV(params_sv);
			dispParams.cArgs = av_top_index(temp_array) + 1;
			dispParams.rgvarg = (VARIANTARG*)CoTaskMemAlloc(dispParams.cArgs * sizeof(VARIANT));

			SV** item;
			for (int i = 0; i < dispParams.cArgs; i++) {
				item = av_fetch(temp_array, i, 0);
				if (item == NULL) {
					warn("Missing item %d in aref passed to GetIDsOfNames", i);
					dispParams.rgvarg[i] = scalar_to_variant(&PL_sv_undef);
				}
				else {
					dispParams.rgvarg[i] = scalar_to_variant(*item);
				}
			}
		}

		if (wants_return) {
			VariantInit(&varResult);
		}

		result = ((IDispatch*)THIS)->lpVtbl->Invoke(THIS, dispIdMember, iid, lcid, wFlags, &dispParams,
			(wants_return ? &varResult : NULL), &excepInfo, &uArgErr);

		// store off the return value before error checking
		if (result == 0 && wants_return) {
			RETVAL = variant_to_scalar(varResult);
		}

		// caller needs to free any VARIANTs it passed
		for (int i = 0; i < dispParams.cArgs; i++) {
			VariantClear(&dispParams.rgvarg[i]);
		}
		CoTaskMemFree(dispParams.rgvarg);

		// caller needs to free any returned VARIANT
		if (wants_return) {
			VariantClear(&varResult);
		}

		if (result == DISP_E_EXCEPTION ) {
			WARN("Exception: %s", SHORTEN(excepInfo.bstrDescription));
			CHECK_ERROR(excepInfo.wCode != 0 ? excepInfo.wCode : excepInfo.scode, error_sv);
		}
		if (result == DISP_E_TYPEMISMATCH || result == DISP_E_PARAMNOTFOUND) {
FATAL("handle parameter error");
		}

		// now that we've handled all the custom error checking, we can do the usual thing
		CHECK_ERROR(result, error_sv);

		if (! wants_return) {
			XSRETURN_UNDEF;
		}
	OUTPUT:
		RETVAL

SV*
IDispatch::GetKeys(lcid = LOCALE_USER_DEFAULT)
	INPUT:
		LCID lcid;
	INIT:
		UINT count;
		ITypeInfo* pTInfo;
		TYPEATTR* pTypeAttr;
		UINT num_ids;
		BSTR* rgBstrNames;
		HRESULT result;
		SV* error_sv;
	CODE:
		// does this item even provide type info?
		result = ((IDispatch*)THIS)->lpVtbl->GetTypeInfoCount(THIS, &count);
		if (result == E_NOTIMPL) {
			XSRETURN_UNDEF;
		}
		CHECK_ERROR(result, error_sv);
		if (count == 0) {
			warn("ITypeInfo not provided by IDispatch");
			XSRETURN_UNDEF;
		}

		// get the type info
		result = ((IDispatch*)THIS)->lpVtbl->GetTypeInfo(THIS, 0, lcid, &pTInfo);
		CHECK_ERROR(result, error_sv);

		// create the array;
		num_ids = pTypeAttr->cFuncs + pTypeAttr->cVars;
	//WARN("funcs: %d, vars: %d", pTypeAttr->cFuncs, pTypeAttr->cVars);
		rgBstrNames = (BSTR*)CoTaskMemAlloc(sizeof(BSTR)); // we only expect one name back
		AV* temp_array = newAV();
		SV* name_sv;
		for (MEMBERID i = 0; i < num_ids; i++) {
			result = pTInfo->lpVtbl->GetNames(pTInfo, i, rgBstrNames, 1, &count);
			CHECK_ERROR(result, error_sv);

			name_sv = wchar_to_scalar(rgBstrNames[0]);
			av_push(temp_array, name_sv);
		}
		RETVAL = newRV_noinc((SV*)temp_array);
	OUTPUT:
		RETVAL

# Note that this method is not prefixed by the class name.
#
# This is because if we prefix the class name the first argument is
# automatically converted into the THIS pointer, and we no longer have
# access to the Perl object. But we need that access in order to unlink
# the C++ object, and to clean up the Perl object.
void
DESTROY(perl_obj)
	INPUT:
		SV* perl_obj;
	CODE:
	#ifdef DEBUG
	WARN("About to call unlink_perl_object");
	#endif
		unlink_perl_object(perl_obj);
	#ifdef DEBUG
	WARN("Back from unlink_perl_object");
	#endif
