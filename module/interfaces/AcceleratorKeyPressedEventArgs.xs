#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::AcceleratorKeyPressedEventArgs

PROTOTYPES: DISABLE

COREWEBVIEW2_KEY_EVENT_KIND
ICoreWebView2AcceleratorKeyPressedEventArgs2::get_KeyEventKind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->get_KeyEventKind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT
ICoreWebView2AcceleratorKeyPressedEventArgs2::get_VirtualKey()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->get_VirtualKey(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

INT
ICoreWebView2AcceleratorKeyPressedEventArgs2::get_KeyEventLParam()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->get_KeyEventLParam(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PHYSICAL_KEY_STATUS
ICoreWebView2AcceleratorKeyPressedEventArgs2::get_PhysicalKeyStatus()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->get_PhysicalKeyStatus(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2AcceleratorKeyPressedEventArgs2::get_Handled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->get_Handled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2AcceleratorKeyPressedEventArgs2::put_Handled(handled)
	INPUT:
		BOOL handled;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->put_Handled(THIS, handled);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2AcceleratorKeyPressedEventArgs2::get_IsBrowserAcceleratorKeyEnabled()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->get_IsBrowserAcceleratorKeyEnabled(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2AcceleratorKeyPressedEventArgs2::put_IsBrowserAcceleratorKeyEnabled(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2AcceleratorKeyPressedEventArgs2*)THIS)->lpVtbl->put_IsBrowserAcceleratorKeyEnabled(THIS, value);
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
