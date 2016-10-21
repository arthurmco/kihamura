# Makefile for sources
#
# Copyright (C) 2016 Arthur M

AUTOMAKE_OPTIONS = foreign
#SUBDIRS=media

bin_PROGRAMS=kihamura
kihamura_SOURCES=main.cpp gui-main.cpp MediaCollection.cpp Media.cpp Clip.cpp \
 TrackCollection.cpp Track.cpp VideoProject.cpp VideoTrack.cpp \
 VideoObject.cpp VideoClip.cpp AudioObject.cpp AudioClip.cpp AudioTrack.cpp \
 media/AnyMedia.cpp media/FileMedia.cpp media/FileMediaOpener.cpp


AM_CXXFLAGS= -std=c++14 -DDATA_DIR=\"${datadir}\" ${GTK3_CFLAGS}
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}
kihamura_LDADD = ${GTK3_LIBS}


# The interface file
kihadatadir = ${datadir}/kihamura
kihadata_DATA = interface.glade
