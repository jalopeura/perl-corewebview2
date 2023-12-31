#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::SharedBuffer

PROTOTYPES: DISABLE

UINT64
ICoreWebView2SharedBuffer::get_Size()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2SharedBuffer*)THIS)->lpVtbl->get_Size(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

BYTE*
ICoreWebView2SharedBuffer::get_Buffer()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2SharedBuffer*)THIS)->lpVtbl->get_Buffer(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

IStream*
ICoreWebView2SharedBuffer::OpenStream()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2SharedBuffer*)THIS)->lpVtbl->OpenStream(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HANDLE
ICoreWebView2SharedBuffer::get_FileMappingHandle()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2SharedBuffer*)THIS)->lpVtbl->get_FileMappingHandle(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2SharedBuffer::Close()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2SharedBuffer*)THIS)->lpVtbl->Close(THIS);
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
