#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::WindowFeatures

PROTOTYPES: DISABLE

BOOL
ICoreWebView2WindowFeatures::get_HasPosition()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_HasPosition(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2WindowFeatures::get_HasSize()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_HasSize(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2WindowFeatures::get_Left()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_Left(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2WindowFeatures::get_Top()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_Top(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2WindowFeatures::get_Height()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_Height(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2WindowFeatures::get_Width()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_Width(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2WindowFeatures::get_ShouldDisplayMenuBar()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_ShouldDisplayMenuBar(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2WindowFeatures::get_ShouldDisplayStatus()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_ShouldDisplayStatus(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2WindowFeatures::get_ShouldDisplayToolbar()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_ShouldDisplayToolbar(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2WindowFeatures::get_ShouldDisplayScrollBars()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WindowFeatures*)THIS)->lpVtbl->get_ShouldDisplayScrollBars(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
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
