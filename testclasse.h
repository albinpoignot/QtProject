#ifndef TESTCLASSE_H
#define TESTCLASSE_H

#include <QtTest/QtTest>

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
