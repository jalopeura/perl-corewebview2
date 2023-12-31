#
# !!! This file is used to generate code stubs and compare them against existing files, for the purpose of adding new
# !!! functionality from new versions of WebView2.h; it is part of the development process, not part of the build process
#
use strict;

# TODO: make sure environment options will actually work with multiple interfaces; if not, I may need to cast it some other way
#       may possibly need to cast to void, then cast to the right type; not sure
#       let's undo the changes to Handler.h and do the additional vtables manually
#       may even need to have multiple interfaces that do not inherit from each other
#       possibly it shouldn't matter; if cast to interface5 and called as that, it should still work, then casting the right way in the macro should fix it
#       may need a new macro for Envrionment Options to make the new versions work

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

use constant FORCE_OVERWRITE   => 0;
#use constant FORCE_OVERWRITE => 'YES REALLY POD AND TESTS TOO'; # special (undocumented) value
use constant SUPPRESS_DIFF     => 0;

my $UPDATE_MANUAL_FILES = grep { $_ eq 'update' } @ARGV;

chdir('module');
mkdir('interfaces');
mkdir('lib/CoreWebView2'); # lib should already exist with .pm and .pod files
mkdir('t');

map {
	$FileChecker::preexisting{$_} = 1;
} ('MANIFEST', glob('interfaces/*'), glob('lib/CoreWebView2/*.pod'), glob('t/*'));

#my @h_files = qw(string/defs.h);
#my $target_folder = 'stream';
#my @h_files = qw(D:/Strawberry/c/x86_64-w64-mingw32/include/oaidl.h);
#my $target_folder = 'oaidl';
my @h_files = qw(WebView/include/WebView2.h);
my $target_folder = 'interfaces';

my %perl_names = (
	HRESULT => 'UV',
	HCURSOR => 'UV',
	HWND    => 'UV',
	DWORD   => 'UV',
	UINT    => 'UV',
	UINT32  => 'UV',
	UINT64  => 'UV',
	int     => 'IV',
	INT     => 'IV',
	INT32   => 'IV',
	INT64   => 'IV',
	double  => 'NV',
	LPWSTR  => 'WCHAR',
	PCWSTR  => 'WCHAR',
	LPCWSTR => 'WCHAR',
);
sub perl_name_from_c_name {
	my ($c_name) = @_;
	$c_name=~s/\*+$//;

	if ($perl_names{$c_name}) {
		return $perl_names{$c_name};
	}

	(my $perl_name = $c_name)=~s/^ICoreWebView2/CoreWebView2/;
	$perl_name=~s/_\d+$//;
	unless ($perl_name eq 'CoreWebView2') {
		$perl_name=~s/\d+$// if $perl_name=~/CoreWebView2/; # don't do this for enums (all caps)
		$perl_name=~s/^COREWEBVIEW2_//i;
		$perl_name=~s/^CoreWebView2/CoreWebView2::/i;
	}

	return $perl_names{$c_name} = $perl_name;
}

my $INTERFACE_NAME = 'ICoreWebView2';
my $MODULE_NAME = perl_name_from_c_name($INTERFACE_NAME);
my $MSDOCS = "https://docs.microsoft.com/en-us/microsoft-edge/webview2/reference/win32";
#my $CUSTOM_OBJECTS = qr/ICoreWebView2(CustomSchemeRegistration|EnvironmentOptions)\d*/;
my %CUSTOM_OBJECTS = (
	'ICoreWebView2CustomSchemeRegistration' => 'CustomSchemeRegistration',
	'ICoreWebView2EnvironmentOptions6'      => 'EnvironmentOptions',
);

# no auto-generated object
my $SKIP = (
	 # 'real' structs, not interfaces; handled by typemap
	COREWEBVIEW2_PHYSICAL_KEY_STATUS => 1,
	COREWEBVIEW2_COLOR               => 1,
);

my @EXTRA_CONSTANTS = (
	[ qw(HRESULT S_OK S_FALSE E_ABORT E_ACCESSDENIED E_FAIL E_HANDLE E_INVALIDARG E_NOINTERFACE E_NOTIMPL E_OUTOFMEMORY E_POINTER E_UNEXPECTED E_PENDING) ],
	[ qw(DISPATCH DISPATCH_METHOD DISPATCH_PROPERTYGET DISPATCH_PROPERTYPUT DISPATCH_PROPERTYPUTREF) ],
);

my %doctypes = (
	BOOL    => 'boolean',
	BYTE    => 'integer', # maybe string instead?
	IV      => 'integer',
	NV      => 'number',
	UV      => 'unsigned integer',
	WCHAR   => 'string',
	IStream => 'stream',

	COLOR => "color value",
	POINT => "POINT (arrayref C<[x, y]>)",
	RECT  => "RECT (hashref C<{ left, right, top, bottom }>)",
	PHYSICAL_KEY_STATUS => "key status hashref",
	VARIANT => 'VARIANT',

	HANDLE      => 'TYPE NOT YET SUPPORTED',
	IDataObject => 'TYPE NOT YET SUPPORTED',
	IUnknown    => 'TYPE NOT YET SUPPORTED',
);
map { $doctypes{$_} = "L<$_|CoreWebView2::constants/$_> constant" } qw(
	HRESULT
	BOUNDS_MODE BROWSER_PROCESS_EXIT_KIND BROWSING_DATA_KINDS
	CAPTURE_PREVIEW_IMAGE_FORMAT CLIENT_CERTIFICATE_KIND
	CONTEXT_MENU_ITEM_KIND CONTEXT_MENU_TARGET_KIND COOKIE_SAME_SITE_KIND
	DEFAULT_DOWNLOAD_DIALOG_CORNER_ALIGNMENT DOWNLOAD_INTERRUPT_REASON DOWNLOAD_STATE
	FAVICON_IMAGE_FORMAT FRAME_KIND
	HOST_RESOURCE_ACCESS_KIND
	KEY_EVENT_KIND
	MEMORY_USAGE_TARGET_LEVEL MOUSE_EVENT_KIND MOUSE_EVENT_VIRTUAL_KEYS MOVE_FOCUS_REASON
	NAVIGATION_KIND
	PDF_TOOLBAR_ITEMS PERMISSION_KIND PERMISSION_STATE POINTER_EVENT_KIND
	PRINT_COLLATION PRINT_COLOR_MODE PRINT_DIALOG_KIND PRINT_DUPLEX PRINT_MEDIA_SIZE PRINT_ORIENTATION PRINT_STATUS
	PREFERRED_COLOR_SCHEME
	PROCESS_FAILED_KIND PROCESS_FAILED_REASON PROCESS_KIND
	SCRIPT_DIALOG_KIND SERVER_CERTIFICATE_ERROR_ACTION SHARED_BUFFER_ACCESS
	TRACKING_PREVENTION_LEVEL
	WEB_ERROR_STATUS WEB_RESOURCE_CONTEXT
);

sub doctype {
	my ($ctype, $perltype, $article) = @_;

	my $doctype
		= $perltype=~/::.+?Handler$/                   ? "event handler object"
		: $perltype=~/::/ || $perltype eq $MODULE_NAME ? "L<$perltype> object"
		:                                                ($doctypes{$ctype} || $doctypes{$perltype});

	$doctype or warn "No doctype found for $ctype / $perltype";

	if (! $article) {
		return $doctype;
	}

	my $first = $doctype=~/L<(.)/ ? $1 : substr($doctype,0,1);
	my $article = $first=~/^[aeiou]/i ? 'an ' : 'a ';
	return $article . $doctype;
}

sub customize {
	my ($packages) = @_;

	my ($globals) = $packages->{globals};

	my ($get_version) = grep { $_->{cname} eq 'GetAvailableCoreWebView2BrowserVersionString' } @{ $globals->{members} };
	$get_version->{params}[1]{out} = 1;
	$get_version->{params}[1]{ctype}=~s/\*$//;
	delete $get_version->{retval}{out};

	my ($compare_versions) = grep { $_->{cname} eq 'CompareBrowserVersions' } @{ $globals->{members} };
	$compare_versions->{params}[2]{out} = 1;
	$compare_versions->{params}[2]{ctype}=~s/\*$//;
	delete $compare_versions->{retval}{out};

	my @mismatch;
	for my $value (values %$packages) {
		next unless $value->{members};
		push @mismatch, grep { $_->{type} ne 'constant' && $_->{cname} ne $_->{perlname} } @{ $value->{members} };
	}
	map { $_->{perlname} = $_->{cname} } @mismatch;

	# fix event names
	for my $value (values %$packages) {
		next unless $value->{members};
		for my $member (@{ $value->{members} }) {
			next unless ($member->{type} eq 'event' && $member->{cname} eq 'Invoke');
			(my $event_name = $value->{basename})=~s/(Event)?Handler$//;
			$member->{perlname} = $event_name;
		}
	}
}

#
# don't edit below here
#

my (@packages, %packages, %stats);

my $code;
for my $h_file (@h_files) {
	open IN, $h_file or die $!;
	binmode(IN);
	{
		local $/ = undef;
		$code .= <IN>;
	}
	close IN;
}

