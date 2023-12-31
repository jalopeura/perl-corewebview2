#pragma once
#include "InterfaceWrapper.h"

void* get_custom_registration(SV* hashref, REFIID riid = GUID_NULL);

class CustomSchemeRegistration : public InterfaceWrapper {
public:
	CustomSchemeRegistration();
	CustomSchemeRegistration(LPCWSTR schemeName, BOOL secure = false,
		UINT32 allowedOriginsCount = 0, LPCWSTR* allowedOrigins = NULL, BOOL has_auth = false);
	virtual ~CustomSchemeRegistration();

	CustomSchemeRegistration(const CustomSchemeRegistration&) = delete;
	CustomSchemeRegistration(CustomSchemeRegistration&&) = delete;
	CustomSchemeRegistration& operator=(const CustomSchemeRegistration&) = delete;
	CustomSchemeRegistration& operator=(CustomSchemeRegistration&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2CustomSchemeRegistration
	WRAP_INTERFACE(CustomSchemeRegistration1, ICoreWebView2CustomSchemeRegistration, CustomSchemeRegistration)
	HRESULT get_SchemeName(LPWSTR* schemeName);
	HRESULT get_TreatAsSecure(BOOL* secure);
	HRESULT put_TreatAsSecure(BOOL secure);
	HRESULT GetAllowedOrigins(UINT32* allowedOriginsCount, LPWSTR** allowedOrigins);
	HRESULT SetAllowedOrigins(UINT32 allowedOriginsCount, LPCWSTR* allowedOrigins);
	HRESULT get_HasAuthorityComponent(BOOL* has_auth);
	HRESULT put_HasAuthorityComponent(BOOL has_auth);
private:
	// ICoreWebView2CustomSchemeRegistration
	LPWSTR m_schemeName = NULL;
	BOOL m_TreatAsSecure = false;
	LPWSTR* m_allowedOrigins = NULL;
	unsigned int m_allowedOriginsCount = 0;
	void ReleaseAllowedOrigins();
	BOOL m_HasAuthorityComponent = false;
};

