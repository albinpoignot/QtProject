#include "c_details.h"
#include "ui_c_details.h"

C_details::C_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::C_details)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
}

C_details::~C_details()
{
    delete ui;
}

void C_details::setDetails(C_poi point, QStringList catList)
{
    ui->retranslateUi(this);

    ui->txtLongitude->setText(QString::number(point.getPoint().x()));
    ui->txtLatitude->setText(QString::number(point.getPoint().y()));
    ui->txtNom->setText(point.getNom());
    ui->txtDesc->setPlainText(point.getDescription());
    ui->txtHoraires->setPlainText(point.getHoraires());

    ui->cbCategories->clear();
    ui->cbCategories->addItems(catList);
    ui->cbCategories->setCurrentIndex(ui->cbCategories->findText(point.getCat()));

    qDebug() << "C_details::setDetails : " + point.toString();
}


void C_details::on_buttonBox_accepted()
{
    C_poi point;
    QMessageBox messageBox;
    messageBox.setText("Voulez-vous vraiment mettre à jour ce POI ?");
    messageBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    messageBox.setDefaultButton(QMessageBox::No);

    int ret = messageBox.exec();

    switch(ret)
    {
        case QMessageBox::Yes:
            point.setPoint(QPointF(ui->txtLongitude->text().toFloat(), ui->txtLatitude->text().toFloat()));
            point.setNom(ui->txtNom->text());
            point.setCat(ui->cbCategories->currentText());
            point.setDescription(ui->txtDesc->toPlainText());
            point.setHoraires(ui->txtHoraires->toPlainText());

            C_qdbc::updatePoi(point);

            messageBox.close();
            this->close();

            emit updateFinished(point);

            break;
        case QMessageBox::No:
            messageBox.close();
            break;
    }

   // qDebug() << "on_buttonBox_accepted : " + point.toString();

}

void C_details::on_buttonBox_rejected()
{
    this->close();
}


