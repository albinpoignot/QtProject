#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "c_webservice.h"
#include <QMessageBox>
#include <QFileDialog>
#include "qmapcontrol.h"
#include <QVBoxLayout>
#include <QWidget>

using namespace qmapcontrol;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


private:
    Ui::MainWindow *ui;
    void openQmapControl();
};

#endif // MAINWINDOW_H
