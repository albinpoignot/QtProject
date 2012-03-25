/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created: Thu Mar 22 11:05:47 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Accueil
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Accueil)
    {
        if (Accueil->objectName().isEmpty())
            Accueil->setObjectName(QString::fromUtf8("Accueil"));
        Accueil->resize(539, 331);
        pushButton = new QPushButton(Accueil);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 100, 291, 71));
        pushButton_2 = new QPushButton(Accueil);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 180, 291, 71));
        label = new QLabel(Accueil);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 101, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setMargin(0);
        label_2 = new QLabel(Accueil);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 50, 441, 31));
        label_3 = new QLabel(Accueil);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 296, 171, 21));
        QFont font1;
        font1.setPointSize(8);
        label_3->setFont(font1);
        label_4 = new QLabel(Accueil);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 300, 61, 17));
        label_4->setFont(font1);

        retranslateUi(Accueil);

        QMetaObject::connectSlotsByName(Accueil);
    } // setupUi

    void retranslateUi(QDialog *Accueil)
    {
        Accueil->setWindowTitle(QApplication::translate("Accueil", "Accueil", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Accueil", "Ouvrir une base de donn\303\251es existante", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Accueil", "Cr\303\251er une nouvelle base de donn\303\251es", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Accueil", "Bienvenue", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Accueil", "Si c'est votre premi\303\250re visite, veuillez cr\303\251er une nouvelle base de donn\303\251es", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Accueil", "Abdelnor Bousmina - Albin Poignot", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Accueil", "Version 1.0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
