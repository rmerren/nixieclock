#-------------------------------------------------
#
# Project created by QtCreator 2010-10-26T10:41:14
#
#-------------------------------------------------

QT       += core gui

TARGET = nixieclock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xededd5aa
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES += \
    images.qrc

unix {
    INSTALLS += target desktop icon48
    target.path = /usr/bin/nixieclock
    desktop.path = /usr/share/applications/hildon
    desktop.files += maemofiles/nixieclock.desktop
    icon48.path = /usr/share/icons/hicolor/48x48/apps
    icon48.files += maemofiles/nixieclock_icon.png
}

