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
    test_GCF_NN_N();
    test_LCM_NN_N();
    test_ABS_Z_N();
    test_POZ_Z_D();
    test_MUL_ZM_Z();
    test_TRANS_N_Z();
    test_TRANS_Z_N();
    test_ADD_ZZ_Z();
    test_SUB_ZZ_Z();
    test_MUL_ZZ_Z();
    test_DIV_ZZ_Z();
    test_MOD_ZZ_Z();
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
    Natural a, res;

    a.n = 3;
    a.dig = {9, 9, 9};
    res.n = 4;
    res.dig = {1, 0, 0, 0};
    DO_CHECK(ADD_1N_N(a) == res);

    a.n = 2;
    a.dig = {8, 9};
    res.n = 2;
    res.dig = {9, 0};
    DO_CHECK(ADD_1N_N(a) == res);

    a.n = 5;
    a.dig = { 8, 9, 9, 0, 9 };
    res.n = 5;
    res.dig = { 8, 9, 9, 1, 0 };
    DO_CHECK(ADD_1N_N(a) == res);

    a.n = 1;
    a.dig = { 0 };
    res.n = 1;
    res.dig = { 1 };
    DO_CHECK(ADD_1N_N(a) == res);

    a.n = 1;
    a.dig = { 1 };
    res.n = 1;
    res.dig = { 2 };
    DO_CHECK(ADD_1N_N(a) == res);
}

void BTest::test_ADD_NN_N() {
    Natural a, b, res;

    a.n = 3;
    a.dig = {9, 9, 9};
    b.n = 3;
    b.dig = {9, 9, 9};
    res.n = 4;
    res.dig = {1, 9, 9, 8};
    DO_CHECK(ADD_NN_N(a, b) == res);

    a.n = 7;
    a.dig = { 1, 4, 9, 0, 9, 9, 9 };
    b.n = 6;
    b.dig = { 1, 1, 1, 1, 1, 1 };
    res.n = 7;
    res.dig = { 1, 6, 0, 2, 1, 1, 0 };
    DO_CHECK(ADD_NN_N(a, b) == res);

    a.n = 7;
    a.dig = { 1, 4, 9, 0, 9, 9, 9 };
    b.n = 2;
    b.dig = { 5, 1 };
    res.n = 7;
    res.dig = { 1, 4, 9, 1, 0, 5, 0 };
    DO_CHECK(ADD_NN_N(a, b) == res);

    a.n = 2;
    a.dig = { 5, 1 };
    b.n = 7;
    b.dig = { 1, 4, 9, 0, 9, 9, 9 };
    res.n = 7;
    res.dig = { 1, 4, 9, 1, 0, 5, 0 };
    DO_CHECK(ADD_NN_N(a, b) == res);

    a.n = 1;
    a.dig = { 1 };
    b.n = 1;
    b.dig = { 0 };
    res.n = 1;
    res.dig = { 1 };
    DO_CHECK(ADD_NN_N(a, b) == res);

    a.n = 1;
    a.dig = { 1 };
    b.n = 1;
    b.dig = { 9 };
    res.n = 2;
    res.dig = { 1, 0 };
    DO_CHECK(ADD_NN_N(a, b) == res);

    a.n = 1;
    a.dig = { 0 };
    b.n = 1;
    b.dig = { 0 };
    res.n = 1;
    res.dig = { 0 };
    DO_CHECK(ADD_NN_N(a, b) == res);
}

void BTest::test_SUB_NN_N() {
    Natural a, b, res;

    a.n = 2;
    a.dig = {9, 9};
    b.n = 3;
    b.dig = {9, 9, 9};
    res.n = 3;
    res.dig = {9, 0, 0};
    DO_CHECK(SUB_NN_N(a, b) == res);

    a.n = 1;
    a.dig = { 9 };
    b.n = 1;
    b.dig = { 9 };
    res.n = 1;
    res.dig = { 0 };
    DO_CHECK(SUB_NN_N(a, b) == res);

    a.n = 3;
    a.dig = { 8, 0, 8 };
    b.n = 2;
    b.dig = { 9, 0 };
    res.n = 3;
    res.dig = { 7, 1, 8 };
    DO_CHECK(SUB_NN_N(a, b) == res);

    a.n = 3;
    a.dig = { 1, 0, 0 };
    b.n = 2;
    b.dig = { 9, 9 };
    res.n = 1;
    res.dig = { 1 };
    DO_CHECK(SUB_NN_N(a, b) == res);
}

