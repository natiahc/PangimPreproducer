#ifndef GUI_H
#define GUI_H

#include "gui_global.h"

#include <QObject>

namespace Pangim
{

class IQtQuick2ApplicationViewer;

}

struct GuiData;
class QtQuick2ApplicationViewer;

class GUI_SHARED_EXPORT Gui : public QObject
{
    Q_OBJECT

public:
    static Gui& instance();
    ~Gui();

    Pangim::IQtQuick2ApplicationViewer* qmlViewer() const;

    Q_INVOKABLE QtQuick2ApplicationViewer* createQmlViewer();
    Q_INVOKABLE QtQuick2ApplicationViewer* createQmlViewer(QtQuick2ApplicationViewer* parent);

    void setFontFamily(const QString& family);
    QString fontFamily() const;

    void setFontWeight(int weight);
    int fontWeight() const;

    void showUserInterface();
    void registerObjectToQML(const QString& name, QObject* object);
    void registerValueToQML(const QString& name, const QVariant& value);

protected:
    Gui();

private:
    GuiData *d;

};

#endif // GUI_H
