QT -= gui
QT += dbus

CONFIG -= app_bundle
CONFIG += link_pkgconfig
PKGCONFIG += polkit-qt5-1

SOURCES += \
        main.cpp \
    sysenv.cpp

HEADERS += \
    sysenv.h

DISTFILES += com.deepin.examples.ch06.sysenvhelper.conf \
             com.deepin.examples.ch06.setsysenv.policy
