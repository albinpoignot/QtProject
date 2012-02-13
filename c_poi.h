#ifndef C_POI_H
#define C_POI_H

#include <QString>
#include <QHash>

class C_poi
{
private:
    QString sCategorie;
    QString sNom;
    QHash<float, float> hPoint;
public:
    C_poi();
    void setCat(QString);
    void setNom(QString);
    void setPoint(QHash<float,float>);
    QString getCat();
    QString getNom();
    QHash<float,float> getPoint();
};

#endif // C_POI_H
