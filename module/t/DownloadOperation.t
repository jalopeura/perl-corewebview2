use strict;
use warnings;

use Test::More tests => 23;
BEGIN { use_ok('CoreWebView2') };

# DownloadOperation
ok(0, 'DownloadOperation::Cancel');
ok(0, 'DownloadOperation::Pause');
ok(0, 'DownloadOperation::Resume');
ok(0, 'DownloadOperation::add_BytesReceivedChanged');
ok(0, 'DownloadOperation::add_EstimatedEndTimeChanged');
ok(0, 'DownloadOperation::add_StateChanged');
ok(0, 'DownloadOperation::get_BytesReceived');
ok(0, 'DownloadOperation::get_CanResume');
ok(0, 'DownloadOperation::get_ContentDisposition');
ok(0, 'DownloadOperation::get_EstimatedEndTime');
ok(0, 'DownloadOperation::get_InterruptReason');
ok(0, 'DownloadOperation::get_MimeType');
ok(0, 'DownloadOperation::get_ResultFilePath');
ok(0, 'DownloadOperation::get_State');
ok(0, 'DownloadOperation::get_TotalBytesToReceive');
ok(0, 'DownloadOperation::get_Uri');
ok(0, 'DownloadOperation::remove_BytesReceivedChanged');
ok(0, 'DownloadOperation::remove_EstimatedEndTimeChanged');
ok(0, 'DownloadOperation::remove_StateChanged');

ok(0, 'BytesReceivedChanged event');

ok(0, 'EstimatedEndTimeChanged event');

ok(0, 'StateChanged event');