#
# IIDs
#

my %iid = $code=~m/const\s+IID\s+IID_(\S+)\s+=\s+([^\r\n;]+)/msg;
for my $value (values %iid) {
	$value=~s/,0x([\da-f]{2})\b/$1/ig;
	$value=~s/0x//ig;
	$value=~s/[{}]//g;
	$value=~s/,/-/g;
	$value=~s/-([\da-fA-F]{4})([^-])/-$1-$2/;
	$value = '{' . uc($value) . '}';
}

#
# enums (=> constant)
#

my @constant_members;

if (@EXTRA_CONSTANTS) {
	for my $extra (@EXTRA_CONSTANTS) {
		my $type = shift @$extra;
		push @constant_members, map {{
			type     => 'constant',
			cname    => $_,
			perlname => $_,
			group    => $type,
		}} @$extra;
	}
}

while ($code=~s/typedef[^\n]*\s*enum\s+(\S+)\s+\{(.+?)\}\s*\1//ms) {
	my $type = perl_name_from_c_name($1);
	my $body = $2;

	my @names = $body=~/(\S+)\s*=/g;
	for my $name (@names) {
		push @constant_members, {
			type     => 'constant',
			cname    => $name,
			perlname => perl_name_from_c_name($name),
			group    => $type,
		};
	}
}

push @packages, $packages{constants} = {
	basename => 'constants',
	cname    => '',
	perlname => '',
	members  => \@constant_members,
};

#
# globals (=> package functions)
#

my @global_members;

while ($code=~s/STDAPI (.+?)\((.+?)\);//) {
	my $name = $1;
	my $params = $2;

	$params=~s/(\s+)(\*+)/$2$1/g;
	my @params = map {
		my ($type, $pname) = split /\s+/, $_;
		{
			name     => $pname,
			ctype    => $type,
			perltype => perl_name_from_c_name($type),
		};
	} split /\s*,\s*/, $params;

	push @global_members, {
		type     => 'global',
		cname    => $name,
		perlname => perl_name_from_c_name($name),
		params   => \@params,
		retval   => {
			ctype    => 'HRESULT',
			perltype => perl_name_from_c_name('HRESULT'),
			out      => 1,
			error    => 1,
		}
	};
}

push @packages, $packages{globals} = {
	basename => 'globals',
	cname    => '',
	perlname => '',
	members  => \@global_members,
};

while ($code=~s/typedef struct (\S*)Vtbl\s+\{(.+?)\}\s+\1Vtbl;//ms) {
	my $type = $1;
	my $body = $2;

	# drop the associated forward declaration, and interface definitions
	$code=~s/typedef interface $type $type;//;
	$code=~s/MIDL_INTERFACE.+?$type : public .+?\{.+?\};//ms;
	$code=~s/interface $type\b.+?\{.+?\};//ms;

	my $perlname = perl_name_from_c_name($type);

	# does this perlname already exist? (i.e., is this a later version of a particular interface?)
	my $package = $packages{$perlname};

	if ($package) {
		$package->{cname} = $type;
	}
	else {
		my @f = split /::/, $perlname;
		push @packages, $package = {
			basename => $f[-1],
			cname    => $type,
			perlname => $perlname,
			members  => [],
		};
	}

	$packages{$perlname} = $package;
	my $members = $package->{members};

	my $otype = $type=~/Handler$/ ? 'event' : 'method';

	my @methods = $body=~m{([^\n]+)\s*\(\s*STDMETHODCALLTYPE \*(\S+)\s*\)\((.*?)\);}msg;
	while (@methods) {
		my $rettype = shift @methods;
		my $name = shift @methods;
		my $params = shift @methods;

		# we don't need to generate Perl interfaces for these
		next if $name=~/^(QueryInterface|AddRef|Release)$/;

		# was this function already found in an earlier version of the interface?
		if (my ($m) = grep { $_->{cname} eq $name } @$members) {
			# use the most recent version of the interface that has this function
			$m->{iface} = $package->{cname},
			# and do not reprocess
			next;
		}

		my $has_outparams;
		my @params = map {
			my %p;
			if (s{/\*(.+?)\*/}{}) {
				my $comment = $1;
				while ($comment=~s/\[(.+?)\]//) {
					$p{$1} = 1;
				}
			}
			s/\s+/ /g;
			s/^ //;
			s/ $//;
			s/ (\*+)/$1 /g;
			s/^const\s+//g;

			my ($ptype, $pname) = split /\s+/, $_;
			$p{name}     = $pname;
			$p{ctype}    = $ptype;
			$p{perltype} = perl_name_from_c_name($ptype);

			if ($p{out}) {
				$p{ctype}=~s/\*$//;
				$has_outparams++;
			}

			\%p;
		} split /,/, $params;
#if ($name eq 'get_Buffer') {
#	warn $params;
#	warn Dumper \@params;
#}

		while ($rettype=~s/\[(.+?)\]//) {
			my $p = $1;
			next if $p=~/^(prop(put|get)?)$/;
			warn $p;
		}
		$rettype=~s{/\*\s*\*/}{};
		$rettype=~s/^\s+//;
		$rettype=~s/\s+$//;

		my $retval = {
			ctype    => $rettype,
			perltype => perl_name_from_c_name($rettype),
		};
		unless ($has_outparams) {
			$retval->{out} = 1;
		}
		if ($rettype eq 'HRESULT') {
			$retval->{error} = 1;
		}

		my $member = {
			iface    => $package->{cname},
			type     => $otype,
			cobject  => $type,
			cname    => $name,
			perlname => perl_name_from_c_name($name),
			params   => \@params,
			retval   => $retval,
		};

		push @$members, $member;
	}
}

customize(\%packages);

#
# generation
#

