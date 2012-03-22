#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::init()
{
    initQsettings();

    QVBoxLayout * layout  = new QVBoxLayout();

    // create MapControl
    mc = new MapControl(QSize(ui->tabWidget->width() - 25, ui->tabWidget->height() - 60));

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

    connect(mc, SIGNAL(mouseEventCoordinate(const QMouseEvent*,QPointF)),
            this, SLOT(clickInTheWorld(const QMouseEvent*,QPointF)));

    connect(&ws, SIGNAL(requestFinished()), this, SLOT(wsFinished()));

    connect(settingView, SIGNAL(newCategorie(QString)), this, SLOT(addCategorie(QString)));
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(filtrer(QModelIndex)));

    details->setParent(this);

    addZoomButton();
    drawTabWidgetContent();

    fillFiltre();

    ui->menuBar->setVisible(true);
    connect(ui->menuBar, SIGNAL(triggered(QAction*)),
            this, SLOT(languageChanged(QAction*)));

    connect(ui->menuAide,SIGNAL(triggered(QAction*)),this,SLOT(on_ActionModeEmploi(QAction*)));

}

void MainWindow::setTranslator(QTranslator * tr)
{
    trsl = tr;
}

void MainWindow::setModeEmploi(C_modeEmploi * me)
{
    modeEmploi = me;
}

void MainWindow::languageChanged(QAction * action)
{
    if(action != 0)
    {
        qApp->removeTranslator(trsl);

        trsl = new QTranslator();

        //trsl->load("qt_" + action->objectName(), "/usr/share/qt4/translations");
        trsl->load(QString("qtproject_") + action->objectName());

        qApp->installTranslator(trsl);

        ui->retranslateUi(this);
    }
}

void MainWindow::on_ActionModeEmploi(QAction * action)
{
    if(action != 0)
    {
        modeEmploi->show();
    }
}

void MainWindow::initQsettings()
{
    if(!settings.contains("supermarche"))    settings.setValue("supermarche","supermarche");
    if(!settings.contains("musee"))    settings.setValue("musee","musee");
    if(!settings.contains("cinema"))    settings.setValue("cinema","cinema");
    if(!settings.contains("theatre"))    settings.setValue("theatre","theatre");

}

void MainWindow::fillFiltre()
{

    QStringList cles = settings.allKeys();
    model = new QStandardItemModel;

    foreach(QString cle,cles)
    {
        QStandardItem * item = new QStandardItem(settings.value(cle).toString());
        item->setCheckable(true);
        item->setEditable(false);
        item->setCheckState(Qt::Checked);
        model->appendRow(item);

    }

    ui->listView->setModel(model);

}

void MainWindow::setDetails(C_details * leDetails)
{
    details = leDetails;
}

