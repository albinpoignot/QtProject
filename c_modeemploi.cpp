#include "c_modeemploi.h"
#include "ui_c_modeemploi.h"

C_modeEmploi::C_modeEmploi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::C_modeEmploi)
{
    ui->setupUi(this);

    connect(ui->b_fermer,SIGNAL(clicked()),this,SLOT(close()));

    QString fileName = "modeemploi.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream flux(&fichier);

    QString all = flux.readAll();

    ui->textEdit->setText(all);

}

void C_modeEmploi::changeLang()
{
     ui->retranslateUi(this);
}

C_modeEmploi::~C_modeEmploi()
{
    delete ui;
}
