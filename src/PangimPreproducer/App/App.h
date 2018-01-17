#ifndef APP_H
#define APP_H

#include "pangim_preproducer_global.h"

#include <QObject>

class PANGIM_PREPRODUCER_SHARED_EXPORT App : public QObject
{
    Q_OBJECT

public:
    static App & instance();
    ~App();

    void launchGUI();

protected:
    App();

signals:

public slots:
};

#endif // APP_H
