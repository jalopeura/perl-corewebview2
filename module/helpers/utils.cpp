#include <tchar.h>
#include <locale>
#include <codecvt>
#include <map>
#include "utils.h"
#include "PerlObjectWrapper.h"

std::wstring_convert<convert_type, wchar_t> converter;

std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> g_string_converter;
//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

char* errstr;

std::map<void*, SV*> g_known_objects;

HV* tie_hash = get_hv("CoreWebView2::TIECLASS", GV_ADD);
SV* autodie_sv = get_sv("CoreWebView2::AUTODIE", GV_ADD);

#ifdef DEBUG
HV* debug_hash = get_hv("CoreWebView2::DEBUG", GV_ADD);
bool debugme(const char* key) {
	SV** item;
//WARN("Debug check: %s", key);

	// pass NULL to skip check
	if (key == NULL)
		return true;

	// check if the user has allowed all tags
	item = hv_fetch(debug_hash, "all", 3, 0);
	if (item && SvTRUE(*item))
		return true;

	// otherwise check if the user has requested this tag from Perl
	U32 keylen = strlen(key);
	item = hv_fetch(debug_hash, key, keylen, 0);
	return (item && SvTRUE(*item));
}

HV* iid_hash = get_hv("CoreWebView2::IID", GV_ADD);
std::string iidname(const char* iidstr) {
	// nothing to do if no name passed
	if (iidstr == NULL) {
		return std::string("NO ID PASSED");
	}

	// get the SV from the hash; nothing to do if not found
	U32 keylen = strlen(iidstr);
	SV** item = hv_fetch(iid_hash, iidstr, keylen, 0);
	if (item == NULL) {
		return std::string("NAME NOT FOUND");
	}

	return std::string(SvPV_nolen(*item));
}
#endif // DEBUG

std::wstring scalar_to_wstring(SV* scalar) {
	return g_string_converter.from_bytes(SvPV_nolen(scalar));
}

SV* wchar_to_scalar(LPCWSTR str) {
	if (str == 0) {
		return &PL_sv_undef;
	}
	SV* scalar = newSVpv(g_string_converter.to_bytes(str).c_str(), 0);
	return scalar;
}

COREWEBVIEW2_COLOR aref_to_color(SV* aref) {
	COREWEBVIEW2_COLOR color;
	UINT rgb;

	if (SvROK(aref)) {
		SV** item;
		AV* list = newAV();

		// convert items
		rgb     = (item = av_fetch(list, 0, 0)) ? SvUV(*item) : 0;
		color.A = (item = av_fetch(list, 1, 0)) ? SvUV(*item) : 255; // default to alpha 255 if not present
	}
	else {
		rgb     = SvUV(aref);
		color.A = 255; // default to alpha 255 if scalar passed instead of aref
	}

	color.R = rgb & 0xFF0000 >> 16;
	color.G = rgb & 0x00FF00 >> 8;
	color.B = rgb & 0x0000FF;

	return color;
}

SV* color_to_aref(COREWEBVIEW2_COLOR color) {
	AV* list = newAV();

	av_push(list, newSVuv(color.R << 16 | color.G << 8 | color.B));
	av_push(list, newSVuv(color.A));

	return newRV_noinc((SV*)list);
}

COREWEBVIEW2_PHYSICAL_KEY_STATUS href_to_key_status(SV* href) {
	COREWEBVIEW2_PHYSICAL_KEY_STATUS status;
	SV** item;

	HV* hash = (HV*)SvRV(href);

	// convert items
	status.RepeatCount   = (item = hv_fetch(hash, "RepeatCount",   11, 0)) ? SvUV(*item) : 0;
	status.ScanCode      = (item = hv_fetch(hash, "ScanCode",       8, 0)) ? SvUV(*item) : 0;
	status.IsExtendedKey = (item = hv_fetch(hash, "IsExtendedKey", 13, 0)) ? (SvTRUE(*item) ? TRUE : FALSE) : FALSE;
	status.IsMenuKeyDown = (item = hv_fetch(hash, "IsMenuKeyDown", 13, 0)) ? (SvTRUE(*item) ? TRUE : FALSE) : FALSE;
	status.WasKeyDown    = (item = hv_fetch(hash, "WasKeyDown",    10, 0)) ? (SvTRUE(*item) ? TRUE : FALSE) : FALSE;
	status.IsKeyReleased = (item = hv_fetch(hash, "IsKeyReleased", 13, 0)) ? (SvTRUE(*item) ? TRUE : FALSE) : FALSE;

	return status;
}

