#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    QVBoxLayout * layout  = new QVBoxLayout();

    // create MapControl
    MapControl * mc = new MapControl(QSize(480,640));

    // create MapAdapter to get maps from
   MapAdapter* mapadapter = new OSMMapAdapter();

    // create a map layer with the mapadapter
    Layer* l = new MapLayer("Custom Layer", mapadapter);

    // add Layer to the MapControl
    mc->addLayer(l);

    qDebug() << "openQmapControl ou bien";

     layout->addWidget(mc);
     ui->widget->setLayout(layout);
     */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openQmapControl()
{
   /* QVBoxLayout * layout  = new QVBoxLayout();



    // create MapControl
    MapControl * mc = new MapControl(QSize(480,640));

    // create MapAdapter to get maps from
    MapAdapter* mapadapter = new OSMMapAdapter();

    // create a map layer with the mapadapter
    Layer* l = new MapLayer("Custom Layer", mapadapter);

    // add Layer to the MapControl
    mc->addLayer(l);

    qDebug() << "openQmapControl ou bien";

     layout->addWidget(mc);
     ui->widget->setLayout(layout);
*/
}


