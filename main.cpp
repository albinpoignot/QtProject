#include <QtGui/QApplication>
#include "accueil.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Accueil d;
    d.setW(&w);
    d.show();


    return a.exec();
}
