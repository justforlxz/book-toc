QT       += core gui widgets

TARGET = ch06_drawing
TEMPLATE = app

INCLUDEPATH += ../include

SOURCES += \
        main.cpp \
        widget.cpp \
    pluginmanager.cpp \
    painterplugin.cpp

HEADERS += \
        widget.h \
    pluginmanager.h \
    painterplugin.h
