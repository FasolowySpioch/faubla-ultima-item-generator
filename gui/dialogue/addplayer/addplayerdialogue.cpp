#include "addplayerdialogue.h"
#include "ui_addplayerdialogue.h"

#include <QMessageBox>
//#include <iostream>

AddPlayerDialogue::AddPlayerDialogue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPlayerDialogue)
{
    ui->setupUi(this);

    ui->comboBoxAttribute1->addItem("NONE", static_cast<int>(Attribute::NONE));
    ui->comboBoxAttribute1->addItem("WLP", static_cast<int>(Attribute::WLP));
    ui->comboBoxAttribute1->addItem("INS", static_cast<int>(Attribute::INS));
    ui->comboBoxAttribute1->addItem("DEX", static_cast<int>(Attribute::DEX));
    ui->comboBoxAttribute1->addItem("MIG", static_cast<int>(Attribute::MIG));

    ui->comboBoxAttribute2->addItem("NONE", static_cast<int>(Attribute::NONE));
    ui->comboBoxAttribute2->addItem("WLP", static_cast<int>(Attribute::WLP));
    ui->comboBoxAttribute2->addItem("INS", static_cast<int>(Attribute::INS));
    ui->comboBoxAttribute2->addItem("DEX", static_cast<int>(Attribute::DEX));
    ui->comboBoxAttribute2->addItem("MIG", static_cast<int>(Attribute::MIG));

    ui->comboBoxPreff->addItem("BRAK", static_cast<int>(WeaponType::NONE));
    ui->comboBoxPreff->addItem("Magiczna", static_cast<int>(WeaponType::ARCANE));
    ui->comboBoxPreff->addItem("Łuk", static_cast<int>(WeaponType::BOW));
    ui->comboBoxPreff->addItem("Pięści", static_cast<int>(WeaponType::BRAWL));
    ui->comboBoxPreff->addItem("Sztylet", static_cast<int>(WeaponType::DAGGER));
    ui->comboBoxPreff->addItem("Broń palna", static_cast<int>(WeaponType::FIREARM));
    ui->comboBoxPreff->addItem("Korbacz", static_cast<int>(WeaponType::FLAIL));
    ui->comboBoxPreff->addItem("Broń ciężka", static_cast<int>(WeaponType::HEAVY));
    ui->comboBoxPreff->addItem("Włócznia", static_cast<int>(WeaponType::SPEAR));
    ui->comboBoxPreff->addItem("Miecz", static_cast<int>(WeaponType::SWORD));
    ui->comboBoxPreff->addItem("Broń miotana", static_cast<int>(WeaponType::THROWN));


}

AddPlayerDialogue::~AddPlayerDialogue()
{
    delete ui;
}

//TODO: make it save characters in vector => overall players will be in vector... I think
void AddPlayerDialogue::on_BttnNextPlayer_clicked()
{
    Player p;
    setPlayerAdd(&p);
    if(!p.getCharacterName().empty()) playerList.append(p);
}

void AddPlayerDialogue::setPlayerAdd(Player* p){
    if((ui->textEditAuthor->toPlainText()).isEmpty() || (ui->textEditName->toPlainText()).isEmpty()){
        QMessageBox::warning(this, "Błąd", "Wpisz imię postaci oraz jej autora!");
        return;
    }
    p->setAuthorName((ui->textEditAuthor->toPlainText()).toStdString());
    p->setCharacterName((ui->textEditName->toPlainText()).toStdString());
    p->setLevel(ui->spinBoxLvL->value());
    p->setPrimaryDie1(static_cast<Attribute>(ui->comboBoxAttribute1->currentData().toInt()));
    p->setPrimaryDie2(static_cast<Attribute>(ui->comboBoxAttribute2->currentData().toInt()));
    p->setPreferredWeaponType(static_cast<WeaponType>(ui->comboBoxPreff->currentData().toInt()));
    p->setCanMartialWeapon(ui->checkBoxMartialWeapon->isChecked());
    p->setCanMartialArmor(ui->checkBoxMartialArmor->isChecked());
    p->setCanRange(ui->checkBoxRange->isChecked());
    p->setCanShield(ui->checkBoxShield->isChecked());

    ui->textEditAuthor->clear();
    ui->textEditName->clear();
    ui->spinBoxLvL->setValue(ui->spinBoxLvL->minimum());

    if(ui->comboBoxAttribute1->findData(static_cast<int>(Attribute::NONE)) != -1){
        ui->comboBoxAttribute1->setCurrentIndex(static_cast<int>(Attribute::NONE));
    }

    if(ui->comboBoxAttribute2->findData(static_cast<int>(Attribute::NONE)) != -1){
        ui->comboBoxAttribute2->setCurrentIndex(static_cast<int>(Attribute::NONE));
    }

    if (ui->comboBoxPreff->findData(static_cast<int>(WeaponType::NONE)) != -1) {
        ui->comboBoxPreff->setCurrentIndex(static_cast<int>(WeaponType::NONE));
    }


    ui->checkBoxMartialWeapon->setChecked(false);
    ui->checkBoxMartialArmor->setChecked(false);
    ui->checkBoxRange->setChecked(false);
    ui->checkBoxShield->setChecked(false);
}

void AddPlayerDialogue::accept(){
    Player p;
    setPlayerAdd(&p);
    if(!p.getAuthorName().empty()) { playerList.append(p); QDialog::accept(); }
    return;
}


QList<Player> AddPlayerDialogue::getPlayers() const { return playerList; }
