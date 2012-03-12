#include "accueil.h"
#include "ui_accueil.h"

Accueil::Accueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::setW(MainWindow * w)
{
    mw = w;
}

void Accueil::ouvrirMainWindow(QString fileName)
{
    C_qdbc::initDB(fileName);
    C_webservice ws;
    ws.getPOI(48.86,2.33);
    this->close();
    mw->show();
    mw->init();

}

void Accueil::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                         "Open File",
                                                      QDir::currentPath(),
                                                      "bdd (*.db)");

     if(fileName != NULL)
     {
         ouvrirMainWindow(fileName);
     }
}

void Accueil::on_pushButton_2_clicked()
{
    bool ok;
    QString DbName = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("Nom de la bdd:"), QLineEdit::Normal,
                                           "QtProjectDB.db", &ok);
    if (ok && !DbName.isEmpty())
    {
        ouvrirMainWindow(DbName);
    }
}