SV* key_status_to_href(COREWEBVIEW2_PHYSICAL_KEY_STATUS status) {
	HV* hash = newHV();

	// convert items
	hv_store(hash, "RepeatCount",   11, newSVuv(status.RepeatCount), 0);
	hv_store(hash, "ScanCode",       8, newSVuv(status.ScanCode),    0);
	hv_store(hash, "IsExtendedKey", 13, status.IsExtendedKey ? &PL_sv_yes : &PL_sv_no, 0);
	hv_store(hash, "IsMenuKeyDown", 13, status.IsMenuKeyDown ? &PL_sv_yes : &PL_sv_no, 0);
	hv_store(hash, "WasKeyDown",    10, status.WasKeyDown    ? &PL_sv_yes : &PL_sv_no, 0);
	hv_store(hash, "IsKeyReleased", 13, status.IsKeyReleased ? &PL_sv_yes : &PL_sv_no, 0);

	return newRV_noinc((SV*)hash);
}

POINT aref_to_point(SV* aref) {
	POINT point;
	SV** item;

	AV* array = (AV*)SvRV(aref);
	// convert items

	point.x = (item = av_fetch(array, 0, 0)) ? SvUV(*item) : 0;
	point.y = (item = av_fetch(array, 1, 0)) ? SvUV(*item) : 0;

	return point;
}

SV* point_to_aref(POINT point) {
	AV* array = newAV();

	// convert items
	av_push(array, newSVuv(point.x));
	av_push(array, newSVuv(point.y));

	return newRV_noinc((SV*)array);
}

RECT href_to_rect(SV* href) {
	RECT rect;
	SV** item;

	HV* hash = (HV*)SvRV(href);

	// convert items
	rect.left   = (item = hv_fetch(hash, "left",   4, 0)) ? SvUV(*item) : 0;
	rect.top    = (item = hv_fetch(hash, "top",    3, 0)) ? SvUV(*item) : 0;
	rect.right  = (item = hv_fetch(hash, "right",  5, 0)) ? SvUV(*item) : 0;
	rect.bottom = (item = hv_fetch(hash, "bottom", 6, 0)) ? SvUV(*item) : 0;

	return rect;
}

SV* rect_to_href(RECT rect) {
	HV* hash = newHV();

	// convert items
	hv_store(hash, "left",   4, newSVuv(rect.left),   0);
	hv_store(hash, "top",    3, newSVuv(rect.top),    0);
	hv_store(hash, "right",  5, newSVuv(rect.right),  0);
	hv_store(hash, "bottom", 6, newSVuv(rect.bottom), 0);

	return newRV_noinc((SV*)hash);
}

