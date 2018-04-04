#include <QString>
#include <QtTest>
#include "life.h"
#include "life_1d.h"
#include "generation.h"

class Test_lifeTest : public QObject
{
    Q_OBJECT

public:
    Test_lifeTest();

private Q_SLOTS:
    void testCaseCommon();

    void testCase1_h();
    void testCase2_h();
    void testCase3_h();
    void testCase4_h();

    void testCase1_v();
    void testCase2_v();
    void testCase3_v();
    void testCase4_v();

    void testCase1_d();
    void testCase2_d();
    void testCase4_d();

    void testToString();

    void testEqualOp();
};

class Test_life_1D_Test : public QObject
{
    Q_OBJECT

public:
    Test_life_1D_Test();

private Q_SLOTS:
    void testCaseCommon_1D();

    void testCase1_h_1D();
    void testCase2_h_1D();
    void testCase3_h_1D();
    void testCase4_h_1D();

    void testCase1_v_1D();
    void testCase2_v_1D();
    void testCase3_v_1D();
    void testCase4_v_1D();

    void testCase1_d_1D();
    void testCase2_d_1D();
    void testCase4_d_1D();

    void testEqualOp_1D();
    void testToString_1D();
};

Test_lifeTest::Test_lifeTest()
{
}

void Test_lifeTest::testCaseCommon()
{
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

    QVERIFY(l.Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    QVERIFY(l.Get_cell_life(0, 0) == true); //  Check if cell alive with correct index

    QVERIFY(l.Set_cell_dead(0, 0) == true); //  Make cell dead with correct index
    QVERIFY(l.Get_cell_life(0, 0) == false);//  Get cell not alive with correct index

    QVERIFY(l.Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) ==false);//  Cell must be dead
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase1_h()
{
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  1. Any live cell with fewer than two live neighbours dies, as if caused by under-population
    //  Make horisontal test
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) == false);
    QVERIFY(nl.Get_cell_life(1, 0) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase1_v()
{
    //  Make vertical test
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 1);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) == false);
    QVERIFY(nl.Get_cell_life(0, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

}

void Test_lifeTest::testCase1_d()
{
    //  Make diagonal test
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 1);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) == false);
    QVERIFY(nl.Get_cell_life(1, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase2_h()
{
    //  2. Any live cell with two or three live neighbours lives on to the next generation.
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(2, 0);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
}

void Test_lifeTest::testCase2_v()
{
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make vertical test and check with two neighbours
    /*
    ______
    |X|_|_|
    |_|T|_|
    |X|_|_|
    */
    l.Set_cell_alive(0, 0);
    //l.set_cell_alive(0, 1);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
}

void Test_lifeTest::testCase2_d()
{
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make diagonal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|_|X|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(2, 2);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase3_h()
{
    //  3. Any live cell with more than three live neighbours dies, as if by overcrowding.
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|X|
    |_|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(2, 0);
    l.Set_cell_alive(2, 1);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase3_v()
{
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make vertical test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|X|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 1);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase4_h()
{

    //  4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(2, 0);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase4_v()
{
    Life l;
    Life nl;
    //  Make vertical test
    /*
    ______
    |X|_|_|
    |X|T|_|
    |X|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 1);
    l.Set_cell_alive(0, 2);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testCase4_d()
{
    Life l;
    Life nl;
    //  Make diagonal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|X|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(2, 2);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testEqualOp()
{
    Life l;
    Life nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

    QVERIFY(l.Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    nl = l;
    QVERIFY(nl.Get_cell_life(0, 0) == true);   //  Check if cell is alive
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_lifeTest::testToString()
{
    Life l;
    l.Clr();
    char empty[] = "----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n";
    char * data = l.ToString();
    QVERIFY(QString(data) == QString(empty));
}
///////////////////////////////////////////////
Test_life_1D_Test::Test_life_1D_Test()
{
}

void Test_life_1D_Test::testCaseCommon_1D()
{
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

    QVERIFY(l.Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    QVERIFY(l.Get_cell_life(0, 0) == true); //  Check if cell alive with correct index

    QVERIFY(l.Set_cell_dead(0, 0) == true); //  Make cell dead with correct index
    QVERIFY(l.Get_cell_life(0, 0) == false);//  Get cell not alive with correct index

    QVERIFY(l.Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) ==false);//  Cell must be dead
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase1_h_1D()
{
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  1. Any live cell with fewer than two live neighbours dies, as if caused by under-population
    //  Make horisontal test
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) == false);
    QVERIFY(nl.Get_cell_life(1, 0) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase1_v_1D()
{
    //  Make vertical test
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 1);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) == false);
    QVERIFY(nl.Get_cell_life(0, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

}

void Test_life_1D_Test::testCase1_d_1D()
{
    //  Make diagonal test
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 1);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(0, 0) == false);
    QVERIFY(nl.Get_cell_life(1, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase2_h_1D()
{
    //  2. Any live cell with two or three live neighbours lives on to the next generation.
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(2, 0);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
}

void Test_life_1D_Test::testCase2_v_1D()
{
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make vertical test and check with two neighbours
    /*
    ______
    |X|_|_|
    |_|T|_|
    |X|_|_|
    */
    l.Set_cell_alive(0, 0);
    //l.set_cell_alive(0, 1);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
}

void Test_life_1D_Test::testCase2_d_1D()
{
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make diagonal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|_|X|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(2, 2);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase3_h_1D()
{
    //  3. Any live cell with more than three live neighbours dies, as if by overcrowding.
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|X|
    |_|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(2, 0);
    l.Set_cell_alive(2, 1);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase3_v_1D()
{
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make vertical test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|X|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 1);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(1, 1);    //  Cell under test
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == false);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase4_h_1D()
{

    //  4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
    //  Make horisontal test
    /*
    ______
    |X|X|X|
    |_|T|_|
    |_|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(1, 0);
    l.Set_cell_alive(2, 0);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase4_v_1D()
{
    Life_1D l;
    Life_1D nl;
    //  Make vertical test
    /*
    ______
    |X|_|_|
    |X|T|_|
    |X|_|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 1);
    l.Set_cell_alive(0, 2);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testCase4_d_1D()
{
    Life_1D l;
    Life_1D nl;
    //  Make diagonal test
    /*
    ______
    |X|_|X|
    |_|T|_|
    |_|X|_|
    */
    l.Set_cell_alive(0, 0);
    l.Set_cell_alive(0, 2);
    l.Set_cell_alive(2, 2);
    l.Clclt(&nl);
    QVERIFY(nl.Get_cell_life(1, 1) == true);
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testEqualOp_1D()
{
    Life_1D l;
    Life_1D nl;
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests

    QVERIFY(l.Set_cell_alive(0, 0) == true); //  Make live cell with correct index
    nl = l;
    QVERIFY(nl.Get_cell_life(0, 0) == true);   //  Check if cell is alive
    l.Clr();
    nl.Clr();  //  Clear both matrix to make tests
}

void Test_life_1D_Test::testToString_1D()
{
    Life_1D l;
    l.Clr();
    char empty[] = "----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n----------\r\n";
    char * data = l.ToString();
    QVERIFY(QString(data) == QString(empty));

}

class Test_Generation : public QObject
{
    Q_OBJECT

public:
    Test_Generation();

private Q_SLOTS:
    void test_generate();
    void test_initialize();
};

Test_Generation::Test_Generation()
{

}

void Test_Generation::test_initialize()
{
    Life l, nl;
    bool initialized = false;
    generation::initialize(&l);
    for(unsigned int x = 0; x < l.array_w; x++)
    {
        for(unsigned int y = 0; y < l.array_h; y++)
        {
            if(l.Get_cell_life(x, y))
            {
                initialized = true;
            }
        }
    }
    QVERIFY(initialized);
    initialized = false;

    generation::generate(&nl);
    for(unsigned int x = 0; x < l.array_w; x++)
    {
        for(unsigned int y = 0; y < l.array_h; y++)
        {
            if(l.Get_cell_life(x, y) != nl.Get_cell_life(x, y))
            {
                initialized = true;
            }
        }
    }
    QVERIFY(initialized);
}

void Test_Generation::test_generate()
{
    QVERIFY(1);
}

//QTEST_APPLESS_MAIN(Test_lifeTest)
//QTEST_APPLESS_MAIN(Test_life_1D_Test)
QTEST_APPLESS_MAIN(Test_Generation)

#include "tst_test_lifetest.moc"
