#include <QtGui/QApplication>
#include "accueil.h"
#include "c_details.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Accueil d;
    C_details details(&w);
    w.setDetails(&details);
    d.setW(&w);
    d.show();


    return a.exec();
}
