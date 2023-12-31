use strict;
use LWP::UserAgent;
use Archive::Zip qw(:ERROR_CODES :CONSTANTS);

use Data::Dumper;
$Data::Dumper::Sprtkeya = 1;

my $FORCE = 0;

 # should always showthe latest version
my $NUGET_USER_SITE = 'https://www.nuget.org/packages/Microsoft.Web.WebView2';

# https://www.nuget.org/api/v2/package/{packageID}/{packageVersion}
my $NUGET_DOWNLOAD = 'https://www.nuget.org/api/v2/package/Microsoft.Web.WebView2/%s';

my $DOWNLOAD_FOLDER = 'nuget';
my $EXTRACT_FOLDER = 'module/WebView';
my $FILENAME = 'microsoft.web.webview2.%s.nupkg';

my $ZIP_PREFIX = 'build/native';
my @ZIP_FOLDERS = qw(include x64 x86);
my @ZIP_FILES = qw(LICENSE.txt Microsoft.Web.WebView2.nuspec);

#
#
#

$| = 1;

mkdir $DOWNLOAD_FOLDER;

if ($ARGV[0] eq '-f') {
	$FORCE = 1;
}

my $version = $ARGV[0];

my $agent = LWP::UserAgent->new();

# if no version was passed, find the latest version
if ($version) {
	print "Version '$version' passed in\n";
}
else {
	print "Checking website for current version...";

	my $response = $agent->get($NUGET_USER_SITE);
	if ($response->code() != 200) {
		die "\n" . $response->message();
	}
	($version) = $response->content()=~m{<meta property="og:title" content="Microsoft.Web.WebView2 ([^"]+)" />};

	print "got '$version'\n";
}

# we don't have the file yet, download it
my $filename = sprintf("$DOWNLOAD_FOLDER/$FILENAME", $version);
my $do_extract = 0;
if (-e $filename) {
	print "File '$filename' already exists\n";
	$do_extract = $FORCE;
}
else {
	print "Downloading version '$version'...";

	my $url = sprintf($NUGET_DOWNLOAD, $version);
	my $response = $agent->get($url);
	if ($response->code() != 200) {
		die "\n" . $response->message();
	}

	open OUT, ">$filename" or die "Unable to create file '$filename': $!";
	binmode OUT;
	print OUT $response->content();
	close OUT;

	$do_extract = 1;

	print "done\n";
}

if ($do_extract) {
	my $zip = Archive::Zip->new();
	if ($zip->read($filename) != AZ_OK ) {
		die "Unable to unzip '$filename'";
	}

	for my $folder (@ZIP_FOLDERS) {
		my $regex = "$ZIP_PREFIX/$folder/.*";
		my @members = $zip->membersMatching($regex);
		for my $member (@members) {
			next if $member->isDirectory();
			(my $outfile = $member->fileName)=~s{$ZIP_PREFIX}{$EXTRACT_FOLDER};
			$member->extractToFileNamed($outfile);
		}
	}

	for my $file (@ZIP_FILES) {
		my @members = $zip->membersMatching($file);
		$members[0]->extractToFileNamed("$EXTRACT_FOLDER/$file");
	}
}

#$ZIP_PREFIX
#membersMatching( $regex )
#extractToFileNamed( { name => $fileName } )

# https://www.nuget.org/packages/Microsoft.Web.WebView2

# https://www.nuget.org/api/v2/package/{packageID}/{packageVersion}

# https://www.nuget.org/api/v2/package/Microsoft.Web.WebView2/1.0.1661.34

# Microsoft.Web.WebView2 --version 1.0.1661.34

