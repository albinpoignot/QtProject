#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::init()
{
    QVBoxLayout * layout  = new QVBoxLayout();
    //QStactLayout

    // create MapControl
    //mc = new MapControl(QSize(ui->tab->width(),ui->tab->height()));
    mc = new MapControl(QSize(455,315));
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
    // addTable();
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

void MainWindow::addTable()
{

}

void MainWindow::fillTable()
{
    QList<C_poi> listePoi = C_qdbc::getAllPoi();
    int nbPoi = listePoi.size();

    table = new QTableWidget(nbPoi,5);
    ui->verticalLayout->addWidget(table);

    QTableWidgetItem * item;
    for(int i = 0; i < nbPoi;i++)
    {
        for(int j = 0; j < 5; j++)
        {
            item = new QTableWidgetItem();
            switch(j)
            {
                case 0: item->setText(listePoi[i].getCat());
                        break;
                case 1: item->setText(listePoi[i].getNom());
                        break;
                case 2: item->setText(QString::number(listePoi[i].getPoint().x()));
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 3: item->setText(QString::number(listePoi[i].getPoint().y()));
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 4: item->setText("Delete");
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
            }
            table->setItem(i,j,item);
        }
    }

    connect(table, SIGNAL(itemChanged(QTableWidgetItem*)),
            this, SLOT(modifyPoint(QTableWidgetItem*)));

    connect(table, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
            this, SLOT(deletePoint(QTableWidgetItem*)));

}

void MainWindow::modifyPoint(QTableWidgetItem * item)
{
    C_poi point;

    point.setCat(table->item(item->row(), 0)->text());
    point.setNom(table->item(item->row(), 1)->text());
    point.setPoint( QPointF(table->item(item->row(), 2)->text().toFloat(),
                           table->item(item->row(), 3)->text().toFloat()) );

    C_qdbc::updatePoi(point);
}

void MainWindow::deletePoint(QTableWidgetItem * item)
{
    if(item->column() == 4)
    {
        qDebug() << "Suppression demandee -> " << table->item(item->row(), 1)->text();

        int deletedRow = item->row();

        /*buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        buttonBox->show();*/

        /*connect(buttonBox, SIGNAL(accepted()),
                this, SLOT(confirmedDelete()));

        connect(buttonBox, SIGNAL(rejected()),
                this, SLOT(canceledDelete()));*/

        QMessageBox messageBox;
        messageBox.setText("Voulez-vous vraiment supprimer ce POI ?");
        messageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Cancel);

        int ret = messageBox.exec();

        switch(ret)
        {
            case QMessageBox::Ok:
                confirmedDelete(deletedRow);
                break;
            case QMessageBox::Cancel:
                messageBox.close();
                break;
        }

    }
}

void MainWindow::confirmedDelete(int deletedRow)
{
    qDebug() << "Suppression confirmee -> " << table->item(deletedRow, 1)->text();

    if(deletedRow >= 0)
    {
        C_qdbc::deletePoi(table->item(deletedRow, 2)->text().toDouble(), table->item(deletedRow, 3)->text().toDouble());
        table->removeRow(deletedRow);
        //fillTable();
        qDebug() << "delete effectue";
    }

}

/*void MainWindow::canceledDelete()
{
    buttonBox->hide();
}*/
