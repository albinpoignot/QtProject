#include <QtGui/QApplication>
#include "accueil.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //w.show();

    Accueil d;
    d.show();


    return a.exec();
}
