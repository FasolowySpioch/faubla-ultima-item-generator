#ifndef FULTIMA_GEN_MYTABLEPLAYERMODEL_H
#define FULTIMA_GEN_MYTABLEPLAYERMODEL_H

#include "../../src/models/Player.h"
#include <QAbstractTableModel>

class MyPlayerTableModel : public QAbstractTableModel
{
    const std::vector<std::unique_ptr<Player>> *container;

public:
    explicit MyPlayerTableModel(const std::vector<std::unique_ptr<Player>> *_container, QObject* parent = nullptr);

    void refresh();
    void startEditing();
    void endEditing();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};


#endif //FULTIMA_GEN_MYTABLEPLAYERMODEL_H