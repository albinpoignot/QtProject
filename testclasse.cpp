#include "testclasse.h"
#include "c_poi.h"
#include "c_qdbc.h"

TestClasse::TestClasse()
{
    C_qdbc::initDB(QDir::currentPath() + "/testDB.db");
}

void TestClasse::testAddPoi()
{
    C_poi point = C_poi();
    QPointF coord(100,100);
    point.setNom("TestPoint");
    point.setPoint(coord);

    nbRec = C_qdbc::getAllPoi().size();

    C_qdbc::addPoi(point);

    QCOMPARE(nbRec + 1, C_qdbc::getAllPoi().size());
}

void TestClasse::testGetPoi()
{
    C_poi point;

    point = C_qdbc::getPoi(100,100);

    QVERIFY(point.getNom() == "TestPoint");
}

void TestClasse::testDeletePoi()
{
    C_qdbc::deletePoi(100,100);
    QCOMPARE(nbRec, C_qdbc::getAllPoi().size());
}
