#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this,
                                                        "Open File",
                                                     "/home/bous/qt/",
                                                     "bdd (*.db)");

    if(fileName != NULL)
    {
        qDebug() << fileName;
        C_webservice ws(fileName);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    QString DbName = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("Nom de la bdd:"), QLineEdit::Normal,
                                           "QtProjectDB.db", &ok);
    if (ok && !DbName.isEmpty())
    {
        C_webservice ws(DbName);
    }
}
