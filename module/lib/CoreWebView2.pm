use strict;

package CoreWebView2;

require DynaLoader;
require Exporter;
our @ISA = qw(DynaLoader Exporter);

# ICoreWebView2 version    our version
#    1.0.1150.38                0
our $VERSION = "v1.0.2210.55.1";

bootstrap CoreWebView2;

#
# exports
#

my @hresult_group = qw(HRESULT S_OK S_FALSE E_ABORT E_ACCESSDENIED E_FAIL E_HANDLE E_INVALIDARG E_NOINTERFACE E_NOTIMPL E_OUTOFMEMORY E_POINTER E_UNEXPECTED E_PENDING);
my @dispatch_group = qw(DISPATCH DISPATCH_METHOD DISPATCH_PROPERTYGET DISPATCH_PROPERTYPUT DISPATCH_PROPERTYPUTREF);
my @capture_preview_image_format_group = qw(CAPTURE_PREVIEW_IMAGE_FORMAT CAPTURE_PREVIEW_IMAGE_FORMAT_PNG CAPTURE_PREVIEW_IMAGE_FORMAT_JPEG);
my @cookie_same_site_kind_group = qw(COOKIE_SAME_SITE_KIND COOKIE_SAME_SITE_KIND_NONE COOKIE_SAME_SITE_KIND_LAX COOKIE_SAME_SITE_KIND_STRICT);
my @host_resource_access_kind_group = qw(HOST_RESOURCE_ACCESS_KIND HOST_RESOURCE_ACCESS_KIND_DENY HOST_RESOURCE_ACCESS_KIND_ALLOW HOST_RESOURCE_ACCESS_KIND_DENY_CORS);
my @script_dialog_kind_group = qw(SCRIPT_DIALOG_KIND SCRIPT_DIALOG_KIND_ALERT SCRIPT_DIALOG_KIND_CONFIRM SCRIPT_DIALOG_KIND_PROMPT SCRIPT_DIALOG_KIND_BEFOREUNLOAD);
my @process_failed_kind_group = qw(PROCESS_FAILED_KIND PROCESS_FAILED_KIND_BROWSER_PROCESS_EXITED PROCESS_FAILED_KIND_RENDER_PROCESS_EXITED PROCESS_FAILED_KIND_RENDER_PROCESS_UNRESPONSIVE PROCESS_FAILED_KIND_FRAME_RENDER_PROCESS_EXITED PROCESS_FAILED_KIND_UTILITY_PROCESS_EXITED PROCESS_FAILED_KIND_SANDBOX_HELPER_PROCESS_EXITED PROCESS_FAILED_KIND_GPU_PROCESS_EXITED PROCESS_FAILED_KIND_PPAPI_PLUGIN_PROCESS_EXITED PROCESS_FAILED_KIND_PPAPI_BROKER_PROCESS_EXITED PROCESS_FAILED_KIND_UNKNOWN_PROCESS_EXITED);
my @process_failed_reason_group = qw(PROCESS_FAILED_REASON PROCESS_FAILED_REASON_UNEXPECTED PROCESS_FAILED_REASON_UNRESPONSIVE PROCESS_FAILED_REASON_TERMINATED PROCESS_FAILED_REASON_CRASHED PROCESS_FAILED_REASON_LAUNCH_FAILED PROCESS_FAILED_REASON_OUT_OF_MEMORY PROCESS_FAILED_REASON_PROFILE_DELETED);
my @permission_kind_group = qw(PERMISSION_KIND PERMISSION_KIND_UNKNOWN_PERMISSION PERMISSION_KIND_MICROPHONE PERMISSION_KIND_CAMERA PERMISSION_KIND_GEOLOCATION PERMISSION_KIND_NOTIFICATIONS PERMISSION_KIND_OTHER_SENSORS PERMISSION_KIND_CLIPBOARD_READ PERMISSION_KIND_MULTIPLE_AUTOMATIC_DOWNLOADS PERMISSION_KIND_FILE_READ_WRITE PERMISSION_KIND_AUTOPLAY PERMISSION_KIND_LOCAL_FONTS PERMISSION_KIND_MIDI_SYSTEM_EXCLUSIVE_MESSAGES PERMISSION_KIND_WINDOW_MANAGEMENT);
my @permission_state_group = qw(PERMISSION_STATE PERMISSION_STATE_DEFAULT PERMISSION_STATE_ALLOW PERMISSION_STATE_DENY);
my @web_error_status_group = qw(WEB_ERROR_STATUS WEB_ERROR_STATUS_UNKNOWN WEB_ERROR_STATUS_CERTIFICATE_COMMON_NAME_IS_INCORRECT WEB_ERROR_STATUS_CERTIFICATE_EXPIRED WEB_ERROR_STATUS_CLIENT_CERTIFICATE_CONTAINS_ERRORS WEB_ERROR_STATUS_CERTIFICATE_REVOKED WEB_ERROR_STATUS_CERTIFICATE_IS_INVALID WEB_ERROR_STATUS_SERVER_UNREACHABLE WEB_ERROR_STATUS_TIMEOUT WEB_ERROR_STATUS_ERROR_HTTP_INVALID_SERVER_RESPONSE WEB_ERROR_STATUS_CONNECTION_ABORTED WEB_ERROR_STATUS_CONNECTION_RESET WEB_ERROR_STATUS_DISCONNECTED WEB_ERROR_STATUS_CANNOT_CONNECT WEB_ERROR_STATUS_HOST_NAME_NOT_RESOLVED WEB_ERROR_STATUS_OPERATION_CANCELED WEB_ERROR_STATUS_REDIRECT_FAILED WEB_ERROR_STATUS_UNEXPECTED_ERROR WEB_ERROR_STATUS_VALID_AUTHENTICATION_CREDENTIALS_REQUIRED WEB_ERROR_STATUS_VALID_PROXY_AUTHENTICATION_REQUIRED);
my @web_resource_context_group = qw(WEB_RESOURCE_CONTEXT WEB_RESOURCE_CONTEXT_ALL WEB_RESOURCE_CONTEXT_DOCUMENT WEB_RESOURCE_CONTEXT_STYLESHEET WEB_RESOURCE_CONTEXT_IMAGE WEB_RESOURCE_CONTEXT_MEDIA WEB_RESOURCE_CONTEXT_FONT WEB_RESOURCE_CONTEXT_SCRIPT WEB_RESOURCE_CONTEXT_XML_HTTP_REQUEST WEB_RESOURCE_CONTEXT_FETCH WEB_RESOURCE_CONTEXT_TEXT_TRACK WEB_RESOURCE_CONTEXT_EVENT_SOURCE WEB_RESOURCE_CONTEXT_WEBSOCKET WEB_RESOURCE_CONTEXT_MANIFEST WEB_RESOURCE_CONTEXT_SIGNED_EXCHANGE WEB_RESOURCE_CONTEXT_PING WEB_RESOURCE_CONTEXT_CSP_VIOLATION_REPORT WEB_RESOURCE_CONTEXT_OTHER);
my @move_focus_reason_group = qw(MOVE_FOCUS_REASON MOVE_FOCUS_REASON_PROGRAMMATIC MOVE_FOCUS_REASON_NEXT MOVE_FOCUS_REASON_PREVIOUS);
my @key_event_kind_group = qw(KEY_EVENT_KIND KEY_EVENT_KIND_KEY_DOWN KEY_EVENT_KIND_KEY_UP KEY_EVENT_KIND_SYSTEM_KEY_DOWN KEY_EVENT_KIND_SYSTEM_KEY_UP);
my @browser_process_exit_kind_group = qw(BROWSER_PROCESS_EXIT_KIND BROWSER_PROCESS_EXIT_KIND_NORMAL BROWSER_PROCESS_EXIT_KIND_FAILED);
my @mouse_event_kind_group = qw(MOUSE_EVENT_KIND MOUSE_EVENT_KIND_HORIZONTAL_WHEEL MOUSE_EVENT_KIND_LEFT_BUTTON_DOUBLE_CLICK MOUSE_EVENT_KIND_LEFT_BUTTON_DOWN MOUSE_EVENT_KIND_LEFT_BUTTON_UP MOUSE_EVENT_KIND_LEAVE MOUSE_EVENT_KIND_MIDDLE_BUTTON_DOUBLE_CLICK MOUSE_EVENT_KIND_MIDDLE_BUTTON_DOWN MOUSE_EVENT_KIND_MIDDLE_BUTTON_UP MOUSE_EVENT_KIND_MOVE MOUSE_EVENT_KIND_RIGHT_BUTTON_DOUBLE_CLICK MOUSE_EVENT_KIND_RIGHT_BUTTON_DOWN MOUSE_EVENT_KIND_RIGHT_BUTTON_UP MOUSE_EVENT_KIND_WHEEL MOUSE_EVENT_KIND_X_BUTTON_DOUBLE_CLICK MOUSE_EVENT_KIND_X_BUTTON_DOWN MOUSE_EVENT_KIND_X_BUTTON_UP MOUSE_EVENT_KIND_NON_CLIENT_RIGHT_BUTTON_DOWN MOUSE_EVENT_KIND_NON_CLIENT_RIGHT_BUTTON_UP);
my @mouse_event_virtual_keys_group = qw(MOUSE_EVENT_VIRTUAL_KEYS MOUSE_EVENT_VIRTUAL_KEYS_NONE MOUSE_EVENT_VIRTUAL_KEYS_LEFT_BUTTON MOUSE_EVENT_VIRTUAL_KEYS_RIGHT_BUTTON MOUSE_EVENT_VIRTUAL_KEYS_SHIFT MOUSE_EVENT_VIRTUAL_KEYS_CONTROL MOUSE_EVENT_VIRTUAL_KEYS_MIDDLE_BUTTON MOUSE_EVENT_VIRTUAL_KEYS_X_BUTTON1 MOUSE_EVENT_VIRTUAL_KEYS_X_BUTTON2);
my @pointer_event_kind_group = qw(POINTER_EVENT_KIND POINTER_EVENT_KIND_ACTIVATE POINTER_EVENT_KIND_DOWN POINTER_EVENT_KIND_ENTER POINTER_EVENT_KIND_LEAVE POINTER_EVENT_KIND_UP POINTER_EVENT_KIND_UPDATE);
my @bounds_mode_group = qw(BOUNDS_MODE BOUNDS_MODE_USE_RAW_PIXELS BOUNDS_MODE_USE_RASTERIZATION_SCALE);
my @client_certificate_kind_group = qw(CLIENT_CERTIFICATE_KIND CLIENT_CERTIFICATE_KIND_SMART_CARD CLIENT_CERTIFICATE_KIND_PIN CLIENT_CERTIFICATE_KIND_OTHER);
my @download_state_group = qw(DOWNLOAD_STATE DOWNLOAD_STATE_IN_PROGRESS DOWNLOAD_STATE_INTERRUPTED DOWNLOAD_STATE_COMPLETED);
my @download_interrupt_reason_group = qw(DOWNLOAD_INTERRUPT_REASON DOWNLOAD_INTERRUPT_REASON_NONE DOWNLOAD_INTERRUPT_REASON_FILE_FAILED DOWNLOAD_INTERRUPT_REASON_FILE_ACCESS_DENIED DOWNLOAD_INTERRUPT_REASON_FILE_NO_SPACE DOWNLOAD_INTERRUPT_REASON_FILE_NAME_TOO_LONG DOWNLOAD_INTERRUPT_REASON_FILE_TOO_LARGE DOWNLOAD_INTERRUPT_REASON_FILE_MALICIOUS DOWNLOAD_INTERRUPT_REASON_FILE_TRANSIENT_ERROR DOWNLOAD_INTERRUPT_REASON_FILE_BLOCKED_BY_POLICY DOWNLOAD_INTERRUPT_REASON_FILE_SECURITY_CHECK_FAILED DOWNLOAD_INTERRUPT_REASON_FILE_TOO_SHORT DOWNLOAD_INTERRUPT_REASON_FILE_HASH_MISMATCH DOWNLOAD_INTERRUPT_REASON_NETWORK_FAILED DOWNLOAD_INTERRUPT_REASON_NETWORK_TIMEOUT DOWNLOAD_INTERRUPT_REASON_NETWORK_DISCONNECTED DOWNLOAD_INTERRUPT_REASON_NETWORK_SERVER_DOWN DOWNLOAD_INTERRUPT_REASON_NETWORK_INVALID_REQUEST DOWNLOAD_INTERRUPT_REASON_SERVER_FAILED DOWNLOAD_INTERRUPT_REASON_SERVER_NO_RANGE DOWNLOAD_INTERRUPT_REASON_SERVER_BAD_CONTENT DOWNLOAD_INTERRUPT_REASON_SERVER_UNAUTHORIZED DOWNLOAD_INTERRUPT_REASON_SERVER_CERTIFICATE_PROBLEM DOWNLOAD_INTERRUPT_REASON_SERVER_FORBIDDEN DOWNLOAD_INTERRUPT_REASON_SERVER_UNEXPECTED_RESPONSE DOWNLOAD_INTERRUPT_REASON_SERVER_CONTENT_LENGTH_MISMATCH DOWNLOAD_INTERRUPT_REASON_SERVER_CROSS_ORIGIN_REDIRECT DOWNLOAD_INTERRUPT_REASON_USER_CANCELED DOWNLOAD_INTERRUPT_REASON_USER_SHUTDOWN DOWNLOAD_INTERRUPT_REASON_USER_PAUSED DOWNLOAD_INTERRUPT_REASON_DOWNLOAD_PROCESS_CRASHED);
my @print_orientation_group = qw(PRINT_ORIENTATION PRINT_ORIENTATION_PORTRAIT PRINT_ORIENTATION_LANDSCAPE);
my @default_download_dialog_corner_alignment_group = qw(DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT_TOP_LEFT DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT_TOP_RIGHT DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT_BOTTOM_LEFT DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT_BOTTOM_RIGHT);
my @process_kind_group = qw(PROCESS_KIND PROCESS_KIND_BROWSER PROCESS_KIND_RENDERER PROCESS_KIND_UTILITY PROCESS_KIND_SANDBOX_HELPER PROCESS_KIND_GPU PROCESS_KIND_PPAPI_PLUGIN PROCESS_KIND_PPAPI_BROKER);
my @pdf_toolbar_items_group = qw(PDF_TOOLBAR_ITEMS PDF_TOOLBAR_ITEMS_NONE PDF_TOOLBAR_ITEMS_SAVE PDF_TOOLBAR_ITEMS_PRINT PDF_TOOLBAR_ITEMS_SAVE_AS PDF_TOOLBAR_ITEMS_ZOOM_IN PDF_TOOLBAR_ITEMS_ZOOM_OUT PDF_TOOLBAR_ITEMS_ROTATE PDF_TOOLBAR_ITEMS_FIT_PAGE PDF_TOOLBAR_ITEMS_PAGE_LAYOUT PDF_TOOLBAR_ITEMS_BOOKMARKS PDF_TOOLBAR_ITEMS_PAGE_SELECTOR PDF_TOOLBAR_ITEMS_SEARCH PDF_TOOLBAR_ITEMS_FULL_SCREEN PDF_TOOLBAR_ITEMS_MORE_SETTINGS);
my @context_menu_target_kind_group = qw(CONTEXT_MENU_TARGET_KIND CONTEXT_MENU_TARGET_KIND_PAGE CONTEXT_MENU_TARGET_KIND_IMAGE CONTEXT_MENU_TARGET_KIND_SELECTED_TEXT CONTEXT_MENU_TARGET_KIND_AUDIO CONTEXT_MENU_TARGET_KIND_VIDEO);
my @context_menu_item_kind_group = qw(CONTEXT_MENU_ITEM_KIND CONTEXT_MENU_ITEM_KIND_COMMAND CONTEXT_MENU_ITEM_KIND_CHECK_BOX CONTEXT_MENU_ITEM_KIND_RADIO CONTEXT_MENU_ITEM_KIND_SEPARATOR CONTEXT_MENU_ITEM_KIND_SUBMENU);
my @preferred_color_scheme_group = qw(PREFERRED_COLOR_SCHEME PREFERRED_COLOR_SCHEME_AUTO PREFERRED_COLOR_SCHEME_LIGHT PREFERRED_COLOR_SCHEME_DARK);
my @browsing_data_kinds_group = qw(BROWSING_DATA_KINDS BROWSING_DATA_KINDS_FILE_SYSTEMS BROWSING_DATA_KINDS_INDEXED_DB BROWSING_DATA_KINDS_LOCAL_STORAGE BROWSING_DATA_KINDS_WEB_SQL BROWSING_DATA_KINDS_CACHE_STORAGE BROWSING_DATA_KINDS_ALL_DOM_STORAGE BROWSING_DATA_KINDS_COOKIES BROWSING_DATA_KINDS_ALL_SITE BROWSING_DATA_KINDS_DISK_CACHE BROWSING_DATA_KINDS_DOWNLOAD_HISTORY BROWSING_DATA_KINDS_GENERAL_AUTOFILL BROWSING_DATA_KINDS_PASSWORD_AUTOSAVE BROWSING_DATA_KINDS_BROWSING_HISTORY BROWSING_DATA_KINDS_SETTINGS BROWSING_DATA_KINDS_ALL_PROFILE BROWSING_DATA_KINDS_SERVICE_WORKERS);
my @server_certificate_error_action_group = qw(SERVER_CERTIFICATE_ERROR_ACTION SERVER_CERTIFICATE_ERROR_ACTION_ALWAYS_ALLOW SERVER_CERTIFICATE_ERROR_ACTION_CANCEL SERVER_CERTIFICATE_ERROR_ACTION_DEFAULT);
my @favicon_image_format_group = qw(FAVICON_IMAGE_FORMAT FAVICON_IMAGE_FORMAT_PNG FAVICON_IMAGE_FORMAT_JPEG);
my @print_dialog_kind_group = qw(PRINT_DIALOG_KIND PRINT_DIALOG_KIND_BROWSER PRINT_DIALOG_KIND_SYSTEM);
my @print_duplex_group = qw(PRINT_DUPLEX PRINT_DUPLEX_DEFAULT PRINT_DUPLEX_ONE_SIDED PRINT_DUPLEX_TWO_SIDED_LONG_EDGE PRINT_DUPLEX_TWO_SIDED_SHORT_EDGE);
my @print_color_mode_group = qw(PRINT_COLOR_MODE PRINT_COLOR_MODE_DEFAULT PRINT_COLOR_MODE_COLOR PRINT_COLOR_MODE_GRAYSCALE);
my @print_collation_group = qw(PRINT_COLLATION PRINT_COLLATION_DEFAULT PRINT_COLLATION_COLLATED PRINT_COLLATION_UNCOLLATED);
my @print_media_size_group = qw(PRINT_MEDIA_SIZE PRINT_MEDIA_SIZE_DEFAULT PRINT_MEDIA_SIZE_CUSTOM);
my @print_status_group = qw(PRINT_STATUS PRINT_STATUS_SUCCEEDED PRINT_STATUS_PRINTER_UNAVAILABLE PRINT_STATUS_OTHER_ERROR);
my @tracking_prevention_level_group = qw(TRACKING_PREVENTION_LEVEL TRACKING_PREVENTION_LEVEL_NONE TRACKING_PREVENTION_LEVEL_BASIC TRACKING_PREVENTION_LEVEL_BALANCED TRACKING_PREVENTION_LEVEL_STRICT);
my @shared_buffer_access_group = qw(SHARED_BUFFER_ACCESS SHARED_BUFFER_ACCESS_READ_ONLY SHARED_BUFFER_ACCESS_READ_WRITE);
my @memory_usage_target_level_group = qw(MEMORY_USAGE_TARGET_LEVEL MEMORY_USAGE_TARGET_LEVEL_NORMAL MEMORY_USAGE_TARGET_LEVEL_LOW);
my @navigation_kind_group = qw(NAVIGATION_KIND NAVIGATION_KIND_RELOAD NAVIGATION_KIND_BACK_OR_FORWARD NAVIGATION_KIND_NEW_DOCUMENT);
my @frame_kind_group = qw(FRAME_KIND FRAME_KIND_UNKNOWN FRAME_KIND_MAIN_FRAME FRAME_KIND_IFRAME FRAME_KIND_EMBED FRAME_KIND_OBJECT);

