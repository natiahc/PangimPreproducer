#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>

#include "App.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Pangim Preproducer");
    App::instance().launchGUI();
    return app.exec();
}
