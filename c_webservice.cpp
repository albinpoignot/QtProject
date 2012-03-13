#include "c_webservice.h"


void C_webservice::getPOI(double lon,double lat)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QString requete;
    QVariant parser;

    requete = "http://www.geovelo.fr/api_test.php?lon=";
    parser.setValue(lon);
    requete.append(parser.toString());

    requete.append("&lat=");
    parser.setValue(lat);
    requete.append(parser.toString());

    QUrl url = QUrl(requete);

    manager->get(QNetworkRequest(url));

    connect(manager, SIGNAL(finished(QNetworkReply*)),
         this, SLOT(replyFinished(QNetworkReply*)));

    qDebug() << "getPOI - " << requete;
}

void C_webservice::replyFinished(QNetworkReply* rep)
{
    //qDebug("Reponse : ");

    QString string;
    string.append(rep->readAll());

    //qDebug() << string;

    QDomDocument domDoc;
    domDoc.setContent(string);

    rep->deleteLater();

    parseAndInsert(string);
}

void C_webservice::parseAndInsert(QString str)
{
    // STEP 1 : Init variables
    QDomDocument domDoc;
    domDoc.setContent(str);

    QDomNode currentNode;
    QPointF currentPos;
    QString currentPoint;
    QStringList currentPointList;

    qDebug() << "parse and insert";

    C_poi poi;

    // STEP 2 : Iterate over nodes and set variables
    int i;

    QDomNodeList placemarks = domDoc.elementsByTagName("Placemark");

    // STEP 3 : Parse data
    for(i=0; i < placemarks.count(); i++)
    {
        // Get the current placemark
        currentNode = placemarks.at(i);

        // Create a new POI and set properties
        poi = C_poi();
        poi.setCat(domDoc.elementsByTagName("categorie").at(i).firstChild().nodeValue());
        poi.setNom(domDoc.elementsByTagName("nom").at(i).firstChild().nodeValue());

        // Special case for Coordinates where we have to split the result and cast in double
        currentPoint = domDoc.elementsByTagName("coordinates").at(i).firstChild().nodeValue();
        currentPointList = currentPoint.split(",");

        currentPos = QPointF();
        currentPos.setX(currentPointList.at(0).toFloat());
        currentPos.setY(currentPointList.at(1).toFloat());

        poi.setPoint(currentPos);

        //qDebug() << poi.getCat();

        // STEP 4 : Add the POI in the database
        //addPOIToDB(poi);
        C_qdbc::addPoi(poi);

    }

    //this->deleteLater();
    emit requestFinished();

    qDebug() << "-> Requête terminée";
}
/*
void C_webservice::addPOIToDB(C_poi poi)
{
    if(db.open())
    {
        QSqlQuery query;
        QString queryText = "INSERT INTO poi(categorie, nom, long, lat) VALUES('";

        queryText.append(poi.getCat());
        queryText.append("','");
        queryText.append(poi.getNom());
        queryText.append("',");
        queryText.append(QString().setNum(poi.getPoint().rx(), 'g'));
        queryText.append(",");
        queryText.append(QString().setNum(poi.getPoint().ry(), 'g'));
        queryText.append(")");

        bool res = query.exec(queryText);

        if(!res)
        {
            qDebug() << "*** ERREUR *** Impossible d'ajouter le point : " << poi.getNom() << " !";
        }

        db.close();
    }
}*/
