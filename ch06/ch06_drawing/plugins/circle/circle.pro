QT += core gui

TARGET = circle
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += ../../include
DESTDIR = ../

SOURCES = \
    circlepainter.cpp

HEADERS = \
    circlepainter.h

DISTFILES += circle.json 
