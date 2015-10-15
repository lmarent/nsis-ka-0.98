# ------------------------------------*- Autoconf -*-
# Makefile.am - Automake Makefile for GIST/NTLP
# ----------------------------------------------------------
# $Id: Makefile.am 5877 2011-02-16 00:05:32Z bless $
# $HeadURL: https://svn.tm.kit.edu/nsis/ntlp/branches/20091014-autotools/src/Makefile.am $
# ==========================================================
#                      
# (C)opyright, all rights reserved by
# - Institute of Telematics, Karlsruhe Institute of Technology (KIT)
# ==========================================================

#where_PRIMARY = gist_PROGRAMS gist_LIBRARIES

#include common directory definitions of NSIS components
include ../../Makefile.inc

bin_PROGRAMS = gistka

dist_gistka_scripts = intercept loadmodules flush gist

LDADD = $(PROTLIB_LIB)

lib_LTLIBRARIES = libgist.la

API_INC		= $(top_srcdir)/include
PDU_INC		= ./pdu

libgist_la_CPPFLAGS = -I$(API_INC) -I$(PDU_INC) -I$(PROTLIB_INC) -I$(FQUEUE_INC)

gistka_CPPFLAGS = -I$(API_INC) -I$(PDU_INC) -I$(PROTLIB_INC) -I$(FQUEUE_INC)

gistka_SOURCES = ntlp_main.cpp

# netfilter_queue will be automatically added by the LIBS variable
gistka_LDADD = -L. -lgist $(LD_PROTLIB_LIB) $(LD_FQUEUE_LIB) -lssl -lrt -lpthread -lcrypto

libgist_la_SOURCES = apimessage.cpp apiwrapper.cpp capability.cpp	\
	general_objects.cpp gist_conf.cpp GISTConsole.cpp	\
	gist_exceptions.cpp ntlp_global_constants.cpp \
	ntlp_proto.cpp ntlp_starter.cpp ntlp_statemodule_api.cpp	\
	ntlp_statemodule_data.cpp ntlp_statemodule_main.cpp		\
	ntlp_statemodule_querier.cpp ntlp_statemodule_responder.cpp	\
	routingentry.cpp routingtable.cpp secretmanager.cpp		\
	signalingmodule_ntlp.cpp 			\
	authorized_peer_db.h GISTConsole.h ntlp_statemodule.h		\
	secretmanager.h capability.h gist_exceptions.h routingentry.h	\
	signalingmodule_ntlp.h general_objects.h ntlp_proto.h		\
	routingtable.h pdu/ntlp_pdu.cpp pdu/ntlp_ie.cpp			\
	pdu/nattraversal.cpp pdu/hello.cpp pdu/stackconf.cpp		\
	pdu/query_cookie.cpp pdu/mri_est.cpp pdu/stackprop.cpp		\
	pdu/nslpdata.cpp pdu/helloid.cpp pdu/resp_cookie.cpp		\
	pdu/mri_le.cpp pdu/mri_pc.cpp pdu/mri.cpp pdu/nli.cpp 		\
	pdu/confirm.cpp pdu/data.cpp pdu/query.cpp 			\
	pdu/ntlp_errorobject.cpp pdu/sessionid.cpp pdu/response.cpp 	\
	pdu/ntlp_object.cpp pdu/ntlp_error.cpp


include_HEADERS = ../include/apimessage.h ../include/apiwrapper.h	\
	../include/flowinfo.h ../include/gist_conf.h			\
	../include/goettingen_api.h ../include/goettingen_headers.h	\
	../include/mri_est.h ../include/mri.h ../include/mri_le.h	\
	../include/mri_pc.h ../include/msghandle.h			\
	../include/nslpdata.h ../include/ntlp_global_constants.h	\
	../include/ntlp_ie.h ../include/ntlp_object.h			\
	../include/ntlp_starter.h ../include/objectpool.h		\
	../include/poolobject.h ../include/sessionid.h pdu/query.h	\
	pdu/ntlp_pdu.h pdu/hello.cpp pdu/stackprop.h			\
	pdu/nattraversal.h pdu/stackconf.h pdu/confirm.h pdu/data.h	\
	pdu/helloid.cpp pdu/helloid.h pdu/query_cookie.h		\
	pdu/response.h pdu/ntlp_errorobject.h pdu/hello.h		\
	pdu/ntlp_error.h pdu/nli.h pdu/resp_cookie.h

if GIST_NO_WARN_HASHMAP
AM_CXXFLAGS = -Wno-deprecated
else !GIST_NO_WARN_HASHMAP
AM_CXXFLAGS = 
endif

if USE_WITH_FLOWINFO
AM_CXXFLAGS += -DUSE_FLOWINFO
libgist_la_SOURCES += flowinfo.cpp 
endif

if USE_WITH_SCTP
AM_CXXFLAGS += -D_USE_SCTP
gistka_LDADD += -lsctp
endif


if NTLP_DEBUG
AM_CXXFLAGS += -g
AM_CXXFLAGS += -D_DEBUG -D_GLIBCXX_DEBUG -ggdb
endif

# end of Makefile.am
