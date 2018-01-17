#include "App.h"

App& App::instance()
{
    static App thisInstance;
    return thisInstance;
}

App::~App()
{}

void App::launchGUI()
{}

App::App()
{}
