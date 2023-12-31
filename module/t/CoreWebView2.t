use strict;
use warnings;

use Test::More tests => 266;
BEGIN { use_ok('CoreWebView2') };

# CoreWebView2
#ok(0, 'CoreWebView2::AddHostObjectToScript');
#ok(0, 'CoreWebView2::AddScriptToExecuteOnDocumentCreated');
#ok(0, 'CoreWebView2::AddWebResourceRequestedFilter');
#ok(0, 'CoreWebView2::CallDevToolsProtocolMethod');
#ok(0, 'CoreWebView2::CallDevToolsProtocolMethodForSession');
#ok(0, 'CoreWebView2::CapturePreview');
#ok(0, 'CoreWebView2::ClearServerCertificateErrorActions');
#ok(0, 'CoreWebView2::ClearVirtualHostNameToFolderMapping');
#ok(0, 'CoreWebView2::CloseDefaultDownloadDialog');
#ok(0, 'CoreWebView2::ExecuteScript');
#ok(0, 'CoreWebView2::GetDevToolsProtocolEventReceiver');
#ok(0, 'CoreWebView2::GetFavicon');
#ok(0, 'CoreWebView2::GoBack');
#ok(0, 'CoreWebView2::GoForward');
#ok(0, 'CoreWebView2::Navigate');
#ok(0, 'CoreWebView2::NavigateToString');
#ok(0, 'CoreWebView2::NavigateWithWebResourceRequest');
#ok(0, 'CoreWebView2::OpenDefaultDownloadDialog');
#ok(0, 'CoreWebView2::OpenDevToolsWindow');
#ok(0, 'CoreWebView2::OpenTaskManagerWindow');
#ok(0, 'CoreWebView2::PostSharedBufferToScript');
#ok(0, 'CoreWebView2::PostWebMessageAsJson');
#ok(0, 'CoreWebView2::PostWebMessageAsString');
#ok(0, 'CoreWebView2::Print');
#ok(0, 'CoreWebView2::PrintToPdf');
#ok(0, 'CoreWebView2::PrintToPdfStream');
#ok(0, 'CoreWebView2::Reload');
#ok(0, 'CoreWebView2::RemoveHostObjectFromScript');
#ok(0, 'CoreWebView2::RemoveScriptToExecuteOnDocumentCreated');
#ok(0, 'CoreWebView2::RemoveWebResourceRequestedFilter');
#ok(0, 'CoreWebView2::Resume');
#ok(0, 'CoreWebView2::SetVirtualHostNameToFolderMapping');
#ok(0, 'CoreWebView2::ShowPrintUI');
#ok(0, 'CoreWebView2::Stop');
#ok(0, 'CoreWebView2::TrySuspend');
#ok(0, 'CoreWebView2::add_BasicAuthenticationRequested');
#ok(0, 'CoreWebView2::add_ClientCertificateRequested');
#ok(0, 'CoreWebView2::add_ContainsFullScreenElementChanged');
#ok(0, 'CoreWebView2::add_ContentLoading');
#ok(0, 'CoreWebView2::add_ContextMenuRequested');
#ok(0, 'CoreWebView2::add_DOMContentLoaded');
#ok(0, 'CoreWebView2::add_DocumentTitleChanged');
#ok(0, 'CoreWebView2::add_DownloadStarting');
#ok(0, 'CoreWebView2::add_FaviconChanged');
#ok(0, 'CoreWebView2::add_FrameCreated');
#ok(0, 'CoreWebView2::add_FrameNavigationCompleted');
#ok(0, 'CoreWebView2::add_FrameNavigationStarting');
#ok(0, 'CoreWebView2::add_HistoryChanged');
#ok(0, 'CoreWebView2::add_IsDefaultDownloadDialogOpenChanged');
#ok(0, 'CoreWebView2::add_IsDocumentPlayingAudioChanged');
#ok(0, 'CoreWebView2::add_IsMutedChanged');
#ok(0, 'CoreWebView2::add_LaunchingExternalUriScheme');
#ok(0, 'CoreWebView2::add_NavigationCompleted');
#ok(0, 'CoreWebView2::add_NavigationStarting');
#ok(0, 'CoreWebView2::add_NewWindowRequested');
#ok(0, 'CoreWebView2::add_PermissionRequested');
#ok(0, 'CoreWebView2::add_ProcessFailed');
#ok(0, 'CoreWebView2::add_ScriptDialogOpening');
#ok(0, 'CoreWebView2::add_ServerCertificateErrorDetected');
#ok(0, 'CoreWebView2::add_SourceChanged');
#ok(0, 'CoreWebView2::add_StatusBarTextChanged');
#ok(0, 'CoreWebView2::add_WebMessageReceived');
#ok(0, 'CoreWebView2::add_WebResourceRequested');
#ok(0, 'CoreWebView2::add_WebResourceResponseReceived');
#ok(0, 'CoreWebView2::add_WindowCloseRequested');
#ok(0, 'CoreWebView2::get_BrowserProcessId');
#ok(0, 'CoreWebView2::get_CanGoBack');
#ok(0, 'CoreWebView2::get_CanGoForward');
#ok(0, 'CoreWebView2::get_ContainsFullScreenElement');
#ok(0, 'CoreWebView2::get_CookieManager');
#ok(0, 'CoreWebView2::get_DefaultDownloadDialogCornerAlignment');
#ok(0, 'CoreWebView2::get_DefaultDownloadDialogMargin');
#ok(0, 'CoreWebView2::get_DocumentTitle');
#ok(0, 'CoreWebView2::get_Environment');
#ok(0, 'CoreWebView2::get_FaviconUri');
#ok(0, 'CoreWebView2::get_FrameId')
#ok(0, 'CoreWebView2::get_IsDefaultDownloadDialogOpen');
#ok(0, 'CoreWebView2::get_IsDocumentPlayingAudio');
#ok(0, 'CoreWebView2::get_IsMuted');
#ok(0, 'CoreWebView2::get_IsSuspended');
#ok(0, 'CoreWebView2::get_MemoryUsageTargetLevel');
#ok(0, 'CoreWebView2::get_Profile');
#ok(0, 'CoreWebView2::get_Settings');
#ok(0, 'CoreWebView2::get_Source');
#ok(0, 'CoreWebView2::get_StatusBarText');
#ok(0, 'CoreWebView2::put_DefaultDownloadDialogCornerAlignment');
#ok(0, 'CoreWebView2::put_DefaultDownloadDialogMargin');
#ok(0, 'CoreWebView2::put_IsMuted');
#ok(0, 'CoreWebView2::put_MemoryUsageTargetLevel');
#ok(0, 'CoreWebView2::remove_BasicAuthenticationRequested');
#ok(0, 'CoreWebView2::remove_ClientCertificateRequested');
#ok(0, 'CoreWebView2::remove_ContainsFullScreenElementChanged');
#ok(0, 'CoreWebView2::remove_ContentLoading');
#ok(0, 'CoreWebView2::remove_ContextMenuRequested');
#ok(0, 'CoreWebView2::remove_DOMContentLoaded');
#ok(0, 'CoreWebView2::remove_DocumentTitleChanged');
#ok(0, 'CoreWebView2::remove_DownloadStarting');
#ok(0, 'CoreWebView2::remove_FaviconChanged');
#ok(0, 'CoreWebView2::remove_FrameCreated');
#ok(0, 'CoreWebView2::remove_FrameNavigationCompleted');
#ok(0, 'CoreWebView2::remove_FrameNavigationStarting');
#ok(0, 'CoreWebView2::remove_HistoryChanged');
#ok(0, 'CoreWebView2::remove_IsDefaultDownloadDialogOpenChanged');
#ok(0, 'CoreWebView2::remove_IsDocumentPlayingAudioChanged');
#ok(0, 'CoreWebView2::remove_IsMutedChanged');
#ok(0, 'CoreWebView2::remove_LaunchingExternalUriScheme');
#ok(0, 'CoreWebView2::remove_NavigationCompleted');
#ok(0, 'CoreWebView2::remove_NavigationStarting');
#ok(0, 'CoreWebView2::remove_NewWindowRequested');
#ok(0, 'CoreWebView2::remove_PermissionRequested');
#ok(0, 'CoreWebView2::remove_ProcessFailed');
#ok(0, 'CoreWebView2::remove_ScriptDialogOpening');
#ok(0, 'CoreWebView2::remove_ServerCertificateErrorDetected');
#ok(0, 'CoreWebView2::remove_SourceChanged');
#ok(0, 'CoreWebView2::remove_StatusBarTextChanged');
#ok(0, 'CoreWebView2::remove_WebMessageReceived');
#ok(0, 'CoreWebView2::remove_WebResourceRequested');
#ok(0, 'CoreWebView2::remove_WebResourceResponseReceived');
#ok(0, 'CoreWebView2::remove_WindowCloseRequested');
#
#ok(0, 'AddScriptToExecuteOnDocumentCreatedCompleted event');
#
#ok(0, 'BasicAuthenticationRequested event');
#ok(0, 'BasicAuthenticationRequestedEventArgs::GetDeferral');
#ok(0, 'BasicAuthenticationRequestedEventArgs::get_Cancel');
#ok(0, 'BasicAuthenticationRequestedEventArgs::get_Challenge');
#ok(0, 'BasicAuthenticationRequestedEventArgs::get_Response');
#ok(0, 'BasicAuthenticationRequestedEventArgs::get_Uri');
#ok(0, 'BasicAuthenticationRequestedEventArgs::put_Cancel');
#
#ok(0, 'CallDevToolsProtocolMethodCompleted event');
#
#ok(0, 'CapturePreviewCompleted event');
#
#ok(0, 'ClearServerCertificateErrorActionsCompleted event');
#
#ok(0, 'ClientCertificateRequested event');
#ok(0, 'ClientCertificateRequestedEventArgs::GetDeferral');
#ok(0, 'ClientCertificateRequestedEventArgs::get_AllowedCertificateAuthorities');
#ok(0, 'ClientCertificateRequestedEventArgs::get_Cancel');
#ok(0, 'ClientCertificateRequestedEventArgs::get_Handled');
#ok(0, 'ClientCertificateRequestedEventArgs::get_Host');
#ok(0, 'ClientCertificateRequestedEventArgs::get_IsProxy');
#ok(0, 'ClientCertificateRequestedEventArgs::get_MutuallyTrustedCertificates');
#ok(0, 'ClientCertificateRequestedEventArgs::get_Port');
#ok(0, 'ClientCertificateRequestedEventArgs::get_SelectedCertificate');
#ok(0, 'ClientCertificateRequestedEventArgs::put_Cancel');
#ok(0, 'ClientCertificateRequestedEventArgs::put_Handled');
#ok(0, 'ClientCertificateRequestedEventArgs::put_SelectedCertificate');
#
#ok(0, 'ContainsFullScreenElementChanged event');
#
#ok(0, 'ContentLoading event');
#ok(0, 'ContentLoadingEventArgs::get_IsErrorPage');
#ok(0, 'ContentLoadingEventArgs::get_NavigationId');
#
#ok(0, 'ContextMenuRequested event');
#ok(0, 'ContextMenuRequestedEventArgs::GetDeferral');
#ok(0, 'ContextMenuRequestedEventArgs::get_ContextMenuTarget');
#ok(0, 'ContextMenuRequestedEventArgs::get_Handled');
#ok(0, 'ContextMenuRequestedEventArgs::get_Location');
#ok(0, 'ContextMenuRequestedEventArgs::get_MenuItems');
#ok(0, 'ContextMenuRequestedEventArgs::get_SelectedCommandId');
#ok(0, 'ContextMenuRequestedEventArgs::put_Handled');
#ok(0, 'ContextMenuRequestedEventArgs::put_SelectedCommandId');
#
#ok(0, 'DOMContentLoaded event');
#ok(0, 'DOMContentLoadedEventArgs::get_NavigationId');
#
#ok(0, 'DocumentTitleChanged event');
#
#ok(0, 'DownloadStarting event');
#ok(0, 'DownloadStartingEventArgs::GetDeferral');
#ok(0, 'DownloadStartingEventArgs::get_Cancel');
#ok(0, 'DownloadStartingEventArgs::get_DownloadOperation');
#ok(0, 'DownloadStartingEventArgs::get_Handled');
#ok(0, 'DownloadStartingEventArgs::get_ResultFilePath');
#ok(0, 'DownloadStartingEventArgs::put_Cancel');
#ok(0, 'DownloadStartingEventArgs::put_Handled');
#ok(0, 'DownloadStartingEventArgs::put_ResultFilePath');
#
#ok(0, 'ExecuteScriptCompleted event');
#
#ok(0, 'FaviconChanged event');
#
#ok(0, 'FrameCreated event');
#ok(0, 'FrameCreatedEventArgs::get_Frame');
#
#ok(0, 'GetFaviconCompleted event');
#
#ok(0, 'HistoryChanged event');
#
#ok(0, 'IsDefaultDownloadDialogOpenChanged event');
#
#ok(0, 'IsDocumentPlayingAudioChanged event');
#
#ok(0, 'IsMutedChanged event');
#
#ok(0, 'LaunchingExternalUriScheme event');
#ok(0, 'LaunchingExternalUriSchemeEventArgs::GetDeferral');
#ok(0, 'LaunchingExternalUriSchemeEventArgs::get_Cancel');
#ok(0, 'LaunchingExternalUriSchemeEventArgs::get_InitiatingOrigin');
#ok(0, 'LaunchingExternalUriSchemeEventArgs::get_IsUserInitiated');
#ok(0, 'LaunchingExternalUriSchemeEventArgs::get_Uri');
#ok(0, 'LaunchingExternalUriSchemeEventArgs::put_Cancel');
#
#ok(0, 'NavigationCompleted event');
#ok(0, 'NavigationCompletedEventArgs::get_HttpStatusCode');
#ok(0, 'NavigationCompletedEventArgs::get_IsSuccess');
#ok(0, 'NavigationCompletedEventArgs::get_NavigationId');
#ok(0, 'NavigationCompletedEventArgs::get_WebErrorStatus');
#
#ok(0, 'NavigationStarting event');
#ok(0, 'NavigationStartingEventArgs::get_AdditionalAllowedFrameAncestors');
#ok(0, 'NavigationStartingEventArgs::get_Cancel');
#ok(0, 'NavigationStartingEventArgs::get_IsRedirected');
#ok(0, 'NavigationStartingEventArgs::get_IsUserInitiated');
#ok(0, 'NavigationStartingEventArgs::get_NavigationId');
#ok(0, 'NavigationStartingEventArgs::get_NavigationKind');
#ok(0, 'NavigationStartingEventArgs::get_RequestHeaders');
#ok(0, 'NavigationStartingEventArgs::get_Uri');
#ok(0, 'NavigationStartingEventArgs::put_AdditionalAllowedFrameAncestors');
#ok(0, 'NavigationStartingEventArgs::put_Cancel');
#
#ok(0, 'NewWindowRequested event');
#ok(0, 'NewWindowRequestedEventArgs::GetDeferral');
#ok(0, 'NewWindowRequestedEventArgs::get_Handled');
#ok(0, 'NewWindowRequestedEventArgs::get_IsUserInitiated');
#ok(0, 'NewWindowRequestedEventArgs::get_Name');
#ok(0, 'NewWindowRequestedEventArgs::get_NewWindow');
#ok(0, 'NewWindowRequestedEventArgs::get_OriginalSourceFrameInfo');
#ok(0, 'NewWindowRequestedEventArgs::get_Uri');
#ok(0, 'NewWindowRequestedEventArgs::get_WindowFeatures');
#ok(0, 'NewWindowRequestedEventArgs::put_Handled');
#ok(0, 'NewWindowRequestedEventArgs::put_NewWindow');
#
#ok(0, 'PermissionRequested event');
#ok(0, 'PermissionRequestedEventArgs::GetDeferral');
#ok(0, 'PermissionRequestedEventArgs::get_Handled');
#ok(0, 'PermissionRequestedEventArgs::get_IsUserInitiated');
#ok(0, 'PermissionRequestedEventArgs::get_PermissionKind');
#ok(0, 'PermissionRequestedEventArgs::get_SavesInProfile');
#ok(0, 'PermissionRequestedEventArgs::get_State');
#ok(0, 'PermissionRequestedEventArgs::get_Uri');
#ok(0, 'PermissionRequestedEventArgs::put_Handled');
#ok(0, 'PermissionRequestedEventArgs::put_SavesInProfile');
#ok(0, 'PermissionRequestedEventArgs::put_State');
#
#ok(0, 'PrintCompleted event');
#
#ok(0, 'PrintToPdfCompleted event');
#
#ok(0, 'PrintToPdfStreamCompleted event');
#
#ok(0, 'ProcessFailed event');
#ok(0, 'ProcessFailedEventArgs::get_ExitCode');
#ok(0, 'ProcessFailedEventArgs::get_FrameInfosForFailedProcess');
#ok(0, 'ProcessFailedEventArgs::get_ProcessDescription');
#ok(0, 'ProcessFailedEventArgs::get_ProcessFailedKind');
#ok(0, 'ProcessFailedEventArgs::get_Reason');
#
#ok(0, 'ScriptDialogOpening event');
#ok(0, 'ScriptDialogOpeningEventArgs::Accept');
#ok(0, 'ScriptDialogOpeningEventArgs::GetDeferral');
#ok(0, 'ScriptDialogOpeningEventArgs::get_DefaultText');
#ok(0, 'ScriptDialogOpeningEventArgs::get_Kind');
#ok(0, 'ScriptDialogOpeningEventArgs::get_Message');
#ok(0, 'ScriptDialogOpeningEventArgs::get_ResultText');
#ok(0, 'ScriptDialogOpeningEventArgs::get_Uri');
#ok(0, 'ScriptDialogOpeningEventArgs::put_ResultText');
#
#ok(0, 'ServerCertificateErrorDetected event');
#ok(0, 'ServerCertificateErrorDetectedEventArgs::GetDeferral');
#ok(0, 'ServerCertificateErrorDetectedEventArgs::get_Action');
#ok(0, 'ServerCertificateErrorDetectedEventArgs::get_ErrorStatus');
#ok(0, 'ServerCertificateErrorDetectedEventArgs::get_RequestUri');
#ok(0, 'ServerCertificateErrorDetectedEventArgs::get_ServerCertificate');
#ok(0, 'ServerCertificateErrorDetectedEventArgs::put_Action');
#
#ok(0, 'SourceChanged event');
#ok(0, 'SourceChangedEventArgs::get_IsNewDocument');
#
#ok(0, 'StatusBarTextChanged event');
#
#ok(0, 'TrySuspendCompleted event');
#
#ok(0, 'WebMessageReceived event');
#ok(0, 'WebMessageReceivedEventArgs::TryGetWebMessageAsString');
#ok(0, 'WebMessageReceivedEventArgs::get_AdditionalObjects');
#ok(0, 'WebMessageReceivedEventArgs::get_Source');
#ok(0, 'WebMessageReceivedEventArgs::get_WebMessageAsJson');
#
#ok(0, 'WebResourceRequested event');
#ok(0, 'WebResourceRequestedEventArgs::GetDeferral');
#ok(0, 'WebResourceRequestedEventArgs::get_Request');
#ok(0, 'WebResourceRequestedEventArgs::get_ResourceContext');
#ok(0, 'WebResourceRequestedEventArgs::get_Response');
#ok(0, 'WebResourceRequestedEventArgs::put_Response');
#
#ok(0, 'WebResourceResponseReceived event');
#ok(0, 'WebResourceResponseReceivedEventArgs::get_Request');
#ok(0, 'WebResourceResponseReceivedEventArgs::get_Response');
#
#ok(0, 'WindowCloseRequested event');

