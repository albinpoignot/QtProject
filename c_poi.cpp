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

void C_poi::setPoint(QHash<float,float> lesPoints)
{
    hPoint = lesPoints;
}

QString C_poi::getCat()
{
    return sCategorie;
}

QString C_poi::getNom()
{
    return sNom;
}

QHash<float,float> C_poi::getPoint()
{
    return hPoint;
}
