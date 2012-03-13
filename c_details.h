#ifndef C_DETAILS_H
#define C_DETAILS_H

#include <QDialog>
#include <QDebug>
#include "c_poi.h"
#include "c_qdbc.h"

namespace Ui {
    class C_details;
}

class C_details : public QDialog
{
    Q_OBJECT

public:
    explicit C_details(QWidget *parent = 0);
    ~C_details();
    void setDetails(C_poi);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::C_details *ui;
};

#endif // C_DETAILS_H
