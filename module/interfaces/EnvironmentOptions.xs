#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::EnvironmentOptions

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2EnvironmentOptions::get_AdditionalBrowserArguments()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->get_AdditionalBrowserArguments(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions::put_AdditionalBrowserArguments(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->put_AdditionalBrowserArguments(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2EnvironmentOptions::get_Language()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->get_Language(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions::put_Language(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->put_Language(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2EnvironmentOptions::get_TargetCompatibleBrowserVersion()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->get_TargetCompatibleBrowserVersion(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions::put_TargetCompatibleBrowserVersion(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->put_TargetCompatibleBrowserVersion(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2EnvironmentOptions::get_AllowSingleSignOnUsingOSPrimaryAccount()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->get_AllowSingleSignOnUsingOSPrimaryAccount(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions::put_AllowSingleSignOnUsingOSPrimaryAccount(allow)
	INPUT:
		BOOL allow;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions*)THIS)->lpVtbl->put_AllowSingleSignOnUsingOSPrimaryAccount(THIS, allow);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2EnvironmentOptions2::get_ExclusiveUserDataFolderAccess()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions2*)THIS)->lpVtbl->get_ExclusiveUserDataFolderAccess(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions2::put_ExclusiveUserDataFolderAccess(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions2*)THIS)->lpVtbl->put_ExclusiveUserDataFolderAccess(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2EnvironmentOptions3::get_IsCustomCrashReportingEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions3*)THIS)->lpVtbl->get_IsCustomCrashReportingEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions3::put_IsCustomCrashReportingEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions3*)THIS)->lpVtbl->put_IsCustomCrashReportingEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

void
ICoreWebView2EnvironmentOptions4::GetCustomSchemeRegistrations()
	INIT:
		SV* schemeRegistrations_item_sv;
		UINT32 count;
		ICoreWebView2CustomSchemeRegistration** schemeRegistrations;
		bool was_known;
		HRESULT result;
		SV* error_sv;
	PPCODE:
		result = ((ICoreWebView2EnvironmentOptions4*)THIS)->lpVtbl->GetCustomSchemeRegistrations(THIS, &count, &schemeRegistrations);
		CHECK_ERROR(result, error_sv);

		U8 gimme = GIMME_V;
		// if caller wants a list, then we push the items one by one onto the stack
		if (gimme == G_LIST) {
			EXTEND(SP, count);
			for (UINT32 i = 0; i < count; i++) {
				void* wrapper = static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(schemeRegistrations[i])->Wrapper();
	#ifdef DEBUG
	WARN("Getting wrapper object [%p]", wrapper);
	#endif
				schemeRegistrations_item_sv = sv_newmortal();
				create_perl_object(schemeRegistrations_item_sv, wrapper, "CoreWebView2::CustomSchemeRegistration");
				PUSHs(sv_2mortal(schemeRegistrations_item_sv));
			}
		}
		// otherwise, we return a single aref
		else {
			EXTEND(SP, 1);
			AV* temp_array = newAV();
			for (UINT32 i = 0; i < count; i++) {
	#ifdef DEBUG
	//LPWSTR name;
	//schemeRegistrations[i]->lpVtbl->get_SchemeName(schemeRegistrations[i], &name);
	//WARN("Copying allowedOrigins[%d] into perl object: %s\n", i, name);
	//free(name);
	WARN("schemeRegistrations[%d] at %p", i, schemeRegistrations[i]);
	//SV_WARN(schemeRegistrations_item_sv, "Copying to perl");
	#endif
				// convert the interface pointer into a pointer to the wrapper object
				void* wrapper = static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(schemeRegistrations[i])->Wrapper();
	#ifdef DEBUG
	WARN("Getting wrapper object [%p]", wrapper);
	#endif
				schemeRegistrations_item_sv = sv_newmortal();
				create_perl_object(schemeRegistrations_item_sv, wrapper, "CoreWebView2::CustomSchemeRegistration");
	#ifdef DEBUG
	//			else {
	//				WARN("Array item not sorted");
	//			}
	#endif
				av_push(temp_array, schemeRegistrations_item_sv);
				SvREFCNT_inc(schemeRegistrations_item_sv);
	#ifdef DEBUG
	//SV_WARN(schemeRegistrations_item_sv, "Pushed onto array");
	#endif
			}
	#ifdef DEBUG
	//SV_WARN((SV*)temp_array, "Copied to perl");
	#endif
			PUSHs(sv_2mortal(newRV_noinc((SV*)temp_array)));
		}

		// we called AddRef() on the objects in the array, but that reference will be taken care of when the owning Perl object goes out of scope
		// so we don't need to call Release() here
		CoTaskMemFree(schemeRegistrations);
	#ifdef DEBUG
	WARN("Got here");
	#endif

HRESULT
ICoreWebView2EnvironmentOptions4::SetCustomSchemeRegistrations(first, ...)
	INPUT:
		SV* first;
	INIT:
		bool is_aref;
		UINT32 count;
		ICoreWebView2CustomSchemeRegistration** schemeRegistrations;
		SV* error_sv;
	CODE:
		// if there is only one item AND it is an aref, then we are processing an aref
		is_aref = (items == 1 && SvTYPE(first) == SVt_PVAV);
		count = is_aref ? av_top_index((AV*)SvRV(first)) + 1 : items;
		schemeRegistrations = (ICoreWebView2CustomSchemeRegistration**)malloc(sizeof(ICoreWebView2CustomSchemeRegistration*) * count);

		if (is_aref) {
			SV** item;
			AV* temp_array = (AV*)SvRV(first);
			for (int i = 0; i < count; i++) {
				item = av_fetch(temp_array, i, 0);
				schemeRegistrations[i] = (ICoreWebView2CustomSchemeRegistration*)get_custom_registration(*item, IID_ICoreWebView2CustomSchemeRegistration);
			}
		}
		// otherwise, we are processing a list
		else {
			for (int i = 0; i < count; i++) {
				schemeRegistrations[i] = (ICoreWebView2CustomSchemeRegistration*)get_custom_registration(ST(i), IID_ICoreWebView2CustomSchemeRegistration);
			}
		}

		RETVAL = ((ICoreWebView2EnvironmentOptions4*)THIS)->lpVtbl->SetCustomSchemeRegistrations(THIS, count, schemeRegistrations);
		CHECK_ERROR(RETVAL, error_sv);

		// caller gets ownership of 1 reference to each object returned from get_custom_registration()
		// and EnvironmentOptions calls AddRef() on each one with SetCustomSchemeRegistrations()
		// so we need to call Release() now that we're done with it
		for (int i = 0; i < count; i++) {
			schemeRegistrations[i]->lpVtbl->Release(schemeRegistrations[i]);
		}
		free(schemeRegistrations);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2EnvironmentOptions5::get_EnableTrackingPrevention()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions5*)THIS)->lpVtbl->get_EnableTrackingPrevention(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions5::put_EnableTrackingPrevention(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions5*)THIS)->lpVtbl->put_EnableTrackingPrevention(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2EnvironmentOptions6::get_AreBrowserExtensionsEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2EnvironmentOptions6*)THIS)->lpVtbl->get_AreBrowserExtensionsEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2EnvironmentOptions6::put_AreBrowserExtensionsEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2EnvironmentOptions6*)THIS)->lpVtbl->put_AreBrowserExtensionsEnabled(THIS, value);
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
