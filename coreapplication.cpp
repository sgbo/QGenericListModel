#include <QDebug>
#include <QQmlContext>
#include <QTimer>
#include "coreapplication.h"
#include "genericlistmodel.h"
#include "listitem.h"

CoreApplication::CoreApplication(QQmlContext *context)
{
    m_ticks = 0;
    m_listModel = new GenericListModel<ListItem>(this);
    context->setContextProperty("listModel", m_listModel);

    ListItem *item = NULL;
    for (int i = 0; i < 10; i++) {
        item = new ListItem(this);
        item->setName(QString("%1").arg(i));
        m_listModel->append(item);
    }

    m_timer = new QTimer(this);
    m_timer->start(1000);
    connect(m_timer, &QTimer::timeout, this, &CoreApplication::update);
    update();
}

void CoreApplication::update()
{
    for (int i = 0; i < m_listModel->rowCount(); i++) {
        m_listModel->at(i)->setId(i + m_ticks);
    }

    m_ticks++;
}

