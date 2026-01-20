#ifndef ITEMGENDIALOGUE_H
#define ITEMGENDIALOGUE_H

#include "../../../src/models/Player.h"
#include <QDialog>
#include "../../../src/models/Player.h"

namespace Ui {
class ItemGenDialogue;
}

class ItemGenDialogue : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit ItemGenDialogue(const std::vector<std::unique_ptr<Player>> &_players, QWidget *parent = nullptr);
=======
    explicit ItemGenDialogue(std::vector<Player>& players, QWidget *parent = nullptr);
>>>>>>> 231168f40ea90e510cf1cec36e588c4912b31546
    ~ItemGenDialogue();

private slots:
    void on_BttnQuickGenerate_clicked();

private:
    Ui::ItemGenDialogue *ui;
<<<<<<< HEAD
    const std::vector<std::unique_ptr<Player>> &players;
=======
    void setLayoutVisible(bool visible, QLayout* l);
    std::vector<Player>& players;
>>>>>>> 231168f40ea90e510cf1cec36e588c4912b31546
};

#endif // ITEMGENDIALOGUE_H
