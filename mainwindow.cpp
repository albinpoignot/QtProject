#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openQmapControl()
{
    // create MapControl
    MapControl * mc = new MapControl(QSize(480,640));

    // create MapAdapter to get maps from
    MapAdapter* mapadapter = new OSMMapAdapter();

    // create a map layer with the mapadapter
    Layer* l = new MapLayer("Custom Layer", mapadapter);

    // add Layer to the MapControl
    mc->addLayer(l);    


}

void MainWindow::on_pushButton_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this,
                                                        "Open File",
                                                        QDir::currentPath(),
                                                        "bdd (*.db)");

    if(fileName != NULL)
    {
        qDebug() << fileName;
        C_webservice ws(fileName);
        openQmapControl();
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    QString DbName = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("Nom de la bdd:"), QLineEdit::Normal,
                                           QDir::currentPath() + "/QtProjectDB.db", &ok);
    if (ok && !DbName.isEmpty())
    {
        C_webservice ws(DbName);
        openQmapControl();
    }
}
