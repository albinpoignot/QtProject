#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * \file mainwindow.h
 * \brief classe principale de l'application
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QMainWindow>
#include <QMap>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSettings>
#include <QStandardItemModel>
#include <QTextStream>
#include <QTranslator>
#include <QVBoxLayout>
#include <QWidget>

#include <qmath.h>

#include "qmapcontrol.h"

#include "c_qdbc.h"
#include "c_details.h"
#include "c_webservice.h"
#include "settings.h"
#include "c_modeemploi.h"

using namespace qmapcontrol;

/*! \namespace Ui
 *
 * espace de nommage regroupant les interfaces graphiques
 */
namespace Ui {
    class MainWindow;
}

/*! \class MainWindow
   * \brief classe principale de l'application
   *
   * Offre les méthodes générales pour interagir avec l'application et les autres classes
   */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
      * \brief Lance de dessin des points et le remplissage de la table
      */
    void drawTabWidgetContent();

    /**
      * \brief Remplit la liste des filtres
      */
    void fillFiltre();

    /**
      * \brief Initialise la fenêtre : importe les QSettings, crée et affiche la map,
      * connecte les différents SIGNAL aux SLOT, etc...
      */
    void init();

    void setDetails(C_details *);
    void setSettings(Settings *);
    void setTranslator(QTranslator * tr);
    void setTranslator2(QTranslator * tr);
    void setModeEmploi(C_modeEmploi *);

private slots:

    /**
      * \brief Ajoute une nouvelle catégorie aux settings si elle n'existe pas déjà
      * @param laCat La catégorie à ajouter
      */
    void addCategorie(QString laCat);

    /**
      * \brief Not used now
      * @param item not used
      * \deprecated
      */
    void changeCatPoint(QTableWidgetItem* item);

    /**
      * \brief Appelée lors d'un clic sur la map. Dans le cas d'un double clic : récupère les points à proximité
      * @param evnt Evènement écouté (simple ou double click par exemple)
      * @param point Point du clic
      */
    void clickInTheWorld(const QMouseEvent * evnt, QPointF point);

    /**
      * \brief Appelée lors d'un clic sur un item dans la table. Demande une confirmation
      * de suppression si un double clic a eu lieu sur la dernière case d'une des lignes de la table
      * @param item L'item clické
      */
    void on_DbClickOnTable(QTableWidgetItem* item);

    /**
      * \brief
      * @param index
      */
    void filtrer(QModelIndex index);

    /**
      * \brief Appelée lors du clic sur un des choix du menu : change le langage des
      * composants natifs de Qt
      * @param action Element du menu choisi
      */
    void languageChanged(QAction * action);

    /**
      * \brief Appelée lors de la modification d'un contenu dans la table : modifie le point en BDD
      * et dans currentList pour la cohérence.
      * @param item Elément modifié dans la table
      */
    void modifyPoint(QTableWidgetItem* item);

    /**
      * \brief Appelée lors d'un clic sur un POI sur la map
      * @param geom Le point cliqué
      * @param coord_px Les coordonnées du points sur la map (pas les long/lat)
      */
    void pointClick(Geometry* geom, QPoint coord_px);

    /**
      * \brief Appelée lors que le web-service a terminé de récupérer les POI proches
      */
    void wsFinished();

    /**
      * \brief Appelée lors d'un clic sur le bouton d'export : exporte le contenu de la table
      * dans fichier CSV
      */
    void on_btnExport_clicked();

    /**
      * \brief Applique le filtre sur le nom ou la description
      */
    void on_b_filtre_keyword_clicked();

    /**
      * \brief Applique le filtre sur les longitudes/latitudes
      */
    void on_b_filtre_proximite_clicked();

    /**
      * \brief Appelée lorsqu'un item de la table a été modifiée et la met à jour
      * @param index Index de l'item modifié
      */
    void on_tabWidget_currentChanged(int index);

    /**
      * \brief Affiche le dialogue pour ajouter une catégorie
      */
    void on_b_add_cat_clicked();

    /**
      * \brief Supprime la catégorie sélectionnée
      */
    void on_b_delete_cat_clicked();

    /**
      * \brief Appelée lorsqu'un point à été modifié dans la table : mise à jours des valeurs
      * @param point Le point qui a été modifié
      */
    void updateDone(C_poi point);

    /**
      * \brief Appelé lorsque le menu mode d'emploi est selectionné, ouvre la fenetre mode d'emploi
      */
    void on_ActionModeEmploi(QAction *);


