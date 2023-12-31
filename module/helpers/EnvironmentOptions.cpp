#include "EnvironmentOptions.h"
#include "CustomSchemeRegistration.h"

#ifdef DEBUG
#define DEBUG_TAG "EnvironmentOptions"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2EnvironmentOptions
 */

IUNKNOWN_DEFS(EnvironmentOptions1, ICoreWebView2EnvironmentOptions, EnvironmentOptions)

static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_AdditionalBrowserArguments(ICoreWebView2EnvironmentOptions* This, LPWSTR* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_AdditionalBrowserArguments: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->get_AdditionalBrowserArguments(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_AdditionalBrowserArguments(ICoreWebView2EnvironmentOptions* This, LPCWSTR value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_AdditionalBrowserArguments: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->put_AdditionalBrowserArguments(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_Language(ICoreWebView2EnvironmentOptions* This, LPWSTR* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_Language: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->get_Language(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_Language(ICoreWebView2EnvironmentOptions* This, LPCWSTR value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_Language: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->put_Language(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_TargetCompatibleBrowserVersion(ICoreWebView2EnvironmentOptions* This, LPWSTR* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_TargetCompatibleBrowserVersion: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->get_TargetCompatibleBrowserVersion(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_TargetCompatibleBrowserVersion(ICoreWebView2EnvironmentOptions* This, LPCWSTR value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_TargetCompatibleBrowserVersion: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->put_TargetCompatibleBrowserVersion(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_AllowSingleSignOnUsingOSPrimaryAccount(ICoreWebView2EnvironmentOptions* This, BOOL* allow) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_AllowSingleSignOnUsingOSPrimaryAccount: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->get_AllowSingleSignOnUsingOSPrimaryAccount(allow);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_AllowSingleSignOnUsingOSPrimaryAccount(ICoreWebView2EnvironmentOptions* This, BOOL allow) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_AllowSingleSignOnUsingOSPrimaryAccount: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions1*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions1*>(This)->Wrapper()->put_AllowSingleSignOnUsingOSPrimaryAccount(allow);
}

static ICoreWebView2EnvironmentOptionsVtbl EnvironmentOptionsVtbl = {
	IUNKNOWN_INIT(EnvironmentOptions1)
	EnvironmentOptions_get_AdditionalBrowserArguments,
	EnvironmentOptions_put_AdditionalBrowserArguments,
	EnvironmentOptions_get_Language,
	EnvironmentOptions_put_Language,
	EnvironmentOptions_get_TargetCompatibleBrowserVersion,
	EnvironmentOptions_put_TargetCompatibleBrowserVersion,
	EnvironmentOptions_get_AllowSingleSignOnUsingOSPrimaryAccount,
	EnvironmentOptions_put_AllowSingleSignOnUsingOSPrimaryAccount,
};

HRESULT EnvironmentOptions::get_AdditionalBrowserArguments(LPWSTR* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_AdditionalBrowserArguments (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_AdditionalBrowserArguments == NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("!");
}
#endif // DEBUG
		*value = NULL;
		//*value = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR));
		//(*value)[0] = 0;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning NULL");
}
#endif // DEBUG
	}
	else {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("%p", m_AdditionalBrowserArguments);
}
#endif // DEBUG
		size_t size = wcslen(m_AdditionalBrowserArguments) + 1;
		*value = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR) * size); // output strings MUST use CoTaskMemAlloc
		wcscpy(*value, m_AdditionalBrowserArguments);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning [%s]", SHORTEN(*value));
}
#endif // DEBUG
	}
	return S_OK;
}

HRESULT EnvironmentOptions::put_AdditionalBrowserArguments(LPCWSTR value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_AdditionalBrowserArguments (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_AdditionalBrowserArguments) {
		free(m_AdditionalBrowserArguments);
	}

	size_t size = wcslen(value) + 1;
	m_AdditionalBrowserArguments = (LPWSTR)malloc(sizeof(LPWSTR) * size);
	wcscpy(m_AdditionalBrowserArguments, value);
	return S_OK;
}

HRESULT EnvironmentOptions::get_Language(LPWSTR* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_Language (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_Language == NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("!");
}
#endif // DEBUG
		*value = NULL;
		//*value = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR));
		//(*value)[0] = 0;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning NULL");
}
#endif // DEBUG
	}
	else {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("%p", m_Language);
}
#endif // DEBUG
		size_t size = wcslen(m_Language) + 1;
		*value = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR) * size); // output strings MUST use CoTaskMemAlloc
		wcscpy(*value, m_Language);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning [%s]", SHORTEN(*value));
}
#endif // DEBUG
	}
	return S_OK;
}

