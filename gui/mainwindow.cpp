#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogue/addplayer/addplayerdialogue.h"
#include "dialogue/itemgen/itemgendialogue.h"
#include "dialogue/editplayer/editplayerdialogue.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _item_model(_appcontrol.getItemsRepository())
{
    ui->setupUi(this);
    // ui->TableGeneratedItems->setModel(_item_model);
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
    EditPlayerDialogue epd(this);
    if(epd.exec() == QDialog::Accepted){
        //TODO: Check if players were modified, if yes check index in campain
    }
}


void MainWindow::on_BttnAddPlayers_clicked()
{
    AddPlayerDialogue apd(this);
    if(apd.exec() == QDialog::Accepted){
        //TODO: Grab players to vector
    }
}

// -- Campain functions
//TODO: comeback after a commit with functions
void MainWindow::on_BttnLoadCampain_clicked()
{

}


void MainWindow::on_BttnSaveCampain_clicked()
{

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

