#include "c_webservice.h"

C_webservice::C_webservice()
{
}

 void C_webservice::getPOI(double lat,double lon)
 {
     QNetworkAccessManager *manager = new QNetworkAccessManager(this);

     connect(manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(replyFin(QNetworkReply*)));

     QString requete;
     QVariant parser;
     QNetworkReply *reply;

     requete = "http://www.geovelo.fr/api_test.php?lon=";
     parser.setValue(lon);
     requete.append(parser.toString());

     requete.append("&lat=");
     parser.setValue(lat);
     requete.append(parser.toString());

     //qDebug() << requete;

     QUrl url = QUrl(requete);

     reply = manager->get(QNetworkRequest(url));
 }

 void C_webservice::replyFin(QNetworkReply* rep)
 {
     qDebug("Reponse : ");

     QString string;
     string.append(rep->readAll());

     qDebug() << string;


     /*while(rep->)
     {

     }*/
 }