HRESULT EnvironmentOptions::put_Language(LPCWSTR value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_Language (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_Language) {
		free(m_Language);
	}

	size_t size = wcslen(value) + 1;
	m_Language = (LPWSTR)malloc(sizeof(LPWSTR) * size);
	wcscpy(m_Language, value);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Updated to [%s]", SHORTEN(m_Language));
}
#endif // DEBUG
	return S_OK;
}

HRESULT EnvironmentOptions::get_TargetCompatibleBrowserVersion(LPWSTR* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_TargetCompatibleBrowserVersion (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_TargetCompatibleBrowserVersion == NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("!");
}
#endif // DEBUG
		*value = NULL;
		//*value = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR));
		//(*value)[0] = 0;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning NULL");
}
#endif // DEBUG
	}
	else {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("m_TargetCompatibleBrowserVersion pointer: %p", m_TargetCompatibleBrowserVersion);
}
#endif // DEBUG
		size_t size = wcslen(m_TargetCompatibleBrowserVersion) + 1;
		*value = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR) * size); // output strings MUST use CoTaskMemAlloc
		wcscpy(*value, m_TargetCompatibleBrowserVersion);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning [%s]", SHORTEN(*value));
}
#endif // DEBUG
	}
	return S_OK;
}

HRESULT EnvironmentOptions::put_TargetCompatibleBrowserVersion(LPCWSTR value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_TargetCompatibleBrowserVersion (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_TargetCompatibleBrowserVersion) {
		free(m_TargetCompatibleBrowserVersion);
	}

	size_t size = wcslen(value) + 1;
	m_TargetCompatibleBrowserVersion = (LPWSTR)malloc(sizeof(LPWSTR) * size);
	wcscpy(m_TargetCompatibleBrowserVersion, value);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Updated to [%s]", SHORTEN(m_TargetCompatibleBrowserVersion));
}
#endif // DEBUG
	return S_OK;
}

HRESULT EnvironmentOptions::get_AllowSingleSignOnUsingOSPrimaryAccount(BOOL* allow) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_AllowSingleSignOnUsingOSPrimaryAccount (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*allow = m_AllowSingleSignOnUsingOSPrimaryAccount;
	return S_OK;
}

HRESULT EnvironmentOptions::put_AllowSingleSignOnUsingOSPrimaryAccount(BOOL allow) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_AllowSingleSignOnUsingOSPrimaryAccount (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_AllowSingleSignOnUsingOSPrimaryAccount = allow;
	return S_OK;
}

/*
 * ICoreWebView2EnvironmentOptions2
 */

IUNKNOWN_DEFS(EnvironmentOptions2, ICoreWebView2EnvironmentOptions2, EnvironmentOptions)

