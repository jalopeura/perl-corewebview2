#pragma once
#include "InterfaceWrapper.h"

void* get_environment_options(SV* hashref, REFIID riid = GUID_NULL);

class EnvironmentOptions : public InterfaceWrapper {
public:
	EnvironmentOptions();
	virtual ~EnvironmentOptions();

	EnvironmentOptions(const EnvironmentOptions&) = delete;
	EnvironmentOptions(EnvironmentOptions&&) = delete;
	EnvironmentOptions& operator=(const EnvironmentOptions&) = delete;
	EnvironmentOptions& operator=(EnvironmentOptions&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ICoreWebView2EnvironmentOptions
	WRAP_INTERFACE(EnvironmentOptions1, ICoreWebView2EnvironmentOptions, EnvironmentOptions)
	HRESULT get_AdditionalBrowserArguments(LPWSTR* value);
	HRESULT put_AdditionalBrowserArguments(LPCWSTR value);
	HRESULT get_Language(LPWSTR* value);
	HRESULT put_Language(LPCWSTR value);
	HRESULT get_TargetCompatibleBrowserVersion(LPWSTR* value);
	HRESULT put_TargetCompatibleBrowserVersion(LPCWSTR value);
	HRESULT get_AllowSingleSignOnUsingOSPrimaryAccount(BOOL* allow);
	HRESULT put_AllowSingleSignOnUsingOSPrimaryAccount(BOOL allow);

	// ICoreWebView2EnvironmentOptions2
	WRAP_INTERFACE(EnvironmentOptions2, ICoreWebView2EnvironmentOptions2, EnvironmentOptions)
	HRESULT get_ExclusiveUserDataFolderAccess(BOOL* exclusive);
	HRESULT put_ExclusiveUserDataFolderAccess(BOOL exclusive);

	// ICoreWebView2EnvironmentOptions3
	WRAP_INTERFACE(EnvironmentOptions3, ICoreWebView2EnvironmentOptions3, EnvironmentOptions)
	HRESULT get_IsCustomCrashReportingEnabled(BOOL* custom);
	HRESULT put_IsCustomCrashReportingEnabled(BOOL custom);

	// ICoreWebView2EnvironmentOptions4
	WRAP_INTERFACE(EnvironmentOptions4, ICoreWebView2EnvironmentOptions4, EnvironmentOptions)
	HRESULT GetCustomSchemeRegistrations(UINT32* count, ICoreWebView2CustomSchemeRegistration*** schemeRegistrations);
	HRESULT SetCustomSchemeRegistrations(UINT32 count, ICoreWebView2CustomSchemeRegistration** schemeRegistrations);

	// ICoreWebView2EnvironmentOptions5
	WRAP_INTERFACE(EnvironmentOptions5, ICoreWebView2EnvironmentOptions5, EnvironmentOptions)
	HRESULT get_EnableTrackingPrevention(BOOL* prevent);
	HRESULT put_EnableTrackingPrevention(BOOL prevent);

	// ICoreWebView2EnvironmentOptions6
	WRAP_INTERFACE(EnvironmentOptions6, ICoreWebView2EnvironmentOptions6, EnvironmentOptions)
	HRESULT get_AreBrowserExtensionsEnabled(BOOL* enabled);
	HRESULT put_AreBrowserExtensionsEnabled(BOOL enabled);

private:
	// ICoreWebView2EnvironmentOptions
	LPWSTR m_AdditionalBrowserArguments = NULL;
	LPWSTR m_Language = NULL;
	LPWSTR m_TargetCompatibleBrowserVersion = NULL;
	BOOL m_AllowSingleSignOnUsingOSPrimaryAccount = false;

	// ICoreWebView2EnvironmentOptions2
	BOOL m_ExclusiveUserDataFolderAccess = false;

	// ICoreWebView2EnvironmentOptions3
	BOOL m_IsCustomCrashReportingEnabled = false;

	// ICoreWebView2EnvironmentOptions4
	ICoreWebView2CustomSchemeRegistration** m_customSchemeRegistrations = nullptr;
	unsigned int m_customSchemeRegistrationsCount = 0;
	void ReleaseCustomSchemeRegistrations();

	// ICoreWebView2EnvironmentOptions5
	BOOL m_EnableTrackingPrevention = true;

	// ICoreWebView2EnvironmentOptions6
	BOOL m_AreBrowserExtensionsEnabled = true;
};
