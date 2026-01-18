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
