#ifndef C_POI_H
#define C_POI_H

/**
 * \file c_poi.h
 * \brief définie le model d'un point d'intérêt
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include <QString>
#include <QHash>
#include <QPointF>
#include <QDebug>

/*! \class C_poi
   * \brief définie le model d'un point d'intérêt
   *
   */
class C_poi
{
private:
    QString sCategorie;
    QString sNom;
    QString sDescription;
    QString sHoraires;
    QPointF pPoint;

public:
    C_poi();
    void setCat(QString);
    void setNom(QString);    
    void setHoraires(QString);
    void setDescription(QString);
    void setPoint(QPointF);
    QString getHoraires();
    QString getDescription();
    QString getCat();
    QString getNom();
    QPointF getPoint();
    QString toString();
};

#endif // C_POI_H
