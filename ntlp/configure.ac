#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# $HeadURL: https://svn.tm.kit.edu/nsis/ntlp/branches/20091014-autotools/configure.ac $
#

AC_PREREQ(2.61)
AC_INIT(gist-ka, 0.97, roland.bless@kit.edu)
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_SRCDIR([src/ntlp_main.cpp])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_CPP
AM_PROG_AR

LT_INIT

#if test -d "../protlib"; then
#   AC_CONFIG_SUBDIRS([../protlib])
#fi

AC_CHECK_LIB([cppunit], [main])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h netdb.h netinet/in.h stdlib.h string.h sys/param.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_MODE_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_HEADER_TIME
AC_STRUCT_TM
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MEMCMP
AC_TYPE_SIGNAL
AC_CHECK_FUNCS([gethostname gettimeofday memset socket strerror])


#check for unordered map
[SAVECXXFLAGS=$CXXFLAGS; CXXFLAGS="-std=c++0x"]
AC_LANG_CPLUSPLUS

AC_CACHE_CHECK([whether unordered_map is available],
			[ac_cv_unordered_map_exists],
[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <unordered_map>]],
				[[std::unordered_map<int,int> testmap;]])],
				[ac_cv_unordered_map_exists=yes],
				[ac_cv_unordered_map_exists=no])])
[CXXFLAGS=$SAVECXXFLAGS]

AM_CONDITIONAL(GIST_NO_WARN_HASHMAP, test "$ac_cv_unordered_map_exists" = yes)

# FLOWINFO USE
AC_ARG_ENABLE([flowinfo],
	[AS_HELP_STRING([--use-flowinfo], [use flowinfo module for mobility support (default: disabled)])],
	[use_flowinfo=$enableval],
	[use_flowinfo=no])
AM_CONDITIONAL(USE_WITH_FLOWINFO, test "$use_flowinfo" = yes)

# DEBUG USE
AC_ARG_ENABLE([debug],
	[AS_HELP_STRING([--disable-debug], [disable debug code (default: debugging enabled)])],
	[ntlp_debug=$enableval],
	[ntlp_debug=yes])
AM_CONDITIONAL(NTLP_DEBUG, test "$ntlp_debug" = yes)

# SCTP USE
AC_ARG_ENABLE([sctp],
	[AS_HELP_STRING([--enable-sctp], [include SCTP transport capability (default: disabled)])],
	[enable_sctp=$enableval],
	[enable_sctp=no])
AM_CONDITIONAL(USE_WITH_SCTP, test "$enable_sctp" = yes)

## libnetfilter_queue or obsolete libipq
AC_ARG_ENABLE([nfq],
	[AS_HELP_STRING([--enable-nfq], [compile with libnetfilter_queue support (default: disabled)])],
	[protlib_with_nfq=$enableval],
	[protlib_with_nfq=no])

#LIB NETFILTER_QUEUE
AM_CONDITIONAL(PROTLIB_WITH_NFQ, test "$protlib_with_nfq" = yes)
if test $protlib_with_nfq = yes; then
	AC_CHECK_LIB([netfilter_queue],[nfq_get_payload],,[AC_MSG_ERROR([cannot find libnetfilter_queue, probably you need to install libnetfilter-queue-dev first])])
else
	AC_CHECK_LIB([ipq], [ipq_get_packet],,[AC_MSG_ERROR([cannot find libipq, probably you need to install iptables-dev(el) first])])
fi

AC_ARG_WITH(pkgconfigdir,
	AC_HELP_STRING([--with-pkgconfigdir],
	[Use the specified pkgconfig dir (default is libdir/pkgconfig)]),
	[pkgconfigdir=${withval}],
	[pkgconfigdir='${libdir}/pkgconfig'])

AC_SUBST([pkgconfigdir])
AC_MSG_NOTICE([pkgconfig directory is ${pkgconfigdir}])


#further CONFIG_FILES
AC_CONFIG_FILES([Makefile
				 libgist-0.0.pc
                 src/Makefile
                 test/Makefile])
AC_OUTPUT
