#include <QtGui/QApplication>
#include "accueil.h"
#include "c_details.h"
#include "settings.h"
#include "c_modeemploi.h"

#include "testclasse.h"

/*
 * Décommenter cette ligne et commenter la totalité du main() pour
 * effectuer les tests unitaires
 */
//QTEST_MAIN(TestClasse)

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString locale = QLocale::system().name();

    QTranslator translator;

    QTranslator tr;
    tr.load("qt_" + locale.left(2), "/usr/share/qt4/translations");

     translator.load(QString("qtproject_") + locale);
    a.installTranslator(&translator);
    a.installTranslator(&tr);

    MainWindow w;
    Accueil d;
    Settings settings(&w);
    C_details details(&w);
    C_modeEmploi m;

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    w.setSettings(&settings);
    w.setDetails(&details);
    w.setTranslator(&translator);
    w.setTranslator2(&tr);
    w.setModeEmploi(&m);
    d.setW(&w);
    d.show();

    return a.exec();
}
