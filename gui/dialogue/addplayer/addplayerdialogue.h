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
    ~AddPlayerDialogue() override;
    QList<Player> getPlayers() const;
    void accept() override;

private slots:
    void on_BttnNextPlayer_clicked();

private:
    Ui::AddPlayerDialogue *ui;
    QList<Player> playerList;
    bool validateAndSet(Player* p);
    void clearForm() const;
};

#endif // ADDPLAYERDIALOGUE_H
