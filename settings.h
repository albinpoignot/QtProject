#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>

namespace Ui {
    class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
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
      * \brief To delete
      * \deprecated
      */
    void newCategorie(QString);
private:

    /**
      * \brief Interface utilisateur
      */
    Ui::Settings *ui;
};

#endif // SETTINGS_H
