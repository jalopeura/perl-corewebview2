#include "StreamHandler.h"

#ifdef DEBUG
#define DEBUG_TAG "StreamHandler"
#endif // DEBUG

/*
 * StreamHandler - wraps a Perl object that implements the methods
 */

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * ISequentialStream
 */

IUNKNOWN_DEFS(SequentialStream, ISequentialStream, StreamHandler)

static HRESULT STDMETHODCALLTYPE SequentialStream_Read(ISequentialStream* This, void *pv, ULONG cb, ULONG *pcbRead) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Read: iface %p / object %p", This, static_cast<StreamHandler::SequentialStream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::SequentialStream*>(This)->Wrapper()->Read(pv, cb, pcbRead);
}
static HRESULT STDMETHODCALLTYPE SequentialStream_Write(ISequentialStream* This, const void *pv, ULONG cb, ULONG *pcbWritten) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Write: iface %p / object %p", This, static_cast<StreamHandler::SequentialStream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::SequentialStream*>(This)->Wrapper()->Write(pv, cb, pcbWritten);
}

static ISequentialStreamVtbl SequentialStreamVtbl = {
	IUNKNOWN_INIT(SequentialStream)
	SequentialStream_Read,
	SequentialStream_Write,
};

HRESULT StreamHandler::Read(void *pv, ULONG cb, ULONG *pcbRead) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Read (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* length_sv = newSVuv((UV)cb);
	sv_2mortal(length_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(length_sv);

	PUTBACK;

	int perl_return_count = call_method("Read", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	if (retval == S_OK) {
		STRLEN len;
		char* data = SvPVbyte(retval_sv, len);
		memcpy(pv, data, len);
		*pcbRead = len;
		if (*pcbRead != cb) {
			retval = S_FALSE;
		}
	}

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::Write(const void *pv, ULONG cb, ULONG *pcbWritten) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Write (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* data_sv = newSVpvn((char*)pv, cb);
	sv_2mortal(data_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(data_sv);

	PUTBACK;

	int perl_return_count = call_method("Write", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	if (retval == S_OK) {
		*pcbWritten = SvUV(retval_sv);
	}

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

/*
 * IStream
 */

IUNKNOWN_DEFS(Stream, IStream, StreamHandler)

static HRESULT STDMETHODCALLTYPE Stream_Read(IStream* This, void *pv, ULONG cb, ULONG *pcbRead) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Read: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Read(pv, cb, pcbRead);
}
static HRESULT STDMETHODCALLTYPE Stream_Write(IStream* This, const void *pv, ULONG cb, ULONG *pcbWritten) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Write: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Write(pv, cb, pcbWritten);
}

static HRESULT STDMETHODCALLTYPE Stream_Seek(IStream* This, LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Seek: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Seek(dlibMove, dwOrigin, plibNewPosition);
}
static HRESULT STDMETHODCALLTYPE Stream_SetSize(IStream* This, ULARGE_INTEGER libNewSize) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SetSize: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->SetSize(libNewSize);
}
static HRESULT STDMETHODCALLTYPE Stream_CopyTo(IStream* This, IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CopyTo: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->CopyTo(pstm, cb, pcbRead, pcbWritten);
}
static HRESULT STDMETHODCALLTYPE Stream_Commit(IStream* This, DWORD grfCommitFlags) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Commit: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Commit(grfCommitFlags);
}
static HRESULT STDMETHODCALLTYPE Stream_Revert(IStream* This) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Revert: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Revert();
}
static HRESULT STDMETHODCALLTYPE Stream_LockRegion(IStream* This, ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("LockRegion: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->LockRegion(libOffset, cb, dwLockType);
}
static HRESULT STDMETHODCALLTYPE Stream_UnlockRegion(IStream* This, ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("UnlockRegion: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->UnlockRegion(libOffset, cb, dwLockType);
}
static HRESULT STDMETHODCALLTYPE Stream_Stat(IStream* This, STATSTG *pstatstg, DWORD grfStatFlag) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Stat: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Stat(pstatstg, grfStatFlag);
}
static HRESULT STDMETHODCALLTYPE Stream_Clone(IStream* This, IStream **ppstm) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Clone: iface %p / object %p", This, static_cast<StreamHandler::Stream*>(This));
}
#endif // DEBUG
	return static_cast<StreamHandler::Stream*>(This)->Wrapper()->Clone(ppstm);
}

