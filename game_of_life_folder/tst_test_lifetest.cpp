#include <QString>
#include <QtTest>
#include "life.h"

class Test_lifeTest : public QObject
{
    Q_OBJECT

public:
    Test_lifeTest();

private Q_SLOTS:
    void testCaseCommon();
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();
    void testEqualOp();
};

Test_lifeTest::Test_lifeTest()
{
}

void Test_lifeTest::testCaseCommon()
{
    const unsigned int X = 10, Y= 12;
    Life *l = new Life(X, Y);
    Life *nl = new Life(X, Y);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests

    QVERIFY(l->Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    QVERIFY(l->Get_cell_life(0, 0) == true); //  Check if cell alive with correct index

    QVERIFY(l->Set_cell_dead(0, 0) == true); //  Make cell dead with correct index
    QVERIFY(l->Get_cell_life(0, 0) == false);//  Get cell not alive with correct index

    QVERIFY(l->Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(0, 0) ==false);//  Cell must be dead
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase1()
{
    const unsigned int X = 10, Y= 12;
    Life *l = new Life(X, Y);
    Life *nl = new Life(X, Y);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  1. Any live cell with fewer than two live neighbours dies, as if caused by under-population
    //  Make horisontal test
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(1, 0);
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(0, 0) == false);
    QVERIFY(nl->Get_cell_life(1, 0) == false);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make vertical test
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(0, 1);
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(0, 0) == false);
    QVERIFY(nl->Get_cell_life(0, 1) == false);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make diagonal test
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(1, 1);
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(0, 0) == false);
    QVERIFY(nl->Get_cell_life(1, 1) == false);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase2()
{
    //  2. Any live cell with two or three live neighbours lives on to the next generation.
    const unsigned int X = 10, Y= 12;
    Life *l = new Life(X, Y);
    Life *nl = new Life(X, Y);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|_|_|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(1, 0);
    l->Set_cell_alive(2, 0);
    l->Set_cell_alive(1, 1);    //  Cell under test
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == true);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make vertical test and check with two neighbours
    /*
    ______
    |X|_|_|
    |_|T|_|
    |X|_|_|
    */
    l->Set_cell_alive(0, 0);
    //l->set_cell_alive(0, 1);
    l->Set_cell_alive(0, 2);
    l->Set_cell_alive(1, 1);    //  Cell under test
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == true);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make diagonal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|_|X|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(0, 2);
    l->Set_cell_alive(2, 2);
    l->Set_cell_alive(1, 1);    //  Cell under test
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == true);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase3()
{
    //  3. Any live cell with more than three live neighbours dies, as if by overcrowding.
    const unsigned int X = 10, Y = 12;
    Life *l = new Life(X, Y);
    Life *nl = new Life(X, Y);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|X|
    |_|_|_|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(1, 0);
    l->Set_cell_alive(2, 0);
    l->Set_cell_alive(2, 1);
    l->Set_cell_alive(1, 1);    //  Cell under test
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == false);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    ////////////////////////////////////////////////////////////////////////
    //  Make vertical test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|X|_|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(0, 1);
    l->Set_cell_alive(1, 0);
    l->Set_cell_alive(0, 2);
    l->Set_cell_alive(1, 1);    //  Cell under test
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == false);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase4()
{

    //  4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    const unsigned int X = 10, Y= 12;
    Life *l = new Life(X, Y);
    Life *nl = new Life(X, Y);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|X|_|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(1, 0);
    l->Set_cell_alive(2, 0);
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == true);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make vertical test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|X|_|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(0, 1);
    l->Set_cell_alive(0, 2);
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == true);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
    //  Make diagonal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|X|_|
    */
    l->Set_cell_alive(0, 0);
    l->Set_cell_alive(0, 2);
    l->Set_cell_alive(2, 2);
    l->Clclt(nl);
    QVERIFY(nl->Get_cell_life(1, 1) == true);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testEqualOp()
{
    const unsigned int X = 10, Y= 12;

    Life *l = new Life(X, Y);
    Life *nl = new Life(X, Y);
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests

    QVERIFY(l->Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    *nl = *l;
    QVERIFY(nl->Get_cell_life(0, 0) == true);   //  Check if cell is alive
    l->Clr();
    nl->Clr();  //  Clear both matrix to make tests
}

QTEST_APPLESS_MAIN(Test_lifeTest)

#include "tst_test_lifetest.moc"
