#include <QVariant>
#include <QtQuick/QQuickView>
#include "Gui.h"
#include "App.h"

App& App::instance()
{
    static App thisInstance;
    return thisInstance;
}

App::~App()
{}

void App::launchGUI()
{
    Gui::instance().registerObjectToQML("app", this);
    Gui::instance().showUserInterface();
}

App::App()
{}
