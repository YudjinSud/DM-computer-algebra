#include "BTest.h"

void BTest::runAllTests() {
    test_COM_NN_D();
    test_NZER_N_B();
    test_ADD_1N_N();

}

void BTest::test_COM_NN_D() {
    Natural a,b;

    a.n = 3;
    a.dig = {1,1,1};
    b.n = 3;
    b.dig = {1,1,2};
    DO_CHECK(COM_NN_D(a,b) == 1);

    a.n = 4;
    a.dig = {1,1,1,1};
    b.n = 3;
    b.dig = {1,1,2};
    DO_CHECK(COM_NN_D(a,b) == 2);

    a.n = 2;
    a.dig = {1,1};
    b.n = 3;
    b.dig = {1,1,2};
    DO_CHECK(COM_NN_D(a,b) == 1);

    a.n = 2;
    a.dig = {1,1};
    b.n = 2;
    b.dig = {1,1};
    DO_CHECK(COM_NN_D(a,b) == 0);
}

void BTest::test_NZER_N_B() {
    Natural a;

    a.n = 3;
    a.dig = {1,1,1};
    DO_CHECK(NZER_N_B(a) == 0);

    a.n = 1;
    a.dig = {0};
    DO_CHECK(NZER_N_B(a) == 1);

}

void BTest::test_ADD_1N_N() {
    Natural a;

    a.n = 3;
    a.dig = {9,9,9};
    Natural res;
    res.n = 4;
    res.dig = {1,0,0,0};
    DO_CHECK(ADD_1N_N(a) == res);

}
