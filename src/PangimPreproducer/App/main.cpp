#include <QCoreApplication>
#include "App.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationName("Pangim Preproducer");
    App::instance().launchGUI();
    return app.exec();
}
