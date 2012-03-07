#include "c_qdbc.h"

static QSqlDatabase db;

//static bool isDatabaseReady();

void C_qdbc::initDB(QString database)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(database);

    if(db.open())
    {
        QStringList tablesList = db.tables();

        if(tablesList.length() <= 0)
        {

            QSqlQuery query = QSqlQuery();
            bool res;
            res = query.exec("CREATE TABLE poi(categorie VARCHAR(255), nom VARCHAR(255), long INTEGER NOT NULL, lat INTEGER NOT NULL, UNIQUE(long,lat))");

            if(!res)
            {
                qDebug() << "*** ERREUR *** Initialisation de la BDD impossible ! ";
            }
        }
        db.close();
    }
    else
    {
        qDebug() << "*** ERREUR *** impossible d'ouvrir la BDD' ! ";
    }
}

void C_qdbc::addPoi(C_poi point)
{
    if(db.open())
    {
        QSqlQuery query;
        QString queryText = "INSERT INTO poi(categorie, nom, long, lat) VALUES('";

        queryText.append(point.getCat());
        queryText.append("','");
        queryText.append(point.getNom());
        queryText.append("',");
        queryText.append(QString().setNum(point.getPoint().rx(), 'g'));
        queryText.append(",");
        queryText.append(QString().setNum(point.getPoint().ry(), 'g'));
        queryText.append(")");

        bool res = query.exec(queryText);

        if(!res)
        {
            qDebug() << "*** ERREUR *** Impossible d'ajouter le point : " << point.getNom() << " !";
        }

        db.close();
    }
}

C_poi C_qdbc::getPoi(double lon, double lat)
{
    C_poi point;

    if(db.open())
    {
        QSqlQuery query;
        QString queryText = "SELECT * FROM poi WHERE long = " + QString::number(lon) + " AND lat = " + QString::number(lat);

        bool res = query.exec(queryText);

        if(!res)
        {
            qDebug() << "*** ERREUR *** Impossible d'obtenir le point : " << QString::number(lon) << " - " << QString::number(lat) << " !";
        }
        else
        {
            query.next();

            point = C_poi();
            point.setPoint(QPointF(lon, lat));
            point.setCat(query.value(0).toString());
            point.setNom(query.value(1).toString());
        }

        db.close();
    }

    return point;
}

QList<C_poi> C_qdbc::getAllPoi()
{
    QList<C_poi> points;
    C_poi point;

    if(db.open())
    {
        QSqlQuery query;
        QString queryText = "SELECT * FROM poi";

        bool res = query.exec(queryText);

        if(!res)
        {
            qDebug() << "*** ERREUR *** Impossible d'obtenir les points !";
        }
        else
        {
            points = QList<C_poi>();

            while(query.next())
            {
                point = C_poi();

                point.setCat(query.value(0).toString());
                point.setNom(query.value(1).toString());
                point.setPoint(QPointF(query.value(2).toFloat(), query.value(3).toFloat()));

                points.append(point);
            }
        }

        db.close();
    }

    return points;
}

/*static void updatePoi(double lon, double lat, C_poi point);

static void deletePoi(double lon, double lat);*/