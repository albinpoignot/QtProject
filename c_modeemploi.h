#ifndef C_MODEEMPLOI_H
#define C_MODEEMPLOI_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
    class C_modeEmploi;
}

class C_modeEmploi : public QDialog
{
    Q_OBJECT

public:
    explicit C_modeEmploi(QWidget *parent = 0);
    ~C_modeEmploi();
    void changeLang();

private:
    Ui::C_modeEmploi *ui;
};

#endif // C_MODEEMPLOI_H
