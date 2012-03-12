#include "c_details.h"
#include "ui_c_details.h"

C_details::C_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::C_details)
{
    ui->setupUi(this);
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
}

