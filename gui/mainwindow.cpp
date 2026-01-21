#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogue/addplayer/addplayerdialogue.h"
#include "dialogue/itemgen/itemgendialogue.h"
#include "dialogue/editplayer/editplayerdialogue.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _item_model(_appcontrol.getItemsRepository())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// === BUTTON ON CLICK FUNCTIONS ===

// -- Player functions
void MainWindow::on_BttnEditPlayers_clicked()
{

    //testting if dialouge works for now:
    EditPlayerDialogue epd(_appcontrol.getPlayersRepository(),this);
    connect(&epd, &EditPlayerDialogue::removePlayerRequest, this, &MainWindow::removePlayer);
    if(epd.exec() == QDialog::Accepted){
        Player p = epd.getPlayer();
        int index = epd.getIndex();
        _appcontrol.editPlayer(index, std::make_unique<Player>(p));
    }
}


void MainWindow::on_BttnAddPlayers_clicked()
{
    AddPlayerDialogue apd(this);
    if(apd.exec() == QDialog::Accepted){
        QList<Player> list = apd.getPlayers();
        for(int i = 0; list.size() > i; i++){
            _appcontrol.savePlayer(std::make_unique<Player>(list.at(i)));
        }
    }

    if(apd.getPlayers().size() > 0){
        ui->BttnEditPlayers->setEnabled(true);
        ui->BttnQuickGenerate->setEnabled(true);
        ui->BttnNormalGenerate->setEnabled(true);
        ui->BttnSaveCampain->setEnabled(true);
        ui->BttnDelCampain->setEnabled(true);
    }
}

// -- Campain functions
//TODO: comeback after a commit with functions
void MainWindow::on_BttnLoadCampain_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Wybierz plik",
        QDir::homePath(),
        "*.json"
        );
    if(!fileName.isEmpty()){
        _appcontrol.loadCampaign(fileName);
        _loadedFile = fileName;

        ui->BttnEditPlayers->setEnabled(true);
        ui->BttnQuickGenerate->setEnabled(true);
        ui->BttnNormalGenerate->setEnabled(true);
        ui->BttnSaveCampain->setEnabled(true);
        ui->BttnDelCampain->setEnabled(true);
    }
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
    _appcontrol.saveCampaign(fileName);
    if(!fileName.isEmpty()) _loadedFile = fileName;
}

// -- Generate functions
void MainWindow::on_BttnQuickGenerate_clicked()
{
    std::unique_ptr<Item> item = _appcontrol.generateItemForRandomPlayer();
    if (!item)
        return;

    _appcontrol.saveItem(std::move(item));
}


void MainWindow::on_BttnNormalGenerate_clicked()
{
    ItemGenDialogue idg(_appcontrol.getPlayersRepository(), this);
    if(idg.exec() == QDialog::Accepted){

    }
}


void MainWindow::on_BttnDelCampain_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Wybierz plik",
        QDir::homePath(),
        "*.json"
        );
    _appcontrol.deleteCampaign(fileName);

    if(fileName == _loadedFile){
        clearControls();
    }
}

void MainWindow::clearControls() {
    //TODO: Finish this function
    //ui->TableGeneratedItems
}

void MainWindow::removePlayer(int index){
    _appcontrol.removePlayer(index);
}
