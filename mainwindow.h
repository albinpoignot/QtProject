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


private slots:


private:
    // attributs
    Ui::MainWindow *ui;
    MapControl * mc;
    MapAdapter* mapadapter;
    GeometryLayer * points;

    // methodes

    /**
      * Do nothing...
      */
    void openQmapControl();

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
      * Ajoute les points d'une BDD dans l'attribut "points" pour le dessiner.
      */
    void addPoints();
};

#endif // MAINWINDOW_H
