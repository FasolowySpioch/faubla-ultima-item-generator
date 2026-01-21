#include "itemgendialogue.h"
#include "ui_itemgendialogue.h"

ItemGenDialogue::ItemGenDialogue(AppController *apc, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemGenDialogue), _apc(apc)
{
    ui->setupUi(this);

    //Main setup foe ItemGeneratorDialog:
    setLayoutVisible(false, ui->LayoutAccessory);
    setLayoutVisible(false, ui->LayoutArmor);
    setLayoutVisible(false, ui->LayoutWeapon);
    setLayoutVisible(false, ui->LayoutComboboxDmgType);

    ui->comboBoxChoosePlayer->setCurrentIndex(-1);
    ui->comboBoxChoosePlayer->setPlaceholderText("--- WYBIERZ GRACZA --- ");

    for(int i = 0; i < _apc->getPlayersRepository().size(); i++){
        QString s = QString::fromStdString(_apc->getPlayersRepository().at(i)->getCharacterName());
        ui->comboBoxChoosePlayer->addItem(s, i);
    }

    ui->comboBoxDmgType->addItem("Fizyczne", static_cast<int>(DMGType::PHYSICAL));
    ui->comboBoxDmgType->addItem("Powietrze", static_cast<int>(DMGType::AIR));
    ui->comboBoxDmgType->addItem("Elektryczność", static_cast<int>(DMGType::BOLT));
    ui->comboBoxDmgType->addItem("Ziemia", static_cast<int>(DMGType::EARTH));
    ui->comboBoxDmgType->addItem("Ognien", static_cast<int>(DMGType::FIRE));
    ui->comboBoxDmgType->addItem("Lód", static_cast<int>(DMGType::ICE));
    ui->comboBoxDmgType->addItem("Mrok", static_cast<int>(DMGType::DARK));
    ui->comboBoxDmgType->addItem("Światło", static_cast<int>(DMGType::LIGHT));
    ui->comboBoxDmgType->addItem("Trucizna", static_cast<int>(DMGType::POISON));
}

ItemGenDialogue::~ItemGenDialogue()
{
    delete ui;
}

void ItemGenDialogue::on_BttnQuickGenerate_clicked()
{
    const Player p = *(_apc->getPlayersRepository().at(ui->comboBoxChoosePlayer->currentIndex()));
    _generatedItem = _apc->generateRandomItem(p);
    setLVItemDependent();
}

void ItemGenDialogue::on_bttnGenerateAccessory_clicked()
{
    const Player p = *(_apc->getPlayersRepository().at(ui->comboBoxChoosePlayer->currentIndex()));
    _generatedItem = _apc->generateItem(ItemType::ACCESSORY, p);
    setLVItemDependent();
}

void ItemGenDialogue::on_bttnGenerateArmor_clicked()
{
    const Player p = *(_apc->getPlayersRepository().at(ui->comboBoxChoosePlayer->currentIndex()));
    _generatedItem = _apc->generateItem(ItemType::ARMOR, p);
    setLVItemDependent();
}

void ItemGenDialogue::on_bttnGenerateWeapon_clicked()
{
    const Player p = *(_apc->getPlayersRepository().at(ui->comboBoxChoosePlayer->currentIndex()));
    _generatedItem = _apc->generateItem(ItemType::WEAPON, p);
    setLVItemDependent();
}

void ItemGenDialogue::on_BttnRerollQualityWeap_clicked()
{
    rerollQuality();
}

void ItemGenDialogue::on_bttnRerollQualityArm_clicked()
{
    rerollQuality();
}

void ItemGenDialogue::on_bttnRerollQualityAcc_clicked()
{
    rerollQuality();
}

void ItemGenDialogue::on_lineEditWName_editingFinished()
{

}


void ItemGenDialogue::on_lineEditNameArmor_editingFinished()
{

}


void ItemGenDialogue::on_lineEditAccName_editingFinished()
{

}

void ItemGenDialogue::on_comboBoxDmgType_currentIndexChanged(int index)
{
    if(physicalChanged == false){
        if(ui->comboBoxDmgType->itemData(index).toInt() != static_cast<int>(DMGType::PHYSICAL)){
            dynamic_cast<Weapon*>(_generatedItem.get())->setDmgType(static_cast<DMGType>(ui->comboBoxDmgType->itemData(index).toInt()));
            _generatedItem->addToPrice(100);
            physicalChanged=true;
            setLVItemDependent();
        }
    }
    else{
        if(ui->comboBoxDmgType->itemData(index).toInt() == static_cast<int>(DMGType::PHYSICAL)){
            dynamic_cast<Weapon*>(_generatedItem.get())->setDmgType(static_cast<DMGType>(ui->comboBoxDmgType->itemData(index).toInt()));
            _generatedItem->addToPrice(-100);
            physicalChanged=false;
            setLVItemDependent();
        }
    }
}