our @EXPORT_OK = (qw(CreateCoreWebView2EnvironmentWithOptions CreateCoreWebView2Environment GetAvailableCoreWebView2BrowserVersionString CompareBrowserVersions), @hresult_group, @dispatch_group, @capture_preview_image_format_group, @cookie_same_site_kind_group, @host_resource_access_kind_group, @script_dialog_kind_group, @process_failed_kind_group, @process_failed_reason_group, @permission_kind_group, @permission_state_group, @web_error_status_group, @web_resource_context_group, @move_focus_reason_group, @key_event_kind_group, @browser_process_exit_kind_group, @mouse_event_kind_group, @mouse_event_virtual_keys_group, @pointer_event_kind_group, @bounds_mode_group, @client_certificate_kind_group, @download_state_group, @download_interrupt_reason_group, @print_orientation_group, @default_download_dialog_corner_alignment_group, @process_kind_group, @pdf_toolbar_items_group, @context_menu_target_kind_group, @context_menu_item_kind_group, @preferred_color_scheme_group, @browsing_data_kinds_group, @server_certificate_error_action_group, @favicon_image_format_group, @print_dialog_kind_group, @print_duplex_group, @print_color_mode_group, @print_collation_group, @print_media_size_group, @print_status_group, @tracking_prevention_level_group, @shared_buffer_access_group, @memory_usage_target_level_group, @navigation_kind_group, @frame_kind_group);

