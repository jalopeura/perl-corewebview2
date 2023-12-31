#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2

PROTOTYPES: DISABLE

HRESULT
CreateCoreWebView2EnvironmentWithOptions(browserExecutableFolder, userDataFolder, environmentOptions, environmentCreatedHandler)
	INPUT:
		PCWSTR browserExecutableFolder;
		PCWSTR userDataFolder;
		ICoreWebView2EnvironmentOptions* environmentOptions;
		ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* environmentCreatedHandler;
	INIT:
		SV* error_sv;
	CODE:
	#ifdef DEBUG
	WARN("!");
	WARN("wrapper %p, interface %p", HANDLER, environmentCreatedHandler);
	#endif
		RETVAL = CreateCoreWebView2EnvironmentWithOptions(browserExecutableFolder, userDataFolder, environmentOptions, environmentCreatedHandler);
	#ifdef DEBUG
	WARN("!");
	#endif
		CHECK_ERROR(RETVAL, error_sv);
	#ifdef DEBUG
	WARN("!");
	#endif
	OUTPUT:
		RETVAL

HRESULT
CreateCoreWebView2Environment(environmentCreatedHandler)
	INPUT:
		ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* environmentCreatedHandler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = CreateCoreWebView2Environment(environmentCreatedHandler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
GetAvailableCoreWebView2BrowserVersionString(browserExecutableFolder)
	INPUT:
		PCWSTR browserExecutableFolder;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = GetAvailableCoreWebView2BrowserVersionString(browserExecutableFolder, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

int
CompareBrowserVersions(version1, version2)
	INPUT:
		PCWSTR version1;
		PCWSTR version2;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = CompareBrowserVersions(version1, version2, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

