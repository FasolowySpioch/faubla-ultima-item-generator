#ifndef ITEMGENDIALOGUE_H
#define ITEMGENDIALOGUE_H

#include <QDialog>
#include "../../../src/models/Player.h"

namespace Ui {
class ItemGenDialogue;
}

class ItemGenDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit ItemGenDialogue(const std::vector<std::unique_ptr<Player>>& players, QWidget *parent = nullptr);
    ~ItemGenDialogue();

private slots:
    void on_BttnQuickGenerate_clicked();

private:
    Ui::ItemGenDialogue *ui;
    void setLayoutVisible(bool visible, QLayout* l);
    const std::vector<std::unique_ptr<Player>>& players;
};

#endif // ITEMGENDIALOGUE_H
