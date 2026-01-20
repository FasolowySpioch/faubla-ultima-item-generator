#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    EditPlayerDialogue epd(this);
    if(epd.exec() == QDialog::Accepted){
        //TODO: Check if players were modified, if yes check index in campain
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

}


void MainWindow::on_BttnSaveCampain_clicked()
{

}

// -- Generate functions
void MainWindow::on_BttnQuickGenerate_clicked()
{
    //_appcontrol.generateItemForRandomPlayer();
}


void MainWindow::on_BttnNormalGenerate_clicked()
{
    ItemGenDialogue idg(this);
    if(idg.exec() == QDialog::Accepted){

    }
}

