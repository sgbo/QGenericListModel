#ifndef GENERICLISTMODEL_H
#define GENERICLISTMODEL_H

#include <QAbstractListModel>
#include <QHash>

class GenericListModelData : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit GenericListModelData(QObject *parent);

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;

protected:
    void appendItem(QObject *item);
    QList<QObject *> m_itemList;

private Q_SLOTS:
    void onDataChanged();

private:
    QHash<int, int> m_propertySignalIndexHash;
};

template <typename T>
class GenericListModel : public GenericListModelData
{
public:
    explicit GenericListModel(QObject *parent) : GenericListModelData(parent) {

    }

    void append(T *item) {
        appendItem(item);
    }

    T *at(int i) {
        return qobject_cast<T *>(m_itemList.at(i));
    }
};

#endif // GENERICLISTMODEL_H