my (@h_inc, @xs_inc, @constants, @globals, %eventmap, %argmap, %tests);
my @iface = ([], [], []);
for my $package (@packages) {
	my $cname    = $package->{cname};
	my $perlname = $package->{perlname};
	my $basename = $package->{basename};
	my $members  = $package->{members};

	# handler (h/cpp)
	if ($cname=~/Handler|IString/) {
		my $H = FileChecker->open("$target_folder/$basename.h", FORCE_OVERWRITE);
		my $CPP = FileChecker->open("$target_folder/$basename.cpp", FORCE_OVERWRITE);
		push @h_inc, "$target_folder/$basename.h";

		$stats{cpp} ||=  [];
		push @{ $stats{cpp} }, "$target_folder/$basename.cpp";

		# the below should work as long as there's only one version of each handler interface
		# (since they all simply define a single method, Invoke, that differs only by its arguments, we should be good)
		my $subclass = $basename . 1;

		print $H <<TOP;
/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */

#pragma once
#include "HandlerBase.h"

class $basename : public HandlerBase {
public:
	$basename(SV* perl_object);
	virtual ~$basename();

	$basename(const $basename&) = delete;
	$basename($basename&&) = delete;
	$basename& operator=(const $basename&) = delete;
	$basename& operator=($basename&&) = delete;

	// IUnknown and utility methods inherited from InterfaceWrapper

	// $cname
	WRAP_INTERFACE($subclass, $cname, $basename)
TOP

		print $CPP <<TOP;
/*
 * Auto-generated file.
 * DO NOT EDIT
 * Edit generate.pl in the main folder to make changes here
 */
#include "$basename.h"

#ifdef DEBUG
#define DEBUG_TAG "$basename"
#endif // DEBUG

// IUnknown and utility methods inherited from InterfaceWrapper

/*
 * $cname
 */

IUNKNOWN_DEFS($subclass, $cname, $basename)

TOP

		my (@vtable, @defs);
		for my $member (@$members) {
			my $m_cname    = $member->{cname};
			my $m_perlname = $member->{perlname};
			my $retval     = $member->{retval};
			my $params     = $member->{params};

			# in params need types
			my $i_in_params = join(', ', map { "$_->{ctype} $_->{name}" } @$params);
			my $i_out_params = join(', ', map { $_->{name} } @$params);
			
			(my $c_in_params = $i_in_params)=~s/^.*This,? ?//;
			(my $c_out_params = $i_out_params)=~s/^.*This,? ?//;

			my @perl_in_params = grep { ! $_->{out} } @$params;
			my @perl_out_params = grep { $_->{out} } (@$params, $retval);

			$stats{events} ||=  [];
			push @{ $stats{events} }, join('::', $basename, $m_cname);

			print $H <<METHOD;
	$retval->{ctype} $m_cname($c_in_params);
METHOD

			print $CPP <<METHOD;
static $retval->{ctype} STDMETHODCALLTYPE $basename\_$m_cname($i_in_params) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("$basename\_$m_cname (%p)", This);
}
#endif // DEBUG
	return static_cast<$basename\::$subclass*>(This)->Wrapper()->$m_cname($c_out_params);
}

METHOD

			push @vtable, "$basename\_$m_cname";

			my $param_count = scalar @$params;
			my $def = <<DEF;
$retval->{ctype} $basename\::$m_cname($c_in_params) {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("$m_cname in %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
DEF

			my (@stack, $objcount);
			if ($param_count > 1) { # param 0 is the object itself
				for my $i (1..$#perl_in_params) {
					my $ctype    = $perl_in_params[$i]{ctype};
					my $perltype = $perl_in_params[$i]{perltype};
					my $name     = $perl_in_params[$i]{name};
					# ICoreWebView2 object
					if ($perltype eq $MODULE_NAME || $perltype=~/::/) {
						$def .= <<OBJECT;
	SV* $name\_sv = sv_newmortal();
	create_perl_object($name\_sv, $name, "$perltype");
OBJECT
						push @stack, "XPUSHs($name\_sv);";
						$objcount++;
					}
					# IStream
					elsif ($ctype=~/IStream/) {
						$def .= <<OBJECT;
	SV* $name\_sv = stream_to_scalar($name);
/*
	SV* $name\_sv = sv_newmortal();
WARN(\"About to call create_perl_object (%p)\", $name\_sv);
	create_perl_object($name\_sv, $name, "CoreWebView2::Helper::Stream");
WARN(\"Back from create_perl_object\");
*/
	sv_2mortal($name\_sv);
OBJECT
#						push @stack, "XPUSHs(stream_to_glob($name));";
						push @stack, "XPUSHs($name\_sv);";
						$objcount++;
					}
					# IUnknown* (=> NULL)
					elsif ($ctype=~/IUnknown/) {
						push @stack, "// $name will be NULL";
					
					}
					# HRESULT (=> NULL)
					elsif ($ctype=~/HRESULT/) {
						$def .= <<RESULT;
	SV* $name\_sv;
	CHECK_ERROR($name, $name\_sv);
RESULT
						push @stack, "XPUSHs($name\_sv);";
					
					}
					# unsigned integer value
					elsif ($perltype=~/^([UI]V)$/ || $ctype=~/^(COREWEBVIEW2_(PRINT_STATUS))$/) {
						#push @stack, "XPUSHs(newSVuv(($1)$name));";
						push @stack, "mXPUSHu(($1)$name);";
					}
					# wide string
					elsif ($perltype eq 'WCHAR') {
						push @stack, "XPUSHs(wchar_to_scalar($name));";
					}
					# boolean
					elsif ($perltype eq 'BOOL') {
						push @stack, "XPUSHs($name ? &PL_sv_yes : &PL_sv_no);";
					}
					# undef
					elsif ($perltype eq 'undef') {
						push @stack, "XPUSHs($name &PL_undef);";
					}
					else {
						die "Type $ctype not supported: $perltype $name in $m_perlname in $perlname";
					}
				}
			}

			if ($objcount) {
				$def .= "\n";
			}

			$def .= <<STACK;
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG

	dSP;
	ENTER;
	SAVETMPS;
	//EXTEND(SP, $param_count); 
	PUSHMARK(SP);

	XPUSHs(m_perl_object);
STACK

			for my $item (@stack) {
				$def .= "\t$item\n";
			}

			my $call_flags = 'G_DISCARD';
			$def .= <<CALL;

	PUTBACK;

	call_method("$m_perlname", $call_flags);
	SPAGAIN;

CALL

			# for the moment, we don't care about returning values, but we will

			my $retval = 'S_OK';
			$def .= <<END;
	FREETMPS;
	LEAVE;

	return $retval;
}
END
			push @defs, $def
		}

		print $H "};\n";

		my $vtbl_entries = join(",\n\t", @vtable);
		print $CPP <<CHUNK;
static $cname\Vtbl $basename\Vtbl = {
	IUNKNOWN_INIT($subclass)
	$vtbl_entries,
};
CHUNK

		for my $def (@defs) {
			print $CPP "\n", $def;
		}

		print $CPP <<CHUNK;

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

//$basename\::$basename(SV* perl_object) : HandlerBase(perl_object), $cname\{&$basename\Vtbl} {}
$basename\::$basename(SV* perl_object) :\n\tHandlerBase(perl_object, "$basename") {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	AddInterface(IID_$cname, ($cname*)(new $subclass(this, &$basename\Vtbl)));

	// we don't want to have to keep track of this object,
	// so as soon as someone else grabs a reference, we let it go
	Mortalize();
}

$basename\::~$basename() {
#ifdef DEBUG
if (debugme(DEBUG_TAG)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
	WARN("Deleting subclass $subclass containing interface $cname");
}
#endif // DEBUG
	$subclass* subclass = static_cast<$subclass*>(($cname*)GetInterface(IID_$cname));
	delete subclass;
}
CHUNK
	}
	# regular object (xs, pod)
	else {
		my $XS = FileChecker->open("$target_folder/$basename.xs", FORCE_OVERWRITE);
		push @xs_inc, "$target_folder/$basename.xs";

		$stats{xs} ||= [];
		push @{ $stats{xs} }, "$target_folder/$basename.xs";

		my $PACKAGE_NAME = $perlname || $MODULE_NAME;

		print $XS <<INIT;
#
# Auto-generated file.
# DO NOT EDIT
# Edit generate.pl in the main folder to make changes here
#

MODULE = $MODULE_NAME	PACKAGE = $PACKAGE_NAME

PROTOTYPES: DISABLE

INIT

		my $constants_group;
		for my $member (@$members) {
			next if ($member->{type} eq 'property');

			my $m_cname    = $member->{cname};
			my $m_perlname = $member->{perlname};

			# constants
			if ($member->{type} eq 'constant') {
				if ($member->{group} ne $constants_group) {
					$constants_group = $member->{group};
					push @constants, [ $constants_group ];
					print $XS <<GROUP;
#
# $constants_group
#

GROUP

					$stats{tags} ||=  [];
					push @{ $stats{tags} }, join('::', $basename, $constants_group);
				}
				push @{ $constants[-1] }, $m_perlname;

				print $XS <<CONSTANT;
SV*
$m_perlname()
	CODE:
		RETVAL = newSVuv((UV)$m_cname);
		dualize(RETVAL, "$m_cname");
	OUTPUT:
		RETVAL

CONSTANT

				$stats{constants} ||=  [];
				push @{ $stats{constants} }, join('::', $basename, $m_perlname);

				next;
			}

			# of we get here, we're an object method or a global function
			if ($member->{type} eq 'global') {
				push @globals, $m_perlname;
			}

			my $retval     = $member->{retval};
			my $params     = $member->{params};

			my @xs_in_params = grep { ! $_->{out} && $_->{name} ne 'This' } @$params;
			my @xs_out_params = grep { $_->{out} } (@$params, $retval);

			# special array processing
			if ($package->{cname}=~/^ICoreWebView2EnvironmentOptions\d*$/ && $member->{cname}=~/^[GS]etCustomSchemeRegistrations$/
				|| $package->{cname}=~/^ICoreWebView2CustomSchemeRegistration\d*$/ && $member->{cname}=~/^[GS]etAllowedOrigins$/
				|| $package->{cname}=~/^ICoreWebView2Frame\d*$/ && $member->{cname}=~/^AddHostObjectToScriptWithOrigins$/) {
				if ($member->{cname}=~/^Get/) {
					my ($i) = grep { $xs_out_params[$_]{name}=~/count/i } 0..$#xs_out_params;
					my ($count) = splice(@xs_out_params, $i, 1);
					$xs_out_params[$i]->{count} = $count;
				}
				else {
					my ($i) = grep { $xs_in_params[$_]{name}=~/count/i } 0..$#xs_in_params;
					my ($count) = splice(@xs_in_params, $i, 1);
					$xs_in_params[$i]->{count} = $count;
				}
			}

			my $xs_rettype = 'void';
			local $xs_out_params[0]{name} = $xs_out_params[0]{name};
			if ($#xs_out_params == 0 && ! $xs_out_params[0]->{count}) {
				$xs_rettype = $xs_out_params[0]{ctype};
				$xs_out_params[0]{name} = '&RETVAL';
			}

			my $xs_method_name = $member->{iface} ? join('::', $member->{iface}, $m_perlname) : $m_perlname;
			my $xs_in_params = join(', ', map { $_->{name} } @xs_in_params);
			$xs_in_params=~s/^This,? ?//;

			# special array processing
			if (grep { $_->{count} } @xs_in_params) {
				$xs_in_params=~s/[^,\s]+$/first, .../
			}

			# special cases (custom backing objects):
#			$xs_method_name=~s/^$CUSTOM_OBJECTS\b/$1/;

#			my @check_envopts;

			my $c_retval = 'RETVAL';
			my $extra_init;
			if (not $retval->{out}) {
				$c_retval = 'result';
				$extra_init = "$retval->{ctype} $c_retval";
			}

			my $c_call_params = join(', ', map { $_->{name} } @$params);

			if ($member->{iface}) {
				$m_cname = "(($member->{iface}*)THIS)->lpVtbl->$m_cname";
				$c_call_params=~s/This/THIS/;
			}

			print $XS <<METHOD;
$xs_rettype
$xs_method_name($xs_in_params)
METHOD

			my $key = $member->{type} . 's'; # method or global
			$stats{$key} ||=  [];
			push @{ $stats{$key} }, join('::', $basename, $member->{perlname});

			my @extra_cleanup;
			if ($xs_in_params) {
				print $XS "\tINPUT:\n";
				for my $param (@xs_in_params) {
					if ($param->{count}) {
						print $XS "\t\tSV* first;\n";
						# don't put arrays in INPUT
						next;
					}
					my $ctype = $param->{ctype};
					# special case:
#					if ($ctype=~s/^$CUSTOM_OBJECTS\b/$1/) {
#						push @check_envopts, $param->{name};
#					}
					print $XS "\t\t$ctype $param->{name};\n";

					if ($ctype eq 'VARIANT*') {
						# DO NOT call VariantClear(), since it will call Release() on the interface
						#push @extra_cleanup, "VariantClear($param->{name});";
					}
				}
			}

			print $XS "\tINIT:\n";
			if (my ($array) = grep { $_->{count} } @xs_in_params) {
				print $XS "\t\tbool is_aref;\n";
				print $XS "\t\t$array->{count}{ctype} $array->{count}{name};\n";
				print $XS "\t\t$array->{ctype} $array->{name};\n";
			}
			if ($#xs_out_params > 0 || $xs_out_params[0]->{count}) {
				for my $param (@xs_out_params) {
					if ($param->{count}) {
						print $XS "\t\tSV* $param->{name}_item_sv;\n";
						print $XS "\t\t$param->{count}{ctype} $param->{count}{name};\n";
						$c_call_params=~s/\b($param->{count}{name})\b/&$1/;
					}
					print $XS "\t\t$param->{ctype} $param->{name};\n";
					print $XS "\t\tSV* $param->{name}_sv;\n" unless $param->{count};
					$c_call_params=~s/\b($param->{name})\b/&$1/;
				}
				if ($xs_out_params[0]->{count} && $xs_out_params[0]->{ctype}=~/^ICoreWebView2(.+?)\*\*$/) {
					print $XS "\t\tbool was_known;\n";
				}
			}
			if ($extra_init) {
				print $XS "\t\t$extra_init;\n";
			}
			print $XS "\t\tSV* error_sv;\n";

			if (@xs_in_params && $xs_in_params[-1]->{count}) {
				(my $itemtype = $xs_in_params[-1]{ctype})=~s/\*$//;
				perl_to_c_array($XS, $xs_in_params[-1]{name}, $xs_in_params[-1]{count}{name}, "$m_cname($c_call_params)", $itemtype, \@extra_cleanup);
			}
			elsif (@xs_out_params && $xs_out_params[-1]->{count}) {
				(my $itemtype = $xs_out_params[-1]{ctype})=~s/\*$//;
				c_to_perl_array($XS, $xs_out_params[-1]{name}, $xs_out_params[-1]{count}{name}, "$m_cname($c_call_params)", $itemtype);
			}
			# non-array code/output block
			else { 
				my $CODE = $#xs_out_params > 0 || $xs_out_params[0]->{count} ? 'PPCODE' : 'CODE';
				print $XS <<CODE;
	$CODE:
		$c_retval = $m_cname($c_call_params);
CODE

				for my $cleanup (@extra_cleanup) {
					print $XS <<CODE;
		$cleanup
CODE
				}

print $XS <<CODE;
		CHECK_ERROR($c_retval, error_sv);
CODE

#				for my $name (@check_envopts) {
#					print $XS <<ENVOPTS;
#		// if this object existed before this function was called, we called AddRef() to increase the refcount
#		// if we created it, we already "own" the original reference
#		// we release it now, and if nobody else has any references, it will be self-delete
#		$name->Release();
#ENVOPTS
#				}

				if ($#xs_out_params == 0) {
					print $XS <<OUTPUT
	OUTPUT:
		RETVAL

OUTPUT
				}
				elsif ($#xs_out_params > 0) {
					for my $param (@xs_out_params) {
						if ($package->{cname} eq 'ICoreWebView2EnvironmentOptions5' && $member->{cname}=~/^[GS]etCustomSchemeRegistrations$/
							|| $package->{cname} eq 'ICoreWebView2CustomSchemeRegistration' && $member->{cname}=~/^[GS]etAllowedOrigins$/) {
							print $XS "\t\t$param->{name} : DO NOT OVERWRITE THE CUSTOM CODE WHEN GENERATING\n";
						}
#warn "$param->{ctype} $param->{name}";
						elsif ($param->{ctype}=~/^(LPWSTR)$/) {
							print $XS "\t\t$param->{name}_sv = wchar_to_scalar($param->{name});\n";
							print $XS "\t\tCoTaskMemFree($param->{name});\n";
						}
						else {
							die "Unknown type $param->{ctype} in $m_perlname in $basename";
						}
					}

					my $outcount = scalar @xs_out_params;
					print $XS "\n\t\tEXTEND(SP, $outcount);\n";
					for my $param (@xs_out_params) {
						print $XS "\t\tPUSHs(sv_2mortal($param->{name}_sv));\n";
					}

					print $XS "\n";
				}
				else {
					print $XS "\n";
				}
			} # non-array code/output block
		}

		unless ($package->{basename}=~/constants|globals/) {

			my $ctype = $package->{cname};
#			(my $ctype = $package->{cname})=~s/^$CUSTOM_OBJECTS\b/$1/;
			print $XS <<END;
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
END
		}

		next if $package->{basename}=~/Handler/;

		my $name = $package->{perlname} || $MODULE_NAME . ' ' . ucfirst $package->{basename};
		my $division_type
			= $package->{basename} eq 'constants' ? 'GROUPS'
			: $package->{basename} eq 'globals'   ? 'FUNCTIONS'
			:                                       'METHODS';

		my $POD = FileChecker->open("lib/$MODULE_NAME/$basename.pod", FORCE_OVERWRITE);

		$stats{pod} ||=  [];
		push @{ $stats{pod} }, "lib/$MODULE_NAME/$basename.pod";

		print $POD <<TOP;
=pod

=head1 NAME

$name

=head1 VERSION

0.001.000

=head1 SYNOPSIS

TBD

=head1 DESCRIPTION

TBD

=head1 $division_type

TOP

		if (my @constants = grep { $_->{type} eq 'constant' } @$members) {
			my $group;
			for my $constant (sort { $a->{group} cmp $b->{group} or $a->{perlname} cmp $b->{perlname} } @constants) {
				if ($constant->{group} ne $group) {
					if ($group) {
						print $POD "=back\n\n";
					}
					$group = $constant->{group};

					print $POD <<GROUP
=head2 $group

=over

GROUP
				}

				print $POD "=item * $constant->{perlname}\n\n";
			}

			print $POD "=cut\n";
		}

		my @globals = grep { $_->{type} eq 'global' } @$members;
		my @methods = grep { $_->{type} eq 'method' } @$members;

		next unless @globals || @methods;

		my (%properties, %events);
		for my $member (sort { $a->{perlname} cmp $b->{perlname} } @globals, @methods) {
			$tests{ $package->{basename} }{methods}{ $member->{perlname} } = 1;

			if ($member->{cname}=~/^(get|put|add|remove)_(.+)$/) {
				my ($accessor, $name) = ($1, $2);
				if ($accessor=~/get|put/) {
					$properties{$name}{$accessor} = $member;
				}
				else {
					my $ename = $eventmap{ $package->{basename} }{$name};
					$ename or do {
						my ($handler) = grep { $_->{perltype}=~/Handler$/ } @{ $member->{params} };
						($ename = $handler->{perltype})=~s/EventHandler$//;
						$ename=~s/^.+?:://;
						$eventmap{ $package->{basename} }{$name} = $ename;
					};
					$tests{ $package->{basename} }{events}{$ename} = 1;
					$events{$ename}{$accessor} = $member->{params}[1];
					$events{$ename}{trigger} ||= [];
					push @{ $events{$ename}{trigger} }, $member->{cname};
				}
				next;
			}

			my $anchor = lc($member->{cname});
			my $page = $member->{type} eq 'global' ? 'webview2-idl' : lc($member->{cobject});
			my $link = "$MSDOCS/$page#$anchor";

			print $POD "=head2 $member->{perlname}\n\n";

			my @params = @{ $member->{params} };
			my $has_object;
			if ($params[0]{name} eq 'This') {
				shift @params;
				$has_object = 1;
			}
			my @in_params = grep { ! $_->{out} } @params;
			my @out_params = grep { $_->{out} } @params;

			local $member->{retval}{name} = $member->{retval}{name};
			unless (@out_params) {
				$member->{retval}{name} = 'result';
				@out_params = ($member->{retval});
			}

			my $call = join(', ', map { '$' . $_->{name} } @out_params);
			if ($#out_params) {
				$call = "($call)";
			}

			$call .= ' = ';
			if ($has_object) {
				$call .= '$object->';
			}

			$call .=
				$member->{cname} . '(' . join(', ', map { '$' . $_->{name} } @in_params) . ')';

			print $POD "    $call;\n\n";

			if (@in_params) {
				print $POD "Takes\n\n=over\n\n";
				print $POD join('', map { "=item * \$$_->{name}: " . doctype($_->{ctype}, $_->{perltype}) . "\n\n" } @in_params);
				print $POD "=back\n\n";
			}

			if (scalar @out_params > 1) {
				print $POD "Returns\n\n=over\n\n";
				print $POD join('', map { "=item * \$$_->{name}: " . doctype($_->{ctype}, $_->{perltype}) . "\n\n" } @out_params);
				print $POD "=back\n\n";
			}
			elsif (@out_params) {
				print $POD "Returns " . doctype($out_params[0]{ctype}, $out_params[0]{perltype}, 1) . "\n\n";
			}

			if (my ($handler) = grep { $_->{perltype}=~/Handler/ } @params) {
				(my $event = $handler->{perltype})=~s/^.+?::(.+Completed)Handler$/$1/;
				if ($eventmap{ $package->{basename} }{$event}) {
					$eventmap{ $package->{basename} }{$event};
				}
				$tests{ $package->{basename} }{events}{$event} = 1;
				print $POD "Triggers L</$event>\n\n";
				$events{$event}{trigger} ||= [];
				push @{ $events{$event}{trigger} }, $member->{cname};
				$events{$event}{completed} = $handler;
			}

			print $POD "See L<$link>.\n\n";
		}

		if (%properties) {
			print $POD "=head1 PROPERTIES\n\n";

			for my $pname (sort keys %properties) {
				my $property = $properties{$pname};
				my $getter = $property->{get}{cname};
				my $putter = $property->{put}{cname};

				my $gpage = lc $property->{get}{cobject};
				my @links = ("$MSDOCS/$gpage#" . lc $getter);
				if ($putter) {
					my $spage = lc $property->{put}{cobject};
					push @links, "$MSDOCS/$spage#" . lc $putter;
				}

				my $param = $property->{get}{params}[1];
				my $vname = $param->{name};
				my $vtype = ucfirst doctype($param->{ctype}, $param->{perltype}, 1);
				my $links = join(', ', map { "L<$_>" } @links);

				print $POD <<PROPTOP;
=head2 $pname

    \$$vname = \$object->$getter();
PROPTOP

				$stats{properties} ||=  [];
				push @{ $stats{properties} }, join('::', $basename, $pname);

				if ($putter) {
					print $POD "    \$object->$putter(\$$vname);\n";
				}
				print $POD <<PROPEND;

$vtype.

See $links.

PROPEND
			}
		}

		if (%events) {
#print "\n", $package->{basename}," ";
			print $POD "=head1 EVENTS\n\n";

			for my $ename (sort keys %events) {
				my $event = $events{$ename};
#print " $ename";

				print $POD "=head2 $ename\n\n";

				if ($event->{trigger}) {
					for my $method (sort @{ $event->{trigger} }) {
						my $call = $method;
						if ($method=~/add_/) {
							$call = "\$token = \$object->$call(\$handler);";
						}
						elsif ($method=~/remove_/) {
							$call = "\$result = \$object->$call(\$token);";
						}
						else {
							$call = "\$result = \$object->$call(...);";
						}
						print $POD "    $call\n";
					}
					print $POD "\n";
				}

				my $hparam = $event->{add} || $event->{completed};
				(my $hkey = $hparam->{perltype});
				my ($invoker) = grep { $_->{cname} eq 'Invoke' } @{ $packages{$hkey}{members} };
				my @params = @{ $invoker->{params} };
				shift @params;
				if ($params[-1]{ctype}=~/IUnknown/) {
					(my $key = $invoker->{params}[0]{perltype})=~s/EventHandler$//;
					$key=~s/^.+?:://;
					$argmap{$key} = 'IUnknown';

					pop @params;
				}
				my $params = join(', ', map { "\$$_->{name}" } @params);

				print $POD <<EVENTSUB;
    # in handler class
    sub $ename {
        my (\$self, $params) = \@_;

        # handle the event here
    }

EVENTSUB

				# if this is a completed event, emit link to the trigger method
				if ($event->{completed}) {
					my $tlinks = join(', ', map { "L</$_>" } @{ $event->{trigger} });
					print $POD "See $tlinks.\n\n";
				}

				print $POD "Passes\n\n=over\n\n";
				for my $param (@params) {
					if ($param->{perltype}=~/EventArgs/) {
						(my $key = $invoker->{params}[0]{perltype})=~s/^.+?:://;
						$key=~s/EventHandler$//;
						($argmap{$key} = $param->{perltype})=~s/^.+?:://;
					}

					print $POD "=item * \$$param->{name}: " . doctype($param->{ctype}, $param->{perltype}) . "\n\n";
				}
				print $POD "=back\n\n";
			}
		}

		print $POD "=cut\n";
	}
}

