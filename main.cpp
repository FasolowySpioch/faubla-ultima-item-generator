#include "gui/mainwindow.h"
#include "src/systems/WeaponGenerator.h"
#include "src/tests/Test.h"


#include <QApplication>
#include <iostream>

void testWeaponGenerator();

int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     MainWindow w;

     //Test t;
     //t.allArmorTests();
     //t.allCostTests();

     w.show();
     return a.exec();

    return 0;
}

