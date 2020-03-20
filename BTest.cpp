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