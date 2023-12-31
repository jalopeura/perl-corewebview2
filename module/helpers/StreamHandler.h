#pragma once
#include "HandlerBase.h"

IStream* scalar_to_stream(SV* scalar);
SV* stream_to_scalar(IStream* stream);

//IStream* create_stream_from_scalar(SV* init);
//IStream* get_stream(SV* init);

class StreamHandler : public HandlerBase {
public:
	StreamHandler(SV* perl_object);
	virtual ~StreamHandler();

	static SV* GetPerlObjectForStream(IStream* stream);

	StreamHandler(const StreamHandler&) = delete;
	StreamHandler(StreamHandler&&) = delete;
	StreamHandler& operator=(const StreamHandler&) = delete;
	StreamHandler& operator=(StreamHandler&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// ISequentialStream
	WRAP_INTERFACE(SequentialStream, ISequentialStream, StreamHandler)
	HRESULT Read(void *pv, ULONG cb, ULONG *pcbRead);
	HRESULT Write(const void *pv, ULONG cb, ULONG *pcbWritten);

	// IStream
	WRAP_INTERFACE(Stream, IStream, StreamHandler)
	HRESULT Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition);
	HRESULT SetSize(ULARGE_INTEGER libNewSize);
	HRESULT CopyTo(IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten);
	HRESULT Commit(DWORD grfCommitFlags);
	HRESULT Revert();
	HRESULT LockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
	HRESULT UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
	HRESULT Stat(STATSTG *pstatstg, DWORD grfStatFlag);
	HRESULT Clone(IStream **ppstm);
};
