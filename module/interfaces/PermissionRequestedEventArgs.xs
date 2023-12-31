#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::PermissionRequestedEventArgs

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2PermissionRequestedEventArgs3::get_Uri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->get_Uri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PERMISSION_KIND
ICoreWebView2PermissionRequestedEventArgs3::get_PermissionKind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->get_PermissionKind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2PermissionRequestedEventArgs3::get_IsUserInitiated()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->get_IsUserInitiated(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PERMISSION_STATE
ICoreWebView2PermissionRequestedEventArgs3::get_State()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->get_State(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PermissionRequestedEventArgs3::put_State(state)
	INPUT:
		COREWEBVIEW2_PERMISSION_STATE state;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->put_State(THIS, state);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2PermissionRequestedEventArgs3::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2PermissionRequestedEventArgs3::get_Handled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->get_Handled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PermissionRequestedEventArgs3::put_Handled(handled)
	INPUT:
		BOOL handled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->put_Handled(THIS, handled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2PermissionRequestedEventArgs3::get_SavesInProfile()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->get_SavesInProfile(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PermissionRequestedEventArgs3::put_SavesInProfile(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PermissionRequestedEventArgs3*)THIS)->lpVtbl->put_SavesInProfile(THIS, value);
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
