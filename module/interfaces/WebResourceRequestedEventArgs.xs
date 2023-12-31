#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::WebResourceRequestedEventArgs

PROTOTYPES: DISABLE

ICoreWebView2WebResourceRequest*
ICoreWebView2WebResourceRequestedEventArgs::get_Request()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequestedEventArgs*)THIS)->lpVtbl->get_Request(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2WebResourceResponse*
ICoreWebView2WebResourceRequestedEventArgs::get_Response()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequestedEventArgs*)THIS)->lpVtbl->get_Response(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2WebResourceRequestedEventArgs::put_Response(response)
	INPUT:
		ICoreWebView2WebResourceResponse* response;
	INIT:
		SV* error_sv;
	CODE:
	#ifdef DEBUG
	WARN("About to call put_Response (%p, %p)", THIS, response);
	#endif
		RETVAL = ((ICoreWebView2WebResourceRequestedEventArgs*)THIS)->lpVtbl->put_Response(THIS, response);
	#ifdef DEBUG
	WARN("Back from put_Response");

	/*
	IStream* stream;
	WARN("About to call get_Content (%p)", response);
	if (response->lpVtbl->get_Content(response, &stream) == S_OK) {
		WARN("Got content");
		ULONG num_read;
		LPWSTR chunk = (LPWSTR)malloc(1000);
		WARN("About to call Read (%p)", stream);
		while (stream->lpVtbl->Read(stream, &chunk, 1000, &num_read) == S_OK) {
			WARN("%s [%d]", SHORTEN(chunk), num_read);
		}
		WARN("Done with Read loop");
		free(chunk);
	}
	else {
		WARN("No content");
	}
	*/

	int code;
	WARN("About to call get_StatusCode (%p)", response);
	if (response->lpVtbl->get_StatusCode(response, &code) == S_OK) {
		WARN("Status code %d", code);
	}
	else {
		WARN("No status code");
	}

	LPWSTR reason;
	WARN("About to call get_ReasonPhrase (%p)", response);
	if (response->lpVtbl->get_ReasonPhrase(response, &reason) == S_OK) {
		WARN("Reason %s", SHORTEN(reason));
	}
	else {
		WARN("No reason phrase");
	}

	ICoreWebView2HttpResponseHeaders* headers;
	WARN("About to call get_Headers (%p)", response);
	if (response->lpVtbl->get_Headers(response, &headers) == S_OK) {
		WARN("Got headers");
		ICoreWebView2HttpHeadersCollectionIterator* iterator;
		WARN("About to call GetIterator (%p)", headers);
		if (headers->lpVtbl->GetIterator(headers, &iterator) == S_OK) {
			WARN("Got iterator");
			BOOL has_it = true;
			LPWSTR name;
			LPWSTR value;
			while (has_it) {
				WARN("About to call get_HasCurrentHeader (%p)", iterator);
				if (iterator->lpVtbl->get_HasCurrentHeader(iterator, &has_it) == S_OK && has_it) {
					WARN("About to call GetCurrentHeader (%p)", iterator);
					if (iterator->lpVtbl->GetCurrentHeader(iterator, &name, &value) == S_OK) {
						WARN("%s => %s", SHORTEN(name), SHORTEN(value));
					}
					else {
						WARN("Unable to get header");
					}
					WARN("About to call MoveNext (%p)", iterator);
					iterator->lpVtbl->MoveNext(iterator, &has_it);
					WARN("Back from MoveNext");
				}
			}
		}
		else {
			WARN("No iterator");
		}
	}
	else {
		WARN("No headers");
	}

	//public HRESULT GetIterator(ICoreWebView2HttpHeadersCollectionIterator ** iterator)

	//public HRESULT get_HasCurrentHeader(BOOL * hasCurrent)
	//public HRESULT GetCurrentHeader(LPWSTR * name, LPWSTR * value)
	//public HRESULT MoveNext(BOOL * hasNext)
	#endif


		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

ICoreWebView2Deferral*
ICoreWebView2WebResourceRequestedEventArgs::GetDeferral()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequestedEventArgs*)THIS)->lpVtbl->GetDeferral(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

COREWEBVIEW2_WEB_RESOURCE_CONTEXT
ICoreWebView2WebResourceRequestedEventArgs::get_ResourceContext()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2WebResourceRequestedEventArgs*)THIS)->lpVtbl->get_ResourceContext(THIS, &RETVAL);
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
	INIT:
		ICoreWebView2WebResourceRequestedEventArgs* cpp_obj;
	CODE:
		// we need to Release() our reference to this interface
		cpp_obj = (ICoreWebView2WebResourceRequestedEventArgs*)get_cpp_object(perl_obj);
		cpp_obj->lpVtbl->Release(cpp_obj);

		// now we can unlink
		unlink_perl_object(perl_obj);
