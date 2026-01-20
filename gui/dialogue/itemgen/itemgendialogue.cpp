#include "itemgendialogue.h"
#include "ui_itemgendialogue.h"

ItemGenDialogue::ItemGenDialogue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemGenDialogue)
{
    ui->setupUi(this);
}

ItemGenDialogue::~ItemGenDialogue()
{
    delete ui;
}

void ItemGenDialogue::on_BttnQuickGenerate_clicked()
{

}

