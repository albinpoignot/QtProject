#ifndef C_DETAILS_H
#define C_DETAILS_H

/**
 * \file c_details.h
 * \brief Mise à jour des points d'intérêt
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include <QDialog>
#include <QMessageBox>

#include <QDebug>

#include "c_poi.h"
#include "c_qdbc.h"

/*! \namespace Ui
 *
 * espace de nommage regroupant les interfaces graphiques
 */
namespace Ui {
    class C_details;
}

/*! \class C_details
   * \brief Mise à jour des points d'intérêt
   *
   * Classe associée à l'interface permettant de modifier les points d'intérêt.
   */
class C_details : public QDialog
{
    Q_OBJECT

public:
    explicit C_details(QWidget *parent = 0);
    ~C_details();

    /**
      * \brief Pré-rempli les champs de l'interface
      * @param point Le point à afficher
      * @param catList La liste des catégories sélectionnables
      */
    void setDetails(C_poi point, QStringList catList);

signals:
    /**
      * \brief Emis lorsque la mise a jour de la BDD est terminée
      * @param point Le point qui a été mis à jour
      */
    void updateFinished(C_poi point);

private slots:
    /**
      * \brief Appelée lors de l'acception de la modification
      */
    void on_buttonBox_accepted();

    /**
      * \brief Appelée lors du refus de la modification
      */
    void on_buttonBox_rejected();

private:
    /**
      * \brief Interface utilisateur
      */
    Ui::C_details *ui;
};

#endif // C_DETAILS_H
