#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Controller

PROTOTYPES: DISABLE

BOOL
ICoreWebView2Controller4::get_IsVisible()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_IsVisible(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_IsVisible(isVisible)
	INPUT:
		BOOL isVisible;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_IsVisible(THIS, isVisible);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

RECT
ICoreWebView2Controller4::get_Bounds()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_Bounds(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_Bounds(bounds)
	INPUT:
		RECT bounds;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_Bounds(THIS, bounds);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2Controller4::get_ZoomFactor()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_ZoomFactor(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_ZoomFactor(zoomFactor)
	INPUT:
		double zoomFactor;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_ZoomFactor(THIS, zoomFactor);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Controller4::add_ZoomFactorChanged(eventHandler)
	INPUT:
		ICoreWebView2ZoomFactorChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->add_ZoomFactorChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::remove_ZoomFactorChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->remove_ZoomFactorChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::SetBoundsAndZoomFactor(bounds, zoomFactor)
	INPUT:
		RECT bounds;
		double zoomFactor;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->SetBoundsAndZoomFactor(THIS, bounds, zoomFactor);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::MoveFocus(reason)
	INPUT:
		COREWEBVIEW2_MOVE_FOCUS_REASON reason;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->MoveFocus(THIS, reason);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Controller4::add_MoveFocusRequested(eventHandler)
	INPUT:
		ICoreWebView2MoveFocusRequestedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->add_MoveFocusRequested(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::remove_MoveFocusRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->remove_MoveFocusRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Controller4::add_GotFocus(eventHandler)
	INPUT:
		ICoreWebView2FocusChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->add_GotFocus(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::remove_GotFocus(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->remove_GotFocus(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Controller4::add_LostFocus(eventHandler)
	INPUT:
		ICoreWebView2FocusChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->add_LostFocus(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::remove_LostFocus(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->remove_LostFocus(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Controller4::add_AcceleratorKeyPressed(eventHandler)
	INPUT:
		ICoreWebView2AcceleratorKeyPressedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->add_AcceleratorKeyPressed(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::remove_AcceleratorKeyPressed(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->remove_AcceleratorKeyPressed(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HWND
ICoreWebView2Controller4::get_ParentWindow()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_ParentWindow(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_ParentWindow(parentWindow)
	INPUT:
		HWND parentWindow;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_ParentWindow(THIS, parentWindow);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::NotifyParentWindowPositionChanged()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->NotifyParentWindowPositionChanged(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::Close()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->Close(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2*
ICoreWebView2Controller4::get_CoreWebView2()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_CoreWebView2(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_COLOR
ICoreWebView2Controller4::get_DefaultBackgroundColor()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_DefaultBackgroundColor(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_DefaultBackgroundColor(backgroundColor)
	INPUT:
		COREWEBVIEW2_COLOR backgroundColor;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_DefaultBackgroundColor(THIS, backgroundColor);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2Controller4::get_RasterizationScale()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_RasterizationScale(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_RasterizationScale(scale)
	INPUT:
		double scale;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_RasterizationScale(THIS, scale);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Controller4::get_ShouldDetectMonitorScaleChanges()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_ShouldDetectMonitorScaleChanges(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_ShouldDetectMonitorScaleChanges(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_ShouldDetectMonitorScaleChanges(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Controller4::add_RasterizationScaleChanged(eventHandler)
	INPUT:
		ICoreWebView2RasterizationScaleChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->add_RasterizationScaleChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::remove_RasterizationScaleChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->remove_RasterizationScaleChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_BOUNDS_MODE
ICoreWebView2Controller4::get_BoundsMode()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_BoundsMode(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_BoundsMode(boundsMode)
	INPUT:
		COREWEBVIEW2_BOUNDS_MODE boundsMode;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_BoundsMode(THIS, boundsMode);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Controller4::get_AllowExternalDrop()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Controller4*)THIS)->lpVtbl->get_AllowExternalDrop(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Controller4::put_AllowExternalDrop(value)
	INPUT:
		BOOL value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Controller4*)THIS)->lpVtbl->put_AllowExternalDrop(THIS, value);
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
