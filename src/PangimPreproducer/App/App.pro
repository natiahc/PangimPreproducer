QT += qml quick

TEMPLATE = app

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = $$PWD/../../../Build/bin

CONFIG(debug, debug|release) {
    TARGET = PangimPreproducerd
} else {
    TARGET = PangimPreproducer
}

DEFINES += PANGIM_PREPRODUCER_LIBRARY

SOURCES += \
    App.cpp \
    Main.cpp

HEADERS += \
    pangim_preproducer_global.h \
    App.h

include(../Gui/Gui.pri)
