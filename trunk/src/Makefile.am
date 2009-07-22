bin_PROGRAMS = gipsec

gipsec_SOURCES = \
	main.c \
	gipsec.c \
	gipsec.h \
	gipsec-options.c \
	gipsec-options.h

gipsec_CPPFLAGS = \
	$(GIPSEC_CFLAGS) \
	-DGIPSEC_LOCALEDIR=\"$(datadir)/locale\" \
	-DGLADEDIR=\""$(gladedir)"\"

gipsec_LDADD = \
	$(GIPSEC_LIBS)

gladedir = $(datadir)/gipsec
glade_DATA = gipsec.glade
