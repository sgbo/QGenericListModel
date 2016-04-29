#ifndef LISTITEM_H
#define LISTITEM_H

#include <QObject>

class ListItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
public:
    explicit ListItem(QObject *parent);

    QString name() const;
    void setName(const QString &name);

    int id() const;
    void setId(int id);

Q_SIGNALS:
    void nameChanged(const QString &);
    void idChanged(int);

private:
    QString m_name;
    int m_id;
};

#endif // LISTITEM_H
