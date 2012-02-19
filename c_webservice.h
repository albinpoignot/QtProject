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

#include "c_poi.h"

#include <QDebug>

class C_webservice:public QObject
{

    Q_OBJECT
private:
     QSqlDatabase db;
     void insertReply(QString);
     void addPOIToDB(C_poi);

private slots:
    void replyFin(QNetworkReply*);

public:
    C_webservice();
    C_webservice(QString);

    /*!
      * Récupère le XML du point ?
      * @param lat Latitude du POI
      * @param lon Longitude du POI
      */
    void getPOI(double lat,double lon);


};

#endif // C_WEBSERVICE_H