our %EXPORT_TAGS = (
	all => \@EXPORT_OK,
	HRESULT => \@hresult_group,
	DISPATCH => \@dispatch_group,
	CAPTURE_PREVIEW_IMAGE_FORMAT => \@capture_preview_image_format_group,
	COOKIE_SAME_SITE_KIND => \@cookie_same_site_kind_group,
	HOST_RESOURCE_ACCESS_KIND => \@host_resource_access_kind_group,
	SCRIPT_DIALOG_KIND => \@script_dialog_kind_group,
	PROCESS_FAILED_KIND => \@process_failed_kind_group,
	PROCESS_FAILED_REASON => \@process_failed_reason_group,
	PERMISSION_KIND => \@permission_kind_group,
	PERMISSION_STATE => \@permission_state_group,
	WEB_ERROR_STATUS => \@web_error_status_group,
	WEB_RESOURCE_CONTEXT => \@web_resource_context_group,
	MOVE_FOCUS_REASON => \@move_focus_reason_group,
	KEY_EVENT_KIND => \@key_event_kind_group,
	BROWSER_PROCESS_EXIT_KIND => \@browser_process_exit_kind_group,
	MOUSE_EVENT_KIND => \@mouse_event_kind_group,
	MOUSE_EVENT_VIRTUAL_KEYS => \@mouse_event_virtual_keys_group,
	POINTER_EVENT_KIND => \@pointer_event_kind_group,
	BOUNDS_MODE => \@bounds_mode_group,
	CLIENT_CERTIFICATE_KIND => \@client_certificate_kind_group,
	DOWNLOAD_STATE => \@download_state_group,
	DOWNLOAD_INTERRUPT_REASON => \@download_interrupt_reason_group,
	PRINT_ORIENTATION => \@print_orientation_group,
	DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT => \@default_download_dialog_corner_alignment_group,
	PROCESS_KIND => \@process_kind_group,
	PDF_TOOLBAR_ITEMS => \@pdf_toolbar_items_group,
	CONTEXT_MENU_TARGET_KIND => \@context_menu_target_kind_group,
	CONTEXT_MENU_ITEM_KIND => \@context_menu_item_kind_group,
	PREFERRED_COLOR_SCHEME => \@preferred_color_scheme_group,
	BROWSING_DATA_KINDS => \@browsing_data_kinds_group,
	SERVER_CERTIFICATE_ERROR_ACTION => \@server_certificate_error_action_group,
	FAVICON_IMAGE_FORMAT => \@favicon_image_format_group,
	PRINT_DIALOG_KIND => \@print_dialog_kind_group,
	PRINT_DUPLEX => \@print_duplex_group,
	PRINT_COLOR_MODE => \@print_color_mode_group,
	PRINT_COLLATION => \@print_collation_group,
	PRINT_MEDIA_SIZE => \@print_media_size_group,
	PRINT_STATUS => \@print_status_group,
	TRACKING_PREVENTION_LEVEL => \@tracking_prevention_level_group,
	SHARED_BUFFER_ACCESS => \@shared_buffer_access_group,
	MEMORY_USAGE_TARGET_LEVEL => \@memory_usage_target_level_group,
	NAVIGATION_KIND => \@navigation_kind_group,
	FRAME_KIND => \@frame_kind_group
);

