#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::init()
{

    QVBoxLayout * layout  = new QVBoxLayout();
    //QStactLayout

    // create MapControl
    mc = new MapControl(QSize(ui->tab->width(),ui->tab->height()));
    mc->showScale(true);

    // create MapAdapter to get maps from
    mapadapter = new OSMMapAdapter();

    // create a map layer with the mapadapter
    Layer* l = new MapLayer("Custom Layer", mapadapter);

    // add Layer to the MapControl
     mc->addLayer(l);
     layout->addWidget(mc);
     ui->tab->setLayout(layout);

     // Paris
     mc->setView(QPointF(2.3522219,48.856614));

     mc->setZoom(11);

     addZoomButton();
     addGeometry();
     fillTable();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

   drawPoints();

   mc->addLayer(points);
}

void MainWindow::drawPoints()
{
    QList<C_poi> listePoints = C_qdbc::getAllPoi();
    int nbPoi = listePoints.size();
    for(int i = 0; i < nbPoi ; i++)
    {
        addPoint(listePoints.at(i));
    }
}

void MainWindow::addPoint(C_poi poi)
{
    // Personnalisation du dessin
    QPen* pointpen = new QPen(QColor(0,255,0)); // couleur verte
    pointpen->setWidth(5); // épaisseur du trait

    // Point : coord => 2,... et 48,... || rayon => 15 || nom => Albin || ?? || pinceau pour le dessin
    CirclePoint * point = new CirclePoint(poi.getPoint().x(), poi.getPoint().y(), 15, poi.getNom(), Point::Middle, pointpen);

    // Ajout à l'affichage !
    points->addGeometry(point);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTable()
{
    QList<C_poi> listePoi = C_qdbc::getAllPoi();
    int nbPoi = listePoi.size();
    QTableWidget * table = new QTableWidget(nbPoi,5);
    ui->verticalLayout->addWidget(table);

    QTableWidgetItem * item;
    for(int i = 0; i < nbPoi;i++)
    {
        for(int j = 0; j < 4; j++)
        {
            item = new QTableWidgetItem();
            switch(j)
            {
                case 0: item->setText(listePoi[i].getCat());break;
                case 1: item->setText(listePoi[i].getNom());break;
                case 2: item->setText(QString::number(listePoi[i].getPoint().x()));break;
                case 3: item->setText(QString::number(listePoi[i].getPoint().y()));break;
            }
            table->setItem(i,j,item);
        }
    }
}
