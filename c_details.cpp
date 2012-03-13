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

void C_details::setDetails(C_poi point)
{
    ui->txtLongitude->setText(QString::number(point.getPoint().x()));
    ui->txtLatitude->setText(QString::number(point.getPoint().y()));
    ui->txtNom->setText(point.getNom());
    ui->txtCategorie->setText(point.getCat());
    ui->txtDesc->setPlainText(point.getDescription());
    //ui->txtDesc->setText(point.getDescription());
    ui->txtHoraires->setPlainText(point.getHoraires());
    //ui->txtHoraires->setText(point.getHoraires());

    qDebug() << "C_details::setDetails : " + point.toString();
}


void C_details::on_buttonBox_accepted()
{
    C_poi point;
    point.setPoint(QPointF(ui->txtLongitude->text().toFloat(), ui->txtLatitude->text().toFloat()));
    point.setNom(ui->txtNom->text());
    point.setCat(ui->txtCategorie->text());
    point.setDescription(ui->txtDesc->toPlainText());
    point.setHoraires(ui->txtHoraires->toPlainText());

    qDebug() << "on_buttonBox_accepted : " + point.toString();

    C_qdbc::updatePoi(point);
}

void C_details::on_buttonBox_rejected()
{
    this->close();
}
