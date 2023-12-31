#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::PointerInfo

PROTOTYPES: DISABLE

DWORD
ICoreWebView2PointerInfo::get_PointerKind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PointerKind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PointerKind(pointerKind)
	INPUT:
		DWORD pointerKind;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PointerKind(THIS, pointerKind);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_PointerId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PointerId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PointerId(pointerId)
	INPUT:
		UINT32 pointerId;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PointerId(THIS, pointerId);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_FrameId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_FrameId(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_FrameId(frameId)
	INPUT:
		UINT32 frameId;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_FrameId(THIS, frameId);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_PointerFlags()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PointerFlags(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PointerFlags(pointerFlags)
	INPUT:
		UINT32 pointerFlags;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PointerFlags(THIS, pointerFlags);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

RECT
ICoreWebView2PointerInfo::get_PointerDeviceRect()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PointerDeviceRect(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PointerDeviceRect(pointerDeviceRect)
	INPUT:
		RECT pointerDeviceRect;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PointerDeviceRect(THIS, pointerDeviceRect);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

RECT
ICoreWebView2PointerInfo::get_DisplayRect()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_DisplayRect(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_DisplayRect(displayRect)
	INPUT:
		RECT displayRect;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_DisplayRect(THIS, displayRect);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

POINT
ICoreWebView2PointerInfo::get_PixelLocation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PixelLocation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PixelLocation(pixelLocation)
	INPUT:
		POINT pixelLocation;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PixelLocation(THIS, pixelLocation);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

POINT
ICoreWebView2PointerInfo::get_HimetricLocation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_HimetricLocation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_HimetricLocation(himetricLocation)
	INPUT:
		POINT himetricLocation;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_HimetricLocation(THIS, himetricLocation);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

POINT
ICoreWebView2PointerInfo::get_PixelLocationRaw()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PixelLocationRaw(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PixelLocationRaw(pixelLocationRaw)
	INPUT:
		POINT pixelLocationRaw;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PixelLocationRaw(THIS, pixelLocationRaw);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

POINT
ICoreWebView2PointerInfo::get_HimetricLocationRaw()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_HimetricLocationRaw(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_HimetricLocationRaw(himetricLocationRaw)
	INPUT:
		POINT himetricLocationRaw;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_HimetricLocationRaw(THIS, himetricLocationRaw);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

DWORD
ICoreWebView2PointerInfo::get_Time()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_Time(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_Time(time)
	INPUT:
		DWORD time;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_Time(THIS, time);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_HistoryCount()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_HistoryCount(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_HistoryCount(historyCount)
	INPUT:
		UINT32 historyCount;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_HistoryCount(THIS, historyCount);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2PointerInfo::get_InputData()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_InputData(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_InputData(inputData)
	INPUT:
		INT32 inputData;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_InputData(THIS, inputData);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

DWORD
ICoreWebView2PointerInfo::get_KeyStates()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_KeyStates(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_KeyStates(keyStates)
	INPUT:
		DWORD keyStates;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_KeyStates(THIS, keyStates);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT64
ICoreWebView2PointerInfo::get_PerformanceCount()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PerformanceCount(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PerformanceCount(performanceCount)
	INPUT:
		UINT64 performanceCount;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PerformanceCount(THIS, performanceCount);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2PointerInfo::get_ButtonChangeKind()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_ButtonChangeKind(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_ButtonChangeKind(buttonChangeKind)
	INPUT:
		INT32 buttonChangeKind;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_ButtonChangeKind(THIS, buttonChangeKind);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_PenFlags()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PenFlags(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PenFlags(penFLags)
	INPUT:
		UINT32 penFLags;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PenFlags(THIS, penFLags);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_PenMask()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PenMask(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PenMask(penMask)
	INPUT:
		UINT32 penMask;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PenMask(THIS, penMask);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_PenPressure()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PenPressure(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PenPressure(penPressure)
	INPUT:
		UINT32 penPressure;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PenPressure(THIS, penPressure);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_PenRotation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PenRotation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PenRotation(penRotation)
	INPUT:
		UINT32 penRotation;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PenRotation(THIS, penRotation);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2PointerInfo::get_PenTiltX()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PenTiltX(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PenTiltX(penTiltX)
	INPUT:
		INT32 penTiltX;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PenTiltX(THIS, penTiltX);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

INT32
ICoreWebView2PointerInfo::get_PenTiltY()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_PenTiltY(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_PenTiltY(penTiltY)
	INPUT:
		INT32 penTiltY;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_PenTiltY(THIS, penTiltY);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_TouchFlags()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_TouchFlags(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_TouchFlags(touchFlags)
	INPUT:
		UINT32 touchFlags;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_TouchFlags(THIS, touchFlags);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_TouchMask()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_TouchMask(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_TouchMask(touchMask)
	INPUT:
		UINT32 touchMask;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_TouchMask(THIS, touchMask);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

RECT
ICoreWebView2PointerInfo::get_TouchContact()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_TouchContact(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_TouchContact(touchContact)
	INPUT:
		RECT touchContact;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_TouchContact(THIS, touchContact);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

RECT
ICoreWebView2PointerInfo::get_TouchContactRaw()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_TouchContactRaw(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_TouchContactRaw(touchContactRaw)
	INPUT:
		RECT touchContactRaw;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_TouchContactRaw(THIS, touchContactRaw);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_TouchOrientation()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_TouchOrientation(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_TouchOrientation(touchOrientation)
	INPUT:
		UINT32 touchOrientation;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_TouchOrientation(THIS, touchOrientation);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2PointerInfo::get_TouchPressure()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->get_TouchPressure(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2PointerInfo::put_TouchPressure(touchPressure)
	INPUT:
		UINT32 touchPressure;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2PointerInfo*)THIS)->lpVtbl->put_TouchPressure(THIS, touchPressure);
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
