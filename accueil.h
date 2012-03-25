#ifndef ACCUEIL_H
#define ACCUEIL_H


/**
 * \file accueil.h
 * \brief Interface d'accueil de l'application
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include <QDialog>
#include <QInputDialog>
#include "c_webservice.h"
#include <QMessageBox>
#include <QFileDialog>
#include "qmapcontrol.h"
#include <QVBoxLayout>
#include <QWidget>
#include "mainwindow.h"
#include <QTranslator>

/*! \namespace Ui
 *
 * espace de nommage regroupant les interfaces graphiques
 */
namespace Ui {
    class Accueil;
}

/*! \class Accueil
   * \brief Interface d'accueil de l'application
   *
   *  Classe associée à l'interface d'accueil de l'utilisateur lui permettant de choisir sa base de données
   */
class Accueil : public QDialog
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = 0);
    ~Accueil();

    /**
      * \brief Renseigne la fenêtre parent
      * @param w La fenêtre parent
      */
    void setW(MainWindow * w);

private slots:
    /**
      * \brief Ouverture d'une BDD déjà existante
      */
    void on_pushButton_clicked();

    /**
      * \brief Création d'une nouvelle BDD
      */
    void on_pushButton_2_clicked();

    /**
      * \brief Lance le dessin des boutons sur la map
      */
    void wsFinished();

private:
    /**
      * \brief Interface utilisateur
      */
    Ui::Accueil *ui;

    /**
      * \brief Fenêtre parente
      */
    MainWindow * mw;

    /**
      * \brief Web service de récupération des POI
      */
    C_webservice * ws;

    /**
      * \brief Ouvre la fenetre parente et renseigne la BDD fournie
      * @param fileName Nom de la BDD
      */
    void ouvrirMainWindow(QString fileName);
};

#endif // ACCUEIL_H
