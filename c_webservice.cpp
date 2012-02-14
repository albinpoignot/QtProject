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

     //qDebug() << string;

     QDomDocument domDoc;
     domDoc.setContent(string);

     //qDebug() << domDoc.childNodes().item(0).childNodes().item(0).childNodes().item(0).nodeName();
     /*qDebug() << domDoc.childNodes().item(1).nodeName();

     // DOCUMENT
     qDebug() << domDoc.childNodes().item(1).childNodes().item(0).nodeName();

     // Placemark
     qDebug() << domDoc.childNodes().item(1).childNodes().item(0).childNodes().item(0).nodeName();

     // nom
     qDebug() << domDoc.childNodes().item(1).childNodes().item(0).childNodes().item(0).childNodes().item(1).nodeName();

     // LE nom
     qDebug() << domDoc.childNodes().item(1).childNodes().item(0).childNodes().item(0).childNodes().item(1).firstChild().nodeValue();*/

     insertReply(string);
 }

 void C_webservice::insertReply(QString str)
 {
     // STEP 1 : Init variables
     QDomDocument domDoc;
     domDoc.setContent(str);

     QDomNode document = domDoc.childNodes().item(1).childNodes().item(0);
     QDomNode currentNode;
     QPointF currentPos;
     QString currentPoint;
     QStringList currentPointList;

     //QDomNodeList currentNode_children;

     C_poi poi;

     // STEP 2 : Iterate over nodes and set variables
     int i, j;

     QDomNodeList placemarks = domDoc.elementsByTagName("Placemark");

     // STEP 3 : Parse data
     for(j=0; j < placemarks.count(); j++)
     {
         // Get the current placemark
         currentNode = placemarks.at(j);
         //currentNode_children = currentNode.childNodes();

         // Create a new POI and set properties
         poi = C_poi();
         poi.setCat(domDoc.elementsByTagName("categorie").at(j).firstChild().nodeValue());
         poi.setNom(domDoc.elementsByTagName("nom").at(j).firstChild().nodeValue());

         // Special case for Coordinates where we have to split the result and cast in double
         currentPoint = domDoc.elementsByTagName("coordinates").at(j).firstChild().nodeValue();
         currentPointList = currentPoint.split(",");

         currentPos = QPointF();
         currentPos.setX(currentPointList.at(0).toFloat());
         currentPos.setY(currentPointList.at(1).toFloat());
         //currentPos.insert(currentPointList.at(0).toDouble(),currentPointList.at(1).toDouble());

         //poi.setPoint(domDoc.elementsByTagName("categorie").at(j).firstChild().nodeValue());
     }


 }