our %IID = (
	'{76ECEACB-0462-4D94-AC83-423A6793775E}' => 'ICoreWebView2',
	'{9E8F0CF8-E670-4B5E-B2BC-73E061E3184C}' => 'ICoreWebView2_2',
	'{A0D6DF20-3B92-416D-AA0C-437A9C727857}' => 'ICoreWebView2_3',
	'{20D02D59-6DF2-42DC-BD06-F98A694B1302}' => 'ICoreWebView2_4',
	'{BEDB11B8-D63C-11EB-B8BC-0242AC130003}' => 'ICoreWebView2_5',
	'{499AADAC-D92C-4589-8A75-111BFC167795}' => 'ICoreWebView2_6',
	'{79C24D83-09A3-45AE-9418-487F32A58740}' => 'ICoreWebView2_7',
	'{E9632730-6E1E-43AB-B7B8-7B2C9E62E094}' => 'ICoreWebView2_8',
	'{4D7B2EAB-9FDC-468D-B998-A9260B5ED651}' => 'ICoreWebView2_9',
	'{B1690564-6F5A-4983-8E48-31D1143FECDB}' => 'ICoreWebView2_10',
	'{0BE78E56-C193-4051-B943-23B460C08BDB}' => 'ICoreWebView2_11',
	'{35D69927-BCFA-4566-9349-6B3E0D154CAC}' => 'ICoreWebView2_12',
	'{F75F09A8-667E-4983-88D6-C8773F315E84}' => 'ICoreWebView2_13',
	'{6DAA4F10-4A90-4753-8898-77C5DF534165}' => 'ICoreWebView2_14',
	'{517B2D1D-7DAE-4A66-A4F4-10352FFB9518}' => 'ICoreWebView2_15',
	'{0EB34DC9-9F91-41E1-8639-95CD5943906B}' => 'ICoreWebView2_16',
	'{702E75D4-FD44-434D-9D70-1A68A6B1192A}' => 'ICoreWebView2_17',
	'{7A626017-28BE-49B2-B865-3BA2B3522D90}' => 'ICoreWebView2_18',
	'{6921F954-79B0-437F-A997-C85811897C68}' => 'ICoreWebView2_19',
	'{B4BC1926-7305-11EE-B962-0242AC120002}' => 'ICoreWebView2_20',
	'{9F760F8A-FB79-42BE-9990-7B56900FA9C7}' => 'ICoreWebView2AcceleratorKeyPressedEventArgs',
	'{03B2C8C8-7799-4E34-BD66-ED26AA85F2BF}' => 'ICoreWebView2AcceleratorKeyPressedEventArgs2',
	'{B29C7E28-FA79-41A8-8E44-65811C76DCB2}' => 'ICoreWebView2AcceleratorKeyPressedEventHandler',
	'{B99369F3-9B11-47B5-BC6F-8E7895FCEA17}' => 'ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler',
	'{EF05516F-D897-4F9E-B672-D8E2307A3FB0}' => 'ICoreWebView2BasicAuthenticationRequestedEventArgs',
	'{58B4D6C2-18D4-497E-B39B-9A96533FA278}' => 'ICoreWebView2BasicAuthenticationRequestedEventHandler',
	'{07023F7D-2D77-4D67-9040-6E7D428C6A40}' => 'ICoreWebView2BasicAuthenticationResponse',
	'{7EF7FFA0-FAC5-462C-B189-3D9EDBE575DA}' => 'ICoreWebView2BrowserExtension',
	'{30C186CE-7FAD-421F-A3BC-A8EAF071DDB8}' => 'ICoreWebView2BrowserExtensionEnableCompletedHandler',
	'{2EF3D2DC-BD5F-4F4D-90AF-FD67798F0C2F}' => 'ICoreWebView2BrowserExtensionList',
	'{8E41909A-9B18-4BB1-8CDF-930F467A50BE}' => 'ICoreWebView2BrowserExtensionRemoveCompletedHandler',
	'{1F00663F-AF8C-4782-9CDD-DD01C52E34CB}' => 'ICoreWebView2BrowserProcessExitedEventArgs',
	'{FA504257-A216-4911-A860-FE8825712861}' => 'ICoreWebView2BrowserProcessExitedEventHandler',
	'{828E8AB6-D94C-4264-9CEF-5217170D6251}' => 'ICoreWebView2BytesReceivedChangedEventHandler',
	'{5C4889F0-5EF6-4C5A-952C-D8F1B92D0574}' => 'ICoreWebView2CallDevToolsProtocolMethodCompletedHandler',
	'{697E05E9-3D8F-45FA-96F4-8FFE1EDEDAF5}' => 'ICoreWebView2CapturePreviewCompletedHandler',
	'{C5FB2FCE-1CAC-4AEE-9C79-5ED0362EAAE0}' => 'ICoreWebView2Certificate',
	'{E9710A06-1D1D-49B2-8234-226F35846AE5}' => 'ICoreWebView2ClearBrowsingDataCompletedHandler',
	'{3B40AAC6-ACFE-4FFD-8211-F607B96E2D5B}' => 'ICoreWebView2ClearServerCertificateErrorActionsCompletedHandler',
	'{E7188076-BCC3-11EB-8529-0242AC130003}' => 'ICoreWebView2ClientCertificate',
	'{EF5674D2-BCC3-11EB-8529-0242AC130003}' => 'ICoreWebView2ClientCertificateCollection',
	'{BC59DB28-BCC3-11EB-8529-0242AC130003}' => 'ICoreWebView2ClientCertificateRequestedEventArgs',
	'{D7175BA2-BCC3-11EB-8529-0242AC130003}' => 'ICoreWebView2ClientCertificateRequestedEventHandler',
	'{3DF9B733-B9AE-4A15-86B4-EB9EE9826469}' => 'ICoreWebView2CompositionController',
	'{0B6A3D24-49CB-4806-BA20-B5E0734A7B26}' => 'ICoreWebView2CompositionController2',
	'{9570570E-4D76-4361-9EE1-F04D0DBDFB1E}' => 'ICoreWebView2CompositionController3',
	'{E45D98B1-AFEF-45BE-8BAF-6C7728867F73}' => 'ICoreWebView2ContainsFullScreenElementChangedEventHandler',
	'{0C8A1275-9B6B-4901-87AD-70DF25BAFA6E}' => 'ICoreWebView2ContentLoadingEventArgs',
	'{364471E7-F2BE-4910-BDBA-D72077D51C4B}' => 'ICoreWebView2ContentLoadingEventHandler',
	'{7AED49E3-A93F-497A-811C-749C6B6B6C65}' => 'ICoreWebView2ContextMenuItem',
	'{F562A2F5-C415-45CF-B909-D4B7C1E276D3}' => 'ICoreWebView2ContextMenuItemCollection',
	'{A1D309EE-C03F-11EB-8529-0242AC130003}' => 'ICoreWebView2ContextMenuRequestedEventArgs',
	'{04D3FE1D-AB87-42FB-A898-DA241D35B63C}' => 'ICoreWebView2ContextMenuRequestedEventHandler',
	'{B8611D99-EED6-4F3F-902C-A198502AD472}' => 'ICoreWebView2ContextMenuTarget',
	'{4D00C0D1-9434-4EB6-8078-8697A560334F}' => 'ICoreWebView2Controller',
	'{C979903E-D4CA-4228-92EB-47EE3FA96EAB}' => 'ICoreWebView2Controller2',
	'{F9614724-5D2B-41DC-AEF7-73D62B51543B}' => 'ICoreWebView2Controller3',
	'{97D418D5-A426-4E49-A151-E1A10F327D9E}' => 'ICoreWebView2Controller4',
	'{12AAE616-8CCB-44EC-BCB3-EB1831881635}' => 'ICoreWebView2ControllerOptions',
	'{06C991D8-9E7E-11ED-A8FC-0242AC120002}' => 'ICoreWebView2ControllerOptions2',
	'{AD26D6BE-1486-43E6-BF87-A2034006CA21}' => 'ICoreWebView2Cookie',
	'{F7F6F714-5D2A-43C6-9503-346ECE02D186}' => 'ICoreWebView2CookieList',
	'{177CD9E7-B6F5-451A-94A0-5D7A3A4C4141}' => 'ICoreWebView2CookieManager',
	'{02FAB84B-1428-4FB7-AD45-1B2E64736184}' => 'ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler',
	'{6C4819F3-C9B7-4260-8127-C9F5BDE7F68C}' => 'ICoreWebView2CreateCoreWebView2ControllerCompletedHandler',
	'{4E8A3389-C9D8-4BD2-B6B5-124FEE6CC14D}' => 'ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler',
	'{9DA43CCC-26E1-4DAD-B56C-D8961C94C571}' => 'ICoreWebView2CursorChangedEventHandler',
	'{49E1D0BC-FE9E-4481-B7C2-32324AA21998}' => 'ICoreWebView2CustomItemSelectedEventHandler',
	'{D60AC92C-37A6-4B26-A39E-95CFE59047BB}' => 'ICoreWebView2CustomSchemeRegistration',
	'{16B1E21A-C503-44F2-84C9-70ABA5031283}' => 'ICoreWebView2DOMContentLoadedEventArgs',
	'{4BAC7E9C-199E-49ED-87ED-249303ACF019}' => 'ICoreWebView2DOMContentLoadedEventHandler',
	'{C10E7F7B-B585-46F0-A623-8BEFBF3E4EE0}' => 'ICoreWebView2Deferral',
	'{653C2959-BB3A-4377-8632-B58ADA4E66C4}' => 'ICoreWebView2DevToolsProtocolEventReceivedEventArgs',
	'{2DC4959D-1494-4393-95BA-BEA4CB9EBD1B}' => 'ICoreWebView2DevToolsProtocolEventReceivedEventArgs2',
	'{E2FDA4BE-5456-406C-A261-3D452138362C}' => 'ICoreWebView2DevToolsProtocolEventReceivedEventHandler',
	'{B32CA51A-8371-45E9-9317-AF021D080367}' => 'ICoreWebView2DevToolsProtocolEventReceiver',
	'{F5F2B923-953E-4042-9F95-F3A118E1AFD4}' => 'ICoreWebView2DocumentTitleChangedEventHandler',
	'{3D6B6CF2-AFE1-44C7-A995-C65117714336}' => 'ICoreWebView2DownloadOperation',
	'{E99BBE21-43E9-4544-A732-282764EAFA60}' => 'ICoreWebView2DownloadStartingEventArgs',
	'{EFEDC989-C396-41CA-83F7-07F845A55724}' => 'ICoreWebView2DownloadStartingEventHandler',
	'{B96D755E-0319-4E92-A296-23436F46A1FC}' => 'ICoreWebView2Environment',
	'{EE0EB9DF-6F12-46CE-B53F-3F47B9C928E0}' => 'ICoreWebView2Environment10',
	'{F0913DC6-A0EC-42EF-9805-91DFF3A2966A}' => 'ICoreWebView2Environment11',
	'{F503DB9B-739F-48DD-B151-FDFCF253F54E}' => 'ICoreWebView2Environment12',
	'{AF641F58-72B2-11EE-B962-0242AC120002}' => 'ICoreWebView2Environment13',
	'{41F3632B-5EF4-404F-AD82-2D606C5A9A21}' => 'ICoreWebView2Environment2',
	'{80A22AE3-BE7C-4CE2-AFE1-5A50056CDEEB}' => 'ICoreWebView2Environment3',
	'{20944379-6DCF-41D6-A0A0-ABC0FC50DE0D}' => 'ICoreWebView2Environment4',
	'{319E423D-E0D7-4B8D-9254-AE9475DE9B17}' => 'ICoreWebView2Environment5',
	'{E59EE362-ACBD-4857-9A8E-D3644D9459A9}' => 'ICoreWebView2Environment6',
	'{43C22296-3BBD-43A4-9C00-5C0DF6DD29A2}' => 'ICoreWebView2Environment7',
	'{D6EB91DD-C3D2-45E5-BD29-6DC2BC4DE9CF}' => 'ICoreWebView2Environment8',
	'{F06F41BF-4B5A-49D8-B9F6-FA16CD29F274}' => 'ICoreWebView2Environment9',
	'{2FDE08A8-1E9A-4766-8C05-95A9CEB9D1C5}' => 'ICoreWebView2EnvironmentOptions',
	'{FF85C98A-1BA7-4A6B-90C8-2B752C89E9E2}' => 'ICoreWebView2EnvironmentOptions2',
	'{4A5C436E-A9E3-4A2E-89C3-910D3513F5CC}' => 'ICoreWebView2EnvironmentOptions3',
	'{AC52D13F-0D38-475A-9DCA-876580D6793E}' => 'ICoreWebView2EnvironmentOptions4',
	'{0AE35D64-C47F-4464-814E-259C345D1501}' => 'ICoreWebView2EnvironmentOptions5',
	'{57D29CC3-C84F-42A0-B0E2-EFFBD5E179DE}' => 'ICoreWebView2EnvironmentOptions6',
	'{28F0D425-93FE-4E63-9F8D-2AEEC6D3BA1E}' => 'ICoreWebView2EstimatedEndTimeChangedEventHandler',
	'{49511172-CC67-4BCA-9923-137112F4C4CC}' => 'ICoreWebView2ExecuteScriptCompletedHandler',
	'{2913DA94-833D-4DE0-8DCA-900FC524A1A4}' => 'ICoreWebView2FaviconChangedEventHandler',
	'{F2C19559-6BC1-4583-A757-90021BE9AFEC}' => 'ICoreWebView2File',
	'{05EA24BD-6452-4926-9014-4B82B498135D}' => 'ICoreWebView2FocusChangedEventHandler',
	'{F1131A5E-9BA9-11EB-A8B3-0242AC130003}' => 'ICoreWebView2Frame',
	'{7A6A5834-D185-4DBF-B63F-4A9BC43107D4}' => 'ICoreWebView2Frame2',
	'{B50D82CC-CC28-481D-9614-CB048895E6A0}' => 'ICoreWebView2Frame3',
	'{188782DC-92AA-4732-AB3C-FCC59F6F68B9}' => 'ICoreWebView2Frame4',
	'{99D199C4-7305-11EE-B962-0242AC120002}' => 'ICoreWebView2Frame5',
	'{0D6156F2-D332-49A7-9E03-7D8F2FEEEE54}' => 'ICoreWebView2FrameContentLoadingEventHandler',
	'{4D6E7B5E-9BAA-11EB-A8B3-0242AC130003}' => 'ICoreWebView2FrameCreatedEventArgs',
	'{38059770-9BAA-11EB-A8B3-0242AC130003}' => 'ICoreWebView2FrameCreatedEventHandler',
	'{38D9520D-340F-4D1E-A775-43FCE9753683}' => 'ICoreWebView2FrameDOMContentLoadedEventHandler',
	'{59DD7B4C-9BAA-11EB-A8B3-0242AC130003}' => 'ICoreWebView2FrameDestroyedEventHandler',
	'{DA86B8A1-BDF3-4F11-9955-528CEFA59727}' => 'ICoreWebView2FrameInfo',
	'{56F85CFA-72C4-11EE-B962-0242AC120002}' => 'ICoreWebView2FrameInfo2',
	'{8F834154-D38E-4D90-AFFB-6800A7272839}' => 'ICoreWebView2FrameInfoCollection',
	'{1BF89E2D-1B2B-4629-B28F-05099B41BB03}' => 'ICoreWebView2FrameInfoCollectionIterator',
	'{435C7DC8-9BAA-11EB-A8B3-0242AC130003}' => 'ICoreWebView2FrameNameChangedEventHandler',
	'{609302AD-0E36-4F9A-A210-6A45272842A9}' => 'ICoreWebView2FrameNavigationCompletedEventHandler',
	'{E79908BF-2D5D-4968-83DB-263FEA2C1DA3}' => 'ICoreWebView2FrameNavigationStartingEventHandler',
	'{845D0EDD-8BD8-429B-9915-4821789F23E9}' => 'ICoreWebView2FramePermissionRequestedEventHandler',
	'{E371E005-6D1D-4517-934B-A8F1629C62A5}' => 'ICoreWebView2FrameWebMessageReceivedEventHandler',
	'{5A4F5069-5C15-47C3-8646-F4DE1C116670}' => 'ICoreWebView2GetCookiesCompletedHandler',
	'{A2508329-7DA8-49D7-8C05-FA125E4AEE8D}' => 'ICoreWebView2GetFaviconCompletedHandler',
	'{38274481-A15C-4563-94CF-990EDC9AEB95}' => 'ICoreWebView2GetNonDefaultPermissionSettingsCompletedHandler',
	'{F45E55AA-3BC2-11EE-BE56-0242AC120002}' => 'ICoreWebView2GetProcessExtendedInfosCompletedHandler',
	'{C79A420C-EFD9-4058-9295-3E8B4BCAB645}' => 'ICoreWebView2HistoryChangedEventHandler',
	'{0702FC30-F43B-47BB-AB52-A42CB552AD9F}' => 'ICoreWebView2HttpHeadersCollectionIterator',
	'{E86CAC0E-5523-465C-B536-8FB9FC8C8C60}' => 'ICoreWebView2HttpRequestHeaders',
	'{03C5FF5A-9B45-4A88-881C-89A9F328619C}' => 'ICoreWebView2HttpResponseHeaders',
	'{3117DA26-AE13-438D-BD46-EDBEB2C4CE81}' => 'ICoreWebView2IsDefaultDownloadDialogOpenChangedEventHandler',
	'{5DEF109A-2F4B-49FA-B7F6-11C39E513328}' => 'ICoreWebView2IsDocumentPlayingAudioChangedEventHandler',
	'{57D90347-CD0E-4952-A4A2-7483A2756F08}' => 'ICoreWebView2IsMutedChangedEventHandler',
	'{07D1A6C3-7175-4BA1-9306-E593CA07E46C}' => 'ICoreWebView2LaunchingExternalUriSchemeEventArgs',
	'{74F712E0-8165-43A9-A13F-0CCE597E75DF}' => 'ICoreWebView2LaunchingExternalUriSchemeEventHandler',
	'{2D6AA13B-3839-4A15-92FC-D88B3C0D9C9D}' => 'ICoreWebView2MoveFocusRequestedEventArgs',
	'{69035451-6DC7-4CB8-9BCE-B2BD70AD289F}' => 'ICoreWebView2MoveFocusRequestedEventHandler',
	'{30D68B7D-20D9-4752-A9CA-EC8448FBB5C1}' => 'ICoreWebView2NavigationCompletedEventArgs',
	'{FDF8B738-EE1E-4DB2-A329-8D7D7B74D792}' => 'ICoreWebView2NavigationCompletedEventArgs2',
	'{D33A35BF-1C49-4F98-93AB-006E0533FE1C}' => 'ICoreWebView2NavigationCompletedEventHandler',
	'{5B495469-E119-438A-9B18-7604F25F2E49}' => 'ICoreWebView2NavigationStartingEventArgs',
	'{9086BE93-91AA-472D-A7E0-579F2BA006AD}' => 'ICoreWebView2NavigationStartingEventArgs2',
	'{DDFFE494-4942-4BD2-AB73-35B8FF40E19F}' => 'ICoreWebView2NavigationStartingEventArgs3',
	'{9ADBE429-F36D-432B-9DDC-F8881FBD76E3}' => 'ICoreWebView2NavigationStartingEventHandler',
	'{F9A2976E-D34E-44FC-ADEE-81B6B57CA914}' => 'ICoreWebView2NewBrowserVersionAvailableEventHandler',
	'{34ACB11C-FC37-4418-9132-F9C21D1EAFB9}' => 'ICoreWebView2NewWindowRequestedEventArgs',
	'{BBC7BAED-74C6-4C92-B63A-7F5AEAE03DE3}' => 'ICoreWebView2NewWindowRequestedEventArgs2',
	'{842BED3C-6AD6-4DD9-B938-28C96667AD66}' => 'ICoreWebView2NewWindowRequestedEventArgs3',
	'{D4C185FE-C81C-4989-97AF-2D3FA7AB5651}' => 'ICoreWebView2NewWindowRequestedEventHandler',
	'{0F36FD87-4F69-4415-98DA-888F89FB9A33}' => 'ICoreWebView2ObjectCollectionView',
	'{973AE2EF-FF18-4894-8FB2-3C758F046810}' => 'ICoreWebView2PermissionRequestedEventArgs',
	'{74D7127F-9DE6-4200-8734-42D6FB4FF741}' => 'ICoreWebView2PermissionRequestedEventArgs2',
	'{E61670BC-3DCE-4177-86D2-C629AE3CB6AC}' => 'ICoreWebView2PermissionRequestedEventArgs3',
	'{15E1C6A3-C72A-4DF3-91D7-D097FBEC6BFD}' => 'ICoreWebView2PermissionRequestedEventHandler',
	'{792B6ECA-5576-421C-9119-74EBB3A4FFB3}' => 'ICoreWebView2PermissionSetting',
	'{F5596F62-3DE5-47B1-91E8-A4104B596B96}' => 'ICoreWebView2PermissionSettingCollectionView',
	'{E6995887-D10D-4F5D-9359-4CE46E4F96B9}' => 'ICoreWebView2PointerInfo',
	'{8FD80075-ED08-42DB-8570-F5D14977461E}' => 'ICoreWebView2PrintCompletedHandler',
	'{377F3721-C74E-48CA-8DB1-DF68E51D60E2}' => 'ICoreWebView2PrintSettings',
	'{CA7F0E1F-3484-41D1-8C1A-65CD44A63F8D}' => 'ICoreWebView2PrintSettings2',
	'{CCF1EF04-FD8E-4D5F-B2DE-0983E41B8C36}' => 'ICoreWebView2PrintToPdfCompletedHandler',
	'{4C9F8229-8F93-444F-A711-2C0DFD6359D5}' => 'ICoreWebView2PrintToPdfStreamCompletedHandler',
	'{AF4C4C2E-45DB-11EE-BE56-0242AC120002}' => 'ICoreWebView2ProcessExtendedInfo',
	'{32EFA696-407A-11EE-BE56-0242AC120002}' => 'ICoreWebView2ProcessExtendedInfoCollection',
	'{8155A9A4-1474-4A86-8CAE-151B0FA6B8CA}' => 'ICoreWebView2ProcessFailedEventArgs',
	'{4DAB9422-46FA-4C3E-A5D2-41D2071D3680}' => 'ICoreWebView2ProcessFailedEventArgs2',
	'{79E0AEA4-990B-42D9-AA1D-0FCC2E5BC7F1}' => 'ICoreWebView2ProcessFailedEventHandler',
	'{84FA7612-3F3D-4FBF-889D-FAD000492D72}' => 'ICoreWebView2ProcessInfo',
	'{402B99CD-A0CC-4FA5-B7A5-51D86A1D2339}' => 'ICoreWebView2ProcessInfoCollection',
	'{F4AF0C39-44B9-40E9-8B11-0484CFB9E0A1}' => 'ICoreWebView2ProcessInfosChangedEventHandler',
	'{79110AD3-CD5D-4373-8BC3-C60658F17A5F}' => 'ICoreWebView2Profile',
	'{FA740D4B-5EAE-4344-A8AD-74BE31925397}' => 'ICoreWebView2Profile2',
	'{B188E659-5685-4E05-BDBA-FC640E0F1992}' => 'ICoreWebView2Profile3',
	'{8F4AE680-192E-4EC8-833A-21CFADAEF628}' => 'ICoreWebView2Profile4',
	'{2EE5B76E-6E80-4DF2-BCD3-D4EC3340A01B}' => 'ICoreWebView2Profile5',
	'{BD82FA6A-1D65-4C33-B2B4-0393020CC61B}' => 'ICoreWebView2Profile6',
	'{7B4C7906-A1AA-4CB4-B723-DB09F813D541}' => 'ICoreWebView2Profile7',
	'{FBF70C2F-EB1F-4383-85A0-163E92044011}' => 'ICoreWebView2Profile8',
	'{DF1AAB27-82B9-4AB6-AAE8-017A49398C14}' => 'ICoreWebView2ProfileAddBrowserExtensionCompletedHandler',
	'{DF35055D-772E-4DBE-B743-5FBF74A2B258}' => 'ICoreWebView2ProfileDeletedEventHandler',
	'{FCE16A1C-F107-4601-8B75-FC4940AE25D0}' => 'ICoreWebView2ProfileGetBrowserExtensionsCompletedHandler',
	'{9C98C8B1-AC53-427E-A345-3049B5524BBE}' => 'ICoreWebView2RasterizationScaleChangedEventHandler',
	'{7390BB70-ABE0-4843-9529-F143B31B03D6}' => 'ICoreWebView2ScriptDialogOpeningEventArgs',
	'{EF381BF9-AFA8-4E37-91C4-8AC48524BDFB}' => 'ICoreWebView2ScriptDialogOpeningEventHandler',
	'{012193ED-7C13-48FF-969D-A84C1F432A14}' => 'ICoreWebView2ServerCertificateErrorDetectedEventArgs',
	'{969B3A26-D85E-4795-8199-FEF57344DA22}' => 'ICoreWebView2ServerCertificateErrorDetectedEventHandler',
	'{FC77FB30-9C9E-4076-B8C7-7644A703CA1B}' => 'ICoreWebView2SetPermissionStateCompletedHandler',
	'{E562E4F0-D7FA-43AC-8D71-C05150499F00}' => 'ICoreWebView2Settings',
	'{EE9A0F68-F46C-4E32-AC23-EF8CAC224D2A}' => 'ICoreWebView2Settings2',
	'{FDB5AB74-AF33-4854-84F0-0A631DEB5EBA}' => 'ICoreWebView2Settings3',
	'{CB56846C-4168-4D53-B04F-03B6D6796FF2}' => 'ICoreWebView2Settings4',
	'{183E7052-1D03-43A0-AB99-98E043B66B39}' => 'ICoreWebView2Settings5',
	'{11CB3ACD-9BC8-43B8-83BF-F40753714F87}' => 'ICoreWebView2Settings6',
	'{488DC902-35EF-42D2-BC7D-94B65C4BC49C}' => 'ICoreWebView2Settings7',
	'{9E6B0E8F-86AD-4E81-8147-A9B5EDB68650}' => 'ICoreWebView2Settings8',
	'{B747A495-0C6F-449E-97B8-2F81E9D6AB43}' => 'ICoreWebView2SharedBuffer',
	'{31E0E545-1DBA-4266-8914-F63848A1F7D7}' => 'ICoreWebView2SourceChangedEventArgs',
	'{3C067F9F-5388-4772-8B48-79F7EF1AB37C}' => 'ICoreWebView2SourceChangedEventHandler',
	'{81336594-7EDE-4BA9-BF71-ACF0A95B58DD}' => 'ICoreWebView2StateChangedEventHandler',
	'{A5E3B0D0-10DF-4156-BFAD-3B43867ACAC6}' => 'ICoreWebView2StatusBarTextChangedEventHandler',
	'{F41F3F8A-BCC3-11EB-8529-0242AC130003}' => 'ICoreWebView2StringCollection',
	'{00F206A7-9D17-4605-91F6-4E8E4DE192E3}' => 'ICoreWebView2TrySuspendCompletedHandler',
	'{0F99A40C-E962-4207-9E92-E3D542EFF849}' => 'ICoreWebView2WebMessageReceivedEventArgs',
	'{06FC7AB7-C90C-4297-9389-33CA01CF6D5E}' => 'ICoreWebView2WebMessageReceivedEventArgs2',
	'{57213F19-00E6-49FA-8E07-898EA01ECBD2}' => 'ICoreWebView2WebMessageReceivedEventHandler',
	'{97055CD4-512C-4264-8B5F-E3F446CEA6A5}' => 'ICoreWebView2WebResourceRequest',
	'{453E667F-12C7-49D4-BE6D-DDBE7956F57A}' => 'ICoreWebView2WebResourceRequestedEventArgs',
	'{AB00B74C-15F1-4646-80E8-E76341D25D71}' => 'ICoreWebView2WebResourceRequestedEventHandler',
	'{AAFCC94F-FA27-48FD-97DF-830EF75AAEC9}' => 'ICoreWebView2WebResourceResponse',
	'{D1DB483D-6796-4B8B-80FC-13712BB716F4}' => 'ICoreWebView2WebResourceResponseReceivedEventArgs',
	'{7DE9898A-24F5-40C3-A2DE-D4F458E69828}' => 'ICoreWebView2WebResourceResponseReceivedEventHandler',
	'{79701053-7759-4162-8F7D-F1B3F084928D}' => 'ICoreWebView2WebResourceResponseView',
	'{875738E1-9FA2-40E3-8B74-2E8972DD6FE7}' => 'ICoreWebView2WebResourceResponseViewGetContentCompletedHandler',
	'{5C19E9E0-092F-486B-AFFA-CA8231913039}' => 'ICoreWebView2WindowCloseRequestedEventHandler',
	'{5EAF559F-B46E-4397-8860-E422F287FF1E}' => 'ICoreWebView2WindowFeatures',
	'{B52D71D6-C4DF-4543-A90C-64A3E60F38CB}' => 'ICoreWebView2ZoomFactorChangedEventHandler',
);