int create_perl_object(SV* perl_obj_ptr, void* cpp_obj, const char* perl_class_name) {
	HV* perl_obj_stash;
	I32 count;
	SV* tie_obj;

	if (cpp_obj == NULL) {
		sv_setsv(perl_obj_ptr, &PL_sv_undef);
		return NO_OBJECT;
	}

	// check map of known objects
	if (g_known_objects.count(cpp_obj)) {
		sv_setsv(perl_obj_ptr, g_known_objects[cpp_obj]);
//SV_WARN(g_known_objects[cpp_obj], "*** (persistent copy)");
		return EXISTING_OBJECT;
	}

	// create the underlying object (a hash) and make a ref to it
	SV* underlying_object = (SV*)newHV();
//SV_WARN(underlying_object, "***");

	// create a persistent copy to store in g_known_objects
	SV* persistent_copy = newRV_noinc(underlying_object);
//SV_WARN(underlying_object, "***");

//SV_WARN(underlying_object, "*** (tying)");
	// add to map of known objects
	g_known_objects[cpp_obj] = persistent_copy;
//SV_WARN(underlying_object, "*** (tying)");

	sv_setsv(perl_obj_ptr, persistent_copy);
//SV_WARN(underlying_object, "***");

	// weaken our persistent copy, else underlying_object will stick around until global destruction
	sv_rvweaken(persistent_copy);

	// get the stash and bless the ref (to the underlying object) into it
	perl_obj_stash = gv_stashpv(perl_class_name, GV_ADD);
	sv_bless(perl_obj_ptr, perl_obj_stash);
//SV_WARN(underlying_object, "***");

	// link the object via '~' magic
	// (we link to the underlying object and not to the reference itself)
	sv_magic(underlying_object, NULL, PERL_MAGIC_ext, (const char*)cpp_obj, 0);	// cheat by storing data instead of a string
//SV_WARN(underlying_object, "***");

	// now that we have a copy of the interface, we need to grab a ref
	// (so far, everything we pass into here is an interface, so casting to IUknown* should be safe)
	((IUnknown*)cpp_obj)->lpVtbl->AddRef((IUnknown*)cpp_obj);

	// does this class need a tied base object?
	SV** tie_class = hv_fetch(tie_hash, perl_class_name, strlen(perl_class_name), 0);
	if (tie_class) {
//SV_WARN(underlying_object, "*** (tying)");
//SV_WARN(perl_obj_ptr, "About to tie");

		// we don't want the tied object to store a reference to the external object, to avoid circular references
		// so we create a pseudo-object (a scalarref) that will be blessed into the same class
		// so the tied object can then call methods on that object
		SV* placeholder = newSVuv(42);
//SV_WARN(placeholder, "placeholder: creation");
		sv_magic(placeholder, NULL, PERL_MAGIC_ext, (const char*)cpp_obj, 0);	// cheat by storing data instead of a string
//SV_WARN(placeholder, "placeholder: magicked");

		SV* pseudo_object = newRV_noinc(placeholder);
//SV_WARN(placeholder, "placeholder: ref created");
//		SV* pseudo_object = newRV_inc(placeholder);
		sv_bless(pseudo_object, perl_obj_stash);
//SV_WARN(placeholder, "placeholder: ref blessed");
		sv_2mortal(pseudo_object);
//SV_WARN(placeholder, "placeholder: ref mortalized");

		dSP;
		ENTER;
		SAVETMPS;
		//EXTEND(SP, 2); 
		PUSHMARK(SP);

		XPUSHs(*tie_class);
		XPUSHs(pseudo_object);

		//XPUSHs(pseudo_object);

		PUTBACK;

		count = call_method("TIEHASH", G_SCALAR);
		SPAGAIN;

		if (count != 1) croak("Big trouble\n");

		tie_obj = POPs;
//SV_WARN(placeholder, "placeholder: tie object returned");

		// if undef returned, the underlying hash doesn't need to be tied
		if (SvOK(tie_obj)) {
			//SvREFCNT_inc(tie_obj);

			// now that the placeholder has a copy of the interface, we need to grab a ref
			// (so far, everything we pass into here is an interface, so casting to IUknown* should be safe)
			((IUnknown*)cpp_obj)->lpVtbl->AddRef((IUnknown*)cpp_obj);

			// note that TIEHASH does not automatically set the magic for us,
			// so we have to do what "tie %hash, $class" does behind the scenes
			sv_magic(underlying_object, tie_obj, PERL_MAGIC_tied, NULL, 0);
//SV_WARN(placeholder, "placeholder: real object magicked to tie object");
		}
		// do we need an else block to SvREFCNT_dec(placeholder)?

		// if the tie succeeded, the tie object has its own reference to this now
		// otherwise, the object is no longer necessary; either way, drop our reference
//		SvREFCNT_dec(placeholder);

		FREETMPS;
		LEAVE;
//SV_WARN(placeholder, "placeholder: after stack cleanup");

// we are somehow ending upo with 2 references to the placeholder - not sure how

//SV_WARN(tie_obj, "Tie object");
//SV_WARN(perl_obj_ptr, "Done tying");
//SV_WARN(underlying_object, "*** (tying)");
	}

	//sv_2mortal(*perl_obj_ptr);
	return NEW_OBJECT;
}

