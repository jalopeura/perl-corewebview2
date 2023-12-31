//#include <tchar.h>
//#include <locale>
//#include <codecvt>
//#include <map>
#include "variant.h"
#include "PerlObjectWrapper.h"

#define DEBUG_TAG "VARIANT"

#define PERL_WRAPPER_CLASS "CoreWebView2::Helper::PerlObjectWrapper"
#define JS_WRAPPER_CLASS "CoreWebView2::Helper::JSObjectWrapper"
#define DISPATCH_WRAPPER_CLASS "CoreWebView2::Helper::Dispatch"

static bool perl_wrapper_class_is_loaded = false;
static bool js_wrapper_class_is_loaded = false;
// dispatch wrapper class is defined in XS, so if the current code is loaded, so is the wrapper

VARIANT scalar_to_variant(SV* scalar) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Converting scalar to variant");
}
#endif // DEBUG
	VARIANT variant;

	if (SvROK(scalar)) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(scalar), scalar);
}
#endif // DEBUG
		bool needs_wrapper = false;
		if (sv_isobject(scalar)) {
			// if we're a wrapped JS object, get the original IDispatch
			if (sv_derived_from(scalar, JS_WRAPPER_CLASS)) {
				// get the underlying hash  (we can leave it an SV* because we're not going to do any hash operations on it)
				SV* hash = SvRV(scalar);

				// get the tied object
				SV* tied = SvTIED_obj(hash, mg_find(hash, PERL_MAGIC_tied));

				// get the underlying hash (this time we DO need an HV*)
				HV* subhash = (HV*)SvRV(tied);

				// get the wrapped IDispatch out of the tie object
				SV** item;
				item = hv_fetch(subhash, "dispatch", 8, 0);
				if (item && SvTRUE(*item))
					scalar = *item;

				// now let it fall through to the dispatch wrapper check
			}

			// if we're a wrapped IDispatch, return the original object
			if (sv_derived_from(scalar, DISPATCH_WRAPPER_CLASS)) {
				variant.vt = VT_DISPATCH;
				variant.pdispVal = (IDispatch*)get_cpp_object(scalar);
				return variant;
			}

			// if we get here, it is not a wrapped JS object
			needs_wrapper = ! sv_derived_from(scalar, PERL_WRAPPER_CLASS);
		}

		SV* deref = SvRV(scalar);
		switch(SvTYPE(deref)) {
			case SVt_PVAV:
				{
					SAFEARRAYBOUND dimensions[1]; 
					dimensions[0].lLbound = 0; 
					dimensions[0].cElements = av_top_index((AV*)deref) + 1;
					SAFEARRAY* safe_array = SafeArrayCreate(
						VT_VARIANT, // array of variants
						1,          // 1-dimensional
						dimensions  //
					);

					SV** item;
					for (LONG i = 0; i < dimensions[0].cElements; i++) {
						item = av_fetch((AV*)deref, i, 0);
						if (item) {
							VARIANT v = scalar_to_variant(*item);
							HRESULT h = SafeArrayPutElement(safe_array, &i, &v);
							if (h != S_OK) {
								croak("Error %d [%s] when assinging to SAFEARRAY", h, get_error_string(h));
							}
						}
						else {
							croak("Missing item %d in aref passed to JS", i);
						}
					}

					variant.vt = VT_ARRAY | VT_VARIANT;
					variant.parray = safe_array;
					return variant;
				}
				break;
			case SVt_PVHV:
				needs_wrapper = true;
				break;
			case SVt_PVCV:
				needs_wrapper = true;
				break;
			default:
				croak("Unsupported SV type: %d", SvTYPE(deref));
		};

		// if we get here, the scalar is a blessed object, a hashref, or a coderef

		if (needs_wrapper) {
			if (! perl_wrapper_class_is_loaded) {
				// load_module will change '::' to '/', so we need our own copy
				// it will also steal a reference, so we don't need to decrement
				SV* load_wrapper_class = newSVpv(PERL_WRAPPER_CLASS, 0);
				load_module(PERL_LOADMOD_NOIMPORT, load_wrapper_class, NULL);
				perl_wrapper_class_is_loaded = true;
			}

			SV* wrapper_class = newSVpv(PERL_WRAPPER_CLASS, 0);
			sv_2mortal(wrapper_class);

			dSP;
			ENTER;
			SAVETMPS;
			//EXTEND(SP, 2); 
			PUSHMARK(SP);

			XPUSHs(wrapper_class);
			XPUSHs(scalar);

			PUTBACK;

			int perl_return_count = call_method("new", G_SCALAR);
			SPAGAIN;

			if (perl_return_count != 1) {
				WARN ("Got a bad number of returns from perl call: %d", perl_return_count);
			}

			scalar = POPs;
			SvREFCNT_inc(scalar);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(scalar), scalar);
}
#endif // DEBUG

			FREETMPS;
			LEAVE;
		}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(scalar), scalar);
}
#endif // DEBUG

		PerlObjectWrapper* wrapper = new PerlObjectWrapper(scalar);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(scalar), scalar);
}
#endif // DEBUG

		// drop a reference to the scalar so that the PerlObjectWrapper owns the only reference
		SvREFCNT_dec(scalar);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(scalar), scalar);
}
#endif // DEBUG

		// the variant takes ownership of one reference to the IDispatch
		// since we don't store it anywhere local, we just let it have our reference
		variant.vt = VT_DISPATCH;
		variant.pdispVal = (IDispatch*)(wrapper->GetInterface(IID_IDispatch));
		return variant;
	}

	// if we get here, the scalar is not a reference

	// undef
	if (! SvOK(scalar)) {
		variant.vt = VT_EMPTY;
		return variant;
	}

	// integer
	if (SvIOKp(scalar)) {
		variant.vt = VT_I8;
		variant.llVal = SvIV(scalar);
		return variant;
	}

	// float
	if (SvNOKp(scalar)) {
		variant.vt = VT_R8;
		variant.dblVal = SvNV(scalar);
		return variant;
	}

	// string
	if (SvPOKp(scalar)) {
		variant.vt = VT_BSTR;
		std::wstring s = scalar_to_wstring(scalar);
		variant.bstrVal = SysAllocString(s.c_str());
		return variant;
	}

	croak("Unsupported SV type: %d", SvTYPE(scalar));
}

