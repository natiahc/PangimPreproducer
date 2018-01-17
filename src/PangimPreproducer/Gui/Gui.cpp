#include <QtQml>
#include <QVariant>
#include <QFont>

#include "Gui.h"
#include "qtquick2applicationviewer.h"

struct GuiData
{
    GuiData() : viewer(0),
                fontFamily("Arial"),
                fontWeight(QFont::Normal)
                {}

    ~GuiData()
    {
        delete viewer;
        viewer = 0;
    }

    QtQuick2ApplicationViewer* viewer;
    QString apiKey;
    QString fontFamily;
    int fontWeight;
    QHash<QString, QVariant> contextPropertyNameValueHash;
    QHash<QString, QObject*> contextPropertyNameObjectHash;
};


Gui& Gui::instance()
{
    static Gui theInstance;
    return theInstance;
}


Gui::Gui()
{
    d = new GuiData;
    d->viewer = new QtQuick2ApplicationViewer;
    d->viewer->setMinimumSize(QSize(800, 400));

    qmlRegisterType<QtQuick2ApplicationViewer>("com.pangim.QtQuick2ApplicationViewer", 1, 0, "QtQuick2ApplicationViewer");

    this->registerObjectToQML("gui", this);
    this->registerObjectToQML("mainViewer", d->viewer);
}

Gui::~Gui()
{
    delete d;
    d = 0;
}

Pangim::IQtQuick2ApplicationViewer *Gui::qmlViewer() const
{
    return d->viewer;
}

QtQuick2ApplicationViewer *Gui::createQmlViewer()
{
    return this->createQmlViewer(d->viewer);
}

QtQuick2ApplicationViewer* Gui::createQmlViewer(QtQuick2ApplicationViewer* parent)
{
    QtQuick2ApplicationViewer* viewer;

    if(parent)
        viewer = new QtQuick2ApplicationViewer(parent);
    else
        viewer = new QtQuick2ApplicationViewer;

    viewer->setColor(QColor(Qt::black));

    Q_FOREACH(QString propertyName, d->contextPropertyNameValueHash.keys())
        viewer->rootContext()->setContextProperty(
                    propertyName, d->contextPropertyNameValueHash.value(propertyName));

    Q_FOREACH(QString propertyName, d->contextPropertyNameObjectHash.keys())
        viewer->rootContext()->setContextProperty(
                    propertyName, d->contextPropertyNameObjectHash.value(propertyName));

    viewer->rootContext()->setContextProperty("viewer", viewer);

    return viewer;
}

void Gui::setFontFamily(const QString &family)
{
    if(d->fontFamily == family)
        return;

    d->fontFamily = family;
}

QString Gui::fontFamily() const
{
    return d->fontFamily;
}

void Gui::setFontWeight(int weight)
{
    if(d->fontWeight == weight)
        return;

    d->fontWeight = weight;
}

int Gui::fontWeight() const
{
    return d->fontWeight;
}

void Gui::showUserInterface()
{
    if(!d->viewer)
        return;

    d->viewer->addImportPath(QLatin1String("modules"));
    d->viewer->setMainQmlFile(QLatin1String("D:/open_source/PangimPreproducer/src/PangimPreproducer/Gui/qml/PangimGui/main.qml"));
    d->viewer->showMaximized();
}

void Gui::registerObjectToQML(const QString &name, QObject *object)
{
    if (!d->viewer)
        return;

    d->viewer->rootContext()->setContextProperty(name, object);
    d->contextPropertyNameObjectHash.insert(name, object);
}

void Gui::registerValueToQML(const QString &name, const QVariant &value)
{
    if(!d->viewer)
        return;

    d->viewer->rootContext()->setContextProperty(name, value);
    d->contextPropertyNameValueHash.insert(name, value);
}
