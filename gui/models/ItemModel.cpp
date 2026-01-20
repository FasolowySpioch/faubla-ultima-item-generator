#include "ItemModel.h"
#include "../../src/converters/ItemTypeConverter.h"

ItemModel::ItemModel(const std::vector<std::unique_ptr<Item>> &_items, QObject *parent)
    : QAbstractTableModel(parent)
    , items(_items)
{
}


int ItemModel::rowCount(const QModelIndex &parent) const
{
    return static_cast<int>(items.size());
}

int ItemModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant ItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(items.size()))
        return {};

    const Item *object = items.at(index.row()).get();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0:
                return ItemTypeConverter::toQString(object->getItemType());
            case 1:
                return QString::fromStdString(object->getName());
            case 2:
                return QString::number(object->getPrice());
            case 3:
                return QString::fromStdString(object->getDesc());
            default:
                return {};
        }
    }

    return {};
}

QVariant ItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
            case 0:
                return "Type";
            case 1:
                return "Name";
            case 2:
                return "Price";
            case 3:
                return "Description";
            default:
                return {};
        }
    }
}
