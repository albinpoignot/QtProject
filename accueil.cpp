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

void Accueil::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                         "Open File",
                                                      QDir::currentPath(),
                                                      "bdd (*.db)");

     if(fileName != NULL)
     {
         C_webservice ws(fileName);
          MainWindow w;
          w.show();
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
        C_webservice ws(DbName);
       // openQmapControl();
    }
}
