QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dtk-demo
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    titlebarcontent.cpp \
    scanview.cpp \
    mainwindow.cpp \
    controller.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    titlebarcontent.h \
    scanview.h \
    mainwindow.h \
    controller.h \
    scanresult.h