static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_ExclusiveUserDataFolderAccess(ICoreWebView2EnvironmentOptions2* This, BOOL* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_ExclusiveUserDataFolderAccess: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions2*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions2*>(This)->Wrapper()->get_ExclusiveUserDataFolderAccess(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_ExclusiveUserDataFolderAccess(ICoreWebView2EnvironmentOptions2* This, BOOL value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_ExclusiveUserDataFolderAccess: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions2*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions2*>(This)->Wrapper()->put_ExclusiveUserDataFolderAccess(value);
}

static ICoreWebView2EnvironmentOptions2Vtbl EnvironmentOptions2Vtbl = {
	IUNKNOWN_INIT(EnvironmentOptions2)
	EnvironmentOptions_get_ExclusiveUserDataFolderAccess,
	EnvironmentOptions_put_ExclusiveUserDataFolderAccess,
};

HRESULT EnvironmentOptions::get_ExclusiveUserDataFolderAccess(BOOL* exclusive) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_ExclusiveUserDataFolderAccess (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*exclusive = m_ExclusiveUserDataFolderAccess;
	return S_OK;
}

HRESULT EnvironmentOptions::put_ExclusiveUserDataFolderAccess(BOOL exclusive) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_ExclusiveUserDataFolderAccess (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_ExclusiveUserDataFolderAccess = exclusive;
	return S_OK;
}

/*
 * ICoreWebView2EnvironmentOptions3
 */

IUNKNOWN_DEFS(EnvironmentOptions3, ICoreWebView2EnvironmentOptions3, EnvironmentOptions)

static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_IsCustomCrashReportingEnabled(ICoreWebView2EnvironmentOptions3* This, BOOL* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_IsCustomCrashReportingEnabled: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions3*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions3*>(This)->Wrapper()->get_IsCustomCrashReportingEnabled(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_IsCustomCrashReportingEnabled(ICoreWebView2EnvironmentOptions3* This, BOOL value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_IsCustomCrashReportingEnabled: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions3*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions3*>(This)->Wrapper()->put_IsCustomCrashReportingEnabled(value);
}

static ICoreWebView2EnvironmentOptions3Vtbl EnvironmentOptions3Vtbl = {
	IUNKNOWN_INIT(EnvironmentOptions3)
	EnvironmentOptions_get_IsCustomCrashReportingEnabled,
	EnvironmentOptions_put_IsCustomCrashReportingEnabled,
};

HRESULT EnvironmentOptions::get_IsCustomCrashReportingEnabled(BOOL* custom) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_IsCustomCrashReportingEnabled (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*custom = m_IsCustomCrashReportingEnabled;
	return S_OK;
}

HRESULT EnvironmentOptions::put_IsCustomCrashReportingEnabled(BOOL custom) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_IsCustomCrashReportingEnabled (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_IsCustomCrashReportingEnabled = custom;
	return S_OK;
}

/*
 * ICoreWebView2EnvironmentOptions4
 */

IUNKNOWN_DEFS(EnvironmentOptions4, ICoreWebView2EnvironmentOptions4, EnvironmentOptions)

static HRESULT STDMETHODCALLTYPE EnvironmentOptions_GetCustomSchemeRegistrations(ICoreWebView2EnvironmentOptions4* This, UINT32* count, ICoreWebView2CustomSchemeRegistration*** schemeRegistrations) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetCustomSchemeRegistrations: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions4*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions4*>(This)->Wrapper()->GetCustomSchemeRegistrations(count, schemeRegistrations);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_SetCustomSchemeRegistrations(ICoreWebView2EnvironmentOptions4* This, UINT32 count, ICoreWebView2CustomSchemeRegistration** schemeRegistrations) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SetCustomSchemeRegistrations: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions4*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions4*>(This)->Wrapper()->SetCustomSchemeRegistrations(count, schemeRegistrations);
}

static ICoreWebView2EnvironmentOptions4Vtbl EnvironmentOptions4Vtbl = {
	IUNKNOWN_INIT(EnvironmentOptions4)
	EnvironmentOptions_GetCustomSchemeRegistrations,
	EnvironmentOptions_SetCustomSchemeRegistrations,
};

HRESULT EnvironmentOptions::GetCustomSchemeRegistrations(UINT32* count, ICoreWebView2CustomSchemeRegistration*** schemeRegistrations) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_ExclusiveUserDataFolderAccess (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (!count || !schemeRegistrations) {
		return E_POINTER;
	}
	*count = 0;
	if (m_customSchemeRegistrationsCount == 0) {
		*schemeRegistrations = nullptr;
		return S_OK;
	}
	else {
		*schemeRegistrations =
			(ICoreWebView2CustomSchemeRegistration**)CoTaskMemAlloc(sizeof(ICoreWebView2CustomSchemeRegistration*) *
			m_customSchemeRegistrationsCount); // output arrays MUST use CoTaskMemAlloc
		if (!*schemeRegistrations) {
			return HRESULT_FROM_WIN32(GetLastError());
		}
		for (UINT32 i = 0; i < m_customSchemeRegistrationsCount; i++) {
			(*schemeRegistrations)[i] = m_customSchemeRegistrations[i];
			(*schemeRegistrations)[i]->lpVtbl->AddRef((*schemeRegistrations)[i]); // output interfaces must call AddRef() (caller will own the reference)
#ifdef DEBUG
LPWSTR name;
(*schemeRegistrations)[i]->lpVtbl->get_SchemeName((*schemeRegistrations)[i], &name);
WARN("Copying schemeRegistrations[%d] (%s) out of incoming object\n", i, SHORTEN(name));
CoTaskMemFree(name);
#endif // DEBUG
		}
		*count = m_customSchemeRegistrationsCount;
		return S_OK;
	}
}

HRESULT EnvironmentOptions::SetCustomSchemeRegistrations(UINT32 count, ICoreWebView2CustomSchemeRegistration** schemeRegistrations) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_ExclusiveUserDataFolderAccess (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
	WARN("About to release existing registration");
}
if (debugme(DEBUG_TAG)) {
}
#endif // DEBUG
	ReleaseCustomSchemeRegistrations();
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("About to copy registrations into object");
}
#endif // DEBUG
	m_customSchemeRegistrations = (ICoreWebView2CustomSchemeRegistration**)malloc(sizeof(ICoreWebView2CustomSchemeRegistration*) * count);
	if (!m_customSchemeRegistrations) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Unable to allocate memory for %d objects", count);
}
#endif // DEBUG
		return GetLastError();
	}
	for (UINT32 i = 0; i < count; i++) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Doing %d of %d", i+1, count);
}
#endif // DEBUG
		m_customSchemeRegistrations[i] = schemeRegistrations[i];
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Copied interface (%p) to array inside object", m_customSchemeRegistrations[i]);
}
#endif // DEBUG

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("!");
}
#endif // DEBUG
LPWSTR name;

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("!");
}
#endif // DEBUG
m_customSchemeRegistrations[i]->lpVtbl->get_SchemeName(m_customSchemeRegistrations[i], &name);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Copying schemeRegistrations[%d] (%p) into object: %s\n", i, m_customSchemeRegistrations[i], SHORTEN(name));
}
#endif // DEBUG
CoTaskMemFree(name);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("!");
}
#endif // DEBUG
		m_customSchemeRegistrations[i]->lpVtbl->AddRef(m_customSchemeRegistrations[i]);
	}
	m_customSchemeRegistrationsCount = count;
	return S_OK;
}

