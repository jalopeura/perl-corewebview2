#include "CustomSchemeRegistration.h"

#ifdef DEBUG
#define DEBUG_TAG "CustomSchemeRegistration"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ICoreWebView2CustomSchemeRegistration
 */

IUNKNOWN_DEFS(CustomSchemeRegistration1, ICoreWebView2CustomSchemeRegistration, CustomSchemeRegistration)

static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_get_SchemeName(ICoreWebView2CustomSchemeRegistration* This, LPWSTR* name) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_SchemeName: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->get_SchemeName(name);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got %s", name);
}
#endif // DEBUG
}
static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_get_TreatAsSecure(ICoreWebView2CustomSchemeRegistration* This, BOOL* secure) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_TreatAsSecure: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->get_TreatAsSecure(secure);
}
static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_put_TreatAsSecure(ICoreWebView2CustomSchemeRegistration* This, BOOL secure) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_TreatAsSecure: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->put_TreatAsSecure(secure);
}
static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_GetAllowedOrigins(ICoreWebView2CustomSchemeRegistration* This, UINT32* allowedOriginsCount, LPWSTR** allowedOrigins) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetAllowedOrigins: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->GetAllowedOrigins(allowedOriginsCount, allowedOrigins);
}
static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_SetAllowedOrigins(ICoreWebView2CustomSchemeRegistration* This, UINT32 allowedOriginsCount, LPCWSTR* allowedOrigins) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SetAllowedOrigins: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->SetAllowedOrigins(allowedOriginsCount, allowedOrigins);
}
static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_get_HasAuthorityComponent(ICoreWebView2CustomSchemeRegistration* This, BOOL* has_auth) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_HasAuthorityComponent: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->get_HasAuthorityComponent(has_auth);
}
static HRESULT STDMETHODCALLTYPE CustomSchemeRegistration_put_HasAuthorityComponent(ICoreWebView2CustomSchemeRegistration* This, BOOL has_auth) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_HasAuthorityComponent: iface %p / object %p", This, static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This));
}
#endif // DEBUG
	return static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>(This)->Wrapper()->put_HasAuthorityComponent(has_auth);
}

static ICoreWebView2CustomSchemeRegistrationVtbl CustomSchemeRegistrationVtbl = {
	IUNKNOWN_INIT(CustomSchemeRegistration1)
	CustomSchemeRegistration_get_SchemeName,
	CustomSchemeRegistration_get_TreatAsSecure,
	CustomSchemeRegistration_put_TreatAsSecure,
	CustomSchemeRegistration_GetAllowedOrigins,
	CustomSchemeRegistration_SetAllowedOrigins,
	CustomSchemeRegistration_get_HasAuthorityComponent,
	CustomSchemeRegistration_put_HasAuthorityComponent,
};

// ICoreWebView2CustomSchemeRegistration

HRESULT CustomSchemeRegistration::get_SchemeName(LPWSTR* schemeName) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_SchemeName (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("1 (%s)", SHORTEN(m_schemeName));
}
#endif // DEBUG
	size_t size = wcslen(m_schemeName) + 1;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("2 (%d)", size-1);
}
#endif // DEBUG
	*schemeName = (LPWSTR)CoTaskMemAlloc(sizeof(LPWSTR) * size); // output strings MUST use CoTaskMemAlloc
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("3", *schemeName);
}
#endif // DEBUG
	wcscpy(*schemeName, m_schemeName);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("4 (%s)", SHORTEN(*schemeName));
}
#endif // DEBUG
	return S_OK;
}

HRESULT CustomSchemeRegistration::get_TreatAsSecure(BOOL* secure) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_TreatAsSecure (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*secure = m_TreatAsSecure;
	return S_OK;
}

HRESULT CustomSchemeRegistration::put_TreatAsSecure(BOOL secure) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_TreatAsSecure (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_TreatAsSecure = secure;
	return S_OK;
}

HRESULT CustomSchemeRegistration::GetAllowedOrigins(UINT32* allowedOriginsCount, LPWSTR** allowedOrigins) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("GetAllowedOrigins (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (!allowedOrigins || !allowedOriginsCount) {
		return E_POINTER;
	}
	*allowedOriginsCount = 0;
	if (m_allowedOriginsCount == 0) {
		*allowedOrigins = NULL;
		return S_OK;
	}
	else {
		*allowedOrigins = (LPWSTR*)CoTaskMemAlloc(sizeof(LPWSTR) * m_allowedOriginsCount); // output arrays MUST use CoTaskMemAlloc
		if (!(*allowedOrigins)) {
			return HRESULT_FROM_WIN32(GetLastError());
		}
		ZeroMemory(*allowedOrigins, m_allowedOriginsCount * sizeof(LPWSTR));
		for (UINT32 i = 0; i < m_allowedOriginsCount; i++) {
			size_t size = wcslen(m_allowedOrigins[i]) + 1;
			(*allowedOrigins)[i] = (LPWSTR)CoTaskMemAlloc(sizeof(*m_allowedOrigins[i]) * size); // output strings MUST use CoTaskMemAlloc
			wcscpy((*allowedOrigins)[i], m_allowedOrigins[i]);
			if (!(*allowedOrigins)[i]) {
				HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
				for (UINT32 j = 0; j < i; j++) {
					CoTaskMemFree((*allowedOrigins)[j]);
				}
				CoTaskMemFree(*allowedOrigins);
				*allowedOrigins = NULL;
				return hr;
			}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("allowedOrigins[%d] = %s", i, SHORTEN((*allowedOrigins)[i]));
}
#endif // DEBUG
		}
		*allowedOriginsCount = m_allowedOriginsCount;
		return S_OK;
	}
}

