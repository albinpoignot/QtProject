/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Mar 19 23:16:42 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *en;
    QAction *fr;
    QAction *es;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QLabel *catGorieLabel;
    QLabel *nomOuCategorieLabel;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QListView *listView;
    QToolButton *toolButton_2;
    QPushButton *btnExport;
    QMenuBar *menuBar;
    QMenu *menuLangages;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 648);
        MainWindow->setMinimumSize(QSize(50, 50));
        en = new QAction(MainWindow);
        en->setObjectName(QString::fromUtf8("en"));
        en->setCheckable(false);
        fr = new QAction(MainWindow);
        fr->setObjectName(QString::fromUtf8("fr"));
        es = new QAction(MainWindow);
        es->setObjectName(QString::fromUtf8("es"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 781, 381));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 19, 761, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 400, 91, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(600, 447, 116, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(600, 490, 91, 27));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(700, 490, 91, 27));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 550, 88, 27));
        catGorieLabel = new QLabel(centralWidget);
        catGorieLabel->setObjectName(QString::fromUtf8("catGorieLabel"));
        catGorieLabel->setGeometry(QRect(60, 440, 116, 32));
        nomOuCategorieLabel = new QLabel(centralWidget);
        nomOuCategorieLabel->setObjectName(QString::fromUtf8("nomOuCategorieLabel"));
        nomOuCategorieLabel->setGeometry(QRect(420, 450, 141, 16));
        nomOuCategorieLabel->setAcceptDrops(false);
        nomOuCategorieLabel->setAutoFillBackground(false);
        nomOuCategorieLabel->setLineWidth(1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 550, 81, 27));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(420, 490, 131, 27));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(300, 550, 30, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8("button_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(60, 470, 231, 111));
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(300, 514, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("button_add_files/button_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        btnExport = new QPushButton(centralWidget);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));
        btnExport->setGeometry(QRect(20, 400, 111, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 50));
        menuBar->setMinimumSize(QSize(50, 50));
        menuBar->setBaseSize(QSize(50, 50));
        menuLangages = new QMenu(menuBar);
        menuLangages->setObjectName(QString::fromUtf8("menuLangages"));
        menuLangages->setEnabled(true);
        menuLangages->setMinimumSize(QSize(50, 50));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuLangages->menuAction());
        menuLangages->addAction(en);
        menuLangages->addAction(fr);
        menuLangages->addAction(es);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vos POI", 0, QApplication::UnicodeUTF8));
        en->setText(QApplication::translate("MainWindow", "Anglais", 0, QApplication::UnicodeUTF8));
        fr->setText(QApplication::translate("MainWindow", "Fran\303\247ais", 0, QApplication::UnicodeUTF8));
        es->setText(QApplication::translate("MainWindow", "Espagnol", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "carte", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Modifier les points d'int\303\251r\303\252t", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Filtres", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "A proximit\303\251 de :", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Filtrez", 0, QApplication::UnicodeUTF8));
        catGorieLabel->setText(QApplication::translate("MainWindow", "Cat\303\251gories : ", 0, QApplication::UnicodeUTF8));
        nomOuCategorieLabel->setText(QApplication::translate("MainWindow", "Nom ou description :", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Filtrez", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("MainWindow", "Ajouter une cat\303\251gorie dans la liste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        btnExport->setText(QApplication::translate("MainWindow", "Exporter en CSV", 0, QApplication::UnicodeUTF8));
        menuLangages->setTitle(QApplication::translate("MainWindow", "Langages", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
