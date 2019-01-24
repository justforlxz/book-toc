QT += core gui

TARGET = square
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += ../../include
DESTDIR = ../

SOURCES = \
    squarepainter.cpp

HEADERS = \
    squarepainter.h

DISTFILES += square.json 
