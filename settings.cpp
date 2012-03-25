#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

}

Settings::~Settings()
{
    delete ui;
}


void Settings::on_buttonBox_accepted()
{
    emit newCategorie(ui->uiNewCat->text());

}

void Settings::on_buttonBox_rejected()
{
    this->close();
}

void Settings::changeLang()
{
     ui->retranslateUi(this);
}
