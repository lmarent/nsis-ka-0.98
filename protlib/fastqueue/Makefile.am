lib_LTLIBRARIES = libfastqueue.la

include_HEADERS = $(top_srcdir)/fastqueue/fastqueue.h

libfastqueue_la_SOURCES = fastqueue.c eclock_gettime.c
libfastqueue_la_CFLAGS = -I$(top_srcdir)/fastqueue

if PROTLIB_DEBUG
AM_CPPFLAGS = -D_DEBUG
endif

check_PROGRAMS = testqueue
testqueue_SOURCES = testqueue.c fastqueue.c fastqueue.h eclock_gettime.c
testqueue_LDADD = -lrt
testqueue_CPPFLAGS = -DQUEUELEN
testqueue_CFLAGS = -g -Wall -ggdb
TESTS = $(check_PROGRAMS)
