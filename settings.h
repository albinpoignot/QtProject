#ifndef SETTINGS_H
#define SETTINGS_H

/**
 * \file settings.h
 * \brief configuration de l'application
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include <QDialog>
#include <QSettings>

/*! \namespace Ui
 *
 * espace de nommage regroupant les interfaces graphiques
 */
namespace Ui {
    class Settings;
}

/*! \class Settings
   * \brief configuration de l'application
   *
   * Classe associée à l'interface graphique permettant d'ajouter une nouvelle catégorie
   */
class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    void changeLang();
private slots:

    /**
      * \brief Appelée lors de l'acception de l'ajout d'une nouvelle catégorie
      */
    void on_buttonBox_accepted();

    /**
      * \brief Appelée lors du refus de l'ajout d'une nouvelle catégorie
      */
    void on_buttonBox_rejected();
signals:
    /**
      * \brief Signal émis lorsqu'une nouvelle catégorie a été spécifiée par l'utilisateur
      */
    void newCategorie(QString);
private:

    /**
      * \brief Interface utilisateur
      */
    Ui::Settings *ui;
};

#endif // SETTINGS_H
