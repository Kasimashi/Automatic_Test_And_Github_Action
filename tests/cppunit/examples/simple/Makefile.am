EXTRA_DIST = simple.vcproj simple_plugin.opt simple_plugin.vcproj SimplePlugIn.cpp

AM_CPPFLAGS = -I$(top_builddir)/include -I$(top_srcdir)/include

noinst_PROGRAMS = simple

simple_SOURCES = ExampleTestCase.cpp Main.cpp  ExampleTestCase.h

simple_LDADD = \
  $(top_builddir)/src/cppunit/libcppunit.la \
  $(LIBADD_DL)
