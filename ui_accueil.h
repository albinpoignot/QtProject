/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created: Thu Mar 15 15:37:33 2012
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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Accueil
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Accueil)
    {
        if (Accueil->objectName().isEmpty())
            Accueil->setObjectName(QString::fromUtf8("Accueil"));
        Accueil->resize(400, 300);
        pushButton = new QPushButton(Accueil);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(47, 36, 291, 71));
        pushButton_2 = new QPushButton(Accueil);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(47, 126, 291, 71));

        retranslateUi(Accueil);

        QMetaObject::connectSlotsByName(Accueil);
    } // setupUi

    void retranslateUi(QDialog *Accueil)
    {
        Accueil->setWindowTitle(QApplication::translate("Accueil", "Accueil", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Accueil", "ouvrir une base de donn\303\251es existante", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Accueil", "ouvrir une nouvelle base de donn\303\251es", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
