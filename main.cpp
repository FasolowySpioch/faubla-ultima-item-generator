#include "mainwindow.h"
#include "src/systems/WeaponGenerator.h"
#include "src/tests/Test.h"


#include <QApplication>
#include <iostream>

void testWeaponGenerator();

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    Test t;
    t.allWeaponTests();

    return 0;
}

