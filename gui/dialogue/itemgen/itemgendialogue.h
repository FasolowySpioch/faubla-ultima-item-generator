#ifndef ITEMGENDIALOGUE_H
#define ITEMGENDIALOGUE_H

#include <QDialog>
#include "../../../../src/controllers/AppController.h"
#include "../../../../src/models/Armor.h"

namespace Ui {
class ItemGenDialogue;
}

class ItemGenDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit ItemGenDialogue(AppController *apc, QWidget *parent = nullptr);
    ~ItemGenDialogue();


private slots:
    void on_BttnQuickGenerate_clicked();
    void on_comboBoxChoosePlayer_currentIndexChanged(int index);
    void on_bttnGenerateAccessory_clicked();
    void on_bttnGenerateArmor_clicked();
    void on_bttnGenerateWeapon_clicked();
    void on_BttnRerollQualityWeap_clicked();
    void on_bttnRerollQualityArm_clicked();
    void on_bttnRerollQualityAcc_clicked();
    void on_comboBoxDmgType_currentIndexChanged(int index);
    void on_lineEditWName_editingFinished();
    void on_lineEditNameArmor_editingFinished();
    void on_lineEditAccName_editingFinished();

    void on_buttonBox_accepted();

private:
    Ui::ItemGenDialogue *ui;
    AppController * _apc;
    std::unique_ptr<Item> _generatedItem;
    bool physicalChanged = false;

    void setLayoutVisible(bool visible, QLayout* l);
    void setLVItemDependent();
    void rerollQuality();
    void setNameToItem();
    void saveName();
};

#endif // ITEMGENDIALOGUE_H
