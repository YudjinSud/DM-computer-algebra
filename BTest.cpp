#include <iostream>
#include "Btest.h"

void BTest::runAllTests() {
    test_COM_NN_D();
    test_NZER_N_B();
    test_ADD_1N_N();
    test_ADD_NN_N();
    test_SUB_NN_N();
    test_MUL_ND_N();
    test_MUL_Nk_N();
    test_MUL_NN_N();
    test_SUB_NDN_N();
    test_DIV_NN_Dk();
    test_DIV_NN_N();
    test_MOD_NN_N();
}

void BTest::test_COM_NN_D() {
    Natural a, b;

    a.n = 3;
    a.dig = {1, 1, 1};
    b.n = 3;
    b.dig = {1, 1, 2};
    DO_CHECK(COM_NN_D(a, b) == 1);

    a.n = 4;
    a.dig = {1, 1, 1, 1};
    b.n = 3;
    b.dig = {1, 1, 2};
    DO_CHECK(COM_NN_D(a, b) == 2);

    a.n = 2;
    a.dig = {1, 1};
    b.n = 3;
    b.dig = {1, 1, 2};
    DO_CHECK(COM_NN_D(a, b) == 1);

    a.n = 2;
    a.dig = {1, 1};
    b.n = 2;
    b.dig = {1, 1};
    DO_CHECK(COM_NN_D(a, b) == 0);
}

void BTest::test_NZER_N_B() {
    Natural a;

    a.n = 3;
    a.dig = {1, 1, 1};
    DO_CHECK(NZER_N_B(a) == 0);

    a.n = 1;
    a.dig = {0};
    DO_CHECK(NZER_N_B(a) == 1);

}

void BTest::test_ADD_1N_N() {
    Natural a;

    a.n = 3;
    a.dig = {9, 9, 9};
    Natural res;
    res.n = 4;
    res.dig = {1, 0, 0, 0};
    DO_CHECK(ADD_1N_N(a) == res);

    a.n = 2;
    a.dig = {8, 9};
    res.n = 2;
    res.dig = {9, 0};
    DO_CHECK(ADD_1N_N(a) == res);
}

void BTest::test_ADD_NN_N() {
    Natural a, b;

    a.n = 3;
    a.dig = {9, 9, 9};
    b.n = 3;
    b.dig = {9, 9, 9};
    Natural res;
    res.n = 4;
    res.dig = {1, 9, 9, 8};
    DO_CHECK(ADD_NN_N(a, b) == res);
}

void BTest::test_SUB_NN_N() {
    Natural a, b;

    a.n = 2;
    a.dig = {9, 9};
    b.n = 3;
    b.dig = {9, 9, 9};
    Natural res;
    res.n = 3;
    res.dig = {9, 0, 0};
    DO_CHECK(SUB_NN_N(a, b) == res);
}

void BTest::test_MUL_ND_N() {
    Natural a;
    int n = 8;
    a.n = 2;
    a.dig = {9, 9};
    Natural res;
    res.n = 3;
    res.dig = {7, 9, 2};
    DO_CHECK(MUL_ND_N(a, n) == res);
}

void BTest::test_MUL_Nk_N() {
    Natural a;
    int k = 4;
    a.n = 2;
    a.dig = {9, 9};
    Natural res;
    res.n = 6;
    res.dig = {9, 9, 0, 0, 0, 0};
    DO_CHECK(MUL_Nk_N(a, k) == res);
}

void BTest::test_MUL_NN_N() {
    Natural a, b, res;
    a.n = 2;
    a.dig = {9, 9};
    b.n = 2;
    b.dig = {9, 7};
    res.n = 4;
    res.dig = {9, 6, 0, 3};
    DO_CHECK(MUL_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {9, 9, 0};
    b.n = 5;
    b.dig = {9, 7, 8, 0, 4};
    res.n = 8;
    res.dig = {9, 6, 8, 2, 5, 9, 6, 0};
    DO_CHECK(MUL_NN_N(a, b) == res);
}

void BTest::test_SUB_NDN_N() {
    Natural a, b, res;
    int n = 4;
    a.n = 4;
    a.dig = {9, 9, 9, 3};
    b.n = 2;
    b.dig = {9, 7};
    res.n = 4;
    res.dig = {9, 6, 0, 5};
    DO_CHECK(SUB_NDN_N(a, b, n) == res);
}

void BTest::test_DIV_NN_Dk() {
    Natural a, b;
    a.n = 2;
    a.dig = {9, 9};
    b.n = 3;
    b.dig = {3, 2, 9};
    DO_CHECK(DIV_NN_Dk(a, b) == 3);

    a.n = 4;
    a.dig = {1, 8, 1, 2};
    b.n = 2;
    b.dig = {9, 7};
    DO_CHECK(DIV_NN_Dk(a, b) == 1);

    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 2;
    b.dig = {3, 1};
    DO_CHECK(DIV_NN_Dk(a, b) == 3);
}

void BTest::test_DIV_NN_N() {
    Natural a, b, res;
    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 2;
    b.dig = {3, 1};
    res.n = 1;
    res.dig = {3};
    DO_CHECK(DIV_NN_N(a, b) == res);

    a.n = 2;
    a.dig = {9, 9};
    b.n = 3;
    b.dig = {3, 2, 9};
    res.n = 1;
    res.dig = {3};
    DO_CHECK(DIV_NN_N(a, b) == res);

    a.n = 4;
    a.dig = {1, 0, 0, 2};
    b.n = 1;
    b.dig = {9};
    res.n = 3;
    res.dig = {1, 1, 1};
    DO_CHECK(DIV_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 2, 4};
    b.n = 2;
    b.dig = {3, 1};
    res.n = 1;
    res.dig = {4};
    DO_CHECK(DIV_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 2, 4};
    b.n = 2;
    b.dig = {3, 1};
    res.n = 1;
    res.dig = {4};
    DO_CHECK(DIV_NN_N(a, b) == res);
}

void BTest::test_MOD_NN_N() {
    Natural a, b, res;
    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 2;
    b.dig = {3, 1};
    res.n = 2;
    res.dig = {2,9};
    DO_CHECK(MOD_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 1, 1};
    b.n = 3;
    b.dig = {1, 1, 0};
    res.n = 1;
    res.dig = {1};
    DO_CHECK(MOD_NN_N(a, b) == res);
}