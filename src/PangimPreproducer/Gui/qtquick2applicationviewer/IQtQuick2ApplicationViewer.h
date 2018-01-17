#ifndef IQTQUICK2APPLICATIONVIEWER_H
#define IQTQUICK2APPLICATIONVIEWER_H

#include <QtPlugin>

namespace Pangim
{

class IQtQuick2ApplicationViewer
{
public:
    virtual QObject* containerObject() = 0;

    virtual QObject* findObject(const QString& objectName) = 0;
};

}

Q_DECLARE_INTERFACE(Pangim::IQtQuick2ApplicationViewer, "com.Pangim.IQtQuick2ApplicationViewer/1.0")

#endif // IQTQUICK2APPLICATIONVIEWER_H