void EnvironmentOptions::ReleaseCustomSchemeRegistrations() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ReleaseCustomSchemeRegistrations (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_customSchemeRegistrations) {
		for (UINT32 i = 0; i < m_customSchemeRegistrationsCount; i++) {
			m_customSchemeRegistrations[i]->lpVtbl->Release(m_customSchemeRegistrations[i]);
		}
		free(m_customSchemeRegistrations);
		m_customSchemeRegistrations = nullptr;
		m_customSchemeRegistrationsCount = 0;
	}
}

/*
 * ICoreWebView2EnvironmentOptions5
 */

IUNKNOWN_DEFS(EnvironmentOptions5, ICoreWebView2EnvironmentOptions5, EnvironmentOptions)

static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_EnableTrackingPrevention(ICoreWebView2EnvironmentOptions5* This, BOOL* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_EnableTrackingPrevention: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions5*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions5*>(This)->Wrapper()->get_EnableTrackingPrevention(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_EnableTrackingPrevention(ICoreWebView2EnvironmentOptions5* This, BOOL value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_EnableTrackingPrevention: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions5*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions5*>(This)->Wrapper()->put_EnableTrackingPrevention(value);
}

static ICoreWebView2EnvironmentOptions5Vtbl EnvironmentOptions5Vtbl = {
	IUNKNOWN_INIT(EnvironmentOptions5)
	EnvironmentOptions_get_EnableTrackingPrevention,
	EnvironmentOptions_put_EnableTrackingPrevention,
};

HRESULT EnvironmentOptions::get_EnableTrackingPrevention(BOOL* prevent) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_EnableTrackingPrevention (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*prevent = m_EnableTrackingPrevention;
	return S_OK;
}

HRESULT EnvironmentOptions::put_EnableTrackingPrevention(BOOL prevent) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_EnableTrackingPrevention (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_EnableTrackingPrevention = prevent;
	return S_OK;
}

/*
 * ICoreWebView2EnvironmentOptions5
 */

IUNKNOWN_DEFS(EnvironmentOptions6, ICoreWebView2EnvironmentOptions6, EnvironmentOptions)

static HRESULT STDMETHODCALLTYPE EnvironmentOptions_get_AreBrowserExtensionsEnabled(ICoreWebView2EnvironmentOptions6* This, BOOL* value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_AreBrowserExtensionsEnabled: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions6*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions6*>(This)->Wrapper()->get_AreBrowserExtensionsEnabled(value);
}
static HRESULT STDMETHODCALLTYPE EnvironmentOptions_put_AreBrowserExtensionsEnabled(ICoreWebView2EnvironmentOptions6* This, BOOL value) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_AreBrowserExtensionsEnabled: iface %p / object %p", This, static_cast<EnvironmentOptions::EnvironmentOptions6*>(This));
}
#endif // DEBUG
	return static_cast<EnvironmentOptions::EnvironmentOptions6*>(This)->Wrapper()->put_AreBrowserExtensionsEnabled(value);
}

