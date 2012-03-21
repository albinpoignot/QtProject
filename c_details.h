#ifndef C_DETAILS_H
#define C_DETAILS_H

#include <QDialog>
#include <QMessageBox>

#include <QDebug>

#include "c_poi.h"
#include "c_qdbc.h"

namespace Ui {
    class C_details;
}

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

private slots:
    /**
      * \brief Appelée lors de l'acception de la modification
      */
    void on_buttonBox_accepted();

    /**
      * \brief Appelée lors du refus de la modification
      */
    void on_buttonBox_rejected();

    /**
      * \brief To delete
      * \deprecated
      */
    void on_txtNom_textChanged(const QString &arg1);

    /**
      * \brief To delete
      * \deprecated
      */
    void on_txtNom_textEdited(const QString &arg1);

    /**
      * \brief To delete
      * \deprecated
      */
    void on_txtCategorie_textEdited(const QString &arg1);

    /**
      * \brief To delete
      * \deprecated
      */
    void on_txtDesc_textChanged();

    /**
      * \brief To delete
      * \deprecated
      */
    void on_txtDesc_undoAvailable(bool b);

private:
    /**
      * \brief Interface utilisateur
      */
    Ui::C_details *ui;
};

#endif // C_DETAILS_H
