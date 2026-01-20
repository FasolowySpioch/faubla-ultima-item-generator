#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include "../src/controllers/AppController.h"
#include "models/ItemModel.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BttnEditPlayers_clicked();
    void on_BttnAddPlayers_clicked();
    void on_BttnLoadCampain_clicked();
    void on_BttnSaveCampain_clicked();
    void on_BttnQuickGenerate_clicked();
    void on_BttnNormalGenerate_clicked();

    void on_BttnDelCampain_clicked();

private:
    Ui::MainWindow *ui;
    AppController _appcontrol;
    ItemModel _item_model;
    QString _loadedFile = "";
    void removePlayer(int index);

    void clearControls();

};
#endif // MAINWINDOW_H