static ICoreWebView2EnvironmentOptions6Vtbl EnvironmentOptions6Vtbl = {
	IUNKNOWN_INIT(EnvironmentOptions6)
	EnvironmentOptions_get_AreBrowserExtensionsEnabled,
	EnvironmentOptions_put_AreBrowserExtensionsEnabled,
};

HRESULT EnvironmentOptions::get_AreBrowserExtensionsEnabled(BOOL* enabled) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_AreBrowserExtensionsEnabled (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*enabled = m_AreBrowserExtensionsEnabled;
	return S_OK;
}

HRESULT EnvironmentOptions::put_AreBrowserExtensionsEnabled(BOOL enabled) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_AreBrowserExtensionsEnabled (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_AreBrowserExtensionsEnabled = enabled;
	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

EnvironmentOptions::EnvironmentOptions() : InterfaceWrapper("EnvironmentOptions") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2EnvironmentOptions,  (ICoreWebView2EnvironmentOptions*)(new EnvironmentOptions1(this, &EnvironmentOptionsVtbl)));
	AddInterface(IID_ICoreWebView2EnvironmentOptions2, (ICoreWebView2EnvironmentOptions2*)(new EnvironmentOptions2(this, &EnvironmentOptions2Vtbl)));
	AddInterface(IID_ICoreWebView2EnvironmentOptions3, (ICoreWebView2EnvironmentOptions3*)(new EnvironmentOptions3(this, &EnvironmentOptions3Vtbl)));
	AddInterface(IID_ICoreWebView2EnvironmentOptions4, (ICoreWebView2EnvironmentOptions4*)(new EnvironmentOptions4(this, &EnvironmentOptions4Vtbl)));
	AddInterface(IID_ICoreWebView2EnvironmentOptions5, (ICoreWebView2EnvironmentOptions5*)(new EnvironmentOptions5(this, &EnvironmentOptions5Vtbl)));
	AddInterface(IID_ICoreWebView2EnvironmentOptions6, (ICoreWebView2EnvironmentOptions6*)(new EnvironmentOptions6(this, &EnvironmentOptions6Vtbl)));

	// DO NOT Mortalize(), because the Perl object should own one reference
}

