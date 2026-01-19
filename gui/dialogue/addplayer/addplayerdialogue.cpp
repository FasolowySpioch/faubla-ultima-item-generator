#include "addplayerdialogue.h"
#include "ui_addplayerdialogue.h"

AddPlayerDialogue::AddPlayerDialogue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPlayerDialogue)
{
    ui->setupUi(this);
}

AddPlayerDialogue::~AddPlayerDialogue()
{
    delete ui;
}

//TODO: make it save characters in vector => overall players will be in vector... I think
void AddPlayerDialogue::on_BttnNextPlayer_clicked()
{

}

