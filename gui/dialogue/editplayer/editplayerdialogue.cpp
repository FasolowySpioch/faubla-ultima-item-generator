#include "editplayerdialogue.h"
#include "ui_editplayerdialogue.h"

EditPlayerDialogue::EditPlayerDialogue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPlayerDialogue)
{
    ui->setupUi(this);
}

EditPlayerDialogue::~EditPlayerDialogue()
{
    delete ui;
}


//TODO: Accualy make it change things in the form
void EditPlayerDialogue::on_BttnConfirmSelection_clicked()
{

}

