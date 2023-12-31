#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Profile

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2Profile8::get_ProfileName()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_ProfileName(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Profile8::get_IsInPrivateModeEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_IsInPrivateModeEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Profile8::get_ProfilePath()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_ProfilePath(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2Profile8::get_DefaultDownloadFolderPath()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_DefaultDownloadFolderPath(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::put_DefaultDownloadFolderPath(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->put_DefaultDownloadFolderPath(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PREFERRED_COLOR_SCHEME
ICoreWebView2Profile8::get_PreferredColorScheme()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_PreferredColorScheme(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::put_PreferredColorScheme(value)
	INPUT:
		COREWEBVIEW2_PREFERRED_COLOR_SCHEME value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->put_PreferredColorScheme(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::ClearBrowsingData(dataKinds, handler)
	INPUT:
		COREWEBVIEW2_BROWSING_DATA_KINDS dataKinds;
		ICoreWebView2ClearBrowsingDataCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->ClearBrowsingData(THIS, dataKinds, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::ClearBrowsingDataInTimeRange(dataKinds, startTime, endTime, handler)
	INPUT:
		COREWEBVIEW2_BROWSING_DATA_KINDS dataKinds;
		double startTime;
		double endTime;
		ICoreWebView2ClearBrowsingDataCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->ClearBrowsingDataInTimeRange(THIS, dataKinds, startTime, endTime, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::ClearBrowsingDataAll(handler)
	INPUT:
		ICoreWebView2ClearBrowsingDataCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->ClearBrowsingDataAll(THIS, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_TRACKING_PREVENTION_LEVEL
ICoreWebView2Profile8::get_PreferredTrackingPreventionLevel()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_PreferredTrackingPreventionLevel(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::put_PreferredTrackingPreventionLevel(value)
	INPUT:
		COREWEBVIEW2_TRACKING_PREVENTION_LEVEL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->put_PreferredTrackingPreventionLevel(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::SetPermissionState(permissionKind, origin, state, completedHandler)
	INPUT:
		COREWEBVIEW2_PERMISSION_KIND permissionKind;
		LPCWSTR origin;
		COREWEBVIEW2_PERMISSION_STATE state;
		ICoreWebView2SetPermissionStateCompletedHandler* completedHandler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->SetPermissionState(THIS, permissionKind, origin, state, completedHandler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::GetNonDefaultPermissionSettings(completedHandler)
	INPUT:
		ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler* completedHandler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->GetNonDefaultPermissionSettings(THIS, completedHandler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2CookieManager*
ICoreWebView2Profile8::get_CookieManager()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_CookieManager(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Profile8::get_IsPasswordAutosaveEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_IsPasswordAutosaveEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::put_IsPasswordAutosaveEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->put_IsPasswordAutosaveEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Profile8::get_IsGeneralAutofillEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->get_IsGeneralAutofillEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::put_IsGeneralAutofillEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->put_IsGeneralAutofillEnabled(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::AddBrowserExtension(extensionFolderPath, handler)
	INPUT:
		LPCWSTR extensionFolderPath;
		ICoreWebView2ProfileAddBrowserExtensionCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->AddBrowserExtension(THIS, extensionFolderPath, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::GetBrowserExtensions(handler)
	INPUT:
		ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->GetBrowserExtensions(THIS, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::Delete()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->Delete(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Profile8::add_Deleted(eventHandler)
	INPUT:
		ICoreWebView2ProfileDeletedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Profile8*)THIS)->lpVtbl->add_Deleted(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Profile8::remove_Deleted(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Profile8*)THIS)->lpVtbl->remove_Deleted(THIS, token);
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
