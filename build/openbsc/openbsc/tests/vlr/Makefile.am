AM_CPPFLAGS = $(all_includes) -I$(top_srcdir)/include
AM_CFLAGS = -Wall -ggdb3 \
	$(LIBOSMOCORE_CFLAGS) \
	$(LIBOSMOGSM_CFLAGS) \
	$(COVERAGE_CFLAGS) \
	$(LIBOSMOABIS_CFLAGS) \
	$(NULL)
AM_LDFLAGS = $(COVERAGE_LDFLAGS)

noinst_PROGRAMS = vlr_test

vlr_test_SOURCES = vlr_test.c
vlr_test_LDADD = \
	$(top_builddir)/src/libvlr/libvlr.a \
	$(top_builddir)/src/libcommon/libcommon.a \
	$(LIBOSMOCORE_LIBS) \
	$(LIBOSMOGSM_LIBS) \
	$(LIBOSMOVTY_LIBS) \
	$(LIBOSMOABIS_LIBS) \
	$(LIBRARY_DL) \
	$(LIBCRYPTO_LIBS) \
	$(NULL)
