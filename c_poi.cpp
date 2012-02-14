#include "c_poi.h"

C_poi::C_poi()
{
}

void C_poi::setCat(QString laCat)
{
    sCategorie = laCat;
}

void C_poi::setNom(QString leNom)
{
    sNom = leNom;
}

void C_poi::setPoint(QPointF lePoint)
{
    pPoint = lePoint;
}

QString C_poi::getCat()
{
    return sCategorie;
}

QString C_poi::getNom()
{
    return sNom;
}

QPointF C_poi::getPoint()
{
    return pPoint;
}
