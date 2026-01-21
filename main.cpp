#include "gui/mainwindow.h"
#include "src/tests/Test.h"


#include <QApplication>

//TODO: Delete button doesn't work.
//TODO: ItemGenerator dialog window.
//TODO: LoadCampain button dosn't work -> reload tables to have accurate data
//TODO: Correct model after deleting player
//TODO: (Optional) delete items with doubleclick - maybe.
//TODO: (Optional) change DeleteCampain btn to just clear the app / Add missing clear feature

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

