#ifndef C_POI_H
#define C_POI_H

#include <QString>
#include <QHash>
#include <QPointF>

class C_poi
{
private:
    QString sCategorie;
    QString sNom;
    QString sDescription;
    QString sHoraires;
    //QHash<double, double> hPoint;
    QPointF pPoint;

public:
    C_poi();
    void setCat(QString);
    void setNom(QString);    
    void setHoraires(QString);
    void setDescription(QString);
    void setPoint(QPointF);
    QString getHoraires(QString);
    QString getDescription(QString);
    QString getCat();
    QString getNom();
    QPointF getPoint();
};

#endif // C_POI_H
