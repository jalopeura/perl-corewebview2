MODULE = CoreWebView2	PACKAGE = CoreWebView2::Helper::Stream

PROTOTYPES: DISABLE

SV*
IStream::Read(length)
	INPUT:
		ULONG length;
	INIT:
		char* buffer;
		ULONG actually_read;
		HRESULT result;
		SV* error_sv;
	CODE:
		buffer = (char*)malloc(length+1);
		result = ((IStream*)THIS)->lpVtbl->Read(THIS, buffer, length, &actually_read);

		// S_FALSE means there was no error, but less than length bytes was available
		if (result == S_FALSE) {
			// if it read no bytes at all, this is eof
			if (actually_read == 0) {
				XSRETURN_UNDEF;
			}
			// update error code so it passes CHECK_ERROR
			result = S_OK;
		}

		CHECK_ERROR(result, error_sv);

		buffer[actually_read] = 0;
		RETVAL = newSVpvn(buffer, actually_read);
		free(buffer);
	OUTPUT:
		RETVAL

ULONG
IStream::Write(bytes)
	INPUT:
		SV* bytes;
	INIT:
		char* buffer;
		STRLEN length;
		HRESULT result;
		SV* error_sv;
	CODE:
		buffer = SvPVbyte(bytes, length);
		result = ((IStream*)THIS)->lpVtbl->Write(THIS, buffer, length, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ULARGE_INTEGER
IStream::Seek(position, origin)
	INPUT:
		LARGE_INTEGER position;
		DWORD origin;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((IStream*)THIS)->lpVtbl->Seek(THIS, position, origin, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

bool
IStream::SetSize(new_size)
	INPUT:
		ULARGE_INTEGER new_size;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((IStream*)THIS)->lpVtbl->SetSize(THIS, new_size);
		CHECK_ERROR(result, error_sv);

		RETVAL = true;
	OUTPUT:
		RETVAL

void
IStream::CopyTo(target, length)
	INPUT:
		IStream* target;
		ULARGE_INTEGER length;
	INIT:
		ULARGE_INTEGER actually_read;
		ULARGE_INTEGER actually_written;
		HRESULT result;
		SV* error_sv;
	PPCODE:
		result = ((IStream*)THIS)->lpVtbl->CopyTo(THIS, target, length, &actually_read, &actually_written);
		CHECK_ERROR(result, error_sv);

		U8 gimme = GIMME_V;
		// if caller wants a list, then we push both returns onto the stack
		if (gimme == G_LIST) {
			EXTEND(SP, 2);
			//PUSHu(sv_2mortal(newSVuv(actually_read.QuadPart)));
			mPUSHu(actually_read.QuadPart);
		}
		else {
			EXTEND(SP, 1);
		}
		mPUSHu(actually_written.QuadPart);

HRESULT
IStream::Commit(flags)
	INPUT:
		DWORD flags;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((IStream*)THIS)->lpVtbl->Commit(THIS, flags);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
IStream::Revert()
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((IStream*)THIS)->lpVtbl->Revert(THIS);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
IStream::LockRegion(offset, length, lock_type)
	INPUT:
		ULARGE_INTEGER offset;
		ULARGE_INTEGER length;
		DWORD lock_type;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((IStream*)THIS)->lpVtbl->LockRegion(THIS, offset, length, lock_type);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
IStream::UnlockRegion(offset, length, lock_type)
	INPUT:
		ULARGE_INTEGER offset;
		ULARGE_INTEGER length;
		DWORD lock_type;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((IStream*)THIS)->lpVtbl->UnlockRegion(THIS, offset, length, lock_type);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

SV*
IStream::Stat(flag = STATFLAG_DEFAULT)
	INPUT:
		DWORD flag;
	INIT:
		STATSTG statstg;
		HRESULT result;
		SV* error_sv;
		LPOLESTR clsid_str;
		ULARGE_INTEGER time;
	CODE:
		result = ((IStream*)THIS)->lpVtbl->Stat(THIS, &statstg, flag);
		CHECK_ERROR(result, error_sv);

		HV* hash = newHV();

		if (! flag & STATFLAG_NONAME) {
			hv_store(hash, "name", 4, wchar_to_scalar(statstg.pwcsName), 0);
			CoTaskMemFree(statstg.pwcsName);
		}

		if (StringFromCLSID(statstg.clsid, &clsid_str) == S_OK) {
			std::wstring temp_str(clsid_str);
			hv_store(hash, "clsid", 5, wchar_to_scalar(temp_str.c_str()), 0);
			CoTaskMemFree(clsid_str);
		}

		// convert integers
		hv_store(hash, "type",            4, newSVuv(statstg.type),              0);
		hv_store(hash, "size",            4, newSVuv(statstg.cbSize.QuadPart),   0);
		hv_store(hash, "mode",            4, newSVuv(statstg.grfMode),           0);
		hv_store(hash, "locksSupported", 14, newSVuv(statstg.grfLocksSupported), 0);
		hv_store(hash, "stateBits",       9, newSVuv(statstg.grfStateBits),      0);

		time.u.LowPart  = statstg.mtime.dwLowDateTime;
		time.u.HighPart = statstg.mtime.dwHighDateTime;
		hv_store(hash, "mtime",           5, newSVuv(time.QuadPart),             0);
		time.u.LowPart  = statstg.ctime.dwLowDateTime;
		time.u.HighPart = statstg.ctime.dwHighDateTime;
		hv_store(hash, "ctime",           5, newSVuv(time.QuadPart),             0);
		time.u.LowPart  = statstg.atime.dwLowDateTime;
		time.u.HighPart = statstg.atime.dwHighDateTime;
		hv_store(hash, "atime",           5, newSVuv(time.QuadPart),             0);

		RETVAL = newRV_noinc((SV*)hash);
	OUTPUT:
		RETVAL

# Don't prefix class name so we have access to the blessed href (as SV*)
SV*
Clone(blessed_href)
	INPUT:
		SV* blessed_href;
	INIT:
		IStream* THIS;
		char* CLASS;
		IStream* clone;
		HV* stash;
		HRESULT result;
		SV* error_sv;
	CODE:
		THIS = (IStream*)get_cpp_object(blessed_href);
		stash = SvSTASH(SvRV(blessed_href));
		CLASS = HvNAME(stash);

		result = THIS->lpVtbl->Clone(THIS, &clone);
		CHECK_ERROR(result, error_sv);

		create_perl_object(RETVAL, clone, CLASS);
		// don't bother checking return value for NEW_OBJECT, because we know it's new - we just created it
		// but we don't need to AddRef() because we own the initial reference to the C++ object
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

SV*
IStream::stringify(...)
	OVERLOAD: \"\"
	INIT:
		char* buffer;
		ULARGE_INTEGER current;
		ULARGE_INTEGER length;
		LARGE_INTEGER offset;
		ULONG actually_read;
		HRESULT result;
		SV* error_sv;
	CODE:
		offset.QuadPart = 0;

		// save off current position
		result = THIS->lpVtbl->Seek(THIS, offset, STREAM_SEEK_CUR, &current);
		CHECK_ERROR(result, error_sv);

		// go to the end and use the returned position to get the size
	// do we need to add 1?
		result = THIS->lpVtbl->Seek(THIS, offset, STREAM_SEEK_END, &length);
		CHECK_ERROR(result, error_sv);

		// go back to the beginning
		result = THIS->lpVtbl->Seek(THIS, offset, STREAM_SEEK_SET, NULL);
		CHECK_ERROR(result, error_sv);

		// create an appropriately sized buffer and read into it
		buffer = (char*)malloc(length.QuadPart);
		THIS->lpVtbl->Read(THIS, buffer, length.QuadPart, &actually_read);
		CHECK_ERROR(result, error_sv);

		// restore cursor
		offset.QuadPart = current.QuadPart;
		result = THIS->lpVtbl->Seek(THIS, offset, STREAM_SEEK_SET, NULL);
		CHECK_ERROR(result, error_sv);

		// check current position
		result = THIS->lpVtbl->Seek(THIS, offset, STREAM_SEEK_CUR, &current);
		CHECK_ERROR(result, error_sv);

		// convert and free the buffer
		RETVAL = newSVpvn(buffer, actually_read);
		free(buffer);
	//	sv_2mortal(RETVAL); // necessary?
	OUTPUT:
		RETVAL

#
# STREAM_SEEK
#

SV*
STREAM_SEEK_SET()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STREAM_SEEK_SET);
	OUTPUT:
		RETVAL

SV*
STREAM_SEEK_CUR()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STREAM_SEEK_CUR);
	OUTPUT:
		RETVAL