EnvironmentOptions::~EnvironmentOptions() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	ReleaseCustomSchemeRegistrations();

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass EnvironmentOptions1 containing interface ICoreWebView2EnvironmentOptions");
}
#endif // DEBUG
	EnvironmentOptions1* opt1 = static_cast<EnvironmentOptions1*>((ICoreWebView2EnvironmentOptions*)GetInterface(IID_ICoreWebView2EnvironmentOptions));
	delete opt1;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass EnvironmentOptions2 containing interface ICoreWebView2EnvironmentOptions2");
}
#endif // DEBUG
	EnvironmentOptions2* opt2 = static_cast<EnvironmentOptions2*>((ICoreWebView2EnvironmentOptions2*)GetInterface(IID_ICoreWebView2EnvironmentOptions2));
	delete opt2;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass EnvironmentOptions3 containing interface ICoreWebView2EnvironmentOptions3");
}
#endif // DEBUG
	EnvironmentOptions3* opt3 = static_cast<EnvironmentOptions3*>((ICoreWebView2EnvironmentOptions3*)GetInterface(IID_ICoreWebView2EnvironmentOptions3));
	delete opt3;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass EnvironmentOptions4 containing interface ICoreWebView2EnvironmentOptions4");
}
#endif // DEBUG
	EnvironmentOptions4* opt4 = static_cast<EnvironmentOptions4*>((ICoreWebView2EnvironmentOptions4*)GetInterface(IID_ICoreWebView2EnvironmentOptions4));
	delete opt4;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass EnvironmentOptions5 containing interface ICoreWebView2EnvironmentOptions5");
}
#endif // DEBUG
	EnvironmentOptions5* opt5 = static_cast<EnvironmentOptions5*>((ICoreWebView2EnvironmentOptions5*)GetInterface(IID_ICoreWebView2EnvironmentOptions5));
	delete opt5;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass EnvironmentOptions6 containing interface ICoreWebView2EnvironmentOptions6");
}
#endif // DEBUG
	EnvironmentOptions6* opt6 = static_cast<EnvironmentOptions6*>((ICoreWebView2EnvironmentOptions6*)GetInterface(IID_ICoreWebView2EnvironmentOptions6));
	delete opt6;
}

/*
 * helper function
 */