$tests{IUnknown}{methods} = {};

my %seen_args;
for my $package (sort keys %tests) {
	next if $package=~/EventArgs$/;

	# gather up all the tests
	my $prefix = $package eq 'globals' ? 'global function ' : $package . '::';
	my @tests = map { $prefix . $_ } sort keys %{ $tests{$package}{methods} };

	map {
		push @tests, undef, $_ . ' event';
		my $argskey = $argmap{$_};
		if ($tests{$argskey}) {
			$seen_args{$argskey}++;
			my $args = $tests{$argskey};
			my $argpfx = $argskey eq 'globals' ? 'global ' : $argskey . '::';
			push @tests, map { $argpfx . $_  } sort keys %{ $args->{methods} };
		}
		elsif (not /(Completed|Deleted)$/) {
			warn "No args found for $_ in $package";
		}
	} sort keys %{ $tests{$package}{events} };

	delete $tests{$package};

	my $T = FileChecker->open("t/$package.t", FORCE_OVERWRITE);

	$stats{t} ||=  [];
	push @{ $stats{t} }, "t/$package.t";

	my $count = scalar (grep { /\S/ } @tests) + 1; # one extra for use_ok()
	print $T <<TOP;
use strict;
use warnings;

use Test::More tests => $count;
BEGIN { use_ok('CoreWebView2') };

TOP

	print $T "# $package\n";
	print $T map {
		$_ ? "ok(0, '$_');\n" : "\n";
	} @tests;
	print $T "\n";
}

