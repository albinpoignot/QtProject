#ifndef C_MODEEMPLOI_H
#define C_MODEEMPLOI_H

/**
 * \file c_modeemploi.h
 * \brief mode d'emploi de l'application
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include <QDialog>
#include <QFile>
#include <QTextStream>

/*! \namespace Ui
 *
 * espace de nommage regroupant les interfaces graphiques
 */
namespace Ui {
    class C_modeEmploi;
}

/*! \class C_modeEmploi
   * \brief mode d'emploi de l'application
   *
   * Classe associée à l'interface permettant d'afficher le mode d'emploi
   */
class C_modeEmploi : public QDialog
{
    Q_OBJECT

public:
    explicit C_modeEmploi(QWidget *parent = 0);
    ~C_modeEmploi();

    /**
      * \brief Spécifie à la fenêter que la langue du programme a changé et charge donc la traduction
      */
    void changeLang();

private:
    Ui::C_modeEmploi *ui;
};

#endif // C_MODEEMPLOI_H