HRESULT CustomSchemeRegistration::SetAllowedOrigins(UINT32 allowedOriginsCount, LPCWSTR* allowedOrigins) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SetAllowedOrigins (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	ReleaseAllowedOrigins();
	if (allowedOriginsCount == 0) {
		return S_OK;
	}
	else {
		m_allowedOrigins = (LPWSTR*)malloc(sizeof(LPWSTR) * allowedOriginsCount);
		if (!m_allowedOrigins) {
			return HRESULT_FROM_WIN32(GetLastError());
		}
		for (UINT32 i = 0; i < allowedOriginsCount; i++) {
			// is there going to be a problem here with the original expecting comemstring?
			size_t size = wcslen(allowedOrigins[i]) + 1;
			m_allowedOrigins[i] = (LPWSTR)malloc(sizeof(allowedOrigins[i]) * size);
			wcscpy(m_allowedOrigins[i], allowedOrigins[i]);
			if (!m_allowedOrigins[i]) {
				HRESULT hr = HRESULT_FROM_WIN32(GetLastError());
				for (UINT32 j = 0; j < i; j++) {
					free(m_allowedOrigins[j]);
				}
				m_allowedOriginsCount = 0;
				free(m_allowedOrigins);
				m_allowedOrigins = NULL;
				return hr;
			}
		}
		m_allowedOriginsCount = allowedOriginsCount;
		return S_OK;
	}
}

void CustomSchemeRegistration::ReleaseAllowedOrigins() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("ReleaseAllowedOrigins (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (m_allowedOrigins) {
		delete[] (m_allowedOrigins);
		m_allowedOrigins = NULL;
	}
	if (m_allowedOrigins) {
		for (UINT32 i = 0; i < m_allowedOriginsCount; i++) {
			free(m_allowedOrigins[i]);
		}
		free(m_allowedOrigins);
		m_allowedOrigins = NULL;
		m_allowedOriginsCount = 0;
	}
}

HRESULT CustomSchemeRegistration::get_HasAuthorityComponent(BOOL* has_auth) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("get_HasAuthorityComponent (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	*has_auth = m_HasAuthorityComponent;
	return S_OK;
}

HRESULT CustomSchemeRegistration::put_HasAuthorityComponent(BOOL has_auth) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("put_HasAuthorityComponent (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_HasAuthorityComponent = has_auth;
	return S_OK;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

CustomSchemeRegistration::CustomSchemeRegistration() {
	m_typename = "CustomSchemeRegistration";
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ICoreWebView2CustomSchemeRegistration, (ICoreWebView2CustomSchemeRegistration*)(new CustomSchemeRegistration1(this, &CustomSchemeRegistrationVtbl)));

}

CustomSchemeRegistration::CustomSchemeRegistration(LPCWSTR schemeName, BOOL secure, UINT32 allowedOriginsCount,
	LPCWSTR* allowedOrigins, BOOL has_auth) : InterfaceWrapper("CustomSchemeRegistration"),
	m_TreatAsSecure{secure}, m_HasAuthorityComponent{has_auth} {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	if (schemeName == NULL) {
		croak("Scheme name is required");
	}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("%s", SHORTEN(schemeName));
	}
#endif // DEBUG
	size_t size = wcslen(schemeName) + 1;
	m_schemeName = (LPWSTR)malloc(sizeof(schemeName) * size);
	wcscpy(m_schemeName, schemeName);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("%s", SHORTEN(m_schemeName));
	}
#endif // DEBUG

	if (allowedOriginsCount > 0) {
		SetAllowedOrigins(allowedOriginsCount, allowedOrigins);
	}

//	CustomSchemeRegistration1* child1 = new CustomSchemeRegistration1(this, &CustomSchemeRegistrationVtbl);
//	ICoreWebView2CustomSchemeRegistration* iface1 = (ICoreWebView2CustomSchemeRegistration*)child1;
//	AddInterface(IID_ICoreWebView2CustomSchemeRegistration, iface1);
	AddInterface(IID_ICoreWebView2CustomSchemeRegistration, (ICoreWebView2CustomSchemeRegistration*)(new CustomSchemeRegistration1(this, &CustomSchemeRegistrationVtbl)));

	// DO NOT Mortalize(), because the Perl object should own one reference