#map { delete $tests{$_} } keys %seen_args;
#print Dumper \%tests;

my $manifest;
open IN, 'MANIFEST' or die $!;
while (<IN>) {
	last if /^# generated files/;
	$manifest .= $_;
}
close IN;

my @generated = FileChecker->written();
$manifest=~s/\s*$/\n\n# generated files\n/;

my $MANIFEST = FileChecker->open('MANIFEST', FORCE_OVERWRITE);
print $MANIFEST $manifest;

for my $file (sort @generated) {
	print $MANIFEST $file,"\n";
}

close $MANIFEST;

#
# version check
#

my $rxc = qr{<version>(.+?)</version>};
open C, 'WebView/Microsoft.Web.WebView2.nuspec' or die;
my ($c_version) = map { /$rxc/ } grep { /$rxc/} <C>;
close C;

open PM, 'lib/CoreWebView2.pm' or die;
my @pm = <PM>;
close PM;

my $rxp = qr/our \$VERSION = "v(.+?)";/;
my ($pm_version) = map { /$rxp/ } grep { /$rxp/} @pm;

# do we have a separate POD file?
if (-e 'lib/CoreWebView2.pod') {
	open POD, 'lib/CoreWebView2.pod' or die;
	@pm = <POD>;
	close POD;
}
my $pod = join('', @pm);

#my $rxd = qr/=head1 VERSION\s+(\S+)/;
my $rxd = qr/=head1 VERSION\s+(\S+)/;
my ($pod_version) = $pod=~/$rxd/;

# =head1 VERSION
# 
# 1.0.2210.55.1

