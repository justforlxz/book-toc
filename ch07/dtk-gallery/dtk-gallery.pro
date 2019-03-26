QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dtk-gallery
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    controlspage.cpp \
    effectspage.cpp \
    settingsdialog.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    controlspage.h \
    effectspage.h \
    settingsdialog.h

DESTFILES += settings.json

DISTFILES += \
    settings.json
