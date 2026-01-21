#include "gui/mainwindow.h"
#include "src/tests/Test.h"
#include <QApplication>

//TODO: Delete button doesn't work.
//TODO: ItemGenerator dialog window.
//TODO: (Optional) delete items with doubleclick - maybe.
//TODO: Check for clearControls feature in MainWindow if it's doing what's supposed to do

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

