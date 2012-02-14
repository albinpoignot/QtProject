#ifndef C_POI_H
#define C_POI_H

#include <QString>
#include <QHash>

class C_poi
{
private:
    QString sCategorie;
    QString sNom;
    QHash<double, double> hPoint;
public:
    C_poi();
    void setCat(QString);
    void setNom(QString);
    void setPoint(QHash<double,double>);
    QString getCat();
    QString getNom();
    QHash<double,double> getPoint();
};

#endif // C_POI_H
