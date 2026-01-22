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

    on_ComboBoxSelectPlayer_currentIndexChanged(0);
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
    ui->TxtEditAuthor->text() = QString::fromStdString(players.at(index)->getAuthorName());
    ui->TxtEditCharName->text() = QString::fromStdString(players.at(index)->getCharacterName());
    ui->SpinBoxLvl->setValue(players.at(index)->getLevel());

    int idx1 = ui->ComboBoxAttributes->findData(
        static_cast<int>(players.at(index)->getPrimaryDie1())
        );
    if (idx1 != -1)
        ui->ComboBoxAttributes->setCurrentIndex(idx1);

    int idx2 = ui->ComboboxAttributres2->findData(
        static_cast<int>(players.at(index)->getPrimaryDie2())
        );
    if (idx2 != -1)
        ui->ComboboxAttributres2->setCurrentIndex(idx2);

    int idxW = ui->ComboBoxWeaponPreference->findData(
        static_cast<int>(players.at(index)->getPreferredWeaponType())
        );
    if (idxW != -1)
        ui->ComboBoxWeaponPreference->setCurrentIndex(idxW);


    ui->CheckBoxMartialWeapon->setChecked(players.at(index)->getCanMartialWeapon());
    ui->CheckBoxMartialArmor->setChecked(players.at(index)->getCanMartialArmor());
    ui->CheckBoxRange->setChecked(players.at(index)->getCanRange());
    ui->CheckBoxShield->setChecked(players.at(index)->getCanShield());
}

Player EditPlayerDialogue::getPlayer(){
    Player p;
    p.setAuthorName((ui->TxtEditAuthor->text()).toStdString());
    p.setCharacterName((ui->TxtEditCharName->text()).toStdString());
    p.setLevel(ui->SpinBoxLvl->value());
    p.setPrimaryDie1(static_cast<Attribute>(ui->ComboBoxAttributes->currentData().toInt()));
    p.setPrimaryDie2(static_cast<Attribute>(ui->ComboboxAttributres2->currentData().toInt()));
    p.setPreferredWeaponType(static_cast<WeaponType>(ui->ComboBoxWeaponPreference->currentData().toInt()));
    p.setCanMartialWeapon(ui->CheckBoxMartialWeapon->isChecked());
    p.setCanMartialArmor(ui->CheckBoxMartialArmor->isChecked());
    p.setCanRange(ui->CheckBoxRange->isChecked());
    p.setCanShield(ui->CheckBoxShield->isChecked());

    return p;
}

int EditPlayerDialogue::getIndex(){
    return ui->ComboBoxSelectPlayer->currentIndex();
}

void EditPlayerDialogue::refreshPlayerList()
{
    ui->ComboBoxSelectPlayer->blockSignals(true);
    ui->ComboBoxSelectPlayer->clear();

    for(int i = 0; i < players.size(); i++){
        ui->ComboBoxSelectPlayer->addItem(QString::fromStdString(players.at(i)->getCharacterName()), i);
    }
    ui->ComboBoxSelectPlayer->blockSignals(false);
}
