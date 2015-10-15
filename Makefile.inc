## -----------------------------------*- mode: Makefile; -*--
# Top Level Makefile for inclusion for the distribution tree of NSIS-ka
# -------------------------------------------------------
# $HeadURL: https://svn.ipv6.tm.uka.de/nsis/dist/nsis-ka/branches/20091014-autotools/Makefile.inc $
# $Id: Makefile.inc 5879 2011-02-16 11:26:53Z bless $
# -------------------------------------------------------
# Several definitions (directories and linker options) for nsis-ka components
#

DISTDIR=$(top_srcdir)/..


PROTLIB_DIR=$(DISTDIR)/protlib
PROTLIB_SRC=$(PROTLIB_DIR)/src
PROTLIB_INC=$(PROTLIB_DIR)/include
PROTLIB_LIBDIR=$(PROTLIB_SRC)
PROTLIB_LIB=$(PROTLIB_LIBDIR)/libprot.la
LD_PROTLIB_LIB=-L$(PROTLIB_LIBDIR) -lprot

FQUEUE_DIR=$(PROTLIB_DIR)/fastqueue
FQUEUE_SRC=$(FQUEUE_DIR)
FQUEUE_INC=$(FQUEUE_DIR)
FQUEUE_LIBDIR=$(FQUEUE_DIR)
FQUEUE_LIB=$(FQUEUE_LIBDIR)/libfastqueue.la
LD_FQUEUE_LIB=-L$(FQUEUE_LIBDIR) -lfastqueue

NTLP_DIR=$(DISTDIR)/ntlp
NTLP_SRC=$(NTLP_DIR)/src
NTLP_INC=$(NTLP_DIR)/include
NTLP_LIBDIR=$(NTLP_SRC)
NTLP_LIB=$(NTLP_LIBDIR)/libgist.la
LD_NTLP_LIB=-L$(NTLP_LIBDIR) -lgist



# end of Makefile.inc
