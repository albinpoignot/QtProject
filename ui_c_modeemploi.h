/********************************************************************************
** Form generated from reading UI file 'c_modeemploi.ui'
**
** Created: Wed Mar 21 19:37:48 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_MODEEMPLOI_H
#define UI_C_MODEEMPLOI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_C_modeEmploi
{
public:
    QPushButton *b_fermer;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *C_modeEmploi)
    {
        if (C_modeEmploi->objectName().isEmpty())
            C_modeEmploi->setObjectName(QString::fromUtf8("C_modeEmploi"));
        C_modeEmploi->resize(465, 320);
        b_fermer = new QPushButton(C_modeEmploi);
        b_fermer->setObjectName(QString::fromUtf8("b_fermer"));
        b_fermer->setGeometry(QRect(350, 280, 101, 31));
        label = new QLabel(C_modeEmploi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 10, 111, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        textEdit = new QTextEdit(C_modeEmploi);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 40, 421, 221));

        retranslateUi(C_modeEmploi);

        QMetaObject::connectSlotsByName(C_modeEmploi);
    } // setupUi

    void retranslateUi(QDialog *C_modeEmploi)
    {
        C_modeEmploi->setWindowTitle(QApplication::translate("C_modeEmploi", "Dialog", 0, QApplication::UnicodeUTF8));
        b_fermer->setText(QApplication::translate("C_modeEmploi", "Fermer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("C_modeEmploi", "Mode d'emploi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class C_modeEmploi: public Ui_C_modeEmploi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_MODEEMPLOI_H
