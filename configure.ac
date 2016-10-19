#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([kihamura], [0.0.1], [arthurmco@gmail.com])
AC_CONFIG_SRCDIR([src/])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_CHECK_FUNCS([strerror strrchr])

# Check for some other libraries
PKG_CHECK_MODULES([GTK3], [gtk+-3.0 > 3.10])

# Defines
AC_DEFINE_UNQUOTED([DATAPATH], ["$pkgdatadir"], [Data directory path])

AC_OUTPUT([Makefile src/Makefile src/media/Makefile])
