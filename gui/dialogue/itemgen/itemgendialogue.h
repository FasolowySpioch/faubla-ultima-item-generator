#ifndef ITEMGENDIALOGUE_H
#define ITEMGENDIALOGUE_H

#include "../../../src/models/Player.h"
#include <QDialog>

namespace Ui {
class ItemGenDialogue;
}

class ItemGenDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit ItemGenDialogue(const std::vector<std::unique_ptr<Player>> &_players, QWidget *parent = nullptr);
    ~ItemGenDialogue();

private:
    Ui::ItemGenDialogue *ui;
    const std::vector<std::unique_ptr<Player>> &players;
};

#endif // ITEMGENDIALOGUE_H
