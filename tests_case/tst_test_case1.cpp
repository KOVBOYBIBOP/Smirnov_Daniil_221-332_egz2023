
#include <QtTest>
#include "func_for_server.h"  // Включение заголовочного файла с определением функций

class test_case1 : public QObject
{
    Q_OBJECT

public:
    test_case1();
    ~test_case1();

private slots:
    void test_case1();
    void test_case2();  // Изменено имя функции

};

test_case1::test_case1()
{

}

test_case1::~test_case1()
{

}

void test_case1::test_case1()
{
    QStringList params1 = { "2,8", "3,7", "4,8" };
    QStringList params2 = { "1,2", "3,4", "5,6" };
    QStringList params3 = { "7,3", "9,1", "6,5" };
    QStringList params4 = { "0,0", "1,1", "2,2" };
    QStringList params5 = { "5,5", "6,6", "7,7" };
    QStringList params6 = { "-3,5", "-1,2", "-4,8" };
    QStringList params7 = { "-2,-2", "-1,-1", "0,0" };
    QStringList params8 = { "10,10", "11,11", "12,12" };
    QStringList params9 = { "-5,0", "-3,2", "-6,-1" };
    QStringList params10 = { "4,2", "7,5", "6,8" };
    QCOMPARE(perimetr(params1),"4.82843");
    QCOMPARE(perimetr(params2),"11.3137");

    QCOMPARE(perimetr(params3),"10.0645");
    QCOMPARE(perimetr(params4),"5.65685");

    QCOMPARE(perimetr(params5),"5.65685");
    QCOMPARE(perimetr(params6),"13.476");

    QCOMPARE(perimetr(params7),"5.65685");
    QCOMPARE(perimetr(params8),"5.65685");
    QCOMPARE(perimetr(params9),"8.48528");
    QCOMPARE(perimetr(params10),"13.7295");
}

void test_case1::test_case2()
{
    QStringList params1 = { "2,8", "3,7", "4,8" };
    QStringList params2 = { "1,2", "3,4", "5,6" };
    QStringList params3 = { "7,3", "9,1", "6,5" };
    QStringList params4 = { "0,0", "1,1", "2,2" };
    QStringList params5 = { "5,5", "6,6", "7,7" };
    QStringList params6 = { "-3,5", "-1,2", "-4,8" };
    QStringList params7 = { "-2,-2", "-1,-1", "0,0" };
    QStringList params8 = { "10,10", "11,11", "12,12" };
    QStringList params9 = { "-5,0", "-3,2", "-6,-1" };
    QStringList params10 = { "4,2", "7,5", "6,8" };
    QCOMPARE(square(params1),"1");
    QCOMPARE(square(params2),"0");

    QCOMPARE(square(params3),"1");
    QCOMPARE(square(params4),"0");

    QCOMPARE(square(params5),"0");
    QCOMPARE(square(params6),"1.5");

    QCOMPARE(square(params7),"0");
    QCOMPARE(square(params8),"0");
    QCOMPARE(square(params9),"0");
    QCOMPARE(square(params10),"6");
}

QTEST_APPLESS_MAIN(test_case1)

#include "tst_test_case1.moc"