void MainWindow::setSettings(Settings * leSettingView)
{
    settingView = leSettingView;
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

void MainWindow::drawTabWidgetContent()
{
    addGeometryLayer();
    currentList = C_qdbc::getAllPoi();
    fillTable();
}

void MainWindow::addGeometryLayer()
{
   points = new GeometryLayer("Points", mapadapter);

   drawPoints();

   mc->addLayer(points);
}

void MainWindow::drawPoints()
{
    //qDebug() << "*** draw points start - listeCirclePoints.size() = " << listeCirclePoints.size();

    points->clearGeometries();

    // STEP 1 : suppression des pointeurs
    if(!listeCirclePoints.isEmpty())
    {
        for(int i=0; i<listeCirclePoints.size(); i++)
        {
            listeCirclePoints.removeAt(i);
            //qDebug() << listeCirclePoints[i]->coordinate().x();
        }
    }

    //qDebug() << " ****** all points are deleted";

    // STEP 2 : obtention des points actuellement dans la BDD pour dessin
    QList<C_poi> listePoints = C_qdbc::getAllPoi();
    int nbPoi = listePoints.size();

    for(int i = 0; i < nbPoi ; i++)
    {
        addPoint(listePoints.at(i));
    }

    connect(points, SIGNAL(geometryClicked(Geometry*,QPoint)),
            this, SLOT(pointClick(Geometry*,QPoint)));

    //qDebug() << "fin de drawPoints() - listeCirclePoints.size() = " << listeCirclePoints.size();
}

void MainWindow::addPoint(C_poi poi)
{
    // Personnalisation du dessin
    QPen* pointpen = new QPen(QColor(0,255,0)); // couleur verte
    pointpen->setWidth(5); // épaisseur du trait

    // Point : coord => 2,... et 48,... || rayon => 15 || nom || ?? || pinceau pour le dessin
    CirclePoint * point = new CirclePoint(poi.getPoint().x(), poi.getPoint().y(), 15, poi.getCat(), Point::Middle, pointpen);

    listeCirclePoints.append(point);

    // Ajout à l'affichage !
    points->addGeometry(point);

    delete pointpen;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTable()
{
    ui->verticalLayout->removeWidget(table);
    delete table;    
    fillTable();
}

void MainWindow::fillTable()
{
    int nbPoi = currentList.size();

    table = new QTableWidget(nbPoi,8);
    ui->verticalLayout->addWidget(table);


    QTableWidgetItem * item = new QTableWidgetItem();
    item->setText("Catégorie");
    table->setHorizontalHeaderItem(0,item);

    item = new QTableWidgetItem();
    item->setText("Nom");
    table->setHorizontalHeaderItem(1,item);

    item = new QTableWidgetItem();
    item->setText("Latitude");
    table->setHorizontalHeaderItem(2,item);

    item = new QTableWidgetItem();
    item->setText("longitude");
    table->setHorizontalHeaderItem(3,item);

    item = new QTableWidgetItem();
    item->setText("Description");
    table->setHorizontalHeaderItem(4,item);

    item = new QTableWidgetItem();
    item->setText("Horaires");
    table->setHorizontalHeaderItem(5/*cb = new QComboBox();
                                                       cb->addItems(settings.allKeys());
                                                       cb->setCurrentIndex(cb->findText(currentList[i].getCat()));
                                                       table->setCellWidget(i, 0, cb);*/,item);

    item = new QTableWidgetItem();
    item->setText("Modifier");
    table->setHorizontalHeaderItem(6,item);

    item = new QTableWidgetItem();
    item->setText("Supprimer");
    table->setHorizontalHeaderItem(7,item);

    for(int i = 0; i < nbPoi;i++)
    {
        for(int j = 0; j < 8; j++)
        {
            item = new QTableWidgetItem();
            switch(j)
            {
                case 0: item->setText(currentList[i].getCat());
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 1: item->setText(currentList[i].getNom());
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 2: item->setText(QString::number(currentList[i].getPoint().x()));
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 3: item->setText(QString::number(currentList[i].getPoint().y()));
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 4: item->setText(currentList[i].getDescription());
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 5: item->setText(currentList[i].getHoraires());
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 6: item->setText("Modifier");
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
                case 7: item->setText("Supprimer");
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        break;
            }
            table->setItem(i,j,item);
        }
    }

    connect(table, SIGNAL(itemDoubleClicked(QTableWidgetItem *)),
            this, SLOT(on_DbClickOnTable(QTableWidgetItem*)));
}

void MainWindow::changeCatPoint(QTableWidgetItem * item)
{
    qDebug() << table->row(item);
}

void MainWindow::modifyPoint(QTableWidgetItem * item)
{
    C_poi point;

    QComboBox * cb = (QComboBox*)(table->cellWidget(item->row(), 0));

    point.setCat(cb->currentText());
    point.setNom(table->item(item->row(), 1)->text());
    point.setPoint( QPointF(table->item(item->row(), 2)->text().toFloat(),
                           table->item(item->row(), 3)->text().toFloat()) );
    point.setDescription(table->item(item->row(),4)->text());
    point.setHoraires(table->item(item->row(),5)->text());
    C_qdbc::updatePoi(point);


    currentList[item->row()].setCat(point.getCat());
    currentList[item->row()].setNom(point.getNom());
    currentList[item->row()].setDescription(point.getDescription());
    currentList[item->row()].setHoraires(point.getHoraires());

}

void MainWindow::on_DbClickOnTable(QTableWidgetItem * item)
{
    if(item->column() == 7)
    {
        //qDebug() << "Suppression demandee -> " << table->item(item->row(), 1)->text();

        int deletedRow = item->row();

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
    else if(item->column() == 6)
    {
        C_poi point = C_qdbc::getPoi(table->item(item->row(), 2)->text().toFloat(),
                                     table->item(item->row(), 3)->text().toFloat());

        details->setDetails(point, settings.allKeys());

        ui->lineEdit_2->setText(QString::number(point.getPoint().x()));
        ui->lineEdit_3->setText(QString::number(point.getPoint().y()));

        details->show();

        currentRow = item->row();

        connect(details, SIGNAL(updateFinished(C_poi)),
                this, SLOT(updateDone(C_poi)));

    }
}

void MainWindow::confirmedDelete(int deletedRow)
{
    //qDebug() << "Suppression confirmee -> " << table->item(deletedRow, 1)->text();

    if(deletedRow >= 0)
    {
        C_qdbc::deletePoi(table->item(deletedRow, 2)->text().toDouble(), table->item(deletedRow, 3)->text().toDouble());
        table->removeRow(deletedRow);
    }

}

void MainWindow::pointClick(Geometry* geom, QPoint coord_px)
{
    CirclePoint * cp = (CirclePoint*) geom;

    C_poi point = C_qdbc::getPoi(cp->longitude(), cp->latitude());

    details->setDetails(point, settings.allKeys());

    /* TO THE RIGHT
     * details->move(this->x() + ui->tabWidget->x() + ui->tabWidget->width() + 10,
     *             this->y() + ui->tabWidget->y() + 50);
     */

    /*
     * ON THE POINT
     */
    details->move(coord_px.x() + 30, coord_px.y() + details->height() - 50);

    qDebug() << QString::number(coord_px.x() + 30) << " - " << QString::number(coord_px.y() + details->height() - 50);

    ui->lineEdit_2->setText(QString::number(point.getPoint().x()));
    ui->lineEdit_3->setText(QString::number(point.getPoint().y()));

    details->show();

}

void MainWindow::clickInTheWorld(const QMouseEvent* evnt,QPointF point)
{
    if(evnt->type() == QEvent::MouseButtonDblClick)
    {
        //qDebug() << "DOUBLE click in the world - " << QString::number(point.x()) << ":" << QString::number(point.y());

        QMessageBox messageBox;
        messageBox.setText("Voulez-vous récupérer les points proches de votre clic ?");
        messageBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        messageBox.setDefaultButton(QMessageBox::No);

        int ret = messageBox.exec();

        switch(ret)
        {
            case QMessageBox::Yes:
                ws.getPOI(point.x(), point.y());
                messageBox.close();
                break;
            case QMessageBox::No:
                messageBox.close();
                break;
        }

    }
}

void MainWindow::wsFinished()
{
    qDebug() << "Request finished _ wsFinished()";
    drawPoints();
    currentList = C_qdbc::getAllPoi();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{    
    updateTable();
}

void MainWindow::on_b_add_cat_clicked()
{
    settingView->show();
}

void MainWindow::addCategorie(QString laCat)
{
    if(!settings.contains(laCat))    settings.setValue(laCat,laCat);
    fillFiltre();
}

void MainWindow::on_b_delete_cat_clicked()
{
    QModelIndex mi = ui->listView->currentIndex();
    QString cat = ui->listView->model()->data(mi).toString();
    QMessageBox messageBox;
    messageBox.setText("Voulez-vous vraiment supprimmer " + cat + "?");
    messageBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    messageBox.setDefaultButton(QMessageBox::No);

    int ret = messageBox.exec();

    switch(ret)
    {
        case QMessageBox::Yes:
            settings.remove(cat);
            fillFiltre();
            messageBox.close();
            break;
        case QMessageBox::No:
            messageBox.close();
            break;
    }

}
void MainWindow::filtrer(QModelIndex index)
{
    QStandardItem *item = model->item(index.row());
    if(item->checkState() == Qt::Checked)
    {
        item->setCheckState(Qt::Unchecked);
        removePointFromCat(ui->listView->model()->data(index).toString());
    }
    else
    {
        item->setCheckState(Qt::Checked);
        restorePointFromCat(ui->listView->model()->data(index).toString());
    }
}

void MainWindow::removePointFromCat(QString cat)
{
    foreach(CirclePoint * point, listeCirclePoints)
    {
        if(point->name().compare(cat) == 0 )
        {
            points->removeGeometry(point);
        }

    }
    int i = 0;
    foreach(C_poi point, currentList)
    {
        if(point.getCat().compare(cat) == 0)
        {
            currentList.removeAt(i);
        }else i++;
    }
    updateTable();
}

void MainWindow::restorePointFromCat(QString cat)
{
    QList<C_poi> allpoints = C_qdbc::getAllPoi();

    foreach(CirclePoint * point, listeCirclePoints)
    {
        if(point->name().compare(cat) == 0 )
        {
            points->addGeometry(point);            
        }
    }
    foreach(C_poi point,allpoints)
    {
        if(point.getCat().compare(cat) == 0)
            currentList.append(point);
    }
    updateTable();
}

void MainWindow::on_b_filtre_keyword_clicked()
{
    QString filtre = ui->lineEdit->text();

    QList<C_poi> listePoi = C_qdbc::getAllPoi();
    QList<C_poi> points;

    bool allPoints = true;

    if(!filtre.isEmpty())
    {

        foreach(C_poi point,listePoi)
        {
            if(point.getNom().contains(filtre) || point.getDescription().contains(filtre))
                points.append(point);
        }

        allPoints = false;

    }else
    {
        points = listePoi;
    }

    if(!points.isEmpty())
    {
       keepPointFromList(points,allPoints);
    }
}

void MainWindow::on_b_filtre_proximite_clicked()
{
    QList<C_poi> points;
    QList<C_poi> listePoi = C_qdbc::getAllPoi();

    bool allPoints = true;

    if(ui->lineEdit_2->text().length() != 0 && ui->lineEdit_3->text().length() != 0)
    {
        double lat = ui->lineEdit_2->text().toDouble();
        double lon = ui->lineEdit_3->text().toDouble();

        QMap<qreal, int> distances;    // (key,value) => (distance, indice), la qmap est triée par la clé

        int i =0;
        foreach(C_poi point,listePoi)
        {
            qreal d = qSqrt( qPow((point.getPoint().y() - lon),2) + qPow((point.getPoint().x() - lat),2) );
            distances.insert(d,i);
            i++;
        }

        // les 10 premiers éléments de la qmap sont donc les 10 plus petites disctances
        // et la valeur associée à ces cles est l'indice du point dans listePoi

        QMap<qreal,int>::const_iterator it = distances.begin();

        for(; it != distances.begin() + 10 ; it++)
        {
            points.append(listePoi[it.value()]);
        }

        allPoints = false;

    }
    else
    {
        points = listePoi;
    }

    if(!points.isEmpty())
    {
       keepPointFromList(points,allPoints);
    }

}

void MainWindow::keepPointFromList(QList<C_poi> pois,bool allPoints)
{
    int nbCat = model->rowCount();

    for(int i =0; i < nbCat;i++)
    {
        if(allPoints)
            model->item(i)->setCheckState(Qt::Checked);
        else
            model->item(i)->setCheckState(Qt::Unchecked);
    }
    points->clearGeometries();
    foreach(CirclePoint * point, listeCirclePoints)
    {
        foreach(C_poi poi,pois)
         {
            if(point->name().compare(poi.getCat()) == 0 && point->coordinate().x() == poi.getPoint().x() && point->coordinate().y() == poi.getPoint().y())
            {
               points->addGeometry(point);
            }
         }
    }
    currentList = pois;
    updateTable();
}

void MainWindow::on_btnExport_clicked()
{
    QFile file(QDir::currentPath() + "/export_test.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    C_poi point;

    for(int i = 0; i < currentList.size(); i++)
    {
        point = currentList.at(i);
        out << QString::number(point.getPoint().x()) + ';' + QString::number(point.getPoint().y()) + ';' +
               point.getNom() + ';' + point.getCat() + ';' + point.getDescription() + ';' +
               point.getHoraires() + '\n';
    }

    file.close();

}

void MainWindow::updateDone(C_poi point)
{
    table->item(currentRow, 0)->setText(point.getCat());

    table->item(currentRow, 1)->setText(point.getNom());

    table->item(currentRow, 2)->setText(QString::number(point.getPoint().x()));

    table->item(currentRow, 3)->setText(QString::number(point.getPoint().y()));

    table->item(currentRow, 4)->setText(point.getDescription());

    table->item(currentRow, 5)->setText(point.getHoraires());
}
