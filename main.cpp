#include <QtGui/QApplication>
#include "mainwindow.h"
#include "c_webservice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    C_webservice ws;

    ws.getPOI(12,15);

    return a.exec();
}
