Name:           libvxhs 
Version:        1.0
Release:        1%{?dist}
Summary:        The Veritas HyperScale storage connector library
Group:          Development
License:        GPLv2
URL:            https://github.com/VeritasHyperScale/libqnio
Source:         %{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

%description
libvxhs is a storage connector library for accessing vdisks on Veritas
HyperScale storage.

%prep
%setup

%build
make %{?_smp_mflags}

%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

%clean
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT


%files
/usr/include/qnio
/usr/lib64/libvxhs.so
/usr/local/bin/*

%changelog
* Tue Feb 21 2017 Ashish Mittal <Ashish.Mittal@veritas.com> - 1.0
- First checkin of the packaging spec file
