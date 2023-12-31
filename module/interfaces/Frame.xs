#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = CoreWebView2	PACKAGE = CoreWebView2::Frame

PROTOTYPES: DISABLE

LPWSTR
ICoreWebView2Frame5::get_Name()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->get_Name(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_NameChanged(eventHandler)
	INPUT:
		ICoreWebView2FrameNameChangedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_NameChanged(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_NameChanged(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_NameChanged(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::AddHostObjectToScriptWithOrigins(name, object, first, ...)
	INPUT:
		LPCWSTR name;
		VARIANT* object;
		SV* first;
	INIT:
		bool is_aref;
		UINT32 originsCount;
		LPCWSTR* origins;
		SV* error_sv;
	CODE:
		// if there is only one item AND it is an aref, then we are processing an aref
		is_aref = (items == 1 && SvTYPE(first) == SVt_PVAV);
		originsCount = is_aref ? av_top_index((AV*)SvRV(first)) + 1 : items;
		origins = (LPCWSTR*)malloc(sizeof(LPCWSTR) * originsCount);

		if (is_aref) {
			SV** item;
			AV* temp_array = (AV*)SvRV(first);
			for (int i = 0; i < originsCount; i++) {
				item = av_fetch(temp_array, i, 0);
				std::wstring str = scalar_to_wstring(*item);
				origins[i] = str.c_str();
			}
		}
		// otherwise, we are processing a list
		else {
			for (int i = 0; i < originsCount; i++) {
				std::wstring str = scalar_to_wstring(ST(i));
				origins[i] = str.c_str();
			}
		}

		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->AddHostObjectToScriptWithOrigins(THIS, name, object, originsCount, origins);
		CHECK_ERROR(RETVAL, error_sv);

		// since these strings have been copied by the underlying object, we now have to free them
		for (int i = 0; i < originsCount; i++) {
			free((void*)origins[i]);
		}
		free(origins);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::RemoveHostObjectFromScript(name)
	INPUT:
		LPCWSTR name;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->RemoveHostObjectFromScript(THIS, name);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_Destroyed(eventHandler)
	INPUT:
		ICoreWebView2FrameDestroyedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_Destroyed(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_Destroyed(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_Destroyed(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

BOOL
ICoreWebView2Frame5::IsDestroyed()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->IsDestroyed(THIS, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_NavigationStarting(eventHandler)
	INPUT:
		ICoreWebView2FrameNavigationStartingEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_NavigationStarting(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_NavigationStarting(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_NavigationStarting(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_ContentLoading(eventHandler)
	INPUT:
		ICoreWebView2FrameContentLoadingEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_ContentLoading(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_ContentLoading(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_ContentLoading(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_NavigationCompleted(eventHandler)
	INPUT:
		ICoreWebView2FrameNavigationCompletedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_NavigationCompleted(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_NavigationCompleted(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_NavigationCompleted(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_DOMContentLoaded(eventHandler)
	INPUT:
		ICoreWebView2FrameDOMContentLoadedEventHandler* eventHandler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_DOMContentLoaded(THIS, eventHandler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_DOMContentLoaded(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_DOMContentLoaded(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::ExecuteScript(javaScript, handler)
	INPUT:
		LPCWSTR javaScript;
		ICoreWebView2ExecuteScriptCompletedHandler* handler;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->ExecuteScript(THIS, javaScript, handler);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::PostWebMessageAsJson(webMessageAsJson)
	INPUT:
		LPCWSTR webMessageAsJson;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->PostWebMessageAsJson(THIS, webMessageAsJson);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::PostWebMessageAsString(webMessageAsString)
	INPUT:
		LPCWSTR webMessageAsString;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->PostWebMessageAsString(THIS, webMessageAsString);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_WebMessageReceived(handler)
	INPUT:
		ICoreWebView2FrameWebMessageReceivedEventHandler* handler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_WebMessageReceived(THIS, handler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_WebMessageReceived(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_WebMessageReceived(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

EventRegistrationToken
ICoreWebView2Frame5::add_PermissionRequested(handler)
	INPUT:
		ICoreWebView2FramePermissionRequestedEventHandler* handler;
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->add_PermissionRequested(THIS, handler, &RETVAL);
		CHECK_ERROR(result, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::remove_PermissionRequested(token)
	INPUT:
		EventRegistrationToken token;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->remove_PermissionRequested(THIS, token);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

HRESULT
ICoreWebView2Frame5::PostSharedBufferToScript(sharedBuffer, access, additionalDataAsJson)
	INPUT:
		ICoreWebView2SharedBuffer* sharedBuffer;
		COREWEBVIEW2_SHARED_BUFFER_ACCESS access;
		LPCWSTR additionalDataAsJson;
	INIT:
		SV* error_sv;
	CODE:
		RETVAL = ((ICoreWebView2Frame5*)THIS)->lpVtbl->PostSharedBufferToScript(THIS, sharedBuffer, access, additionalDataAsJson);
		CHECK_ERROR(RETVAL, error_sv);
	OUTPUT:
		RETVAL

UINT32
ICoreWebView2Frame5::get_FrameId()
	INIT:
		HRESULT result;
		SV* error_sv;
	CODE:
		result = ((ICoreWebView2Frame5*)THIS)->lpVtbl->get_FrameId(THIS, &RETVAL);
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
