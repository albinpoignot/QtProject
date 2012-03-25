#ifndef TESTCLASSE_H
#define TESTCLASSE_H

/**
 * \file testclasse.h
 * \brief Tests unitaires
 * \author Albin Poignot
 *         Abdelnor Bousmina
 */


#include <QtTest/QtTest>

/*! \class TestClasse
   * \brief Tests unitaires
   *
   */
class TestClasse: public QObject
{
    Q_OBJECT
private slots:
    void testAddPoi();
    void testGetPoi();
    void testDeletePoi();

private:
    int nbRec;
public:
    TestClasse();
};

#endif // TESTCLASSE_H
