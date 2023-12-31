#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::HttpHeadersCollectionIterator

PROTOTYPES: DISABLE

void
ICoreWebView2HttpHeadersCollectionIterator::GetCurrentHeader()
	INIT:
		LPWSTR name;
		SV* name_sv;
		LPWSTR value;
		SV* value_sv;
		HRESULT result;
		SV* error_sv;
	PPCODE:
		result = ((ICoreWebView2HttpHeadersCollectionIterator*)THIS)->lpVtbl->GetCurrentHeader(THIS, &name, &value);
		CHECK_ERROR(result, error_sv);
		name_sv = wchar_to_scalar(name);
		CoTaskMemFree(name);
		value_sv = wchar_to_scalar(value);
		CoTaskMemFree(value);

		EXTEND(SP, 2);
		PUSHs(sv_2mortal(name_sv));
		PUSHs(sv_2mortal(value_sv));

BOOL
ICoreWebView2HttpHeadersCollectionIterator::get_HasCurrentHeader()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2HttpHeadersCollectionIterator*)THIS)->lpVtbl->get_HasCurrentHeader(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2HttpHeadersCollectionIterator::MoveNext()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2HttpHeadersCollectionIterator*)THIS)->lpVtbl->MoveNext(THIS, &RETVAL);
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
