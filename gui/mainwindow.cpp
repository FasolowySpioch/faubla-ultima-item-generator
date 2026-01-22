#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogue/addplayer/addplayerdialogue.h"
#include "dialogue/itemgen/itemgendialogue.h"
#include "dialogue/editplayer/editplayerdialogue.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _item_model(new MyItemTableModel(&_appcontrol.getItemsRepository(), parent))
    , _player_model(new MyPlayerTableModel(&_appcontrol.getPlayersRepository(), parent))
{
    ui->setupUi(this);
    ui->TableGeneratedItems->setModel(_item_model);
    ui->TablePlayers->setModel(_player_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// === BUTTON ON CLICK SLOTS ===

// -- Player functions
void MainWindow::on_BttnEditPlayers_clicked()
{
    EditPlayerDialogue epd(_appcontrol.getPlayersRepository(),this);
    connect(&epd, &EditPlayerDialogue::removePlayerRequest, this, &MainWindow::on_removePlayer);

    if(epd.exec() == QDialog::Accepted){
        Player p = epd.getPlayer();
        int index = epd.getIndex();
        _appcontrol.editPlayer(index, std::make_unique<Player>(p));
    }

    updateUIState();
}


void MainWindow::on_BttnAddPlayers_clicked()
{
    AddPlayerDialogue apd(this);
    if(apd.exec() == QDialog::Accepted){
        QList<Player> list = apd.getPlayers();
        for(int i = 0; list.size() > i; i++){
            _appcontrol.savePlayer(std::make_unique<Player>(list.at(i)));
        }
        _player_model->refresh();
    }

    updateUIState();
}

// -- Campaign functions
void MainWindow::on_BttnLoadCampain_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Wybierz plik",
        QDir::homePath(),
        "*.json"
        );

    if (_appcontrol.loadCampaign(fileName))
    {
        _loadedFile = fileName;
        updateUIState();
    }

    _item_model->refresh();
    _player_model->refresh();
}


void MainWindow::on_BttnSaveCampain_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        QDir::homePath(),
        "kampania.json",
        "*.json"
        );
    if(!fileName.endsWith(".json", Qt::CaseInsensitive)) fileName += ".json";

    if (_appcontrol.saveCampaign(fileName))
    {
        if(!fileName.isEmpty()) _loadedFile = fileName;
    }
}

// -- Generate functions
void MainWindow::on_BttnQuickGenerate_clicked()
{
    std::unique_ptr<Item> item = _appcontrol.generateItemForRandomPlayer();
    if (!item)
        return;

    _appcontrol.saveItem(std::move(item));
    _item_model->refresh();
}


void MainWindow::on_BttnNormalGenerate_clicked()
{
    ItemGenDialogue idg(&_appcontrol, this);
    if(idg.exec() == QDialog::Accepted){

     _item_model->refresh();
    }
}

void MainWindow::on_BttnNewCampain_clicked()
{
    const QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                                    "Wyczyść kampanię",
                                                                    "Czy na pewno chcesz wyczyścić całą kampanię?",
                                                                    QMessageBox::Ok | QMessageBox::Cancel);

    if (reply == QMessageBox::Ok)
    {
        _appcontrol.clearRepository();
        _item_model->refresh();
        _player_model->refresh();
        updateUIState();
    }
}

void MainWindow::on_removePlayer(int index){
    _appcontrol.removePlayer(index);
    _player_model->refresh();
}

void MainWindow::updateUIState() const
{
    const bool hasPlayers = !_appcontrol.getPlayersRepository().empty();
    ui->BttnEditPlayers->setEnabled(hasPlayers);
    ui->BttnQuickGenerate->setEnabled(hasPlayers);
    ui->BttnNormalGenerate->setEnabled(hasPlayers);
}

void MainWindow::on_TableGeneratedItems_doubleClicked(const QModelIndex &index)
{
    QMessageBox::StandardButton message = QMessageBox::warning(this, "Usuń przedmiot", "Czy na pewno chcesz usunąć przedmiot?", QMessageBox::Ok | QMessageBox::Cancel);
    if(message == QMessageBox::Ok){
        int row = index.row();
        int repoSize = _appcontrol.getItemsRepository().size();
        int realIndex = repoSize - 1 - row;
        _appcontrol.removeItem(static_cast<size_t>(realIndex));

        _item_model->refresh();
    }
}

