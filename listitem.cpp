#include "listitem.h"

ListItem::ListItem(QObject *parent) : QObject(parent)
{

}

QString ListItem::name() const
{
    return m_name;
}

void ListItem::setName(const QString &name)
{
    if (m_name != name){
        m_name = name;
        emit nameChanged(name);
    }
}

int ListItem::id() const
{
    return m_id;
}

void ListItem::setId(int id)
{
    if (m_id != id) {
        m_id = id;
        emit idChanged(id);
    }
}

