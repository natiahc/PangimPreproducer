QT += opengl

TEMPLATE = lib

DESTDIR = $$PWD/../../../Build/bin

CONFIG(debug, debug|release){
    TARGET = Guid
}else{
    TARGET = Gui
}

DEFINES += GUI_LIBRARY

SOURCES += \
    Gui.cpp

HEADERS += \
    gui_global.h \
    Gui.h


OTHER_FILES += \
    Gui.pri


# Add more folders to ship with the application, here
folder_01.source = qml/PangimGui
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()
