#include "editplayerdialogue.h"
#include "ui_editplayerdialogue.h"
#include <QMessageBox>

EditPlayerDialogue::EditPlayerDialogue(const std::vector<std::unique_ptr<Player>>& players, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPlayerDialogue), players(players)
{
    ui->setupUi(this);

    //ui->ComboBoxSelectPlayer->addItem("---WYBIERZ GRACZA---", 99);
    for(int i = 0; i < players.size(); i++){
        QString s = QString::fromStdString(players.at(i)->getCharacterName());
        ui->ComboBoxSelectPlayer->addItem(s, i);
    }

    ui->ComboBoxAttributes->addItem("NONE", static_cast<int>(Attribute::NONE));
    ui->ComboBoxAttributes->addItem("WLP", static_cast<int>(Attribute::WLP));
    ui->ComboBoxAttributes->addItem("INS", static_cast<int>(Attribute::INS));
    ui->ComboBoxAttributes->addItem("DEX", static_cast<int>(Attribute::DEX));
    ui->ComboBoxAttributes->addItem("MIG", static_cast<int>(Attribute::MIG));

    ui->ComboboxAttributres2->addItem("NONE", static_cast<int>(Attribute::NONE));
    ui->ComboboxAttributres2->addItem("WLP", static_cast<int>(Attribute::WLP));
    ui->ComboboxAttributres2->addItem("INS", static_cast<int>(Attribute::INS));
    ui->ComboboxAttributres2->addItem("DEX", static_cast<int>(Attribute::DEX));
    ui->ComboboxAttributres2->addItem("MIG", static_cast<int>(Attribute::MIG));

    ui->ComboBoxWeaponPreference->addItem("BRAK", static_cast<int>(WeaponType::NONE));
    ui->ComboBoxWeaponPreference->addItem("Magiczna", static_cast<int>(WeaponType::ARCANE));
    ui->ComboBoxWeaponPreference->addItem("Łuk", static_cast<int>(WeaponType::BOW));
    ui->ComboBoxWeaponPreference->addItem("Pięści", static_cast<int>(WeaponType::BRAWL));
    ui->ComboBoxWeaponPreference->addItem("Sztylet", static_cast<int>(WeaponType::DAGGER));
    ui->ComboBoxWeaponPreference->addItem("Broń palna", static_cast<int>(WeaponType::FIREARM));
    ui->ComboBoxWeaponPreference->addItem("Korbacz", static_cast<int>(WeaponType::FLAIL));
    ui->ComboBoxWeaponPreference->addItem("Broń ciężka", static_cast<int>(WeaponType::HEAVY));
    ui->ComboBoxWeaponPreference->addItem("Włócznia", static_cast<int>(WeaponType::SPEAR));
    ui->ComboBoxWeaponPreference->addItem("Miecz", static_cast<int>(WeaponType::SWORD));
    ui->ComboBoxWeaponPreference->addItem("Broń miotana", static_cast<int>(WeaponType::THROWN));
}

EditPlayerDialogue::~EditPlayerDialogue()
{
    delete ui;
}


void EditPlayerDialogue::on_BttnDelPlayer_clicked()
{
    if(players.size() > 1){
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Usunięcie postaci", "Czy na pewno chcesz usunąć postać?");
        if( reply == QMessageBox::Yes){
            emit removePlayerRequest(ui->ComboBoxSelectPlayer->currentIndex());

            ui->ComboBoxSelectPlayer->blockSignals(true);
            ui->ComboBoxSelectPlayer->clear();

            for(int i = 0; i < players.size(); i++){
                QString s = QString::fromStdString(players.at(i)->getCharacterName());
                ui->ComboBoxSelectPlayer->addItem(s, i);
            }

            ui->ComboBoxSelectPlayer->blockSignals(false);
            on_ComboBoxSelectPlayer_currentIndexChanged(0);
        }
    }
    else QMessageBox::warning(this, "Uwaga", "Nie można usunąć jedynej postaci.");
}


void EditPlayerDialogue::on_ComboBoxSelectPlayer_currentIndexChanged(int index)
{
    ui->TxtEditAuthor->setPlainText(QString::fromStdString(players.at(index)->getAuthorName()));
    ui->TxtEditCharName->setPlainText(QString::fromStdString(players.at(index)->getCharacterName()));
    ui->SpinBoxLvl->setValue(players.at(index)->getLevel());

    if(ui->ComboBoxAttributes->findData(static_cast<int>(players.at(index)->getPrimaryDie1()))){
        ui->ComboBoxAttributes->setCurrentIndex(static_cast<int>(players.at(index)->getPrimaryDie1()));
    }
    if(ui->ComboboxAttributres2->findData(static_cast<int>(players.at(index)->getPrimaryDie2()))){
        ui->ComboboxAttributres2->setCurrentIndex(static_cast<int>(players.at(index)->getPrimaryDie2()));
    }
    if(ui->ComboBoxWeaponPreference->findData(static_cast<int>(players.at(index)->getPreferredWeaponType()))){
        ui->ComboBoxWeaponPreference->setCurrentIndex(static_cast<int>(players.at(index)->getPreferredWeaponType()));
    }

    ui->CheckBoxMartialWeapon->setChecked(players.at(index)->getCanMartialWeapon());
    ui->CheckBoxMartialArmor->setChecked(players.at(index)->getCanMartialArmor());
    ui->CheckBoxRange->setChecked(players.at(index)->getCanRange());
    ui->CheckBoxShield->setChecked(players.at(index)->getCanShield());
}

