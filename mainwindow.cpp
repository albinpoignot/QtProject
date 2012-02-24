#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout * layout  = new QVBoxLayout();

    // create MapControl
    mc = new MapControl(QSize(ui->widget->width(),ui->widget->height()));
    mc->showScale(true);

    // create MapAdapter to get maps from
    mapadapter = new OSMMapAdapter();

    // create a map layer with the mapadapter
    Layer* l = new MapLayer("Custom Layer", mapadapter);

    // add Layer to the MapControl
     mc->addLayer(l);
     layout->addWidget(mc);
     ui->widget->setLayout(layout);
     setCentralWidget(ui->widget);

     mc->setView(QPointF(2.3522219,48.856614));

     mc->setZoom(11);

     addZoomButton();
     addGeometry();

}

void MainWindow::addZoomButton()
{
    // create buttons as controls for zoom
    QPushButton* zoomin = new QPushButton("+");
    QPushButton* zoomout = new QPushButton("-");
    zoomin->setMaximumWidth(50);
    zoomout->setMaximumWidth(50);

    connect(zoomin, SIGNAL(clicked(bool)),
            mc, SLOT(zoomIn()));
    connect(zoomout, SIGNAL(clicked(bool)),
            mc, SLOT(zoomOut()));

    // add zoom buttons to the layout of the MapControl
    QVBoxLayout* innerlayout = new QVBoxLayout;
    innerlayout->addWidget(zoomin);
    innerlayout->addWidget(zoomout);
    mc->setLayout(innerlayout);
}

void MainWindow::addGeometry()
{
   points = new GeometryLayer("Points", mapadapter);

   addPoints();

   mc->addLayer(points);
}

void MainWindow::addPoints()
{
     CirclePoint point = CirclePoint();
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


