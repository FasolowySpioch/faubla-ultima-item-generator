#include "itemgendialogue.h"
#include "ui_itemgendialogue.h"

ItemGenDialogue::ItemGenDialogue(const std::vector<std::unique_ptr<Player>>& players, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemGenDialogue), players(players)
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
