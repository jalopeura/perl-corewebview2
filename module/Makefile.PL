use 5.030001;
use ExtUtils::MakeMaker;
use Config;

my $DEBUG;
if (grep { /^debug$/i } @ARGV) {
	$DEBUG = '-DDEBUG';
}

my $CC = 'g++';
my $DLL = ($Config{archname} =~ /x64/ || $Config{myuname} =~ /x86_64/)
	? 'WebView/x64/WebView2Loader.dll'
	: 'WebView/x86/WebView2Loader.dll';

my @files = ('lib');
my %libfiles;
while (@files) {
	my $file = shift @files;
	if (-d $file) {
		push @files, glob("$file/*");
		next;
	}
	(my $target = $file)=~s{^lib/}{\$(INST_LIBDIR)/};
	$libfiles{$file} = $target;
}

my @xs = glob('helpers/*.xs'), glob('interfaces/*.xs');
my @c = ( glob('helpers/*.cpp'), glob('interfaces/*.cpp') );
my @h = map { (my $h = $_)=~s/\.cpp/.h/; $h; } @c;

my @xs_object = map { my ($o) = m{([^/]+)\.[^.]+?$}; "$o\$(OBJ_EXT)" } (@xs);
my @c_object = map { my ($o) = m{([^/]+)\.[^.]+?$}; "$o\$(OBJ_EXT)" } (@c);

my @object = ('CoreWebView2$(OBJ_EXT)', @c_object);

sub MY::postamble {
	my $subxs = join(' ', @xs);
	my $deps = <<DEP;

CoreWebView2.xs : $subxs
DEP
#	for my $i (0..$#xs) {
#		(my $c = $xs[$i])=~s/\.xs$/.c/;
#		$deps .= <<DEP;
#
#$c : $xs[$i]
#
#$xs_object[$i] : $c
#	\$(CCCMD) \$(CCCDLFLAGS) "-I\$(PERL_INC)" \$(PASTHRU_DEFINE) \$(DEFINE) $c
#DEP
#	}
	for my $i (0..$#c) {
		$deps .= <<DEP;

$c_object[$i] : $c[$i]
	\$(CCCMD) \$(CCCDLFLAGS) "-I\$(PERL_INC)" \$(PASTHRU_DEFINE) \$(DEFINE) $c[$i]
DEP
	}
#warn $deps;
	return $deps;
}

# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
	NAME              => 'CoreWebView2',
	VERSION_FROM      => 'lib/CoreWebView2.pm', # finds $VERSION, requires EU::MM from perl >= 5.5
	PREREQ_PM         => {
		"Platform::Windows" => 0,
	}, # e.g., Module::Name => 1.1
#	ABSTRACT_FROM     => 'CoreWebView2.pm', # retrieve abstract from module
	AUTHOR            => 'jalopeura <jalopeura@hotmail.com>',
	LICENSE           => 'perl',
	#Value must be from legacy list of licenses here
	#http://search.cpan.org/perldoc?Module%3A%3ABuild%3A%3AAPI
	LIBS              => ['-L./WebView/x64 -lWebView2Loader.dll -lshlwapi -mwindows'], # e.g., '-lm'
	DEFINE            => "$DEBUG", # e.g., '-DHAVE_SOMETHING'
#	INC               => '-I. -I./WebView/include -g', # debug build
	INC               => '-I. -I./WebView/include -I./helpers', # non-debug build
	'C'            => \@c,
	'H'            => \@h,
#	'OBJECT'       => join(' ', @object),
	'OBJECT'       =>  \@object,
    PM => {
		%libfiles,
		$DLL => '$(INST_ARCHAUTODIR)/WebView2Loader.dll',
	},
	CC                => $CC,
	LD                => '$(CC)',
	XSOPT             => '-C++',
#	TYPEMAPS          => ['perlobject.map'],
#	TYPEMAPS          => ['typemap'],

	# this really helps during development; it will generate the main XS => C if any
	# of the included XS files changes
	depend            => { 'CoreWebView2.c' => join(' ', 'CoreWebView2.xs', @xs) },
);
#if  (eval {require ExtUtils::Constant; 1}) {
#  # If you edit these definitions to change the constants used by this module,
#  # you will need to use the generated const-c.inc and const-xs.inc
#  # files to replace their "fallback" counterparts before distributing your
#  # changes.
#  my @names = (qw());
#  ExtUtils::Constant::WriteConstants(
#                                     NAME         => 'Win32::GUI::WebView2',
#                                     NAMES        => \@names,
#                                     DEFAULT_TYPE => 'IV',
#                                     C_FILE       => 'const-c.inc',
#                                     XS_FILE      => 'const-xs.inc',
#                                  );
#
#}
#else {
#  use File::Copy;
#  use File::Spec;
#  foreach my $file ('const-c.inc', 'const-xs.inc') {
#    my $fallback = File::Spec->catfile('fallback', $file);
#    copy ($fallback, $file) or die "Can't copy $fallback to $file: $!";
#  }
#}
