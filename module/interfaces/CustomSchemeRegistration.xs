#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::CustomSchemeRegistration

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2CustomSchemeRegistration::get_SchemeName()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
	#ifdef DEBUG
	WARN("%p", THIS);
	#endif
		result = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->get_SchemeName(THIS, &RETVAL);
	#ifdef DEBUG
	WARN("!");
	#endif
		CHECK_ERROR(result, error_sv);
	#ifdef DEBUG
	WARN("!");
	#endif
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2CustomSchemeRegistration::get_TreatAsSecure()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->get_TreatAsSecure(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CustomSchemeRegistration::put_TreatAsSecure(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->put_TreatAsSecure(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

void
ICoreWebView2CustomSchemeRegistration::GetAllowedOrigins()
	INIT:
		SV* allowedOrigins_item_sv;
		UINT32 allowedOriginsCount;
		LPWSTR* allowedOrigins;
		HRESULT result;
		SV* error_sv;
	PPCODE:
		result = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->GetAllowedOrigins(THIS, &allowedOriginsCount, &allowedOrigins);
		CHECK_ERROR(result, error_sv);

		U8 gimme = GIMME_V;
		// if caller wants a list, then we push the items one by one onto the stack
		if (gimme == G_LIST) {
			EXTEND(SP, allowedOriginsCount);
			for (UINT32 i = 0; i < allowedOriginsCount; i++) {
	#ifdef DEBUG
	WARN("Getting allowedOrigins[%d] = %s", i, SHORTEN(allowedOrigins[i]));
	#endif
				allowedOrigins_item_sv = wchar_to_scalar(allowedOrigins[i]);
	#ifdef DEBUG
	SV_DUMP(allowedOrigins_item_sv);
	#endif
				PUSHs(sv_2mortal(allowedOrigins_item_sv));
			}
		}
		// otherwise, we return a single aref
		else {
			EXTEND(SP, 1);
			AV* temp_array = newAV();
			for (UINT32 i = 0; i < allowedOriginsCount; i++) {
	#ifdef DEBUG
	WARN("Getting allowedOrigins[%d] = %s", i, SHORTEN(allowedOrigins[i]));
	#endif
				allowedOrigins_item_sv = wchar_to_scalar(allowedOrigins[i]);
	#ifdef DEBUG
	SV_DUMP(allowedOrigins_item_sv);
	#endif
				av_push(temp_array, allowedOrigins_item_sv);
			}
			PUSHs(sv_2mortal(newRV_noinc((SV*)temp_array)));
		}

		// since these strings have been copied to Perl SV, we now have to free them
		for (int i = 0; i < allowedOriginsCount; i++) {
			CoTaskMemFree(allowedOrigins[i]);
		}
		CoTaskMemFree(allowedOrigins);

HRESULT
ICoreWebView2CustomSchemeRegistration::SetAllowedOrigins(first, ...)
	INPUT:
		SV* first;
	INIT:
		bool is_aref;
		UINT32 allowedOriginsCount;
		LPCWSTR* allowedOrigins;
		SV* error_sv;
	CODE:
		// if there is only one item AND it is an aref, then we are processing an aref
		is_aref = (items == 1 && SvTYPE(first) == SVt_PVAV);
		allowedOriginsCount = is_aref ? av_top_index((AV*)SvRV(first)) + 1 : items;
		allowedOrigins = (LPCWSTR*)malloc(sizeof(LPCWSTR) * allowedOriginsCount);

		if (is_aref) {
			SV** item;
			AV* temp_array = (AV*)SvRV(first);
			for (int i = 0; i < allowedOriginsCount; i++) {
				item = av_fetch(temp_array, i, 0);
				std::wstring str = scalar_to_wstring(*item);
				allowedOrigins[i] = str.c_str();
			}
		}
		// otherwise, we are processing a list
		else {
			for (int i = 0; i < allowedOriginsCount; i++) {
				std::wstring str = scalar_to_wstring(ST(i));
				allowedOrigins[i] = str.c_str();
			}
		}

		RETVAL = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->SetAllowedOrigins(THIS, allowedOriginsCount, allowedOrigins);
		CHECK_ERROR(RETVAL, error_sv);

		// since these strings have been copied by the underlying object, we now have to free them
		for (int i = 0; i < allowedOriginsCount; i++) {
			free((void*)allowedOrigins[i]);
		}
		free(allowedOrigins);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2CustomSchemeRegistration::get_HasAuthorityComponent()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->get_HasAuthorityComponent(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2CustomSchemeRegistration::put_HasAuthorityComponent(hasAuthorityComponent)
	INPUT:
		BOOL hasAuthorityComponent;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2CustomSchemeRegistration*)THIS)->lpVtbl->put_HasAuthorityComponent(THIS, hasAuthorityComponent);
		CHECK_ERROR(RETVAL, error_sv);
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
		unlink_perl_object(perl_obj);
