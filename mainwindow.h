#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QFileDialog>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QWidget>
#include <QSettings>
#include <QStandardItemModel>
#include <QMap>
#include <qmath.h>

#include "qmapcontrol.h"

#include "c_qdbc.h"
#include "c_details.h"
#include "c_webservice.h"
#include "settings.h"

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
    void setSettings(Settings *);
    void drawTabWidgetContent();
    void fillFiltre();
private slots:
    void modifyPoint(QTableWidgetItem*);
    void deletePoint(QTableWidgetItem*);
    void pointClick(Geometry*, QPoint coord_px);
    void clickInTheWorld(const QMouseEvent *, QPointF);
    void wsFinished();

    void on_tabWidget_currentChanged(int index);

    void on_toolButton_clicked();

    void addCategorie(QString);
    void on_toolButton_2_clicked();
    void filtrer(QModelIndex);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

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
    QSettings settings;
    Settings * settingView;
     QStandardItemModel *model;
     QList<C_poi> currentList;
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
      * Rempli le tableau permettant de modifier tous les points d'intérêt
      */
    void fillTable();

    void confirmedDelete(int);

    /**
      * met à jour le tableau de points d'intérêt
      */
    void updateTable();

    /**
      * Initilise la liste des catégories présente dans qSetting (pour le 1er lancement de l'application)
      */
    void initQsettings();

    /**
      * Retire de la carte les points d'une catégorie desélectionnée
      */
    void removePointFromCat(QString);

    /**
      * Redessine les points d'une catégorie sélectionnée
      */
    void restorePointFromCat(QString);

    /**
      * Garde les points filtrés sur la carte et dans le tableau
      * @param La liste des points à afficher
      * @param vrai si ce sont toutes les catégories qui sont affichées, faux si un filtre est appliqué
      */
    void keepPointFromList(QList<C_poi>,bool);


    //void canceledDelete();
};

#endif // MAINWINDOW_H