void ItemGenDialogue::on_comboBoxChoosePlayer_currentIndexChanged(int index)
{
    if(ui->comboBoxChoosePlayer->itemData(index).toInt()!=-1){
        ui->BttnQuickGenerate->setEnabled(true);
        ui->bttnGenerateAccessory->setEnabled(true);
        ui->bttnGenerateWeapon->setEnabled(true);
        ui->bttnGenerateArmor->setEnabled(true);
    }
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

void ItemGenDialogue::setLVItemDependent(){
    ItemType t = _generatedItem->getItemType();
    switch (t) {
    case ItemType::ARMOR:{
        Armor* genA = dynamic_cast<Armor*>(_generatedItem.get()); //<- Had to include armor for some wierd reason
        QString attributes[4] = {"WLP", "INS", "DEX", "MIG"};
        QString yesNo[2] = {"Nie", "Tak"};

        setLayoutVisible(true, ui->LayoutArmor);
        setLayoutVisible(false, ui->LayoutAccessory);
        setLayoutVisible(false, ui->LayoutWeapon);
        setLayoutVisible(false, ui->LayoutComboboxDmgType);

        ui->widget->setVisible(false);

        ui->lineEditNameArmor->setText(QString::fromStdString(_generatedItem->getName()));

        if(genA->getMagDefAtr()==Attribute::NONE){
            ui->labelDisplayMagicDef->setText(QString::number(genA->getMagDefBonus()));
            ui->labelDisplayMagicBonus->setText(QString::number(0));
        }
        else{
            ui->labelDisplayMagicDef->setText(attributes[static_cast<int>(genA->getMagDefAtr())]);
            ui->labelDisplayMagicBonus->setText(QString::number(genA->getMagDefBonus()));
        }
        if(genA->getDefAtr()==Attribute::NONE){
            ui->labelDisplayDefense->setText(QString::number(genA->getDefBonus()));
            ui->labelDisplayDefBonus ->setText(QString::number(0));
        }
        else{
            ui->labelDisplayDefense->setText(attributes[static_cast<int>(genA->getDefAtr())]);
            ui->labelDisplayDefBonus->setText(QString::number(genA->getDefBonus()));
        }

        ui->labelDisplayIniciative->setText(QString::number(genA->getInitiative()));
        ui->txtBrowserQuality->setText(QString::fromStdString(_generatedItem->getDesc()));
        ui->labelDisplayMartialArm->setText(yesNo[static_cast<int>(genA->getIsMartial())]);
        ui->labelDisplayShield->setText(yesNo[static_cast<int>(genA->getIsShield())]);
        ui->labelDisplayPriceA->setText(QString::number(_generatedItem->getPriceModified()));

        ui->comboBoxChoosePlayer->setDisabled(true);
        break;
    }
    case ItemType::WEAPON:{
        QString weapon_type[10] = {
            "Arkaniczna",
            "Łuk",
            "Bijatyka",
            "Sztylet",
            "Broń palna",
            "Korbacz",
            "Ciężka",
            "Włócznia",
            "Miecz",
            "Rzucana"
        };
        QString attributes[4] = {"WLP", "INS", "DEX", "MIG"};

        Weapon* genW = dynamic_cast<Weapon*>(_generatedItem.get());

        setLayoutVisible(true, ui->LayoutComboboxDmgType);
        setLayoutVisible(true, ui->LayoutWeapon);

        setLayoutVisible(false, ui->LayoutAccessory);
        setLayoutVisible(false, ui->LayoutArmor);
        ui->widget->setVisible(false);

        ui->lineEditWName->setText(QString::fromStdString(_generatedItem->getName()));
        ui->labelDisplayWeaponType->setText(weapon_type[static_cast<int>(genW->getWeaponType())]);

        QString accCheck = "[ " + attributes[static_cast<int>(genW->getAccuracy1())] + " + " + attributes[static_cast<int>(genW->getAccuracy2())] + " ]";

        ui->labelDisplayAccCheck->setText(accCheck);
        ui->labelDisplayAccBonus->setText(QString::number(genW->getAccuracyBonus()));
        ui->labelDisplayWDmgDesc->setText("[ HR + "+QString::number(genW->getDmgDesc())+" ]");

        int idx = ui->comboBoxDmgType->findData(static_cast<int>(genW->getDmgType()));
        if(idx != -1){ ui-> comboBoxDmgType->setCurrentIndex(idx); }

        ui->txtBrowserDisplayQualityW->setText(QString::fromStdString(_generatedItem->getDesc()));

        QString yesNo[2] = {"Nie", "Tak"};

        ui->labelDisplayOneHanded->setText(yesNo[static_cast<int>(genW->getIsSingleHanded())]);
        ui->labelDisplayRange->setText(yesNo[static_cast<int>(genW->getIsRange())]);
        ui->labelDisplayMartialW->setText(yesNo[static_cast<int>(genW->getIsMartial())]);
        ui->labelDisplayPriceW->setText(QString::number(_generatedItem->getPriceModified()));

        ui->comboBoxChoosePlayer->setDisabled(true);
        break;
    }
    default:{
        setLayoutVisible(true, ui->LayoutAccessory);
        setLayoutVisible(false, ui->LayoutArmor);
        setLayoutVisible(false, ui->LayoutWeapon);
        setLayoutVisible(false, ui->LayoutComboboxDmgType);
        ui->widget->setVisible(false);

        ui->lineEditAccName->setText(QString::fromStdString(_generatedItem->getName()));
        ui->textBrowserQualA->setText(QString::fromStdString(_generatedItem->getDesc()));
        ui->labelDisplayPriceAcc->setText(QString::number(_generatedItem->getPriceModified()));

        ui->comboBoxChoosePlayer->setDisabled(true);
        break;
    }
    }
    ui->widget->setVisible(false);
}

void ItemGenDialogue::rerollQuality() {
    _apc->rerollQuality(_generatedItem.get());
    setLVItemDependent();
}
