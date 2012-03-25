#ifndef C_QDBC_H
#define C_QDBC_H

/**
 * \file c_qdbc.h
 * \brief offre des methodes d'intéraction avec la base de données
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */

#include "c_poi.h"

#include <QString>
#include <QStringList>
#include <QDebug>

#include <QVariant>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/*! \class C_qdbc
   * \brief classe offrant des methodes d'intéraction avec la base de données
   *
   */
class C_qdbc
{
private:

    /**
      * \brief Retourne TRUE si la BDD est prête, FALSE sinon
      */
    static bool isDatabaseReady();

signals:
    /**
      * \brief Emis lorsque la mise a jour de la BDD est terminée
      */
    static void updateFinished();


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
      * \brief Suppression d'un POI
      * @param lon : longitude du point à supprimer
      * @param lat : latitude du point à supprimer
      */
    static void deletePoi(double lon, double lat);

    /**
      * \brief Suppression d'un POI
      * @param point : le point à modifier
      */
    static void deletePoi(C_poi point);

    /**
      * \brief Supprime la base de données
      */
    static void removeDb();

    /**
      * \brief Mise à jour d'un POI
      * @param point : nouveau point (lon et lat ne doivent pas changer)
      */
    static void updatePoi(C_poi point);
};

#endif // C_QDBC_H