SV* variant_to_scalar(VARIANT variant) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
warn("Converting variant to scalar");
}
#endif // DEBUG
	SV* scalar;

	if (variant.vt & VT_ARRAY) {
		// JS arrays should always be VARIANT
		VARTYPE at = variant.vt & ~VT_ARRAY;
		if (at != VT_VARIANT) {
			croak("Unsupported type %d in VT_ARRAY", at);
		}

		// JS array should always be one-dimensional
		// TODO - sanity check on dimenions here?

		HRESULT hr;
		LONG lower, upper;
		hr = SafeArrayGetLBound(variant.parray, 1, &lower);
		if (hr != S_OK) {
			errstr = get_error_string(hr);
			croak("Unable to get lower bound: %d => %s", hr, errstr);
		}
		hr = SafeArrayGetUBound(variant.parray, 1, &upper);
		if (hr != S_OK) {
			errstr = get_error_string(hr);
			croak("Unable to get upper bound: %d => %s", hr, errstr);
		}

		AV* temp_array = newAV();
		for (LONG i = lower; i <= upper; i++) {
			VARIANT v; VariantInit(&v);
			hr = SafeArrayGetElement(variant.parray, &i, &v);
			if (hr == S_OK) {
				av_push(temp_array, variant_to_scalar(v));
			}
			else {
				errstr = get_error_string(hr);
				croak("Unable to copy variant from VT_ARRAY: %d => %s", hr, errstr);
			}
		}
		return newRV_noinc((SV*)temp_array);
	}

	switch(variant.vt) {
		case VT_EMPTY:     //VT_EMPTY = 0
		case VT_NULL:      //VT_NULL = 1 - according to the docs, JS nulls should come through as VT_EMPTY, but just in case
			scalar = &PL_sv_undef;
			break;
		//VT_I2 = 2                 SHORT iVal
		
		case VT_I4:        //VT_I4 = 3                 LONG lVal
			scalar = newSViv(variant.lVal);
			break;
		//VT_R4 = 4                 FLOAT fltVal
		
		case VT_R8:        //VT_R8 = 5                 DOUBLE dblVal
			scalar = newSVnv(variant.dblVal);
			break;
		//VT_CY = 6                 CY cyVal (currency
		//VT_DATE = 7               DATE date
		case VT_BSTR:      //VT_BSTR = 8               BSTR bstrVal (byte string)
			scalar = wchar_to_scalar(variant.bstrVal);
			break;
		case VT_DISPATCH:  //VT_DISPATCH = 9           IDispatch* pdispVal
			if (scalar = PerlObjectWrapper::GetPerlObjectForDispatch(variant.pdispVal)) {
				// get the underlying hash
				HV* hash = (HV*)SvRV(scalar);

				// get the wrapped perl object out of the hash
				SV** item;
				item = hv_fetch(hash, "wrapped", 7, 0);
				if (item && SvTRUE(*item)) {
					scalar = *item;

					// do we need to do this?
					SvREFCNT_inc(scalar);

					break;
				}
			}

			if (! js_wrapper_class_is_loaded) {
				// load_module will change '::' to '/', so we need our own copy
				// it will also steal a reference, so we don't need to decrement
				SV* load_wrapper_class = newSVpv(JS_WRAPPER_CLASS, 0);
				load_module(PERL_LOADMOD_NOIMPORT, load_wrapper_class, NULL);
				js_wrapper_class_is_loaded = true;
			}

			{
				// create a dispatch object
				SV* dispatch = sv_newmortal();
				create_perl_object(dispatch, variant.pdispVal, DISPATCH_WRAPPER_CLASS);

				SV* wrapper_class = newSVpv(JS_WRAPPER_CLASS, 0);
				sv_2mortal(wrapper_class);

				dSP;
				ENTER;
				SAVETMPS;
				//EXTEND(SP, 2); 
				PUSHMARK(SP);

				XPUSHs(wrapper_class);
				XPUSHs(dispatch);

				PUTBACK;

				int perl_return_count = call_method("new", G_SCALAR);
				SPAGAIN;

				if (perl_return_count != 1) {
					WARN ("Got a bad number of returns from perl call: %d", perl_return_count);
				}

				scalar = POPs;
				SvREFCNT_inc(scalar);
			}
			break;
		//VT_ERROR = 10             SCODE scode
		case VT_BOOL:      //VT_BOOL = 11              VARIANT_BOOL boolVal (-1 for true, 0 for false)
			scalar = variant.boolVal ? &PL_sv_yes : &PL_sv_no;
			break;
		//VT_VARIANT = 12           VARIANT* pvarVal
		//VT_UNKNOWN = 13           IUnknown* punkVal - according to docs, generic IUknown is not supported, but apparently is accepted if it also implements IDispatch
		//VT_DECIMAL = 14           DECIMAL* pdecVal - according to docs, not supported
		//VT_I1 = 16                CHAR cVal
		//VT_UI1 = 17               BYTE bVal
		//VT_UI2 = 18               USHORT uiVal
		//VT_UI4 = 19               ULONG ulVal
		//VT_I8 = 20                LONGLONG llVal
		//VT_UI8 = 21               ULONGLONG ullVal
		//VT_INT = 22               INT intVal
		//VT_UINT = 23              UINT uintVal;
		//VT_VOID = 24              C-style void (is this a void* or just no value?)
		//VT_HRESULT = 25
		//VT_PTR = 26               many pointer types
		//VT_SAFEARRAY = 27         SAFEARRAY* parray
		//VT_CARRAY = 28
		//VT_USERDEFINED = 29       ??? user defined
		//VT_LPSTR = 30             CHAR* pcVal (is this really where it's stored?)
		//VT_LPWSTR = 31
		//VT_RECORD = 36            ??? user defined - according to docs, not supported
		//VT_INT_PTR = 37           INT* pintVal
		//VT_UINT_PTR = 38          UINT* puintVal
		//VT_FILETIME = 64
		//VT_BLOB = 65              ??? length prefixed bytes
		//VT_STREAM = 66
		//VT_STORAGE = 67
		//VT_STREAMED_OBJECT = 68   VT_STREAM, but it contains an object
		//VT_STORED_OBJECT = 69     VT_STORAGE, but it contains an object
		//VT_BLOB_OBJECT = 70       VT_BLOB, but it contains an object
		//VT_CF = 71                ??? clipboard format
		//VT_CLSID = 72             ??? class id
		//VT_VERSIONED_STREAM = 73  ??? stream that has a GUID version
		//VT_BSTR_BLOB = 0xfff      ??? reserved
		//VT_VECTOR = 0x1000        ??? "simple counted array"
		//VT_ARRAY = 0x2000         SAFEARRAY* parray (or maybe SAFEARRAY** pparray
		//VT_BYREF = 0x4000         PVOID byref - for local use
		//VT_RESERVED = 0x8000
		//VT_ILLEGAL = 0xffff
		//VT_ILLEGALMASKED = 0xfff
		//VT_TYPEMASK = 0xff

		default:
			croak("Unsupported variant type: %d", variant.vt);
	}

	return scalar;
}
