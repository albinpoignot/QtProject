#include <QtGui/QApplication>
#include "accueil.h"
#include "c_details.h"
#include "settings.h"
#include "c_modeemploi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name();

    QTranslator translator;
    translator.load("qt_" + locale.left(2), "/usr/share/qt4/translations");
    a.installTranslator(&translator);

    MainWindow w;
    Accueil d;
    Settings settings(&w);
    C_details details(&w);
    C_modeEmploi m;

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    w.setSettings(&settings);
    w.setDetails(&details);
    w.setTranslator(&translator);
    w.setModeEmploi(&m);
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
