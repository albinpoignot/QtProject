#include "c_poi.h"

C_poi::C_poi()
{
}

void C_poi::setCat(QString laCat)
{
    laCat.replace("'","\'");
    sCategorie = laCat;
}

void C_poi::setNom(QString leNom)
{
    leNom.replace("'","\'");
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

void C_poi::setDescription(QString laDescription)
{
    laDescription.replace("'","\\'");
    qDebug() << "setdescription:" << laDescription;
    sDescription = laDescription;
}

void C_poi::setHoraires(QString lesHoraires)
{
    sHoraires = lesHoraires;
}

QString C_poi::getDescription()
{
    return sDescription;
}

QString C_poi::getHoraires()
{
    return sHoraires;
}

QString C_poi::toString()
{
    return QString::number(this->getPoint().x()) + "," + QString::number(this->getPoint().y()) + " - " + this->getNom() +
            " - " + this->getCat() + " - " + this->getDescription() + " - " + this->getHoraires();
}
