#ifndef C_QDBC_H
#define C_QDBC_H

#include "c_poi.h"

#include <QString>
#include <QStringList>
#include <QDebug>

#include <QVariant>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class C_qdbc
{
private:

    /**
      * \brief Retourne TRUE si la BDD est prête, FALSE sinon
      */
    static bool isDatabaseReady();

public:

    /**
      * \brief Initialise une base de données
      * @param database : chemin de la bdd (ex: /home/user/project/database.db)
      */
    static void initDB(QString database);

    /**
      * \brief Ajout d'un POI
      * @param point : POI a ajouter
      */
    static void addPoi(C_poi point);

    /**
      * \brief Obtention d'un POI
      * @param lon : longitude du point voulu
      * @param lat : latitude du point voulu
      */
    static C_poi getPoi(double lon, double lat);

    /**
      * \brief Obtention de tous les POI
      */
    static QList<C_poi> getAllPoi();

    /**
      * \brief Mise à jour d'un POI
      * @param lon : longitude du point à modifier
      * @param lat : latitude du point à modifier
      * @param point : nouveau point (lon et lat ne doivent pas changer)
      */
    static void updatePoi(double lon, double lat, C_poi point);

    /**
      * \brief Suppression d'un POI
      * @param lon : longitude du point à supprimer
      * @param lat : latitude du point à supprimer
      */
    static void deletePoi(double lon, double lat);
};

#endif // C_QDBC_H