SV*
STREAM_SEEK_END()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STREAM_SEEK_END);
	OUTPUT:
		RETVAL

#
# STGC
#

SV*
STGC_DEFAULT()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STGC_DEFAULT);
	OUTPUT:
		RETVAL

SV*
STGC_OVERWRITE()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STGC_OVERWRITE);
	OUTPUT:
		RETVAL

SV*
STGC_ONLYIFCURRENT()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STGC_ONLYIFCURRENT);
	OUTPUT:
		RETVAL

SV*
STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE);
	OUTPUT:
		RETVAL

SV*
STGC_CONSOLIDATE()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STGC_CONSOLIDATE);
	OUTPUT:
		RETVAL

#
# LOCKTYPE
#

SV*
LOCK_WRITE()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)LOCK_WRITE);
	OUTPUT:
		RETVAL

SV*
LOCK_EXCLUSIVE()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)LOCK_EXCLUSIVE);
	OUTPUT:
		RETVAL

SV*
LOCK_ONLYONCE()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)LOCK_ONLYONCE);
	OUTPUT:
		RETVAL

#
# STATFLAG
#

SV*
STATFLAG_DEFAULT()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STATFLAG_DEFAULT);
	OUTPUT:
		RETVAL

SV*
STATFLAG_NONAME()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STATFLAG_NONAME);
	OUTPUT:
		RETVAL

SV*
STATFLAG_NOOPEN()
	CODE:
		RETVAL = newSV(0);
		sv_setuv(RETVAL, (UV)STATFLAG_NOOPEN);
	OUTPUT:
		RETVAL
