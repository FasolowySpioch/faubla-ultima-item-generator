#include "itemgendialogue.h"
#include "ui_itemgendialogue.h"

<<<<<<< HEAD
ItemGenDialogue::ItemGenDialogue(const std::vector<std::unique_ptr<Player>> &_players, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemGenDialogue)
    , players(_players)
=======
ItemGenDialogue::ItemGenDialogue(std::vector<Player>& players, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemGenDialogue), players(players)
>>>>>>> 231168f40ea90e510cf1cec36e588c4912b31546
{
    ui->setupUi(this);

    //Main setup foe ItemGeneratorDialog:
    setLayoutVisible(false, ui->LayoutAccessory);
    setLayoutVisible(false, ui->LayoutArmor);
    setLayoutVisible(false, ui->LayoutWeapon);
    setLayoutVisible(false, ui->LayoutComboboxDmgType);
}

ItemGenDialogue::~ItemGenDialogue()
{
    delete ui;
}

void ItemGenDialogue::on_BttnQuickGenerate_clicked()
{

}

void ItemGenDialogue::setLayoutVisible(bool visible, QLayout* l){
    if (!l) return;
    for (int i = 0; i < l->count(); ++i) {
        auto item = l->itemAt(i);
        if (auto widgetItem = dynamic_cast<QWidgetItem*>(item)) {
            if (widgetItem->widget())
                widgetItem->widget()->setVisible(visible);
        }
    }
}