private:

    /**
      * \brief Interface graphique
      */
    Ui::MainWindow *ui;

    /**
      * \brief Instance de MapControl
      */
    MapControl * mc;

    /**
      * \brief Instance de MapAdapter
      */
    MapAdapter* mapadapter;

    /**
      * \brief Layer où les POI sont dessinés
      */
    GeometryLayer * points;

    /**
      * \brief Table des POI
      */
    QTableWidget * table;

    /**
      * \brief Instance de la fenêtre affichant les détails d'un POI
      */
    C_details * details;

    /**
      * \brief Instance de la fenêtre affichant le mode d'emploi
      */
    C_modeEmploi * modeEmploi;

    /**
      * \brief Instance d'un objet permettant d'accéder au web-service
      */
    C_webservice ws;


    /**
      * \brief Liste des points dessinés à l'écran
      */
    QList<CirclePoint *> listeCirclePoints;

    /**
      * \brief Settings
      */
    QSettings settings;

    /**
      * \brief Fenêtre d'ajout des settings
      */
    Settings * settingView;

    /**
      * \brief
      */
    QStandardItemModel *model;

    /**
      * \brief Liste des points actuellement gérés
      */
    QList<C_poi> currentList;

    /**
      * \brief Translator courant
      */
    QTranslator * trsl;
    QTranslator * trsl2;
    /**
      * \brief Ligne du point mis à jour
      */
    int currentRow;

    /**
      * \brief Ajoute les boutons de zoom et de-zoom sur l'écran
      */
    void addZoomButton();

    /**
      * \brief Ajoute un GeometryLayer à l'écran pour dessiner les points
      * En fait, il renseigne l'attribut "points"
      */
    void addGeometryLayer();

    /**
      * \brief Récupère tous les points de la base de données pour les passer à addPoint
      */
    void drawPoints();

    /**
      * \brief Ajoute le point passé en paramètre dans l'attribut "points" pour le dessiner.
      * @param poi Le POI a insérer
      */
    void addPoint(C_poi poi);

    /**
      * \brief Rempli le tableau permettant de modifier tous les points d'intérêt
      */
    void fillTable();

    /**
      * \brief Appelée lorsque la suppression est confirmée : effectue effectivement la suppression
      * dans la BDD
      * @param deletedRow Le numéro de la ligne à supprimer
      */
    void confirmedDelete(int deletedRow);

    /**
      * \brief Met à jour le tableau de points d'intérêt
      */
    void updateTable();

    /**
      * \brief Initilise la liste des catégories présente dans qSetting (pour le 1er lancement de l'application)
      */
    void initQsettings();

    /**
      * \brief Retire de la carte les points d'une catégorie désélectionnée
      * @param cat La catégorie désélectionnée
      */
    void removePointFromCat(QString cat);

    /**
      * \brief Redessine les points d'une catégorie sélectionnée
      * @param cat La catégorie sélectionnée
      */
    void restorePointFromCat(QString cat);

    /**
      * \brief Garde les points filtrés sur la carte et dans le tableau
      * @param La liste des points à afficher
      * @param vrai si ce sont toutes les catégories qui sont affichées, faux si un filtre est appliqué
      */
    void keepPointFromList(QList<C_poi>,bool);

};

#endif // MAINWINDOW_H
