#ifndef ADDPLAYERDIALOGUE_H
#define ADDPLAYERDIALOGUE_H

#include <QDialog>
#include "../../../src/models/Player.h"

namespace Ui {
class AddPlayerDialogue;
}

class AddPlayerDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerDialogue(QWidget *parent = nullptr);
    ~AddPlayerDialogue();
    QList<Player> getPlayers() const;

    void accept();

private slots:
    void on_BttnNextPlayer_clicked();
private:
    Ui::AddPlayerDialogue *ui;
    QList<Player> playerList;
    void setPlayerAdd(Player* p);

};

#endif // ADDPLAYERDIALOGUE_H
