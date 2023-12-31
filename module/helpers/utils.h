#pragma once

#define CINTERFACE
#include "WebView2.h"
#include <string>
#include <shlwapi.h>

// converter
#include <locale>
#include <codecvt>
using convert_type = std::codecvt_utf8<wchar_t>;
extern std::wstring_convert<convert_type, wchar_t> converter;
#define SHORTEN(x) converter.to_bytes(std::wstring(x)).c_str()

//#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#undef THIS // interesting... why do we need to do this?
#undef Pause
#undef Stat
#undef bind

// the version of cop.h in lib/CORE does not have G_LIST (at least, in my perl it doesn't)
// and we might as well include the others, in case we want them later
#ifndef G_LIST
#define G_VOID          1
#define G_SCALAR        2
#define G_LIST          3
#define G_WANT          3
#endif

extern IStream* scalar_to_stream(SV* scalar);
extern SV* stream_to_scalar(IStream* stream);

#ifdef DEBUG
bool debugme(const char* key);
std::string iidname(const char* iidstr);
#endif // DEBUG

std::wstring scalar_to_wstring(SV* scalar);
SV* wchar_to_scalar(LPCWSTR str);

COREWEBVIEW2_COLOR aref_to_color(SV* aref);
SV* color_to_aref(COREWEBVIEW2_COLOR color);

COREWEBVIEW2_PHYSICAL_KEY_STATUS href_to_key_status(SV* href);
SV* key_status_to_href(COREWEBVIEW2_PHYSICAL_KEY_STATUS status);

//IStream* glob_to_stream(SV* glob);
//SV* stream_to_glob(IStream* stream);

POINT aref_to_point(SV* aref);
SV* point_to_aref(POINT point);

RECT href_to_rect(SV* href);
SV* rect_to_href(RECT rect);

#define NO_OBJECT       0
#define EXISTING_OBJECT 1
#define NEW_OBJECT      2

int create_perl_object(SV* perl_obj_ptr, void* cpp_obj, const char* perl_class_name);
void* get_cpp_object(SV* perl_obj);
void unlink_perl_object(SV* perl_obj);

extern SV* autodie_sv;
void dualize(SV* arg, const char* string);
/* Note: Caller must free the returned string */
char* get_error_string(HRESULT id);

#define WARN(PATTERN, ...) warn("At %s line %d: " PATTERN, __FILE__, __LINE__, ##__VA_ARGS__);
#define FATAL(PATTERN, ...) croak("At %s line %d: " PATTERN, __FILE__, __LINE__, ##__VA_ARGS__);
#define SV_DUMP(scalar) warn("At %s line %d:", __FILE__, __LINE__); sv_dump(scalar);
#define SV_WARN(scalar, PATTERN, ...) warn("At %s line %d: " PATTERN, __FILE__, __LINE__, ##__VA_ARGS__); sv_dump(scalar);

/*
this macros checks the HRESULT of a call into Windows
it sets $ICoreWebView2::Error based on the code returned from windows
if the error code is not S_OK:
   if $ICoreWebView1::autodie is true, it dies
   otherwise it returns undef
*/
extern char* errstr;
#define CHECK_ERROR(errval, err_sv) \
	err_sv = get_sv("CoreWebView2::Error", 1); \
	sv_setiv(err_sv, (IV)errval); \
	errstr = get_error_string(errval); \
	if (errstr) { \
		dualize(err_sv, errstr); \
		free(errstr); \
	} \
	if (errval != S_OK && SvTRUE(autodie_sv)) { \
		warn_sv(err_sv); \
		croak("...at %s line %d; ", __FILE__, __LINE__); \
	} \

/*
this macro gets the HRESULT to pass back to Windows
if it died, it grabs the value of ERRSV ($@)
otherwise, it grabs the numeric return value
*/
#define GET_EVENT_RESULT(retcount, perl_retval, errname, result) \
	result = S_OK; \
	perl_retval = ERRSV; \
	if (SvTRUE(perl_retval)) { \
		result = (HRESULT)SvIV(perl_retval); \
		if (result == 0) { \
			result = E_FAIL; \
		} \
		POPs; \
	} \
	else { \
		if (retcount != 1) { \
			WARN ("Got a bad number of returns from perl call: %d", retcount); \
		} \
		perl_retval = POPs; \
	}

#define DISPLAY_WIDE_STRING(string) \
	MessageBoxW( \
		NULL, \
		string, \
		NULL, \
		MB_OK \
	);
