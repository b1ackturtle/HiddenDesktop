HEADERS       = src/traywidget.h
SOURCES       = src/main.cpp \
                src/traywidget.cpp
RESOURCES     = resources.qrc

QT += widgets

QMAKE_INFO_PLIST = ./Info.plist
OBJECTS_DIR = ./build
MOC_DIR = ./build
