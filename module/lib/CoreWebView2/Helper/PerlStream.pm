use strict;
package CoreWebView2::Helper::PerlStream;

use Data::Dumper;
$Data::Dumper::Sortkeys = 1;

use CoreWebView2::Helper::Stream qw(:STREAM_SEEK); # for the constants

sub new {
	my ($class, $init) = @_;

	my $fh;
	if (ref $init) {
		$fh = $init;
	}
	else {
		open my $fh2, '+<', \$init or die $!;
		$fh = $fh2;
	}

	return bless {
		fh => $fh,
	}, $class;
}

sub Read {
	my ($self, $length) = @_;

	read $self->{fh}, my $data, $length;

	return $data;
}

sub Write {
	my ($self, $data) = @_;
	# return length actually written
}

sub Seek {
	my ($self, $position, $whence) = @_;

	seek $self->{fh}, $position, $whence;

	return tell $self->{fh};
}

sub SetSize {
	my ($self, $size) = @_;
	# return bool
}

sub CopyTo {
	my ($self, $target, $length) = @_;
	# return (bytes_read, bytes_written)
}

sub Commit {
	my ($self, $flags) = @_;
	# return bool
}

sub Revert {
	my ($self) = @_;
	# return bool
}

sub LockRegion {
	my ($self, $offset, $length, $type) = @_;
	# return bool
}

sub UnlockRegion {
	my ($self, $offset, $length, $type) = @_;
	# return bool
}

sub Stat {
	my ($self, $flags) = @_;
	# return href
}

sub Clone {
	my ($self) = @_;
	# return new stream
}
my @stream_seek_group = qw(STREAM_SEEK_SET STREAM_SEEK_CUR STREAM_SEEK_END);

1;
