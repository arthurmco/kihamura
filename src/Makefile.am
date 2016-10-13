# Makefile for sources
#
# Copyright (C) 2016 Arthur M

AUTOMAKE_OPTIONS = foreign
#SUBDIRS=media

AM_CXXFLAGS= -std=c++11 ${GTK3_CFLAGS}
AM_LDFLAGS= ${GTK3_LIBS}

bin_PROGRAMS=kihamura
kihamura_SOURCES=main.cpp MediaCollection.cpp Media.cpp Clip.cpp \
 TrackCollection.cpp Track.cpp VideoProject.cpp VideoTrack.cpp \
 VideoObject.cpp VideoClip.cpp AudioObject.cpp AudioClip.cpp AudioTrack.cpp \
 media/AnyMedia.cpp media/FileMedia.cpp media/FileMediaOpener.cpp

# The interface file
kihadatadir = ${datadir}/kihamura
kihadata_DATA = interface.glade