__END__$VAR1 = bless( {
$VAR1 = bless( {
                 '_previous' => bless( {
                                         '_content' => '<html><head><title>Object moved</title></head><body>

<h2>Object moved to <a href="https://globalcdn.nuget.org/packages/microsoft.web.webview2.1.0.1722.45.nupkg">here</a>.</h2>

</body></html>

',
                                         '_msg' => 'Found',
                                         '_request' => bless( {
                                                                '_content' => '',
                                                                '_uri' => bless( do{\(my $o = 'https://www.nuget.org/api/v2/package/Microsoft.Web.WebView2/1.0.1722.45')}, 'URI::https' ),
                                                                '_uri_canonical' => $VAR1->{'_previous'}{'_request'}{'_uri'},
                                                                '_headers' => bless( {
                                                                                       '::std_case' => {
                                                                                                         'if-ssl-cert-subject' => 'If-SSL-Cert-Subject'
                                                                                                       },
                                                                                       'user-agent' => 'libwww-perl/6.42'
                                                                                     }, 'HTTP::Headers' ),
                                                                '_method' => 'GET'
                                                              }, 'HTTP::Request' ),
                                         '_headers' => bless( {
                                                                'request-context' => 'appId=cid-v1:338f6804-b1a9-4fe3-bba7-c93064e7ae7b',
                                                                'client-date' => 'Sat, 15 Apr 2023 02:03:19 GMT',
                                                                'client-peer' => '13.66.39.44:443',
                                                                'client-ssl-cert-issuer' => '/C=US/O=Microsoft Corporation/CN=Microsoft Azure TLS Issuing CA 01',
                                                                'x-content-type-options' => 'nosniff',
                                                                'x-xss-protection' => '1; mode=block',
                                                                'client-ssl-cipher' => 'ECDHE-RSA-AES256-GCM-SHA384',
                                                                'content-security-policy' => 'frame-ancestors \'none\'',
                                                                'date' => 'Sat, 15 Apr 2023 02:03:18 GMT',
                                                                'strict-transport-security' => 'max-age=31536000; includeSubDomains',
                                                                'title' => 'Object moved',
                                                                'client-transfer-encoding' => [
                                                                                                'chunked'
                                                                                              ],
                                                                'access-control-expose-headers' => 'Request-Context',
                                                                'client-ssl-cert-subject' => '/C=US/ST=WA/L=Redmond/O=Microsoft Corporation/CN=*.nuget.org',
                                                                'location' => 'https://globalcdn.nuget.org/packages/microsoft.web.webview2.1.0.1722.45.nupkg',
                                                                'client-response-num' => 1,
                                                                'content-type' => 'text/html; charset=utf-8',
                                                                'client-ssl-socket-class' => 'IO::Socket::SSL',
                                                                'x-frame-options' => 'DENY',
                                                                'set-cookie' => [
                                                                                  'ARRAffinity=746146f9b8a568138e0f8e8d19178ca6868557dc4149a92ed430f901c8a2c233;Path=/;HttpOnly;Secure;Domain=www.nuget.org',
                                                                                  'ARRAffinitySameSite=746146f9b8a568138e0f8e8d19178ca6868557dc4149a92ed430f901c8a2c233;Path=/;HttpOnly;SameSite=None;Secure;Domain=www.nuget.org'
                                                                                ],
                                                                '::std_case' => {
                                                                                  'content-base' => 'Content-Base',
                                                                                  'x-content-type-options' => 'X-Content-Type-Options',
                                                                                  'client-ssl-cert-issuer' => 'Client-SSL-Cert-Issuer',
                                                                                  'x-xss-protection' => 'X-XSS-Protection',
                                                                                  'client-ssl-cipher' => 'Client-SSL-Cipher',
                                                                                  'content-security-policy' => 'Content-Security-Policy',
                                                                                  'request-context' => 'Request-Context',
                                                                                  'client-date' => 'Client-Date',
                                                                                  'client-peer' => 'Client-Peer',
                                                                                  'base' => 'Base',
                                                                                  'strict-transport-security' => 'Strict-Transport-Security',
                                                                                  'title' => 'Title',
                                                                                  'access-control-expose-headers' => 'Access-Control-Expose-Headers',
                                                                                  'client-ssl-cert-subject' => 'Client-SSL-Cert-Subject',
                                                                                  'client-transfer-encoding' => 'Client-Transfer-Encoding',
                                                                                  'set-cookie' => 'Set-Cookie',
                                                                                  'x-frame-options' => 'X-Frame-Options',
                                                                                  'client-response-num' => 'Client-Response-Num',
                                                                                  'client-ssl-socket-class' => 'Client-SSL-Socket-Class'
                                                                                },
                                                                'cache-control' => 'private'
                                                              }, 'HTTP::Headers' ),
                                         '_rc' => '302',
                                         '_protocol' => 'HTTP/1.1'
                                       }, 'HTTP::Response' ),
                 '_headers' => bless( {
                                        'x-ms-meta-da7b2905_0f3c_4262_921c_b1593d1336f1_esrp_requestid' => '5fa7fcac-ebe2-4169-899e-f556b684a62f',
                                        'client-ssl-cipher' => 'ECDHE-RSA-AES256-GCM-SHA384',
                                        'x-content-type-options' => 'nosniff',
                                        'x-cache' => 'HIT',
                                        'client-peer' => '152.199.4.184:443',
                                        'client-date' => 'Sat, 15 Apr 2023 02:03:20 GMT',
                                        'etag' => '0x8DB3C4E837772C1',
                                        'cache-control' => 'max-age=86400',
                                        'connection' => 'close',
                                        'x-ms-lease-status' => 'unlocked',
                                        'expires' => 'Sun, 16 Apr 2023 02:03:19 GMT',
                                        'client-ssl-socket-class' => 'IO::Socket::SSL',
                                        'x-cdn-rewrite' => 'Root path in dist',
                                        'content-md5' => 'w/PYHrEKtNl1WDBB0RS6GQ==',
                                        'server' => 'ECAcc (sec/968D)',
                                        'strict-transport-security' => 'max-age=31536000; includeSubDomains',
                                        'access-control-allow-origin' => '*',
                                        'date' => 'Sat, 15 Apr 2023 02:03:19 GMT',
                                        'x-ms-meta-sha512' => 'RUpNZiFF2dcPZIz858th14ElA8xCEZxpT6iRsd3p/7+JeQ02Mbr0MbDva6plWZbxLbHzpG9D4vxTeuftDWWwQA==',
                                        'x-ms-request-id' => '05667c61-201e-0048-33f4-6ea0c0000000',
                                        'client-ssl-cert-issuer' => '/C=US/O=Microsoft Corporation/CN=Microsoft Azure TLS Issuing CA 01',
                                        'age' => '31637',
                                        'x-ms-version' => '2009-09-19',
                                        '::std_case' => {
                                                          'client-ssl-cert-issuer' => 'Client-SSL-Cert-Issuer',
                                                          'x-content-type-options' => 'X-Content-Type-Options',
                                                          'access-control-allow-origin' => 'Access-Control-Allow-Origin',
                                                          'x-ms-meta-da7b2905_0f3c_4262_921c_b1593d1336f1_esrp_requestid' => 'X-Ms-Meta-Da7b2905_0f3c_4262_921c_b1593d1336f1_ESRP_RequestId',
                                                          'client-ssl-cipher' => 'Client-SSL-Cipher',
                                                          'x-ms-meta-sha512' => 'X-Ms-Meta-SHA512',
                                                          'x-ms-request-id' => 'X-Ms-Request-Id',
                                                          'client-peer' => 'Client-Peer',
                                                          'x-cache' => 'X-Cache',
                                                          'client-date' => 'Client-Date',
                                                          'x-ms-version' => 'X-Ms-Version',
                                                          'x-ms-lease-status' => 'X-Ms-Lease-Status',
                                                          'x-ms-blob-type' => 'X-Ms-Blob-Type',
                                                          'access-control-expose-headers' => 'Access-Control-Expose-Headers',
                                                          'client-ssl-cert-subject' => 'Client-SSL-Cert-Subject',
                                                          'strict-transport-security' => 'Strict-Transport-Security',
                                                          'client-ssl-socket-class' => 'Client-SSL-Socket-Class',
                                                          'client-response-num' => 'Client-Response-Num',
                                                          'x-cdn-rewrite' => 'X-CDN-Rewrite'
                                                        },
                                        'accept-ranges' => 'bytes',
                                        'client-response-num' => 1,
                                        'content-type' => 'application/octet-stream',
                                        'last-modified' => 'Thu, 13 Apr 2023 18:40:11 GMT',
                                        'x-ms-blob-type' => 'BlockBlob',
                                        'access-control-expose-headers' => 'x-ms-request-id,Server,x-ms-version,x-ms-meta-da7b2905_0f3c_4262_921c_b1593d1336f1_ESRP_RequestId,x-ms-meta-SHA512,Content-Type,Cache-Control,Last-Modified,ETag,Content-MD5,x-ms-lease-status,x-ms-blob-type,Content-Length,Date,Transfer-Encoding',
                                        'client-ssl-cert-subject' => '/C=US/ST=WA/L=Redmond/O=Microsoft Corporation/CN=*.nuget.org',
                                        'content-length' => '3100834'
                                      }, 'HTTP::Headers' ),
                 '_rc' => '200',
                 '_protocol' => 'HTTP/1.1',
                 '_msg' => 'OK',
                 '_request' => bless( {
                                        '_uri_canonical' => bless( do{\(my $o = 'https://globalcdn.nuget.org/packages/microsoft.web.webview2.1.0.1722.45.nupkg')}, 'URI::https' ),
                                        '_headers' => bless( {
                                                               'user-agent' => 'libwww-perl/6.42',
                                                               '::std_case' => {
                                                                                 'if-ssl-cert-subject' => 'If-SSL-Cert-Subject'
                                                                               }
                                                             }, 'HTTP::Headers' ),
                                        '_content' => '',
                                        '_uri' => $VAR1->{'_request'}{'_uri_canonical'},
                                        '_protocol' => undef,
                                        '_method' => 'GET'
                                      }, 'HTTP::Request' )
               }, 'HTTP::Response' );