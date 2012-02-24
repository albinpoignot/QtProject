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
    void setW(MainWindow * );

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Accueil *ui;
    void ouvrirMainWindow(QString );
    MainWindow * mw;
};

#endif // ACCUEIL_H
