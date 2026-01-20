#ifndef FULTIMA_GEN_ITEMMODEL_H
#define FULTIMA_GEN_ITEMMODEL_H

#include "../../src/models/Item.h"
#include <QAbstractTableModel>


class ItemModel : public QAbstractTableModel
{
    const std::vector<std::unique_ptr<Item>> &items;

public:
    explicit ItemModel(const std::vector<std::unique_ptr<Item>> &_items, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};


#endif //FULTIMA_GEN_ITEMMODEL_H