void* get_environment_options(SV* hashref, REFIID riid) {
	EnvironmentOptions* options = NULL;

	// check if hashref defined and a reference
	if (! (hashref && SvROK(hashref))) {
		return NULL;
	}

	// if we get here, hashref is a reference
	// check if it is an object, and if so, use that object
	HV* hash = (HV*)SvRV(hashref);
	if (SvOBJECT(hash)) {
		options = (EnvironmentOptions*)get_cpp_object(hashref);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Converting from blessed hashref (%p)", options);
}
#endif // DEBUG
		// caller will own a reference to the interface; if we create one for it, it owns the single
		// reference initialized during construction, but if we extract an existing object, we
		// need to increment the reference count
		options->AddRef();
	}
	else {
		// if we get here, hashref is an unblessed reference
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("About to create object");
}
#endif // DEBUG
		options = new EnvironmentOptions();
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Done creating object");
}
#endif // DEBUG

		// ICoreWebView2EnvironmentOptions
		if (hv_exists(hash, "AdditionalBrowserArguments", 26)) {
			SV** value_sv = hv_fetch(hash, "AdditionalBrowserArguments", 26, 0);
			if (value_sv) {
				std::wstring value = scalar_to_wstring(*value_sv);
				options->put_AdditionalBrowserArguments(value.c_str());
			}
		}
		if (hv_exists(hash, "Language", 8)) {
			SV** value_sv = hv_fetch(hash, "Language", 8, 0);
			if (value_sv) {
				std::wstring value = scalar_to_wstring(*value_sv);
				options->put_Language(value.c_str());
			}
		}
		if (hv_exists(hash, "TargetCompatibleBrowserVersion", 30)) {
			SV** value_sv = hv_fetch(hash, "TargetCompatibleBrowserVersion", 30, 0);
			if (value_sv) {
				std::wstring value = scalar_to_wstring(*value_sv);
				options->put_TargetCompatibleBrowserVersion(value.c_str());
			}
		}
		if (hv_exists(hash, "AllowSingleSignOnUsingOSPrimaryAccount", 38)) {
			SV** value_sv = hv_fetch(hash, "AllowSingleSignOnUsingOSPrimaryAccount", 38, 0);
			if (value_sv) {
				options->put_AllowSingleSignOnUsingOSPrimaryAccount(SvTRUE(*value_sv));
			}
		}
		// ICoreWebView2EnvironmentOptions2
		if (hv_exists(hash, "ExclusiveUserDataFolderAccess", 29)) {
			SV** value_sv = hv_fetch(hash, "ExclusiveUserDataFolderAccess", 29, 0);
			if (value_sv) {
				options->put_ExclusiveUserDataFolderAccess(SvTRUE(*value_sv));
			}
		}
		// ICoreWebView2EnvironmentOptions3
		if (hv_exists(hash, "IsCustomCrashReportingEnabled", 29)) {
			SV** value_sv = hv_fetch(hash, "IsCustomCrashReportingEnabled", 29, 0);
			if (value_sv) {
				options->put_IsCustomCrashReportingEnabled(SvTRUE(*value_sv));
			}
		}
		// ICoreWebView2EnvironmentOptions4
		if (hv_exists(hash, "CustomSchemeRegistrations", 25)) {
			SV** value_sv = hv_fetch(hash, "CustomSchemeRegistrations", 25, 0);
			if (value_sv) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	SV_WARN(*value_sv, "Got a hash item");
}
#endif // DEBUG
				AV* temp_array = (AV*)SvRV(*value_sv);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Dereferenced item");
}
#endif // DEBUG
				UINT32 count = av_top_index((AV*)temp_array) + 1;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got count %d", count);
}
#endif // DEBUG
				ICoreWebView2CustomSchemeRegistration** schemeRegistrations =
					(ICoreWebView2CustomSchemeRegistration**)malloc(sizeof(ICoreWebView2CustomSchemeRegistration*) * count);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Allocated memory");
}
#endif // DEBUG

				SV** item;
				for (int i = 0; i < count; i++) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tDoing %d", i+1);
}
#endif // DEBUG
					item = av_fetch(temp_array, i, 0);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tGot an item");
}
#endif // DEBUG
					if (item) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	SV_WARN(*item, "\tItem is valid");
}
#endif // DEBUG
						schemeRegistrations[i] = (ICoreWebView2CustomSchemeRegistration*)get_custom_registration(*item, IID_ICoreWebView2CustomSchemeRegistration);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("%p", schemeRegistrations[i]);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tAssigned to array");
}
#endif // DEBUG
					}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tDone %d", i+1);
}
#endif // DEBUG
				}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tDone array");
}
#endif // DEBUG
				options->SetCustomSchemeRegistrations(count, schemeRegistrations);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tSet property");
}
#endif // DEBUG

				// we didn't call AddRef on any of the objects in the array, because we're just passing them through
				// so we don't need to call Release() here
				free(schemeRegistrations);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tFreed memory");
}
#endif // DEBUG
			}
		}
		// ICoreWebView2EnvironmentOptions5
		if (hv_exists(hash, "EnableTrackingPrevention", 24)) {
			SV** value_sv = hv_fetch(hash, "EnableTrackingPrevention", 24, 0);
			if (value_sv) {
				options->put_EnableTrackingPrevention(SvTRUE(*value_sv));
			}
		}
	}

	if (riid == GUID_NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning bare object");
}
#endif // DEBUG
		return options;
	}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Getting interface");
}
#endif // DEBUG

	void* iface = options->GetInterface(riid);

	if (iface != NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got interface (%p)", iface);
}
#endif // DEBUG
		return iface;
	}

	croak("Requested interface not found in get_environment_options");
	return NULL;
}
