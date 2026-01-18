#ifndef ADDPLAYERDIALOGUE_H
#define ADDPLAYERDIALOGUE_H

#include <QDialog>

namespace Ui {
class AddPlayerDialogue;
}

class AddPlayerDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerDialogue(QWidget *parent = nullptr);
    ~AddPlayerDialogue();

private slots:
    void on_BttnNextPlayer_clicked();

private:
    Ui::AddPlayerDialogue *ui;
};

#endif // ADDPLAYERDIALOGUE_H
