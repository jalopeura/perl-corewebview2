#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::PrintSettings

PROTOTYPES: DISABLE

COREWEBVIEW2_PRINT_ORIENTATION
ICoreWebView2PrintSettings2::get_Orientation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_Orientation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_Orientation(orientation)
	INPUT:
		COREWEBVIEW2_PRINT_ORIENTATION orientation;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_Orientation(THIS, orientation);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_ScaleFactor()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_ScaleFactor(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_ScaleFactor(scaleFactor)
	INPUT:
		double scaleFactor;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_ScaleFactor(THIS, scaleFactor);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_PageWidth()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_PageWidth(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_PageWidth(pageWidth)
	INPUT:
		double pageWidth;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_PageWidth(THIS, pageWidth);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_PageHeight()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_PageHeight(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_PageHeight(pageHeight)
	INPUT:
		double pageHeight;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_PageHeight(THIS, pageHeight);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_MarginTop()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_MarginTop(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_MarginTop(marginTop)
	INPUT:
		double marginTop;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_MarginTop(THIS, marginTop);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_MarginBottom()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_MarginBottom(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_MarginBottom(marginBottom)
	INPUT:
		double marginBottom;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_MarginBottom(THIS, marginBottom);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_MarginLeft()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_MarginLeft(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_MarginLeft(marginLeft)
	INPUT:
		double marginLeft;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_MarginLeft(THIS, marginLeft);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

double
ICoreWebView2PrintSettings2::get_MarginRight()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_MarginRight(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_MarginRight(marginRight)
	INPUT:
		double marginRight;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_MarginRight(THIS, marginRight);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2PrintSettings2::get_ShouldPrintBackgrounds()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_ShouldPrintBackgrounds(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_ShouldPrintBackgrounds(shouldPrintBackgrounds)
	INPUT:
		BOOL shouldPrintBackgrounds;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_ShouldPrintBackgrounds(THIS, shouldPrintBackgrounds);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2PrintSettings2::get_ShouldPrintSelectionOnly()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_ShouldPrintSelectionOnly(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_ShouldPrintSelectionOnly(shouldPrintSelectionOnly)
	INPUT:
		BOOL shouldPrintSelectionOnly;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_ShouldPrintSelectionOnly(THIS, shouldPrintSelectionOnly);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2PrintSettings2::get_ShouldPrintHeaderAndFooter()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_ShouldPrintHeaderAndFooter(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_ShouldPrintHeaderAndFooter(shouldPrintHeaderAndFooter)
	INPUT:
		BOOL shouldPrintHeaderAndFooter;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_ShouldPrintHeaderAndFooter(THIS, shouldPrintHeaderAndFooter);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2PrintSettings2::get_HeaderTitle()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_HeaderTitle(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_HeaderTitle(headerTitle)
	INPUT:
		LPCWSTR headerTitle;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_HeaderTitle(THIS, headerTitle);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2PrintSettings2::get_FooterUri()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_FooterUri(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_FooterUri(footerUri)
	INPUT:
		LPCWSTR footerUri;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_FooterUri(THIS, footerUri);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2PrintSettings2::get_PageRanges()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_PageRanges(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_PageRanges(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_PageRanges(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2PrintSettings2::get_PagesPerSide()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_PagesPerSide(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_PagesPerSide(value)
	INPUT:
		INT32 value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_PagesPerSide(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2PrintSettings2::get_Copies()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_Copies(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_Copies(value)
	INPUT:
		INT32 value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_Copies(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PRINT_COLLATION
ICoreWebView2PrintSettings2::get_Collation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_Collation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_Collation(value)
	INPUT:
		COREWEBVIEW2_PRINT_COLLATION value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_Collation(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PRINT_COLOR_MODE
ICoreWebView2PrintSettings2::get_ColorMode()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_ColorMode(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_ColorMode(value)
	INPUT:
		COREWEBVIEW2_PRINT_COLOR_MODE value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_ColorMode(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PRINT_DUPLEX
ICoreWebView2PrintSettings2::get_Duplex()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_Duplex(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_Duplex(value)
	INPUT:
		COREWEBVIEW2_PRINT_DUPLEX value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_Duplex(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_PRINT_MEDIA_SIZE
ICoreWebView2PrintSettings2::get_MediaSize()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_MediaSize(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_MediaSize(value)
	INPUT:
		COREWEBVIEW2_PRINT_MEDIA_SIZE value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_MediaSize(THIS, value);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

LPWSTR
ICoreWebView2PrintSettings2::get_PrinterName()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->get_PrinterName(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PrintSettings2::put_PrinterName(value)
	INPUT:
		LPCWSTR value;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PrintSettings2*)THIS)->lpVtbl->put_PrinterName(THIS, value);
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