# non-CoreWebView2 interfaces:
$IID{'{00000000-0000-0000-0000-000000000000}'} = 'IID_NULL';
$IID{'{00000000-0000-0000-C000-000000000046}'} = 'IID_IUnknown';
$IID{'{0000000C-0000-0000-C000-000000000046}'} = 'IID_IStream'; # is this one correct?
$IID{'{00020400-0000-0000-C000-000000000046}'} = 'IID_IDispatch';
$IID{'{00020401-0000-0000-C000-000000000046}'} = 'IID_ITypeInfo';

$IID{'{0C733A30-2A1C-11CE-ADE5-00AA0044773D}'} = 'IID_ISequentialStream';

# any class that has properties and is not mentioned here will get the default tie class
our %TIECLASS = (
);

# set the default tie class for any relevant classes
my @pkg = (
	[ 'CoreWebView2::', $main::{'CoreWebView2::'} ],
	sort map { [ 'CoreWebView2::' . $_, $CoreWebView2::{$_} ] } grep { /::$/ } keys %CoreWebView2::
);
for my $pkg (@pkg) {
	my ($name, $sym) = @$pkg;
	# do we have a property getter and/or setter?
	if (grep { /^(get|put)_/ } keys %$sym) {
		$name=~s/::$//;
		next if $TIECLASS{$name};
		$TIECLASS{$name} = 'CoreWebView2::properties';
	}
}

