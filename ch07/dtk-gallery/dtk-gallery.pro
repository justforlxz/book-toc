QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dtk-gallery
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp

RESOURCES +=         resources.qrc
