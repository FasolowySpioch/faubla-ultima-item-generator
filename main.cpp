#include "gui/mainwindow.h"
#include "src/tests/Test.h"
#include <QApplication>

//TODO: (Optional) delete items with doubleclick - maybe.

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

