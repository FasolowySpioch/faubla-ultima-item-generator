#ifndef EDITPLAYERDIALOGUE_H
#define EDITPLAYERDIALOGUE_H

#include <QDialog>

namespace Ui {
class EditPlayerDialogue;
}

class EditPlayerDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit EditPlayerDialogue(QWidget *parent = nullptr);
    ~EditPlayerDialogue();

private slots:
    void on_BttnConfirmSelection_clicked();

private:
    Ui::EditPlayerDialogue *ui;
};

#endif // EDITPLAYERDIALOGUE_H
