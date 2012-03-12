#ifndef C_WEBSERVICE_H
#define C_WEBSERVICE_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDomDocument>
#include <QDomNode>
#include <QXmlInputSource>
#include <QXmlReader>
#include <QXmlSimpleReader>
#include <QUrl>
#include <QVariant>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "c_qdbc.h"
#include "c_poi.h"

#include <QDebug>


class C_webservice:public QObject
{

    Q_OBJECT
private:
     QSqlDatabase db;

     /**
       * Parse le résultat et insère le tout dans la base de données SQLite
       * @param Le résultat d'une requête à parser
       */
     void parseAndInsert(QString);

     /**
       * Ajout un point d'intéret à la base de données SQLite
       * @param poi Le point d'intérêt à ajouter
       */
     void addPOIToDB(C_poi poi);

private slots:
    /**
      * Appelée à la fin d'une requete. Récupère le résultat et appelle parseAndInsert()
      * @param rep Requete qui vient d'etre terminée
      */
     void replyFinished(QNetworkReply* rep);

signals:
     void requestFinished();

public:
    /*!
      * Récupère le XML du point ?
      * @param lat Latitude du POI
      * @param lon Longitude du POI
      */
    void getPOI(double lat,double lon);


};

#endif // C_WEBSERVICE_H
