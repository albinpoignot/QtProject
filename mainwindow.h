#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QFileDialog>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QWidget>

#include "qmapcontrol.h"

#include "c_qdbc.h"
#include "c_details.h"
#include "c_webservice.h"

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
    void drawTabWidgetContent();

private slots:
    void modifyPoint(QTableWidgetItem*);
    void deletePoint(QTableWidgetItem*);
    void pointClick(Geometry*, QPoint coord_px);
    void clickInTheWorld(const QMouseEvent *, QPointF);
    void wsFinished();

    void on_tabWidget_currentChanged(int index);

private:
    // attributs
    Ui::MainWindow *ui;
    MapControl * mc;
    MapAdapter* mapadapter;
    GeometryLayer * points;
    QTableWidget * table;
    C_details * details;
    C_webservice ws;
    QList<CirclePoint *> listeCirclePoints;

    // methodes

    /**
      * Ajoute les boutons de zoom et de-zoom sur l'écran
      */
    void addZoomButton();

    /**
      * Ajoute un GeometryLayer à l'écran pour dessiner les points
      * En fait, il renseigne l'attribut "points"
      */
    void addGeometryLayer();

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

    void updateTable();

    //void canceledDelete();
};

#endif // MAINWINDOW_H