# these appear to be internal JS interfaces
# {500CB338-810C-4E06-927A-0CED2C5C19C0}
# {F2A70B4A-FA05-45DA-9A4E-7BE0467E18E7}
# {2E324595-31A2-4797-9F23-A657B22A1E4B}
# {349F926B-227F-40EF-A359-B941253ED0D3}

sub refcount {
	my ($item) = @_;
	my @out = ('object: ' . (_refcount(\$item) - 1));
	if ($item=~/HASH/) {
		push @out , 'hash: ' . (_refcount($item) - 1);
		if (my $t = tied %{ $item }) {
			push @out , 'tie: ' . (_refcount(\$t) - 1);
			if ($t=~/HASH/) {
				push @out , 'tie hash: ' . (_refcount($t) - 1);
			}
		}
	}
	warn join(' ', @out, "<= $item");
}

#
# tied property hash (CURRENTLY UNUSED)
#

package CoreWebView2::properties;
use Scalar::Util qw(weaken);

use Data::Dumper;

my %CLASS_PROPERTIES;

####################################################################################################
#
# DO NOT TIE ANYTHING TO THIS CLASS YOURSELF
#
# Each CoreWebView2 object is specially linked to a C++ object, and when the object is DESTROYED,
# that link is removed
#
# To make the tied magic below work, the tied object is also linked to the C++ object, and has an
# inheritance as follows:
#
# @CoreWebView2::MyClass::hash::ISA = qw(CoreWebView2::properties CoreWebView2::MyClass);
#
# So the result is we have an external object and a tied object than can both call the same methods
# on the same C++ object, but the external object can access certain methods (get_X, put_X) as
# hash keys instead of methods, via the tied object.
#
####################################################################################################