static IStreamVtbl StreamVtbl = {
	IUNKNOWN_INIT(Stream)
	Stream_Read,
	Stream_Write,
	Stream_Seek,
	Stream_SetSize,
	Stream_CopyTo,
	Stream_Commit,
	Stream_Revert,
	Stream_LockRegion,
	Stream_UnlockRegion,
	Stream_Stat,
	Stream_Clone,
};

HRESULT StreamHandler::Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Seek (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* move_sv = newSVuv((UV)dlibMove.QuadPart);
	sv_2mortal(move_sv);

	SV* origin_sv = newSVuv((UV)dwOrigin);
	sv_2mortal(origin_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 3); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(move_sv);
	XPUSHs(origin_sv);

	PUTBACK;

	int perl_return_count = call_method("Seek", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	if (retval == S_OK) {
		(*plibNewPosition).QuadPart = SvUV(retval_sv);
	}

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::SetSize(ULARGE_INTEGER libNewSize) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SetSize (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* size_sv = newSVuv((UV)libNewSize.QuadPart);
	sv_2mortal(size_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(size_sv);

	PUTBACK;

	int perl_return_count = call_method("SetSize", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	// perl return is simply true/false

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::CopyTo(IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("CopyTo (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* target_sv = sv_newmortal();
	create_perl_object(target_sv, pstm, "CoreWebView2::Helper::Stream");

	SV* length_sv = newSVuv((UV)cb.QuadPart);
	sv_2mortal(length_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 3); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(target_sv);
	XPUSHs(length_sv);

	PUTBACK;

	int perl_return_count = call_method("CopyTo", G_LIST);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	if (retval == S_OK) {
		(*pcbRead).QuadPart = SvUV(retval_sv);
		(*pcbWritten).QuadPart = POPu;
	}

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::Commit(DWORD grfCommitFlags) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Commit (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* flags_sv = newSVuv((UV)grfCommitFlags);
	sv_2mortal(flags_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 2); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(flags_sv);

	PUTBACK;

	int perl_return_count = call_method("Commit", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	// perl return is simply true/false

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::Revert() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Revert (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 1); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

	PUTBACK;

	int perl_return_count = call_method("Revert", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	// perl return is simply true/false

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::LockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("LockRegion (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* offset_sv = newSVuv((UV)libOffset.QuadPart);
	sv_2mortal(offset_sv);

	SV* length_sv = newSVuv((UV)cb.QuadPart);
	sv_2mortal(length_sv);

	SV* type_sv = newSVuv((UV)dwLockType);
	sv_2mortal(type_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 4); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(offset_sv);
	XPUSHs(length_sv);
	XPUSHs(type_sv);

	PUTBACK;

	int perl_return_count = call_method("LockRegion", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	// perl return is simply true/false

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("UnlockRegion (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

	SV* offset_sv = newSVuv((UV)libOffset.QuadPart);
	sv_2mortal(offset_sv);

	SV* length_sv = newSVuv((UV)cb.QuadPart);
	sv_2mortal(length_sv);

	SV* type_sv = newSVuv((UV)dwLockType);
	sv_2mortal(type_sv);

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 4); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
	XPUSHs(offset_sv);
	XPUSHs(length_sv);
	XPUSHs(type_sv);

	PUTBACK;

	int perl_return_count = call_method("UnlockRegion", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	// perl return is simply true/false

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

HRESULT StreamHandler::Stat(STATSTG *pstatstg, DWORD grfStatFlag) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Stat (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

// see Stream.xs and do the opposite

return E_NOTIMPL;
}

HRESULT StreamHandler::Clone(IStream **ppstm) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Clone (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG

	HRESULT retval;
	SV* retval_sv;

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, 1); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);

	PUTBACK;

	int perl_return_count = call_method("Clone", G_SCALAR);
	SPAGAIN;

	GET_EVENT_RESULT(perl_return_count, retval_sv, "CoreWebView2::Error", retval);

	if (retval == S_OK) {
		*ppstm = (IStream*)get_cpp_object(retval_sv);
	}

	PUTBACK;
	FREETMPS;
	LEAVE;

	return retval;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

static std::map<IStream*, StreamHandler*> s_streams;

StreamHandler::StreamHandler(SV* perl_object) : HandlerBase(perl_object, "StreamHandler") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_ISequentialStream, (ISequentialStream*)(new SequentialStream(this, &SequentialStreamVtbl)));
	AddInterface(IID_IStream,           (IStream*)(new Stream(this, &StreamVtbl)));
//	AddInterface(IID_IDispatch, (IDispatch*)(new Dispatch(this, &PerlObjectWrapper_DispatchVtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();

	IStream* stream = (IStream*)GetInterface(IID_IStream);
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Mapping s_streams[%p] = %p", stream, this);
}
#endif // DEBUG
	s_streams[stream] = this;
}

StreamHandler::~StreamHandler() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Erasing mapping");
}
#endif // DEBUG
	s_streams.erase( (IStream*)GetInterface(IID_IStream) );

#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass SequentialStream containing interface ISequentialStream");
}
#endif // DEBUG
	SequentialStream* sstream = static_cast<SequentialStream*>((ISequentialStream*)GetInterface(IID_ISequentialStream));
	delete sstream;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting subclass Stream containing interface IStream");
}
#endif // DEBUG
	Stream* stream = static_cast<Stream*>((IStream*)GetInterface(IID_IStream));
	delete stream;
}

SV* StreamHandler::GetPerlObjectForStream(IStream* stream) {
	if (s_streams.count(stream)) {
		StreamHandler* handler = s_streams[stream];
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Fetching wrapped object %p / %p from IStream %p", handler, handler->m_perl_object, stream);
}
#endif // DEBUG
		return handler->m_perl_object;
	}
	return NULL;
}

#define PERL_WRAPPER_CLASS "CoreWebView2::Helper::PerlStream"
#define ISTREAM_WRAPPER_CLASS "CoreWebView2::Helper::Stream"

static bool perl_wrapper_class_is_loaded = false;
// IStream wrapper class is defined in XS, so if the current code is loaded, so is the wrapper

IStream* scalar_to_stream(SV* scalar) {
	// if the scalar is not a blessed reference, wrap it in a CoreWebView2::Helper::PerlStream
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("scalar_to_stream");
}
#endif // DEBUG
	if (! sv_isobject(scalar)) {
		if (! perl_wrapper_class_is_loaded) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("loading %s", PERL_WRAPPER_CLASS);
}
#endif // DEBUG
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
	}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got here");
}
#endif // DEBUG

	// once we get here, we're a blessed reference of some kind

	// if we're a wrapped IStream, return the original object
	if (sv_derived_from(scalar, ISTREAM_WRAPPER_CLASS)) {
		return (IStream*)get_cpp_object(scalar);
	}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got here");
}
#endif // DEBUG

	// if we get here, we are a Perl wrapper of some kind
	StreamHandler* handler = new StreamHandler(scalar);
	return (IStream*)handler->GetInterface(IID_IStream);
}

SV* stream_to_scalar(IStream* stream) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("stream_to_scalar");
}
#endif // DEBUG
	SV* scalar;
	// if this is the IStream* from a StreamHandler, return the original Perl object
	if (scalar = StreamHandler::GetPerlObjectForStream(stream)) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got here");
}
#endif // DEBUG
		// do we need to do this?
		SvREFCNT_inc(scalar);

		return scalar;
	}
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Got here");
}
#endif // DEBUG

	// otherwise, create a CoreWebView2::Helper::Stream and return that
	scalar = newSV(0); // caller is responsible for mortalizing if necessary
	create_perl_object(scalar, stream, ISTREAM_WRAPPER_CLASS);
	return scalar;
}
