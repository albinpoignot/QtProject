#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "c_webservice.h"
#include <QMessageBox>
#include <QFileDialog>
#include "qmapcontrol.h"
#include <QVBoxLayout>
#include <QWidget>
#include "c_qdbc.h"
#include "c_details.h"

using namespace qmapcontrol;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    void setDetails(C_details *);
    void drawPOI();

private slots:
    void modifyPoint(QTableWidgetItem*);
    void deletePoint(QTableWidgetItem*);
    void pointClick(Geometry*, QPoint coord_px);

private:
    // attributs
    Ui::MainWindow *ui;
    MapControl * mc;
    MapAdapter* mapadapter;
    GeometryLayer * points;
    QTableWidget * table;
    C_details * details;

    // methodes

    /**
      * Ajoute les boutons de zoom et de-zoom sur l'écran
      */
    void addZoomButton();

    /**
      * Ajoute un GeometryLayer à l'écran pour dessiner les points
      * En fait, il renseigne l'attribut "points"
      */
    void addGeometry();

    /**
      * récupère tous les points de la base de données pour les passer à addPoint
      */
    void drawPoints();

    /**
      * Ajoute le point passé en paramètre dans l'attribut "points" pour le dessiner.
      */
    void addPoint(C_poi);

    /**
      * Ajoute un tableau permettant de modifier tous les points d'intérêt
      */
    void addTable();

    /**
      * Rempli le tableau permettant de modifier tous les points d'intérêt
      */
    void fillTable();

    void confirmedDelete(int);

    //void canceledDelete();
};

#endif // MAINWINDOW_H
