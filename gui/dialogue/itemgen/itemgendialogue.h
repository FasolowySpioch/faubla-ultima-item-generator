#ifndef ITEMGENDIALOGUE_H
#define ITEMGENDIALOGUE_H

#include <QDialog>

namespace Ui {
class ItemGenDialogue;
}

class ItemGenDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit ItemGenDialogue(QWidget *parent = nullptr);
    ~ItemGenDialogue();

private slots:
    void on_BttnQuickGenerate_clicked();

private:
    Ui::ItemGenDialogue *ui;
};

#endif // ITEMGENDIALOGUE_H