void BTest::test_MUL_ND_N() {
    Natural a, res;
    int n;

    n = 8;
    a.n = 2;
    a.dig = {9, 9};
    res.n = 3;
    res.dig = {7, 9, 2};
    DO_CHECK(MUL_ND_N(a, n) == res);

    n = 9;
    a.n = 2;
    a.dig = { 1, 1 };
    res.n = 2;
    res.dig = { 9, 9 };
    DO_CHECK(MUL_ND_N(a, n) == res);

    n = 9;
    a.n = 1;
    a.dig = { 1 };
    res.n = 1;
    res.dig = { 9 };
    DO_CHECK(MUL_ND_N(a, n) == res);

    n = 9;
    a.n = 2;
    a.dig = { 1, 0 };
    res.n = 2;
    res.dig = { 9, 0 };
    DO_CHECK(MUL_ND_N(a, n) == res);
}

void BTest::test_MUL_Nk_N() {
    Natural a, res;
    int k;

    k = 4;
    a.n = 2;
    a.dig = {9, 9};
    res.n = 6;
    res.dig = {9, 9, 0, 0, 0, 0};
    DO_CHECK(MUL_Nk_N(a, k) == res);

    k = 10;
    a.n = 3;
    a.dig = { 1, 0, 1 };
    res.n = 13;
    res.dig = { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    DO_CHECK(MUL_Nk_N(a, k) == res);

    k = 10;
    a.n = 1;
    a.dig = { 0};
    res.n = 1;
    res.dig = { 0 };
    DO_CHECK(MUL_Nk_N(a, k) == res);

    k = 0;
    a.n = 3;
    a.dig = { 1, 1, 1 };
    res.n = 3;
    res.dig = { 1, 1, 1 };
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

    a.n = 2;
    a.dig = { 9, 9 };
    b.n = 1;
    b.dig = { 0};
    res.n = 1;
    res.dig = { 0 };
    DO_CHECK(MUL_NN_N(a, b) == res);

    a.n = 2;
    a.dig = { 9, 9 };
    b.n = 1;
    b.dig = { 2 };
    res.n = 3;
    res.dig = { 1, 9, 8 };
    DO_CHECK(MUL_NN_N(a, b) == res);

    a.n = 2;
    a.dig = { 9, 9 };
    b.n = 1;
    b.dig = { 1 };
    res.n = 2;
    res.dig = { 9, 9 };
    DO_CHECK(MUL_NN_N(a, b) == res);

    a.n = 2;
    a.dig = { 1, 0 };
    b.n = 5;
    b.dig = { 1, 0, 0, 0, 0 };
    res.n = 6;
    res.dig = { 1, 0, 0, 0, 0, 0 };
    DO_CHECK(MUL_NN_N(a, b) == res);
}

void BTest::test_SUB_NDN_N() {
    Natural a, b, res;
    int n;

    n = 4;
    a.n = 4;
    a.dig = {9, 9, 9, 3};
    b.n = 2;
    b.dig = {9, 7};
    res.n = 4;
    res.dig = {9, 6, 0, 5};
    DO_CHECK(SUB_NDN_N(a, b, n) == res);

    n = 1;
    a.n = 4;
    a.dig = { 1, 0, 0, 0 };
    b.n = 2;
    b.dig = { 9, 7 };
    res.n = 3;
    res.dig = { 9, 0, 3 };
    DO_CHECK(SUB_NDN_N(a, b, n) == res);

    n = 0;
    a.n = 4;
    a.dig = { 1, 0, 0, 0 };
    b.n = 2;
    b.dig = { 9, 7 };
    res.n = 4;
    res.dig = { 1, 0, 0, 0 };
    DO_CHECK(SUB_NDN_N(a, b, n) == res);

    n = 9;
    a.n = 10;
    a.dig = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    b.n = 9;
    b.dig = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    res.n = 1;
    res.dig = { 1 };
    DO_CHECK(SUB_NDN_N(a, b, n) == res);

    n = 9;
    a.n = 10;
    a.dig = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    b.n = 9;
    b.dig = { 1, 0, 1, 0, 1, 0, 1, 0, 1 };
    res.n = 8;
    res.dig = { 9, 0, 9, 0, 9, 0, 9, 1 };
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

    a.n = 5;
    a.dig = {1, 2, 2, 2, 2};
    b.n = 2;
    b.dig = {3, 1};
    DO_CHECK(DIV_NN_Dk(a, b) == 3);

    a.n = 5;
    a.dig = {1, 2, 2, 2, 2};
    b.n = 1;
    b.dig = { 1 };
    DO_CHECK(DIV_NN_Dk(a, b) == 1);

    a.n = 5;
    a.dig = {1, 2, 2, 2, 2};
    b.n = 2;
    b.dig = {1, 0};
    DO_CHECK(DIV_NN_Dk(a, b) == 1);

    a.n = 1;
    a.dig = {1};
    b.n = 2;
    b.dig = {1, 0};
    DO_CHECK(DIV_NN_Dk(a, b) == 1);

    a.n = 1;
    a.dig = {1};
    b.n = 1;
    b.dig = {1};
    DO_CHECK(DIV_NN_Dk(a, b) == 1);

    a.n = 1;
    a.dig = {2};
    b.n = 1;
    b.dig = {2};
    DO_CHECK(DIV_NN_Dk(a, b) == 1);

    a.n = 10;
    a.dig = {1, 2, 2, 2, 6, 6, 6, 9, 9 ,9};
    b.n = 9;
    b.dig = {1, 1, 1, 1, 1, 1, 1, 1, 1 };
    DO_CHECK(DIV_NN_Dk(a, b) == 1);
}

void BTest::test_DIV_NN_N() {
    Natural a, b, res;
    a.n = 3;
    a.dig = {2, 0, 4};
    b.n = 1;
    b.dig = {2};
    res.n = 3;
    res.dig = {1, 0, 2};
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

    a.n = 3;
    a.dig = {1, 1, 1};
    b.n = 3;
    b.dig = {1, 1, 0};
    res.n = 1;
    res.dig = {1};
    DO_CHECK(DIV_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {1, 0, 0};
    a.n = 2;
    a.dig = {1, 0};
    res.n = 2;
    res.dig = {1, 0};
    DO_CHECK(DIV_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {2, 2, 0};
    a.n = 2;
    a.dig = {2, 0};
    res.n = 2;
    res.dig = {1, 1};
    DO_CHECK(DIV_NN_N(a, b) == res);

   /* res.n = 11;
    res.dig = {4, 7, 1, 8, 0, 5, 1, 2, 8, 1, 8};
    b.n = 2;
    b.dig = {1, 3};
    a.n = 12;
    a.dig = {6, 1, 3, 3, 4, 6, 6, 6, 6, 6, 4, 3};
    DO_CHECK(DIV_NN_N(a, b) == res);

   res.n = 10;
    res.dig = {5, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    b.n = 2;
    b.dig = {1, 2};
    a.n = 11;
    a.dig = {6, 1, 3, 3, 4, 6, 6, 6, 6, 6, 4};
    DO_CHECK(DIV_NN_N(a, b) == res);*/
}

void BTest::test_MOD_NN_N() {
   /* Natural a, b, res;
    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 2;
    b.dig = {3, 1};
    res.n = 2;
    res.dig = {2, 9};
    DO_CHECK(MOD_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 1, 1};
    b.n = 3;
    b.dig = {1, 1, 0};
    res.n = 1;
    res.dig = {1};
    DO_CHECK(MOD_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 1, 1};
    b.n = 1;
    b.dig = {1};
    res.n = 1;
    res.dig = {0};
    DO_CHECK(MOD_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 1, 1};
    b.n = 2;
    b.dig = {5, 0};
    res.n = 2;
    res.dig = {1, 1};
    DO_CHECK(MOD_NN_N(a, b) == res);

    res.n = 1;
    res.dig = {0};
    b.n = 2;
    b.dig = {1, 2};
    a.n = 11;
    a.dig = {6, 1, 3, 3, 4, 6, 6, 6, 6, 6, 4};
    DO_CHECK(MOD_NN_N(a, b) == res);

    a.n = 2;
    a.dig = {3, 3, 3};
    b.n = 2;
    b.dig = {1, 1, 0};
    res.n = 1;
    res.dig = { 3 };
    DO_CHECK(MOD_NN_N(a, b) == res);
*/
}

void BTest::test_GCF_NN_N() {
  /*  Natural a, b, res;

    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 2;
    b.dig = {3, 2};
    res.n = 1;
    res.dig = {2};
    DO_CHECK(GCF_NN_N(a, b) == res);

    a.n = 4;
    a.dig = {1, 6, 6, 5};
    b.n = 2;
    b.dig = {4, 5};
    res.n = 2;
    res.dig = {4, 5};
    DO_CHECK(GCF_NN_N(a, b) == res);

    a.n = 2;
    a.dig = {3, 3, 3};
    b.n = 2;
    b.dig = {1, 1, 0};
    res.n = 1;
    res.dig = { 1 };
    DO_CHECK(GCF_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 4, 3};
    b.n = 4;
    b.dig = {2, 0, 4, 1};
    res.n = 2;
    res.dig = {1, 3};
    DO_CHECK(GCF_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {1, 0, 0};
    a.n = 2;
    a.dig = {1, 0};
    res.n = 2;
    res.dig = {1, 0};
    DO_CHECK(GCF_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 3;
    b.dig = {1, 2, 2};
    res.n = 3;
    res.dig = { 1, 2, 2};
    DO_CHECK(GCF_NN_N(a, b) == res);

    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 1;
    b.dig = {7};
    res.n = 1;
    res.dig = { 1 };
    DO_CHECK(GCF_NN_N(a, b) == res);*/
}

void BTest::test_LCM_NN_N() {
    /*Natural a, b, res;
    a.n = 2;
    a.dig = {1, 2};
    b.n = 2;
    b.dig = {3, 2};
    res.n = 2;
    res.dig = {9, 6};
    DO_CHECK(LCM_NN_N(a, b) == res);

    a.n = 4;
    a.dig = {1, 6, 6, 5};
    b.n = 2;
    b.dig = {4, 5};
    res.n = 4;
    res.dig = {1, 6, 6, 5};
    DO_CHECK(LCM_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {2, 0, 4};
    a.n = 3;
    a.dig = {1, 4, 6};
    res.n = 5;
    res.dig = {1, 4, 8, 9, 2};
    DO_CHECK(LCM_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {1, 0, 0};
    a.n = 2;
    a.dig = {1, 0};
    res.n = 3;
    res.dig = {1, 0, 0};
    DO_CHECK(LCM_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {1, 2, 3};
    a.n = 3;
    a.dig = {1, 2, 3};
    res.n = 3;
    res.dig = {1, 2, 3};
    DO_CHECK(LCM_NN_N(a, b) == res);

    b.n = 7;
    b.dig = {1, 2, 3, 3, 2, 1, 2};
    a.n = 2;
    a.dig = {8, 6};
    res.n = 9;
    res.dig = { 1, 0, 6, 0, 5, 6, 1, 4, 6};
    DO_CHECK(LCM_NN_N(a, b) == res);

    a.n = 2;
    a.dig = {3, 3, 3};
    b.n = 2;
    b.dig = {1, 1, 0};
    res.n = 5;
    res.dig = {3, 6, 6, 3, 0};
    DO_CHECK(LCM_NN_N(a, b) == res);
*/
}

void BTest::test_ABS_Z_N() {
    Integ a, res;
    a.b = 1;
    a.n = 3;
    a.dig = {1, 1, 4};
    res.b = 0;
    res.n = 3;
    res.dig = {1, 1, 4};
    DO_CHECK(ABS_Z_N(a) == res);
}

void BTest::test_POZ_Z_D() {
    Integ a;
    int res;
    a.b = 1;
    a.n = 1;
    a.dig = {0};
    res = 0;
    DO_CHECK(POZ_Z_D(a) == res);

    a.b = 0;
    a.n = 1;
    a.dig = {0};
    res = 0;
    DO_CHECK(POZ_Z_D(a) == res);

    a.b = 1;
    a.n = 1;
    a.dig = {1};
    res = 1;
    DO_CHECK(POZ_Z_D(a) == res);

    a.b = 0;
    a.n = 1;
    a.dig = {1};
    res = 2;
    DO_CHECK(POZ_Z_D(a) == res);
}

void BTest::test_MUL_ZM_Z() {
    Integ a, res;
    a.b = 1;
    a.n = 1;
    a.dig = {0};
    res.b = 0;
    res.n = 1;
    res.dig = {0};
    DO_CHECK(MUL_ZM_Z(a) == res);
}

void BTest::test_TRANS_N_Z() {
    Natural a;
    Integ res;
    a.n = 3;
    a.dig = {1, 2, 3};
    res.b = 0;
    res.n = 3;
    res.dig = {1, 2, 3};
    DO_CHECK(TRANS_N_Z(a) == res);
}

void BTest::test_TRANS_Z_N() {
    Natural res;
    Integ a;
    a.b = 0;
    a.n = 3;
    a.dig = {1, 2, 3};
    res.n = 3;
    res.dig = {1, 2, 3};
    DO_CHECK(TRANS_Z_N(a) == res);
}

void BTest::test_ADD_ZZ_Z() {
    Integ a, b, res;
    a.b = 1;
    a.n = 2;
    a.dig = {2, 5};
    b.b = 0;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 0;
    res.n = 1;
    res.dig = {0};
    DO_CHECK(ADD_ZZ_Z(a, b) == res);

    a.b = 1;
    a.n = 2;
    a.dig = {2, 2};
    b.b = 1;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 1;
    res.n = 2;
    res.dig = {4, 7};
    DO_CHECK(ADD_ZZ_Z(a, b) == res);

    a.b = 0;
    a.n = 2;
    a.dig = {2, 2};
    b.b = 1;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 1;
    res.n = 1;
    res.dig = {3};
    DO_CHECK(ADD_ZZ_Z(a, b) == res);
}

void BTest::test_SUB_ZZ_Z() {
    Integ a, b, res;
    a.b = 1;
    a.n = 2;
    a.dig = {2, 5};
    b.b = 1;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 0;
    res.n = 1;
    res.dig = {0};
    DO_CHECK(SUB_ZZ_Z(a, b) == res);

    a.b = 1;
    a.n = 2;
    a.dig = {2, 5};
    b.b = 0;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 1;
    res.n = 2;
    res.dig = {5, 0};
    DO_CHECK(SUB_ZZ_Z(a, b) == res);

    a.b = 0;
    a.n = 2;
    a.dig = {2, 5};
    b.b = 0;
    b.n = 2;
    b.dig = {2, 1};
    res.b = 0;
    res.n = 1;
    res.dig = {4};
    DO_CHECK(SUB_ZZ_Z(a, b) == res);

    a.b = 0;
    a.n = 2;
    a.dig = {2, 5};
    b.b = 1;
    b.n = 2;
    b.dig = {2, 1};
    res.b = 0;
    res.n = 2;
    res.dig = {4, 6};
    DO_CHECK(SUB_ZZ_Z(a, b) == res);
}

void BTest::test_MUL_ZZ_Z() {
    Integ a, b, res;
    a.b = 1;
    a.n = 2;
    a.dig = {2, 5};
    b.b = 1;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 0;
    res.n = 3;
    res.dig = {6, 2, 5};
    DO_CHECK(MUL_ZZ_Z(a, b) == res);

    a.b = 0;
    a.n = 1;
    a.dig = {2};
    b.b = 1;
    b.n = 2;
    b.dig = {2, 5};
    res.b = 1;
    res.n = 2;
    res.dig = {5, 0};
    DO_CHECK(MUL_ZZ_Z(a, b) == res);
}

void BTest::test_DIV_ZZ_Z() {
    Integ a, res;
    Natural b;
    a.b = 0;
    a.n = 2;
    a.dig = {2, 5};
    b.n = 2;
    b.dig = {2, 5};
    res.b = 0;
    res.n = 1;
    res.dig = {1};
    Integ c = DIV_ZZ_Z(a, b);
    DO_CHECK(DIV_ZZ_Z(a, b) == res);
}

void BTest::test_MOD_ZZ_Z() {
    Integ a, res;
    Natural b;
    a.b = 1;
    a.n = 2;
    a.dig = {2, 5};
    b.n = 2;
    b.dig = {2, 2};
    res.b = 0;
    res.n = 2;
    res.dig = {1, 9};
    DO_CHECK(MOD_ZZ_Z(a, b) == res);
}