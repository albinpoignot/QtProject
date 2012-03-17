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
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
signals:
       void newCategorie(QString);
private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
