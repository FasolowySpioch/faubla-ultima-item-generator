#include "MyPlayerTableModel.h"
#include "../../src/converters/AttributeConverter.h"
#include "../../src/converters/WeaponTypeConverter.h"


MyPlayerTableModel::MyPlayerTableModel(const std::vector<std::unique_ptr<Player>> *_container, QObject *parent)
    : QAbstractTableModel(parent)
    , container(_container)
{
}

void MyPlayerTableModel::refresh()
{
    beginResetModel();
    endResetModel();
}

void MyPlayerTableModel::startEditing()
{
    beginResetModel();
}

void MyPlayerTableModel::endEditing()
{
    endResetModel();
}


int MyPlayerTableModel::rowCount(const QModelIndex &parent) const
{
    if (!container) return 0;
    return static_cast<int>(container->size());
}

int MyPlayerTableModel::columnCount(const QModelIndex &parent) const
{
    if (!container) return 0;
    return 6;
}

QVariant MyPlayerTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(container->size()))
        return {};

    const Player *object = container->at(container->size() - index.row() - 1).get();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0:
                return QString::fromStdString(object->getCharacterName());
            case 1:
                return QString::number(object->getLevel());
            case 2:
                return AttributeConverter::toQString(object->getPrimaryDie1());
            case 3:
                return AttributeConverter::toQString(object->getPrimaryDie2());
            case 4:
                return WeaponTypeConverter::toQString(object->getPreferredWeaponType());
            case 5:
                return QString::fromStdString(object->getAuthorName());
            default:
                return {};
        }
    }

    return {};
}

QVariant MyPlayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
            case 0:
                return "Name";
            case 1:
                return "Level";
            case 2:
                return "Attr 1";
            case 3:
                return "Attr 2";
            case 4:
                return "PrefWeapon";
            case 5:
                return "Author";
            default:
                return {};
        }
    }
    return {};
}
