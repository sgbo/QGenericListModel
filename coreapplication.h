#ifndef COREAPPLICATION_H
#define COREAPPLICATION_H

#include <QObject>
#include <QQmlContext>
#include <QTimer>
#include "genericlistmodel.h"
#include "listitem.h"

class CoreApplication : public QObject
{
    Q_OBJECT
public:
    explicit CoreApplication(QQmlContext *context);

    void update();

private:
    GenericListModel<ListItem> *m_listModel;

    QTimer *m_timer;
    int m_ticks;
};

#endif // COREAPPLICATION_H