sub TIEHASH {
	my ($class, $object) = @_;
#warn Dumper $object;

	my $obj_class = ref $object;

	my $self = bless {
		object => $object,
		class  => $obj_class,
		data   => {},
		keys   => [],
	}, $class;

	# first time we see an object class, scan it for properties
	if (not $CLASS_PROPERTIES{$obj_class}) {
		no strict;
		$CLASS_PROPERTIES{$obj_class} = { map { $_ => 1 } grep { s/^get_// } keys %{"$obj_class\::"} };
	}

	return $self;
}

sub FETCH {
	my ($self, $key) = @_;

	# object property?
	if ($CLASS_PROPERTIES{ $self->{class} }{$key}) {
		my $method = 'get_' . $key;
		no strict;
		return $self->{object}->$method();
	}

	# if not, real data
	return $self->{data}{$key};
}

sub STORE {
	my ($self, $key, $value) = @_;

	# object property?
	if ($CLASS_PROPERTIES{ $self->{class} }{$key}) {
		my $method = 'put_' . $key;
		no strict;
		# will die if read-only property, but that's what we would do anyway
		return $self->$method($value);
	}

	# if not, real data
	return $self->{data}{$key} = $value;
}

sub DELETE {
	my ($self, $key) = @_;

	# object property?
	if ($CLASS_PROPERTIES{ $self->{class} }{$key}) {
		die "Unable to delete inherent property of " . ref $self;
	}

	# if not, real data
	return delete $self->{data}{$key};
}

sub CLEAR {
	my ($self) = @_;

	# clear only the real data
	%{ $self->{data} } = ();
}

sub EXISTS {
	my ($self, $key) = @_;

	# object property?
	if ($CLASS_PROPERTIES{ $self->{class} }{$key}) {
		return 1;
	}

	# if not, real data
	return exists $self->{data}{$key};
}

sub FIRSTKEY {
	my ($self) = @_;

	# combine inherent properties and real data
	@{ $self->{keys} } = (
		keys %{ $CLASS_PROPERTIES{ $self->{class} } },
		keys %{ $self->{data} },
	);

	return shift @{ $self->{keys} };
}

sub NEXTKEY {
	my ($self, $lastkey) = @_;

	return shift @{ $self->{keys} };
}

sub SCALAR {
	my ($self) = @_;

	# combine inherent properties and real data
	@{ $self->{keys} } = (
		keys %{ $CLASS_PROPERTIES{ $self->{class} } },
		keys %{ $self->{data} },
	);
}

#sub UNTIE {
#	my ($self) = @_;
#	warn "Untying tied object $_[0]";
#}

# prevent this object from finding the other DESTROY in its inheritance chain
# (that could cause problems if anyone unties() the object but the object sticks around)
sub DESTROY {
#warn;
#my $i = 0;
#while (my @c = caller($i)) {
#	$i++;
#	warn join(' <> ', $i, @c) . "\n";
#}
#	my ($self) = @_;
#warn "Destroying tied object $_[0]";
#	CoreWebView2::dump($self);
#warn;
}

1;

__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

CoreWebView2 - Perl extension for blah blah blah

=head1 SYNOPSIS

  use CoreWebView2;
  blah blah blah

=head1 DESCRIPTION

Stub documentation for CoreWebView2, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

A. U. Thor, E<lt>a.u.thor@a.galaxy.far.far.awayE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2022 by A. U. Thor

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.30.1 or,
at your option, any later version of Perl 5 you may have available.


=cut
