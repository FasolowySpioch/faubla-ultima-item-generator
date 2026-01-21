#include "MyItemTableModel.h"
#include "../../src/converters/ItemTypeConverter.h"


MyItemTableModel::MyItemTableModel(const std::vector<std::unique_ptr<Item>> *_container, QObject *parent)
    : QAbstractTableModel(parent)
    , container(_container)
{
}


void MyItemTableModel::refresh()
{
    beginResetModel();
    endResetModel();
}

void MyItemTableModel::startEditing()
{
    beginResetModel();
}

void MyItemTableModel::endEditing()
{
    endResetModel();
}


int MyItemTableModel::rowCount(const QModelIndex &parent) const
{
    if (!container) return 0;
    return static_cast<int>(container->size());
}

int MyItemTableModel::columnCount(const QModelIndex &parent) const
{
    if (!container) return 0;
    return 4;
}

QVariant MyItemTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(container->size()))
        return {};

    const Item *object = container->at(container->size() - index.row() - 1).get();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0:
                return ItemTypeConverter::toQString(object->getItemType());
            case 1:
                return QString::fromStdString(object->getName());
            case 2:
                return QString::number(object->getPriceModified());
            case 3:
                return QString::fromStdString(object->getDesc());
            default:
                return {};
        }
    }

    return {};
}

QVariant MyItemTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
    return {};
}
