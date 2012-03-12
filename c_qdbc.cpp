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
            res = query.exec("CREATE TABLE poi(categorie VARCHAR(255), nom VARCHAR(255), long INTEGER NOT NULL, lat INTEGER NOT NULL, description VARCHAR(255), horaires VARCHAR(255), UNIQUE(long,lat))");

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
            qDebug() << "*** ERREUR *** Impossible d'ajouter le point : " + point.getNom() + " (" +
                        QString::number(point.getPoint().x()) + " - " + QString::number(point.getPoint().y()) + ")";
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
            qDebug() << "*** ERREUR *** Impossible d'obtenir le point : " + QString::number(lon) + " - "
                     + QString::number(lat) + " !";
        }
        else
        {
            query.next();

            point = C_poi();
            point.setPoint(QPointF(lon, lat));
            point.setCat(query.value(0).toString());
            point.setNom(query.value(1).toString());
            if(query.value(2).toString() != NULL)
                point.setDescription(query.value(2).toString());
            if(query.value(3).toString() != NULL)
                point.setHoraires(query.value(3).toString());
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
                 if(query.value(4).toString() != NULL)
                point.setDescription(query.value(4).toString());
                  if(query.value(5).toString() != NULL)
                point.setHoraires(query.value(5).toString());

                points.append(point);
            }
        }

        db.close();
    }

    return points;
}


void C_qdbc::updatePoi(C_poi point)
{
    if(db.open())
    {
        QSqlQuery query;
        QString queryText = "UPDATE poi SET categorie = '" + point.getCat() + "', nom = '" + point.getNom() + "', description ='" + point.getDescription()
                + "', horaires = '" + point.getHoraires() + "'";
        queryText.append(" WHERE long = " + QString::number(point.getPoint().x()) + " AND lat = " + QString::number(point.getPoint().y()));

        qDebug() << queryText;

        bool res = query.exec(queryText);

        if(!res)
        {
            qDebug() << "*** ERREUR *** Impossible de modifier le point : " + point.getNom() << " (" <<
                        QString::number(point.getPoint().x()) + " - " << QString::number(point.getPoint().y()) << ")";
        }

        db.close();
    }
}


void C_qdbc::deletePoi(double lon, double lat)
{
    if(db.open())
    {
        QSqlQuery query;
        QString queryText = "DELETE FROM poi WHERE long = " + QString::number(lon) + " AND lat = " + QString::number(lat);

        qDebug() << queryText;

        bool res = query.exec(queryText);

        if(!res)
        {
            qDebug() << "*** ERREUR *** Impossible de supprimer le point : " + QString::number(lon) + " - " + QString::number(lat);
        }

        db.close();
    }
}

void C_qdbc::deletePoi(C_poi point)
{
    deletePoi(point.getPoint().x(), point.getPoint().y());
}
