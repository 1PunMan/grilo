#
# Makefile.am
#
# Author: Víctor M. Jáquez L. <vjaquez@igalia.com>
#
# Copyright (C) 2010, 2011 Igalia S.L. All rights reserved.


lib_LTLIBRARIES = libgrlnet-@GRL_MAJORMINOR@.la

libgrlnet_@GRL_MAJORMINOR@_la_DEPENDENCIES =	\
	$(top_builddir)/src/lib@GRL_NAME@.la

libgrlnet_@GRL_MAJORMINOR@_la_SOURCES =   \
	grl-net-mock.c                         \
	grl-net-wc.c

libgrlnet_@GRL_MAJORMINOR@_la_CFLAGS =	\
	-I $(top_srcdir)/src		\
	-I $(top_srcdir)/src/data	\
	-DLOCALEDIR=\"$(localedir)\" \
	$(DEPS_CFLAGS)			\
	$(NET_CFLAGS)

libgrlnet_@GRL_MAJORMINOR@_la_LIBADD =	\
	$(top_builddir)/src/lib@GRL_NAME@.la	\
	$(DEPS_LIBS)				\
	$(NET_LIBS)

libgrlnet_@GRL_MAJORMINOR@_la_LDFLAGS =	\
	-version-info $(GRLNET_LT_VERSION)		\
	-no-undefined

libgrlnet_@GRL_MAJORMINOR@includedir =	\
	$(includedir)/@GRL_NAME@/net

libgrlnet_@GRL_MAJORMINOR@include_HEADERS =	\
	grl-net-wc.h				\
	grl-net.h

noinst_HEADERS = 		\
	grl-net-mock-private.h

CLEANFILES = *.gir

# introspection support
if HAVE_INTROSPECTION
-include $(INTROSPECTION_MAKEFILE)
gir_headers = $(patsubst %,$(srcdir)/%, $(libgrlnet_@GRL_MAJORMINOR@include_HEADERS))
gir_sources = $(patsubst %,$(srcdir)/%, $(libgrlnet_@GRL_MAJORMINOR@_la_SOURCES))

INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --warn-all

introspection_sources =	\
	$(gir_headers)	\
	$(gir_sources)

GrlNet-@GRL_MAJORMINOR@.gir: libgrlnet-@GRL_MAJORMINOR@.la
GrlNet_@GRL_MAJORMINOR_NORM@_gir_INCLUDES = GObject-2.0 Gio-2.0 Soup-2.4
GrlNet_@GRL_MAJORMINOR_NORM@_gir_CFLAGS = -I $(top_srcdir)/src \
	-I $(top_srcdir)/src/data -I $(top_srcdir)/libs
GrlNet_@GRL_MAJORMINOR_NORM@_gir_LIBS = libgrlnet-@GRL_MAJORMINOR@.la \
	$(top_builddir)/src/lib@GRL_NAME@.la
GrlNet_@GRL_MAJORMINOR_NORM@_gir_FILES = $(introspection_sources)
GrlNet_@GRL_MAJORMINOR_NORM@_gir_SCANNERFLAGS = --c-include="net/grl-net.h"
INTROSPECTION_GIRS += GrlNet-@GRL_MAJORMINOR@.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0/
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(dist_gir_DATA) $(typelib_DATA)
endif

-include $(top_srcdir)/git.mk
