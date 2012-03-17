#include <QtGui/QApplication>
#include "accueil.h"
#include "c_details.h"
#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Accueil d;
    Settings settings(&w);
    C_details details(&w);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    w.setSettings(&settings);
    w.setDetails(&details);
    d.setW(&w);
    d.show();


    /*C_qdbc::initDB("Test.db");
    C_webservice ws;
    ws.getPOI(48.86,2.33);*/
    /*this->close();
    mw->show();
    mw->init();*/

    //C_qdbc::removeDb();
    return a.exec();
}