void* get_cpp_object(SV* perl_obj) {
	SV* underlying_object;
	MAGIC* mg;

	// get the underlying object that the perl_obj is a reference to
	// (we can leave it an SV* because we're just using it to find magic)
	underlying_object = SvRV(perl_obj);
//SV_WARN(perl_obj, "Getting cpp object");

	// get the data linked to the underlying object
	mg = mg_find(underlying_object, PERL_MAGIC_ext);
	if (mg == NULL)
		return NULL;

	return (void*)mg->mg_ptr;
}

void unlink_perl_object(SV* perl_obj) {
//SV_WARN(perl_obj, "Unlinking");
	void* cpp_obj = get_cpp_object(perl_obj);

	// we have two types of objects:
	//   * blessed hashrefs tied to an underlying object
	//   * blessed scalars that are members of the tie object
	// both are linked to 
	if (cpp_obj) {
		SV* underlying_object;
		MAGIC* mg;

		// remove from map of known objects
		g_known_objects.erase(cpp_obj);

		// release our copy of the interface
			// (so far, everything we pass into here is an interface, so casting to IUknown* should be safe)
		((IUnknown*)cpp_obj)->lpVtbl->Release((IUnknown*)cpp_obj);

		// untie if necessary
		underlying_object = SvRV(perl_obj);
		mg = mg_find(underlying_object, PERL_MAGIC_tied);
		if (mg != NULL) {
			SV* tie_obj = (SV*)mg->mg_obj;
//SV_WARN(tie_obj, "Tie object before untying");
//SV_WARN(perl_obj, "About to untie");

			// first, untie this object
			sv_unmagic(underlying_object, PERL_MAGIC_tied);
//SV_WARN(tie_obj, "Tie object after untying");
		}
	}
//SV_WARN(perl_obj, "Done untying");
}

void dualize(SV* arg, const char* string) {
	svtype sv_type;

	sv_type = SvTYPE(arg);
	switch(sv_type) {
		case SVt_IV: // integer
			SvUPGRADE(arg, SVt_PVIV);
			sv_setpv(arg, string);
			SvIOK_on(arg);
			break;

		case SVt_NV: // float
			SvUPGRADE(arg, SVt_PVNV);
			sv_setpv(arg, string);
			SvNOK_on(arg);
			break;

		// how do we do this for blessed refs?
		// this doesn't work
		case SVt_PVMG: // magic variable
		case SVt_PVIV: // already dualized
			sv_setpv(arg, string);
			SvIOK_on(arg);
			break;

		default:
			abort();
//			DEBUGME(2, "Got svtype of %d", sv_type);
	}
}

char* get_error_string(HRESULT id) {
	LPWSTR buffer;
	std::string utf8;
	char* out;

	// FormatMessage - uses whatever Windows what compiled with (not consistent)
	// FormatMessageA - uses current local code page (not consistent)
	// FormatMessageW - uses UTF-16 (consistent)
	DWORD length = FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, // source
		id,
		0,    // language; 0 means current 
		(LPWSTR)&buffer, // use address but cast to type (necessary with flag FORMAT_MESSAGE_ALLOCATE_BUFFER)
		0,    // size (or minimum size for FORMAT_MESSAGE_ALLOCATE_BUFFER
		NULL  // arguments
	);

	if (length > 0) {
		utf8 = g_string_converter.to_bytes(buffer);
		out = (char*)malloc(utf8.length()+1);
		strcpy(out, utf8.c_str());
		out[utf8.length()] = 0;
	}
	else {
		out = (char*)malloc(4);
		strcpy(out, "???");
		out[3] = 0;
	}

	return out;
}
