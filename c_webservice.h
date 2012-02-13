#ifndef C_WEBSERVICE_H
#define C_WEBSERVICE_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QUrl>
#include <QVariant>


#include <QDebug>

class C_webservice:public QObject
{

    Q_OBJECT

private slots:
    void replyFin(QNetworkReply*);

public:
    C_webservice();

    /*!
      * Récupère le XML du point ?
      * @param lat Latitude du POI
      * @param lon Longitude du POI
      */
    void getPOI(double lat,double lon);


};

#endif // C_WEBSERVICE_H
