#ifndef EDITPLAYERDIALOGUE_H
#define EDITPLAYERDIALOGUE_H

#include <QDialog>
#include "../../../src/models/Player.h"

namespace Ui {
class EditPlayerDialogue;
}

class EditPlayerDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit EditPlayerDialogue(const std::vector<std::unique_ptr<Player>>& players,QWidget *parent = nullptr);
    ~EditPlayerDialogue() override;

    Player getPlayer();
    int getIndex();

signals:
    void removePlayerRequest(int index);

private slots:
    void on_BttnDelPlayer_clicked();
    void on_ComboBoxSelectPlayer_currentIndexChanged(int index);

private:
    Ui::EditPlayerDialogue *ui;
    const std::vector<std::unique_ptr<Player>>& players;

    void refreshPlayerList();
};
#endif // EDITPLAYERDIALOGUE_H