/*
WARN("%s", SHORTEN(m_schemeName));

WARN("!");
LPWSTR name;
WARN("!");
get_SchemeName(&name);
WARN("%s", SHORTEN(name));
CoTaskMemFree(name);

WARN("!");
iface1->lpVtbl->get_SchemeName(iface1, &name);
WARN("%s", SHORTEN(name));
CoTaskMemFree(name);
WARN("!");
*/
}

CustomSchemeRegistration::~CustomSchemeRegistration() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	free(m_schemeName);
	ReleaseAllowedOrigins();

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass CustomSchemeRegistration1 containing interface ICoreWebView2CustomSchemeRegistration");
}
#endif // DEBUG
	CustomSchemeRegistration1* reg = static_cast<CustomSchemeRegistration1*>((ICoreWebView2CustomSchemeRegistration*)GetInterface(IID_ICoreWebView2CustomSchemeRegistration));
	delete reg;
}

/*
 * helper function
 */

void* get_custom_registration(SV* hashref, REFIID riid) {
	CustomSchemeRegistration* registration = NULL;
	std::wstring schemeName;
	BOOL treatAsSecure = false;
	UINT32 allowedOriginsCount = 0;
	LPWSTR* allowedOrigins = NULL;
	BOOL hasAuthorityComponent = false;

	// allow a single string instead of a hashref
	if (hashref && ! SvROK(hashref)) {
		schemeName = scalar_to_wstring(hashref);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("About to create object");
}
#endif // DEBUG
		registration = new CustomSchemeRegistration(schemeName.c_str());
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Done creating object");
}
#endif // DEBUG
	}
	else {
		// check if hashref defined and a reference
		if (! (hashref && SvROK(hashref))) {
			return NULL;
		}

		// if we get here, hashref is a reference
		// check if it is an object, and if so, use that object
		HV* hash = (HV*)SvRV(hashref);
		if (SvOBJECT(hash)) {
			registration = (CustomSchemeRegistration*)get_cpp_object(hashref);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Converting from blessed hashref (%p)", registration);
}
#endif // DEBUG
			// caller will own a reference to the interface; if we create one for it, it owns the single
			// reference initialized during construction, but if we extract an existing object, we
			// need to increment the reference count
			registration->AddRef();
		}
		else {
			// CustomSchemeRegistration
			if (hv_exists(hash, "SchemeName", 10)) {
				SV** value_sv = hv_fetch(hash, "SchemeName", 10, 0);
				if (value_sv) {
					schemeName = scalar_to_wstring(*value_sv);
				}
			}
			if (hv_exists(hash, "TreatAsSecure", 13)) {
				SV** value_sv = hv_fetch(hash, "TreatAsSecure", 13, 0);
				if (value_sv) {
					treatAsSecure = SvTRUE(*value_sv);
				}
			}
			if (hv_exists(hash, "AllowedOrigins", 14)) {
				SV** value_sv = hv_fetch(hash, "AllowedOrigins", 14, 0);
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
					allowedOriginsCount = av_top_index((AV*)temp_array) + 1;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got count %d", allowedOriginsCount);
}
#endif // DEBUG
					allowedOrigins = (LPWSTR*)malloc(sizeof(LPWSTR) * allowedOriginsCount);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Allocated memory");
}
#endif // DEBUG

					SV** item;
					for (int i = 0; i < allowedOriginsCount; i++) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tDoing %i", i+1);
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
							std::wstring value = scalar_to_wstring(*item);
							LPCWSTR origin = value.c_str();
							size_t size = wcslen(origin) + 1;
							allowedOrigins[i] = (LPWSTR)malloc(size);
							wcscpy(allowedOrigins[i], origin);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("%p", allowedOrigins[i]);
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
				}
			}
			if (hv_exists(hash, "HasAuthorityComponent", 21)) {
				SV** value_sv = hv_fetch(hash, "HasAuthorityComponent", 21, 0);
				if (value_sv) {
					hasAuthorityComponent = SvTRUE(*value_sv);
				}
			}

			if (schemeName.empty()) {
				croak("SchemeName is required");
				return NULL;
			}

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("About to create object");
}
#endif // DEBUG
			registration = new CustomSchemeRegistration(schemeName.c_str(), treatAsSecure,
				allowedOriginsCount, (LPCWSTR*)allowedOrigins, hasAuthorityComponent);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("About to create object");
}
#endif // DEBUG

			if (allowedOriginsCount > 0) {
				for (UINT32 i = 0; i < allowedOriginsCount; i++) {
					free(allowedOrigins[i]);
				}
				free(allowedOrigins);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("\tFreed memory");
}
#endif // DEBUG
			}
		}
	}

	if (riid == GUID_NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Returning bare object");
}
#endif // DEBUG
		return registration;
	}

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Getting interface");
}
#endif // DEBUG
	void* iface = registration->GetInterface(riid);

	if (iface != NULL) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got interface (%p)", iface);
}
#endif // DEBUG
		return iface;
	}

	croak("Requested interface not found in get_custom_registration");
	return NULL;
}
