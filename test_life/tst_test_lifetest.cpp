#include <QString>
#include <QtTest>
#include "life.h"

class Test_lifeTest : public QObject
{
    Q_OBJECT

public:
    Test_lifeTest();

private Q_SLOTS:
    void testCase1();
};

Test_lifeTest::Test_lifeTest()
{
}

void Test_lifeTest::testCase1()
{
    life *l = new life(10, 10);
    QVERIFY(l->set_cell_alive(0, 0) == true); //  Make live cell with correct index
    QVERIFY(l->get_cell_life(0, 0) == true); //  Check if cell alive with correct index

    QVERIFY(l->set_cell_dead(0, 0) == true); //  Make cell dead with correct index
    QVERIFY(l->get_cell_life(0, 0) == false);//  Get cell not alive with correct index

    QVERIFY(l->set_cell_alive(0, 0) == true); //  Make live cell with correct index
    life *nl = new life(10, 10);
    l->clclt(nl);
    QVERIFY(nl->get_cell_life(0, 0) ==false);//  Cell must be dead
}

QTEST_APPLESS_MAIN(Test_lifeTest)

#include "tst_test_lifetest.moc"
