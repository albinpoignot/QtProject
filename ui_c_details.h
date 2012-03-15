/********************************************************************************
** Form generated from reading UI file 'c_details.ui'
**
** Created: Thu Mar 15 15:37:33 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_DETAILS_H
#define UI_C_DETAILS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_C_details
{
public:
    QLineEdit *txtLongitude;
    QLineEdit *txtLatitude;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtNom;
    QTextEdit *txtDesc;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *txtHoraires;
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QLineEdit *txtCategorie;

    void setupUi(QDialog *C_details)
    {
        if (C_details->objectName().isEmpty())
            C_details->setObjectName(QString::fromUtf8("C_details"));
        C_details->resize(304, 260);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(C_details->sizePolicy().hasHeightForWidth());
        C_details->setSizePolicy(sizePolicy);
        C_details->setMinimumSize(QSize(0, 0));
        C_details->setMaximumSize(QSize(9999, 9999));
        C_details->setCursor(QCursor(Qt::ArrowCursor));
        C_details->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"}"));
        C_details->setModal(false);
        txtLongitude = new QLineEdit(C_details);
        txtLongitude->setObjectName(QString::fromUtf8("txtLongitude"));
        txtLongitude->setGeometry(QRect(90, 40, 51, 27));
        txtLongitude->setCursor(QCursor(Qt::ArrowCursor));
        txtLongitude->setStyleSheet(QString::fromUtf8(""));
        txtLongitude->setReadOnly(true);
        txtLatitude = new QLineEdit(C_details);
        txtLatitude->setObjectName(QString::fromUtf8("txtLatitude"));
        txtLatitude->setGeometry(QRect(190, 40, 51, 27));
        txtLatitude->setCursor(QCursor(Qt::ArrowCursor));
        txtLatitude->setStyleSheet(QString::fromUtf8(""));
        txtLatitude->setReadOnly(true);
        label = new QLabel(C_details);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 41, 17));
        label_2 = new QLabel(C_details);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 40, 31, 17));
        txtNom = new QLineEdit(C_details);
        txtNom->setObjectName(QString::fromUtf8("txtNom"));
        txtNom->setGeometry(QRect(20, 10, 261, 27));
        txtNom->setStyleSheet(QString::fromUtf8(""));
        txtDesc = new QTextEdit(C_details);
        txtDesc->setObjectName(QString::fromUtf8("txtDesc"));
        txtDesc->setGeometry(QRect(80, 120, 201, 31));
        txtDesc->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(C_details);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 51, 17));
        label_4 = new QLabel(C_details);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 51, 17));
        txtHoraires = new QTextEdit(C_details);
        txtHoraires->setObjectName(QString::fromUtf8("txtHoraires"));
        txtHoraires->setGeometry(QRect(80, 160, 201, 41));
        txtHoraires->setStyleSheet(QString::fromUtf8(""));
        buttonBox = new QDialogButtonBox(C_details);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 220, 176, 27));
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_5 = new QLabel(C_details);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 80, 61, 17));
        txtCategorie = new QLineEdit(C_details);
        txtCategorie->setObjectName(QString::fromUtf8("txtCategorie"));
        txtCategorie->setGeometry(QRect(80, 80, 201, 27));
        txtCategorie->setCursor(QCursor(Qt::ArrowCursor));
        txtCategorie->setStyleSheet(QString::fromUtf8(""));
        txtCategorie->setReadOnly(false);

        retranslateUi(C_details);

        QMetaObject::connectSlotsByName(C_details);
    } // setupUi

    void retranslateUi(QDialog *C_details)
    {
        C_details->setWindowTitle(QApplication::translate("C_details", "D\303\251tails d'un POI", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("C_details", "Long.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("C_details", "Lat.", 0, QApplication::UnicodeUTF8));
        txtNom->setText(QString());
        label_3->setText(QApplication::translate("C_details", "Desc.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("C_details", "Horaires", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("C_details", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class C_details: public Ui_C_details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_DETAILS_H