if (substr($pm_version, 0, length($c_version)) ne $c_version) {
	print "Version mismatch: $c_version <=> $pm_version\n\n";

	my @pchunks = split /\./, $pm_version;
	my @cchunks = split /\./, $c_version;
	my $extra = join('.', @pchunks[ scalar(@cchunks) .. $#pchunks ]);

	print qq{our \$VERSION = "v$c_version.$extra";\n\n};

	# at version changes, we force this even if the user didn't ask for it
	$UPDATE_MANUAL_FILES = 1;
}

if (substr($pod_version, 0, length($c_version)) ne $c_version) {
	print "Version mismatch: $c_version <=> $pod_version\n\n";

	my @pchunks = split /\./, $pod_version;
	my @cchunks = split /\./, $c_version;
	my $extra = join('.', @pchunks[ scalar(@cchunks) .. $#pchunks ]);

	print <<POD;
=head1 VERSION

$c_version.$extra

POD

	# at version changes, we force this even if the user didn't ask for it
	$UPDATE_MANUAL_FILES = 1;
}

if ($UPDATE_MANUAL_FILES) {
	print "For CoreWebView2.pm:\n\n"; # exporter stuff here

	my @ok = 'qw(' . join(' ', sort @globals) . ')';
	my @tags = ('all => \@EXPORT_OK');
	for my $c (sort { $a->[0] cmp $b->[0] } @constants) {
		my ($type, @names) = @$c;

		my $varname = lc $type;
		print "my \@$varname\_group = qw(" . join(' ', @$c) . ");\n";

		push @ok, '@' . $varname . '_group';
		push @tags, "$type => \\\@$varname\_group";
	}
	print "\n";

	print "our \@EXPORT_OK = (" . join(', ', @ok) . ");\n\n";

	print "our \%EXPORT_TAGS = (\n\t" . join(",\n\t", @tags) . "\n);\n\n";

	print "\n";

	my @interfaces;
	for my $name (keys %iid) {
		my ($base, $seq)
			= $name=~/^(.+?)_(\d+)/ ? ($1, $2)
			: $name=~/^(.+?)(\d+)$/ ? ($1, $2)
			:                         ($name, 1);
		push @interfaces, [ $iid{$name}, $name, $base, $seq ];
	}
	@interfaces = sort { $a->[2] cmp $b->[2] || $a->[3] <=> $b->[3] } @interfaces;
	print "our \%IID = (\n";
	for my $item (@interfaces) {
		print "\t'$item->[0]' => '$item->[1]',\n";
	}
	print ");\n\n";

	print "For CoreWebView2.xs:\n\n";

	print join("\n", map { qq{#include "$_"} } sort @h_inc), "\n\n";

	@xs_inc = (
		(sort grep { $_ eq lc $_ } @xs_inc),
		(sort grep { $_ ne lc $_ } @xs_inc),
	);
	print join("\n", map { "INCLUDE: $_" } @xs_inc), "\n\n";

	print "For typemap:\n\n"; # exporter stuff here

	for my $i (0..$#iface) {
		my $type
			= $i == 0 ? 'T_IFACE'
			: $i == 1 ? 'T_TIED_IFACE'
			:           'T_TIED_HASH';

		my $len = 0;
		map { if (length($_) > $len) { $len = length($_) } } @{ $iface[$i] };


		for my $name (sort @{ $iface[$i] }) {
			my @versions = ($name);
			if ($name=~s/(\d+)$//) {
				@versions = ($name);
				my $last = $1;
				for my $n (2..$last) {
					push @versions, $name . $n;
				}
			}

			for my $version (@versions) {
				$version=~s/_$//;
				my $line = sprintf("%-${len}s\t%s", $version . '*', $type);
				$line=~s/ {4}/\t/g;
				$line=~s/ +\tT_/\t\tT_/;
				if (length($name) % 4 != 0) {
					$line=~s/$version\*/$version*\t/;
				}
				print $line, "\n";
			}
		}
		print "\n"
	}

	print "For CoreWebView2.pod:\n\n";
	for my $file (@xs_inc) {
		next if $file=~/EventArgs/;
		my ($base) = $file=~m{^interfaces/(.+?).xs$};
		print "=item L<$base|CoreWebView2::$base>\n\n";
	}
	print "\n\n";

#warn Dumper \@interfaces;

	print "For Widget.pm:\n\n";

	my %events;
	for my $package (@packages) {
		next unless $package->{members};
		my (@pkg_events, %seen);
		for my $member (@{ $package->{members} }) {
			next unless $member->{params};
			next if $member->{type}=~/constant|event/;
			for my $param (@{ $member->{params} }) {
				my $event = $param->{ctype};
				next unless $event=~s/Handler\*$//;
				$event=~s/^ICoreWebView2//;
				next if $seen{$event};
				$seen{$event} = 1;

				$event=~s/Event$//;
				push @pkg_events, $event;
			}
		}
		next unless @pkg_events;

		$events{ $package->{basename} } = [ sort @pkg_events ];
	}

	my @event_keys = (
		(sort grep { $_ eq lc $_ } keys %events),
		(sort grep { $_ ne lc $_ } keys %events),
	);

	print "my \%EVENTS = (\n";
	for my $package (@event_keys) {
		print "\t'$package' => [qw(",
			join(' ', sort @{ $events{$package} }),
			")],\n";
	}
	print ");\nsub events { \%EVENTS }\n\n";

	print "my \@params = (\n\tqw(environment uri),\n\tmap { 'on' . \$_ } (\n";
	for my $key (@event_keys) {
		print "\t\t\@{ \$EVENTS{$key} },\n";
	}
	print "\t)\n);\nsub params { \@params }\n\n";

#	my ($environment_package) = grep { $_->{basename} eq 'Environment' }  @packages;
#	print "my \%environment_methods = map { (\$_ => 1) } qw(\n";
#	for my $method (sort { $a->{perlname} cmp $b->{perlname} } @{ $environment_package->{members} }) {
#		next unless $method->{type} eq 'method';
#		next if $method->{perlname}=~/^(add|remove)_/;
#		print "\t$method->{perlname}\n";
#	}
#	print ");\n\n";
#
#	my ($controller_package) = grep { $_->{basename} eq 'Controller' }  @packages;
#	print "my \%controller_methods = map { (\$_ => 1) } qw(\n";
#	for my $method (sort { $a->{perlname} cmp $b->{perlname} } @{ $controller_package->{members} }) {
#		next unless $method->{type} eq 'method';
#		next if $method->{perlname}=~/^(add|remove)_/;
#		print "\t$method->{perlname}\n";
#	}
#	print ");\n\n";
}
print "\n\n";

if (%FileChecker::preexisting) {
	for my $file (sort keys %FileChecker::preexisting) {
		if ($FileChecker::preexisting{$file} == 1) {
			print "$file: pre-existing but not generated\n";
		}
		elsif ($FileChecker::preexisting{$file} == -1) {
			print "$file: newly created\n";
		}
		else {
			print "$file: unrecognized indicator $FileChecker::preexisting{$file}\n";
		}
	}
	print "\n\n";
}

print "DONE\n\n";

$stats{helper_pm}  = [ 'lib/CoreWebView2.pm', glob('lib/CoreWebView2/Helper/*.pm') ];
$stats{helper_xs}  = [ 'CoreWebView2.xs', glob('helpers/*.xs') ];
$stats{helper_cpp} = [ glob('helpers/*.cpp') ];

#print Dumper [ glob('helpers/*.cpp') ];

$stats{packages} = [ grep { $_!~/\b(constants|globals)\b/ } @{ $stats{xs} } ];
my @counts = map { scalar @{ $stats{$_} } } qw(xs cpp pod t packages tags constants globals methods properties events helper_pm helper_xs helper_cpp);
printf <<STATS, @counts;
Generated
  %3d XS files
  %3d CPP files (with accompanying headers)
  %3d POD file stubs
  %3d test stubs

Implementing
  %3d packages
  %3d export tags
  %3d constants
  %3d global functions
  %3d methods
  %3d properties (accessors included in method count)
  %3d events/callbacks

Manually maintained
  %3d PM files
  %3d XS files
  %3d CPP files (with headers)
STATS

#
# helpers
#

# to turn C returns into Perl returns in an XS sub
sub c_to_perl_array {
	my ($fh, $cname, $count, $ccall, $itemtype) = @_;

	my $convert_item = "// NO CONVERSION METHOD FOUND";
	my $free_array = "// NO free() CODE FOUND";
	if ($itemtype eq 'LPWSTR') {
		$convert_item = "$cname\_item_sv = wchar_to_scalar($cname\[i]);";

		$free_array = <<FREE;
		// since these strings have been copied to Perl SV, we now have to free them
		for (int i = 0; i < $count; i++) {
			CoTaskMemFree($cname\[i]);
		}
		CoTaskMemFree($cname);
FREE
		$free_array=~s/^\s*//;
		$free_array=~s/\s*$//;
	}
	elsif ($itemtype eq 'ICoreWebView2CustomSchemeRegistration*') {
		$convert_item = <<CONVERT;
				void* wrapper = static_cast<CustomSchemeRegistration::CustomSchemeRegistration1*>($cname\[i])->Wrapper();
				$cname\_item_sv = sv_newmortal();
				create_perl_object($cname\_item_sv, wrapper, "CoreWebView2::CustomSchemeRegistration");
CONVERT
		$convert_item=~s/^\s*//;
		$convert_item=~s/\s*$//;

		$free_array = <<FREE;
		// we called AddRef() on the objects in the array, but that reference will be taken care of when the owning Perl object goes out of scope
		// so we don't need to call Release() here
		CoTaskMemFree($cname);
FREE
		$free_array=~s/^\s*//;
		$free_array=~s/\s*$//;
	}

	print $fh <<CODE;
	PPCODE:
		result = $ccall;
		CHECK_ERROR(result, error_sv);

		U8 gimme = GIMME_V;
		// if caller wants a list, then we push the items one by one onto the stack
		if (gimme == G_LIST) {
			EXTEND(SP, $count);
			for (UINT32 i = 0; i < $count; i++) {
				$convert_item
				PUSHs(sv_2mortal($cname\_item_sv));
			}
		}
		// otherwise, we return a single aref
		else {
			EXTEND(SP, 1);
			AV* temp_array = newAV();
			for (UINT32 i = 0; i < $count; i++) {
				$convert_item
				av_push(temp_array, $cname\_item_sv);
			}
			PUSHs(sv_2mortal(newRV_noinc((SV*)temp_array)));
		}

		$free_array

CODE
}

# to turn Perl returns into C returns in an XS sub
sub perl_to_c_array {
	my ($fh, $cname, $count, $ccall, $itemtype, $extra_cleanup) = @_;

	my @convert_item = ("// NO CONVERSION METHOD FOUND") x 2;
	my $free_array = "// NO free() CODE FOUND";
	if ($itemtype eq 'LPCWSTR') {
		$convert_item[0] = <<CONVERT;
std::wstring str = scalar_to_wstring(*item);
				$cname\[i] = str.c_str();
CONVERT
		$convert_item[0]=~s/^\s*//;
		$convert_item[0]=~s/\s*$//;

		$convert_item[1] = <<CONVERT;
std::wstring str = scalar_to_wstring(ST(i));
				$cname\[i] = str.c_str();
CONVERT
		$convert_item[1]=~s/^\s*//;
		$convert_item[1]=~s/\s*$//;

		$free_array = <<FREE;
// since these strings have been copied by the underlying object, we now have to free them
		for (int i = 0; i < $count; i++) {
			free((void*)$cname\[i]);
		}
		free($cname);
FREE
		$free_array=~s/^\s*//;
		$free_array=~s/\s*$//;
	}
	elsif ($itemtype eq 'ICoreWebView2CustomSchemeRegistration*') {
		$convert_item[0] = "$cname\[i] = (ICoreWebView2CustomSchemeRegistration*)get_custom_registration(*item, IID_ICoreWebView2CustomSchemeRegistration);";
		$convert_item[1] = "$cname\[i] = (ICoreWebView2CustomSchemeRegistration*)get_custom_registration(ST(i), IID_ICoreWebView2CustomSchemeRegistration);";

		$free_array = <<FREE;
// caller gets ownership of 1 reference to each object returned from get_custom_registration()
		// and EnvironmentOptions calls AddRef() on each one with SetCustomSchemeRegistrations()
		// so we need to call Release() now that we're done with it
		for (int i = 0; i < $count; i++) {
			$cname\[i]->lpVtbl->Release($cname\[i]);
		}
		free($cname);
FREE
		$free_array=~s/^\s*//;
		$free_array=~s/\s*$//;
	}

	print $fh <<CODE;
	CODE:
		// if there is only one item AND it is an aref, then we are processing an aref
		is_aref = (items == 1 && SvTYPE(first) == SVt_PVAV);
		$count = is_aref ? av_top_index((AV*)SvRV(first)) + 1 : items;
		$cname = ($itemtype*)malloc(sizeof($itemtype) * $count);

		if (is_aref) {
			SV** item;
			AV* temp_array = (AV*)SvRV(first);
			for (int i = 0; i < $count; i++) {
				item = av_fetch(temp_array, i, 0);
				$convert_item[0]
			}
		}
		// otherwise, we are processing a list
		else {
			for (int i = 0; i < $count; i++) {
				$convert_item[1]
			}
		}

		RETVAL = $ccall;
CODE

	for my $cleanup (@$extra_cleanup) {
		print $fh <<CODE;
		$cleanup
CODE
				}

	print $fh <<CODE;
		CHECK_ERROR(RETVAL, error_sv);

		$free_array
	OUTPUT:
		RETVAL

CODE
}

package FileChecker;
use Algorithm::Diff qw(diff);
our $AUTOLOAD;

our (@written, %preexisting);

sub open {
	my ($class, $filename, $force) = @_;

	if (not delete $preexisting{$filename}) {
		$preexisting{$filename} = -1;
	}

	push @written, $filename;

	# undocumented option: certain value of $force will overwrite even POD and tests
	if ($force && $filename=~/\.(pod|t)$/) {
		$force = 0 unless $force eq 'YES REALLY POD AND TESTS TOO';
	}

	my $fh;
	if ($force || not -e $filename) {
		open $fh, '>', $filename or die "$filename: $!";
		binmode($fh);
	}
	else {
		$fh = local *FH;
		tie *$fh, $class, $filename;
	}

	return $fh;
}

sub written {
	my ($self_or_class, $drop) = @_;

	my @ret = @written;

	if ($drop) {
		@written = ();
	}

	return @ret;
}

sub TIEHANDLE {
	my ($class, $filename) = @_;
	return bless {
		filename => $filename,
		buffer   => '',
	}, $class;
}

sub PRINT {
	my ($self, @strings) = @_;
	$self->{buffer} .= join($,, @strings, $\);
}

sub CLOSE {
	my ($self) = @_;
	$self->{closed} = 1;
# here diff against existing file
	unless (main::SUPPRESS_DIFF) {
		$self->mydiff();
	}
}

sub DESTROY {
	my ($self) = @_;
	unless ($self->{closed}) {
		$self->CLOSE();
	}
}

sub AUTOLOAD {
	die join("\n", $AUTOLOAD, @_);
}

my (@f1, $File_Length_Difference); # need to make these visible to the Hunk code
sub mydiff {
	my ($self) = @_;

	local $/ = undef;
	open IN, $self->{filename} or die "$self->{filename}: $!";
	binmode(IN);
	my $data1 = <IN>;
	close IN;
	$data1=~s/\s*$//;

	(my $data2 = $self->{buffer})=~s/\s*$//;

#	if ($self->{filename}=~/\.pod$/) {
#		# drop all regular paragraphs so we are just comparing command paragraphs and verbatim paragraphs
## TODO: also compare links to MS docs
##See L<https://docs.microsoft.com/en-us/microsoft-edge/webview2/reference/win32/icorewebview2acceleratorkeypressedeventargs#get_keyeventkind>.
#		for ($data1, $data2) {
#			# preserve links to microsoft docs
#			s{^(See L<https://docs.microsoft.com)}{===$1}msg;
#
#			s/\r//g;
#			s/^[^=\s].+?\n\n//msg;
#
#			# restore links to microsoft docs
#			s{^===See}{See}msg;
#		}
#	}

	if ($self->{filename}=~/\.t$/) {
		# grab just the test names from both sides
		for ($data1, $data2) {
#			my @tests = m/ok\((?:["'])(.+?)\1/g;
			my @tests = m/ok\(.+?, (["'])(.+?)\1\)/g;
			$_ = join("\n", map { "#ok(0, '$_')" } grep { /[^"']/ } sort @tests) . "\n";
		}
	}

#if ($self->{filename}=~/WebResourceResponseViewGetContentCompletedHandler/) {
#	warn $data2;
#}
#if ($data1 ne $data2) {
#	warn $self->{filename};
#}

	@f1 = split /\n/, $data1;
	my @f2 = split /\n/, $data2;

	my $diffs = diff(\@f1, \@f2);
	return unless @$diffs;

	if ($self->{filename}=~/\.pod$/ and $self->{filename}!~/xProfile/) {
		my @newdiffs;
		for my $hunk (@$diffs) {
			# if this hunk consists entirely of subtractions from existing, we can ignore it
			# (because the existing pod may have manual additions)
			# so if there are any '+' lines (representing the generated file), we need to report it
			next unless grep { $_->[0] eq '+' } @$hunk;
			push @newdiffs, $hunk;
		}
		next unless @newdiffs;
		$diffs = \@newdiffs;
	}

#
# adapted from cdiff.pl (from Algorithm::Diff package)
#

	my $Context_Lines = 3;
	my $char1 = '-' x 3;
	my $char2 = '+' x 3;

	$File_Length_Difference = 0;

	print "$char1 $self->{filename}:existing\n";
	print "$char2 $self->{filename}:generated\n";

	my ($hunk,$oldhunk);
	# Loop over hunks. If a hunk overlaps with the last hunk, join them.
	# Otherwise, print out the old one.
	foreach my $piece (@$diffs) {
		$hunk = new Hunk ($piece, $Context_Lines);
		next unless $oldhunk;

		if ($hunk->does_overlap($oldhunk)) {
		$hunk->prepend_hunk($oldhunk);
		} else {
		$oldhunk->output_diff(\@f1, \@f2);
		}

	} continue {
		$oldhunk = $hunk;
	}

	# print the last hunk
	$oldhunk->output_diff(\@f1, \@f2);
}

#
# code below taken from cdiff.pl (from Algorithm::Diff package)
#

# Package Hunk. A Hunk is a group of Blocks which overlap because of the
# context surrounding each block. (So if we're not using context, every
# hunk will contain one block.)
{
package Hunk;

sub new {
# Arg1 is output from &LCS::diff (which corresponds to one Block)
# Arg2 is the number of items (lines, e.g.,) of context around each block
#
# This subroutine changes $File_Length_Difference
#
# Fields in a Hunk:
# blocks      - a list of Block objects
# start       - index in file 1 where first block of the hunk starts
# end         - index in file 1 where last block of the hunk ends
#
# Variables:
# before_diff - how much longer file 2 is than file 1 due to all hunks
#               until but NOT including this one
# after_diff  - difference due to all hunks including this one
    my ($class, $piece, $context_items) = @_;

    my $block = new Block ($piece); # this modifies $FLD!

    my $before_diff = $File_Length_Difference; # BEFORE this hunk
    my $after_diff = $before_diff + $block->{"length_diff"};
    $File_Length_Difference += $block->{"length_diff"};

    # @remove_array and @insert_array hold the items to insert and remove
    # Save the start & beginning of each array. If the array doesn't exist
    # though (e.g., we're only adding items in this block), then figure
    # out the line number based on the line number of the other file and
    # the current difference in file lengths
    my @remove_array = $block->remove;
    my @insert_array = $block->insert;
    my ($a1, $a2, $b1, $b2, $start1, $start2, $end1, $end2);
    $a1 = @remove_array ? $remove_array[0 ]->{"item_no"} : -1;
    $a2 = @remove_array ? $remove_array[-1]->{"item_no"} : -1;
    $b1 = @insert_array ? $insert_array[0 ]->{"item_no"} : -1;
    $b2 = @insert_array ? $insert_array[-1]->{"item_no"} : -1;

    $start1 = $a1 == -1 ? $b1 - $before_diff : $a1;
    $end1   = $a2 == -1 ? $b2 - $after_diff  : $a2;
    $start2 = $b1 == -1 ? $a1 + $before_diff : $b1;
    $end2   = $b2 == -1 ? $a2 + $after_diff  : $b2;

    # At first, a hunk will have just one Block in it
    my $hunk = {
	    "start1" => $start1,
	    "start2" => $start2,
	    "end1" => $end1,
	    "end2" => $end2,
	    "blocks" => [$block],
              };
    bless $hunk, $class;

    $hunk->flag_context($context_items);

    return $hunk;
}

# Change the "start" and "end" fields to note that context should be added
# to this hunk
sub flag_context {
    my ($hunk, $context_items) = @_;
    return unless $context_items; # no context

    # add context before
    my $start1 = $hunk->{"start1"};
    my $num_added = $context_items > $start1 ? $start1 : $context_items;
    $hunk->{"start1"} -= $num_added;
    $hunk->{"start2"} -= $num_added;

    # context after
    my $end1 = $hunk->{"end1"};
    $num_added = ($end1+$context_items > $#f1) ?
                  $#f1 - $end1 :
                  $context_items;
    $hunk->{"end1"} += $num_added;
    $hunk->{"end2"} += $num_added;
}

# Is there an overlap between hunk arg0 and old hunk arg1?
# Note: if end of old hunk is one less than beginning of second, they overlap
sub does_overlap {
    my ($hunk, $oldhunk) = @_;
    return "" unless $oldhunk; # first time through, $oldhunk is empty

    # Do I actually need to test both?
    return ($hunk->{"start1"} - $oldhunk->{"end1"} <= 1 ||
            $hunk->{"start2"} - $oldhunk->{"end2"} <= 1);
}

# Prepend hunk arg1 to hunk arg0
# Note that arg1 isn't updated! Only arg0 is.
sub prepend_hunk {
    my ($hunk, $oldhunk) = @_;

    $hunk->{"start1"} = $oldhunk->{"start1"};
    $hunk->{"start2"} = $oldhunk->{"start2"};

    unshift (@{$hunk->{"blocks"}}, @{$oldhunk->{"blocks"}});
}


# DIFF OUTPUT ROUTINES. THESE ROUTINES CONTAIN DIFF FORMATTING INFO...
sub output_diff {
#    if    (defined $main::opt_u) {&output_unified_diff(@_)}
#    elsif (defined $main::opt_c) {&output_context_diff(@_)}
#    else {die "unknown diff"}

	# always use context
	&output_unified_diff(@_)
}

sub output_unified_diff {
    my ($hunk, $fileref1, $fileref2) = @_;
    my @blocklist;

    # Calculate item number range.
    my $range1 = $hunk->unified_range(1);
    my $range2 = $hunk->unified_range(2);
    print "@@ -$range1 +$range2 @@\n";

    # Outlist starts containing the hunk of file 1.
    # Removing an item just means putting a '-' in front of it.
    # Inserting an item requires getting it from file2 and splicing it in.
    #    We splice in $num_added items. Remove blocks use $num_added because
    # splicing changed the length of outlist.
    #    We remove $num_removed items. Insert blocks use $num_removed because
    # their item numbers---corresponding to positions in file *2*--- don't take
    # removed items into account.
    my $low = $hunk->{"start1"};
    my $hi = $hunk->{"end1"};
    my ($num_added, $num_removed) = (0,0);
    my @outlist = @$fileref1[$low..$hi];
    map {s/^/ /} @outlist; # assume it's just context

    foreach my $block (@{$hunk->{"blocks"}}) {
	foreach my $item ($block->remove) {
	    my $op = $item->{"sign"}; # -
	    my $offset = $item->{"item_no"} - $low + $num_added;
	    $outlist[$offset] =~ s/^ /$op/;
	    $num_removed++;
	}
	foreach my $item ($block->insert) {
	    my $op = $item->{"sign"}; # +
	    my $i = $item->{"item_no"};
	    my $offset = $i - $hunk->{"start2"} + $num_removed;
	    splice(@outlist,$offset,0,"$op$$fileref2[$i]");
	    $num_added++;
	}
    }

    map {s/$/\n/} @outlist; # add \n's
    print @outlist;

}

sub output_context_diff {
    my ($hunk, $fileref1, $fileref2) = @_;
    my @blocklist;

    print "***************\n";
    # Calculate item number range.
    my $range1 = $hunk->context_range(1);
    my $range2 = $hunk->context_range(2);

    # Print out file 1 part for each block in context diff format if there are
    # any blocks that remove items
    print "*** $range1 ****\n";
    my $low = $hunk->{"start1"};
    my $hi  = $hunk->{"end1"};
    if (@blocklist = grep {$_->remove} @{$hunk->{"blocks"}}) {
	my @outlist = @$fileref1[$low..$hi];
	map {s/^/  /} @outlist; # assume it's just context
	foreach my $block (@blocklist) {
	    my $op = $block->op; # - or !
	    foreach my $item ($block->remove) {
		$outlist[$item->{"item_no"} - $low] =~ s/^ /$op/;
	    }
	}
	map {s/$/\n/} @outlist; # add \n's
	print @outlist;
    }

    print "--- $range2 ----\n";
    $low = $hunk->{"start2"};
    $hi  = $hunk->{"end2"};
    if (@blocklist = grep {$_->insert} @{$hunk->{"blocks"}}) {
	my @outlist = @$fileref2[$low..$hi];
	map {s/^/  /} @outlist; # assume it's just context
	foreach my $block (@blocklist) {
	    my $op = $block->op; # + or !
	    foreach my $item ($block->insert) {
		$outlist[$item->{"item_no"} - $low] =~ s/^ /$op/;
	    }
	}
	map {s/$/\n/} @outlist; # add \n's
	print @outlist;
    }
}

sub context_range {
# Generate a range of item numbers to print. Only print 1 number if the range
# has only one item in it. Otherwise, it's 'start,end'
    my ($hunk, $flag) = @_;
    my ($start, $end) = ($hunk->{"start$flag"},$hunk->{"end$flag"});
    $start++; $end++;  # index from 1, not zero
    my $range = ($start < $end) ? "$start,$end" : $end;
    return $range;
}

sub unified_range {
# Generate a range of item numbers to print for unified diff
# Print number where block starts, followed by number of lines in the block
# (don't print number of lines if it's 1)
    my ($hunk, $flag) = @_;
    my ($start, $end) = ($hunk->{"start$flag"},$hunk->{"end$flag"});
    $start++; $end++;  # index from 1, not zero
    my $length = $end - $start + 1;
    my $first = $length < 2 ? $end : $start; # strange, but correct...
    my $range = $length== 1 ? $first : "$first,$length";
    return $range;
}
} # end Package Hunk

# Package Block. A block is an operation removing, adding, or changing
# a group of items. Basically, this is just a list of changes, where each
# change adds or deletes a single item.
# (Change could be a separate class, but it didn't seem worth it)
{
package Block;
sub new {
# Input is a chunk from &Algorithm::LCS::diff
# Fields in a block:
# length_diff - how much longer file 2 is than file 1 due to this block
# Each change has:
# sign        - '+' for insert, '-' for remove
# item_no     - number of the item in the file (e.g., line number)
# We don't bother storing the text of the item
#
    my ($class,$chunk) = @_;
    my @changes = ();

# This just turns each change into a hash.
    foreach my $item (@$chunk) {
	my ($sign, $item_no, $text) = @$item;
	my $hashref = {"sign" => $sign, "item_no" => $item_no};
	push @changes, $hashref;
    }

    my $block = { "changes" => \@changes };
    bless $block, $class;

    $block->{"length_diff"} = $block->insert - $block->remove;
    return $block;
}


# LOW LEVEL FUNCTIONS
sub op {
# what kind of block is this?
    my $block = shift;
    my $insert = $block->insert;
    my $remove = $block->remove;

    $remove && $insert and return '!';
    $remove and return '-';
    $insert and return '+';
    warn "unknown block type";
    return '^'; # context block
}

# Returns a list of the changes in this block that remove items
# (or the number of removals if called in scalar context)
sub remove { return grep {$_->{"sign"} eq '-'} @{shift->{"changes"}}; }

# Returns a list of the changes in this block that insert items
sub insert { return grep {$_->{"sign"} eq '+'} @{shift->{"changes"}}; }

} # end of package Block
