use strict;
package CoreWebView2::Helper::Stream;

use parent qw(Exporter);

use Symbol qw(gensym);

#
# exports
#

my @stream_seek_group = qw(STREAM_SEEK_SET STREAM_SEEK_CUR STREAM_SEEK_END);
my @stgc_group = qw(STGC_DEFAULT STGC_OVERWRITE STGC_ONLYIFCURRENT STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE STGC_CONSOLIDATE);
my @locktype_group = qw(LOCK_WRITE LOCK_EXCLUSIVE LOCK_ONLYONCE);
my @statflag_group = qw(STATFLAG_DEFAULT STATFLAG_NONAME STATFLAG_NOOPEN);

our @EXPORT_OK = (@stream_seek_group, @stgc_group, @locktype_group, @statflag_group);

our %EXPORT_TAGS = (
	all => \@EXPORT_OK,
	STREAM_SEEK => \@stream_seek_group,
	STGC => \@stgc_group,
	LOCKTYPE => \@locktype_group,
	STATFLAG => \@statflag_group,
);

sub fh {
	my ($self) = @_;
	my $fh = gensym;
	tie *$fh, 'CoreWebView2::Helper::Stream::fh', $self;
	return $fh;
}

package CoreWebView2::Helper::Stream::fh;

sub TIEHANDLE {
	my ($class, $stream) = @_;

	return bless {
		stream => $stream,
	}, $class;
}

sub WRITE {
	my ($self, @chunks) = @_;

	my $length;
	map {
		$length += $self->{stream}->Write($_);
	} @chunks;

	# do we need to return $length?
}

sub PRINT {
	my ($self, @chunks) = @_;

	my $length;
	map {
		$length += $self->{stream}->Write($_);
	} @chunks;

	return 1; # return true;
}

sub PRINTF {
	my ($self, @params) = @_;

	my $string = sprintf(@params);

	my $length = $self->{stream}->Write($string);

	return 1; # return true;
}

sub READ {
	my ($self, undef, $length) = @_;

	$_[1] = $self->{stream}->Read($length);

	return length($_[1]);
}

sub READLINE {
	my ($self) = @_;

	my $out;
	while ( defined (my $char = $self->{stream}->Read(1)) ) {
		$out .= $char;
		last if $char eq $/;
	}

	return $out;
}

sub GETC {
	my ($self) = @_;

	return $self->{stream}->Read(1);
}

sub EOF {
	my ($self, $marker) = @_;

	my $stat = $self->{stream}->Stat();
	my $pos = $self->{stream}->Read(CoreWebView2::Helper::Stream::STREAM_SEEK_CUR, 0);

	return $stat->{size} == $pos;
}

sub CLOSE {
	my ($self) = @_;

	$self->{closed} = 1;
# TODO: check closed marker when other methods are called
}

1;

=pod

IStream::Seek(position, origin)

typedef enum tagSTREAM_SEEK {
  STREAM_SEEK_SET = 0,
  STREAM_SEEK_CUR = 1,
  STREAM_SEEK_END = 2
} STREAM_SEEK;

SEEK_SET, SEEK_CUR, and SEEK_END (start of the file, current position, end of the file) from the Fcntl module. Returns 1 on success, false otherwise.

constant		use Fcntl qw(:seek);		use CoreWebView2::Helper::String qw(:STREAM_SEEK);
0				SEEK_SET					STREAM_SEEK_SET
1				SEEK_CUR					STREAM_SEEK_CUR
2				SEEK_END					STREAM_SEEK_END

IStream::Commit(flags)

Transaction mode: Commit / Revert
commit flags - STGC enumeration (wtypes.h)
typedef enum tagSTGC {
  STGC_DEFAULT = 0,
  STGC_OVERWRITE = 1,
  STGC_ONLYIFCURRENT = 2,
  STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4,
  STGC_CONSOLIDATE = 8
} STGC;

IStream::LockRegion(offset, length, lock_type)

lock types
LOCKTYPE enumeration (objidl.h)
typedef enum tagLOCKTYPE {
  LOCK_WRITE = 1,
  LOCK_EXCLUSIVE = 2,
  LOCK_ONLYONCE = 4
} LOCKTYPE;

IStream::Stat(flag = STATFLAG_DEFAULT)

stat flags
typedef enum tagSTATFLAG {
  STATFLAG_DEFAULT = 0,
  STATFLAG_NONAME = 1,
  STATFLAG_NOOPEN = 2
} STATFLAG;

STATFLAG_DEFAULT
Value: 0
Requests that the statistics include the pwcsName member of the
STATSTG structure.
STATFLAG_NONAME
Value: 1
Requests that the statistics not include the pwcsName member of the
STATSTG structure. If the name is omitted, there is no need for the
ILockBytes::Stat,
IStorage::Stat, and
IStream::Stat methods methods to allocate and free memory for the string value of the name, therefore the method reduces time and resources used in an allocation and free operation.
STATFLAG_NOOPEN
Value: 2
Not implemented.

// for the backing object
CreateStreamOnHGlobal - https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-createstreamonhglobal
SHCreateMemStream - https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-shcreatememstream

SHCreateMemStream differs from CreateStreamOnHGlobal in the following ways.
	Thread safety. The stream created by SHCreateMemStream is thread-safe as of Windows 8. On earlier systems, the stream is not thread-safe. The stream created by CreateStreamOnHGlobal is thread-safe.
	Initial contents. SHCreateMemStream accepts the initial contents in the form of a buffer. CreateStreamOnHGlobal accepts the initial contents in the form of an HGLOBAL.
	Access to contents. SHCreateMemStream does not allow direct access to the stream contents. CreateStreamOnHGlobal permits access through GetHGlobalFromStream.
	Failure information. If SHCreateMemStream returns NULL, it was unable to allocate the necessary memory. Callers should assume the cause is E_OUTOFMEMORY.
	Support for IStream::Clone. Prior to Windows 8, the stream created by SHCreateMemStream does not support IStream::Clone. The stream created by CreateStreamOnHGlobal does. As of Windows 8, the stream created by SHCreateMemStream does support IStream::Clone.
	The stream returned by SHCreateMemStream returns S_FALSE from IStream::Read if you attempt to read past the end of the buffer. The stream returned by CreateStreamOnHGlobal returns S_OK and sets *pcbRead to 0 if you attempt to read past the end of the buffer.

=cut

1;
