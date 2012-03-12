#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>
#include <QInputDialog>
#include "c_webservice.h"
#include <QMessageBox>
#include <QFileDialog>
#include "qmapcontrol.h"
#include <QVBoxLayout>
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
    class Accueil;
}

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
    Ui::Accueil *ui;

    /**
      * \brief Ouvre la fenetre parente et renseigne la BDD fournie
      * @param fileName Nom de la BDD
      */
    void ouvrirMainWindow(QString fileName);
    MainWindow * mw;
    C_webservice * ws;
};

#endif // ACCUEIL_H
