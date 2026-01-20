#include "itemgendialogue.h"
#include "ui_itemgendialogue.h"

ItemGenDialogue::ItemGenDialogue(const std::vector<std::unique_ptr<Player>> &_players, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemGenDialogue)
    , players(_players)
{
    ui->setupUi(this);
}

ItemGenDialogue::~ItemGenDialogue()
{
    delete ui;
}
