#include "Btest.h"


void BTest::runAllTests() {
//    test_COM_NN_D();
//    test_NZER_N_B();
//    test_ADD_1N_N();
//    test_ADD_NN_N();
//    test_SUB_NN_N();
//    test_MUL_ND_N();
//    test_MUL_Nk_N();
//    test_MUL_NN_N();
//    test_SUB_NDN_N();
//    test_DIV_NN_Dk();
    test_DIV_NN_N();
//    test_MOD_NN_N();
//    test_GCF_NN_N();
//    test_LCM_NN_N();
//    test_ABS_Z_N();
//    test_POZ_Z_D();
//    test_MUL_ZM_Z();
//    test_TRANS_N_Z();
//    test_TRANS_Z_N();
    // test_ADD_ZZ_Z();
//    test_SUB_ZZ_Z();
//    test_MUL_ZZ_Z();
//    test_DIV_ZZ_Z();
//    test_MOD_ZZ_Z();
    test_RED_Q_Q();
//    test_INT_Q_B();
//    test_TRANS_Z_Q();
//    test_TRANS_Q_Z();
    //  test_ADD_QQ_Q();
    //    test_SUB_QQ_Q();
//    test_MUL_QQ_Q();
//    test_DIV_QQ_Q();
//    test_ADD_PP_P();
//    test_SUB_PP_P();
//    test_MUL_PQ_P();
//    test_MUL_Pxk_P();
//    test_LED_P_Q();
//    test_DEG_P_N();
//    test_MUL_PP_P();
//    test_DIV_PP_P();
//    test_MOD_PP_P();
    // test_GCF_PP_P();
//    test_DER_P_P();
//    test_NMR_P_P();
    //  test_FAC_P_Q();
}

void BTest::test_COM_NN_D() {
    Natural a, b;std::stringstream s_0;string s,res1;
    s = "123";
    s_0 << s;
    s_0 >> read_Nat(a);
    s = "2";
    s_0 << s;
    s_0 >> read_Nat(b);
    cout << write_Nat(a) << '\n';
    DO_CHECK(COM_NN_D(a,b) == 1);
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


    a.n = 10;
    a.dig = {5, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    b.n = 2;
    b.dig = {1, 2};
    res.n = 10;
    res.dig = {5, 1, 1, 1, 2, 2, 2, 2, 1, 0};
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

    a.n = 10;
    a.dig = {5, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    b.n = 2;
    b.dig = {1, 2};
    res.n = 11;
    res.dig = {6, 1, 3, 3, 4, 6, 6, 6, 6, 6, 4};
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

    a.n = 5;
    a.dig = {1, 2, 2, 2, 2};
    b.n = 2;
    b.dig = {3, 1};
    DO_CHECK(DIV_NN_Dk(a, b) == 3);

    a.n = 5;
    a.dig = {1, 2, 2, 2, 2};
    b.n = 1;
    b.dig = {1};
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
    a.dig = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    b.n = 8;
    b.dig = {4, 4, 4, 4, 4, 4, 4, 4};
    DO_CHECK(DIV_NN_Dk(a, b) == 1);


}

void BTest::test_DIV_NN_N() {
    Natural a,b,res; std::stringstream s_0;string s,res1;
    s = "1002.";
    s_0 << s;
    s_0 >> read_Nat(a);
    s = "2.";
    s_0 << s;
    s_0 >> read_Nat(b);
    s = "501.";
    s_0 << s;
    s_0 >> read_Nat(res);
    //cout << write_Nat(a) <<  " / " << write_Nat(b) << " = " << write_Nat(DIV_NN_N(a,b)) << '\n';
    // cout << write_Nat(res) << '\n';
    DO_CHECK(DIV_NN_N(a,b) == res);

}

void BTest::test_MOD_NN_N() {
    Natural a, b, res;
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

    res.n = 1;
    res.dig = {9};
    b.n = 2;
    b.dig = {1, 3};
    a.n = 12;
    a.dig = {6, 1, 3, 3, 4, 6, 6, 6, 6, 6, 4, 3};
    DO_CHECK(MOD_NN_N(a, b) == res);


}

void BTest::test_GCF_NN_N() {
    Natural a, b, res;
    a.n = 3;
    a.dig = {1, 2, 2};
    b.n = 2;
    b.dig = {3, 2};
    res.n = 1;
    res.dig = {2};
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
}

void BTest::test_LCM_NN_N() {
    Natural a, b, res;
    a.n = 2;
    a.dig = {1, 2};
    b.n = 2;
    b.dig = {3, 2};
    res.n = 2;
    res.dig = {9, 6};
    DO_CHECK(LCM_NN_N(a, b) == res);

    b.n = 3;
    b.dig = {2, 0, 4};
    a.n = 3;
    a.dig = {1, 4, 6};
    res.n = 5;
    res.dig = {1, 4, 8, 9, 2};
    DO_CHECK(LCM_NN_N(a, b) == res);

    b.n = 1;
    b.dig = {0};
    a.n = 2;
    a.dig = {1, 0};
    res.n = 2;
    res.dig = {1, 0};
    DO_CHECK(LCM_NN_N(a, b) == res);


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

    a.b = 0;
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
    Integ a,b,res; std::stringstream s_0;string s,res1;
    s = "1.";
    s_0 << s;
    s_0 >> read_Integ(a);
    s = "10000000000.";
    s_0 << s;
    s_0 >> read_Integ(b);
    s = "10000000001.";
    s_0 << s;
    s_0 >> read_Integ(res);
    //cout << write_Integ(a) <<  " + " << write_Integ(b) << " = " << write_Integ(ADD_ZZ_Z(a,b)) << '\n';
    // cout << write_Integ(res) << '\n';
    DO_CHECK(ADD_ZZ_Z(a,b) == res);
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

    a.b = 1;
    a.n = 1;
    a.dig = {7};
    b.n = 1;
    b.dig = {6};
    res.b = 1;
    res.n = 1;
    res.dig = {2};
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

    a.b = 1;
    a.n = 1;
    a.dig = {7};
    b.n = 1;
    b.dig = {6};
    res.b = 0;
    res.n = 1;
    res.dig = {5};
    DO_CHECK(MOD_ZZ_Z(a, b) == res);

    a.b = 0;
    a.n = 1;
    a.dig = {0};
    b.n = 10;
    b.dig = {5, 9, 5, 9, 5, 9, 5, 9, 5, 9};
    res.b = 0;
    res.n = 1;
    res.dig = {0};
    DO_CHECK(MOD_ZZ_Z(a, b) == res);
}

void BTest::test_RED_Q_Q() {
    Frac a,b,res; std::stringstream s_0;string s,res1;
    s = "(10000000001)/(10000000000)";
    s_0 << s;
    s_0 >> read_Frac(a);
    s = "(10000000001)/(10000000000)";
    s_0 << s;
    s_0 >> read_Frac(res);
    //  cout << write_Frac(a)  << " => " << write_Frac(RED_Q_Q(a)) << '\n';
    //  cout << write_Frac(res) << '\n';
    DO_CHECK(RED_Q_Q(a) == res);
}

void BTest::test_INT_Q_B() {
    Frac a;
    int res;
    a.p.b = 1;
    a.p.n = 3;
    a.p.dig = {1, 2, 5};
    a.q.n = 2;
    a.q.dig = {5, 0};
    res = 0;
    DO_CHECK(INT_Q_B(a) == res);

    a.p.b = 1;
    a.p.n = 3;
    a.p.dig = {1, 2, 5};
    a.q.n = 1;
    a.q.dig = {1};
    res = 1;
    DO_CHECK(INT_Q_B(a) == res);
}

void BTest::test_TRANS_Z_Q() {
    Integ a;
    Frac res;
    a.b = 1;
    a.n = 3;
    a.dig = {1, 2, 5};
    res.p.b = 1;
    res.p.n = 3;
    res.p.dig = {1, 2, 5};
    res.q.n = 1;
    res.q.dig = {1};
    DO_CHECK(TRANS_Z_Q(a) == res);
}

void BTest::test_TRANS_Q_Z() {
    Frac a;
    Integ res;
    a.p.b = 1;
    a.p.n = 3;
    a.p.dig = {1, 2, 5};
    a.q.n = 1;
    a.q.dig = {1};
    res.b = 1;
    res.n = 3;
    res.dig = {1, 2, 5};
    DO_CHECK(TRANS_Q_Z(a) == res);

    a.p.b = 0;
    a.p.n = 1;
    a.p.dig = {0};
    a.q.n = 1;
    a.q.dig = {1};
    res.b = 0;
    res.n = 1;
    res.dig = {0};
    DO_CHECK(TRANS_Q_Z(a) == res);
}

void BTest::test_ADD_QQ_Q() {
    Frac a,b,res; std::stringstream s_0;string s,res1;
    s = "(1)/(1)";
    s_0 << s;
    s_0 >> read_Frac(a);
    s = "(1)/(10000000000)";
    s_0 << s;
    s_0 >> read_Frac(b);
    s = "(10000000001)/(10000000000)";
    s_0 << s;
    s_0 >> read_Frac(res);
    cout << write_Frac(a) <<  " + " << write_Frac(b) << " = " << write_Frac(ADD_QQ_Q(a,b)) << '\n';
    // cout << write_Frac(res) << '\n';
    DO_CHECK(ADD_QQ_Q(a,b) == res);
}

void BTest::test_SUB_QQ_Q() {
    Frac a,b,res; std::stringstream s_0;string s,res1;
    s = "(1)/(1)";
    s_0 << s;
    s_0 >> read_Frac(a);
    s = "(-1)/(10000000000)";
    s_0 << s;
    s_0 >> read_Frac(b);
    s = "(10000000001)/(10000000000)";
    s_0 << s;
    s_0 >> read_Frac(res);
    cout << write_Frac(a) <<  " - " << write_Frac(b) << " = " << write_Frac(SUB_QQ_Q(a,b)) << '\n';
    cout << write_Frac(res) << '\n';
    DO_CHECK(SUB_QQ_Q(a,b) == res);

}

void BTest::test_MUL_QQ_Q() {
    Frac a, b, res;
    a.p.b = 1;
    a.p.n = 3;
    a.p.dig = {1, 2, 5};
    a.q.n = 2;
    a.q.dig = {5, 0};
    b.p.b = 1;
    b.p.n = 2;
    b.p.dig = {3, 4};
    b.q.n = 1;
    b.q.dig = {6};
    res.p.b = 0;
    res.p.n = 2;
    res.p.dig = {8, 5};
    res.q.n = 1;
    res.q.dig = {6};
    DO_CHECK(MUL_QQ_Q(a, b) == res);

    a.p.b = 1;
    a.p.n = 3;
    a.p.dig = {1, 2, 5};
    a.q.n = 2;
    a.q.dig = {5, 0};
    b.p.b = 0;
    b.p.n = 1;
    b.p.dig = {0};
    b.q.n = 1;
    b.q.dig = {6};
    res.p.b = 0;
    res.p.n = 1;
    res.p.dig = {0};
    res.q.n = 1;
    res.q.dig = {1};
    DO_CHECK(MUL_QQ_Q(a, b) == res);
}

void BTest::test_DIV_QQ_Q() {
    Frac a, b, res;
    a.p.b = 1;
    a.p.n = 3;
    a.p.dig = {1, 2, 5};
    a.q.n = 2;
    a.q.dig = {5, 0};
    b.p.b = 1;
    b.p.n = 2;
    b.p.dig = {3, 4};
    b.q.n = 1;
    b.q.dig = {6};
    res.p.b = 0;
    res.p.n = 2;
    res.p.dig = {1, 5};
    res.q.n = 2;
    res.q.dig = {3, 4};
    DO_CHECK(DIV_QQ_Q(a, b) == res);

    a.p.b = 0;
    a.p.n = 1;
    a.p.dig = {0};
    a.q.n = 1;
    a.q.dig = {1};
    b.p.b = 1;
    b.p.n = 1;
    b.p.dig = {1};
    b.q.n = 1;
    b.q.dig = {5};
    res.p.b = 0;
    res.p.n = 1;
    res.p.dig = {0};
    res.q.n = 1;
    res.q.dig = {1};
    DO_CHECK(DIV_QQ_Q(a, b) == res);
}

void BTest::test_ADD_PP_P() {
    Poly x,y,res; std::stringstream s_0;string s,res1;
    s = "(1)/(1)x^10 + (1)/(2)x^0";
    s_0 << s;
    s_0 >> read_Poly(x);
    s = "(1)/(1)x^1 + (1)/(2)x^0";
    s_0 << s;
    s_0 >> read_Poly(y);
    res1 = "(1)/(1)x^10 + (1)/(1)x^1 + (1)/(1)x^0";
    s_0 << res1;
    s_0 >> read_Poly(res);
    DO_CHECK(ADD_PP_P(x,y) == res);
}

void BTest::test_SUB_PP_P() {

}

void BTest::test_MUL_PQ_P() {

}

void BTest::test_MUL_Pxk_P() {

}

void BTest::test_LED_P_Q() {
    /*Frac a1, a2, a3, b1, b2, b3, res;
    Poly x;
    x.m = 1;
    a1.p.b = 1;
    a1.p.n = 1;
    a1.p.dig = {3};
    a1.q.n = 1;
    a1.q.dig = {6};
    a2.p.b = 1;
    a2.p.n = 1;
    a2.p.dig = {1};
    a2.q.n = 1;
    a2.q.dig = {1};
    x.C = {a2, a1};
    res.p.b = 1;
    res.p.n = 1;
    res.p.dig = {3};
    res.q.n = 1;
    res.q.dig = {6};
    Frac c = LED_P_Q(x);
    DO_CHECK(LED_P_Q(x) == res);

    x.m = 1;
    a1.p.b = 1;
    a1.p.n = 1;
    a1.p.dig = {3};
    a1.q.n = 1;
    a1.q.dig = {6};
    a2.p.b = 1;
    a2.p.n = 1;
    a2.p.dig = {1};
    a2.q.n = 1;
    a2.q.dig = {1};
    x.C = {a2, a1};
    res.p.b = 1;
    res.p.n = 1;
    res.p.dig = {3};
    res.q.n = 1;
    res.q.dig = {6};
//    std::cout << write_Frac(LED_P_Q(x)) << std::endl;
//    std::cout << write_Poly(x)<< std::endl;
    DO_CHECK(LED_P_Q(x) == res);*/
    string s = "(3)/(5)x^2 + (-1)/(4)x^1 + (1)/(1)";
    std::stringstream s_0;
    s_0 << s;
    Poly c;
    s_0 >> read_Poly(c);
    Frac res;
    string res1 = "(3)/(5)";
    s_0 << res1;
    s_0 >> read_Frac(res);
    DO_CHECK(LED_P_Q(c) == res);
}

void BTest::test_DEG_P_N() {

}

void BTest::test_FAC_P_Q() {
    Poly x,y,res; std::stringstream s_0;string s,res1;
    s = "(-97)/(1)x^1 + (56)/(1)x^0";
    s_0 << s;
    s_0 >> read_Poly(x);
    s = "(97)/(1)x^1 + (-56)/(1)x^0";
    s_0 << s;
    s_0 >> read_Poly(res);
    DO_CHECK(FAC_P_Q(x) == res);
}

void BTest::test_MUL_PP_P() {
    Frac a1, a2, a3, a4,b1, b2, b3, b4, res1, res2, res3,res4,res5,res6;
    Poly x, y, res;
    x.m = 2;
    a1.p.b = 0;
    a1.p.n = 1;
    a1.p.dig = {2};
    a1.q.n = 1;
    a1.q.dig = {3};
    a2.p.b = 0;
    a2.p.n = 1;
    a2.p.dig = {1};
    a2.q.n = 1;
    a2.q.dig = {3};
    a3.p.b = 0;
    a3.p.n = 1;
    a3.p.dig = {1};
    a3.q.n = 1;
    a3.q.dig = {1};
    x.C = {a3, a2, a1};
    y.m = 2;
    b1.p.b = 0;
    b1.p.n = 1;
    b1.p.dig = {3};
    b1.q.n = 1;
    b1.q.dig = {1};
    b2.p.b = 1;
    b2.p.n = 1;
    b2.p.dig = {3};
    b2.q.n = 1;
    b2.q.dig = {1};
    b3.p.b = 1;
    b3.p.n = 1;
    b3.p.dig = {2};
    b3.q.n = 1;
    b3.q.dig = {1};
    y.C = {b3, b2, b1};
    res.m = 4;
    res1.p.b = 0;
    res1.p.n = 1;
    res1.p.dig = {2};
    res1.q.n = 1;
    res1.q.dig = {1};
    res2.p.b = 1;
    res2.p.n = 1;
    res2.p.dig = {1};
    res2.q.n = 1;
    res2.q.dig = {1};
    res3.p.b = 0;
    res3.p.n = 1;
    res3.p.dig = {2};
    res3.q.n = 1;
    res3.q.dig = {3};
    res4.p.b = 1;
    res4.p.n = 2;
    res4.p.dig = {1,1};
    res4.q.n = 1;
    res4.q.dig = {3};
    res5.p.b = 1;
    res5.p.n = 1;
    res5.p.dig = {2};
    res5.q.n = 1;
    res5.q.dig = {1};
    res.C = {res5, res4, res3,res2,res1};
    DO_CHECK(MUL_PP_P(x, y) == res);

    x.m = 2;
    a1.p.b = 0;
    a1.p.n = 1;
    a1.p.dig = {1};
    a1.q.n = 1;
    a1.q.dig = {1};
    a2.p.b = 0;
    a2.p.n = 1;
    a2.p.dig = {2};
    a2.q.n = 1;
    a2.q.dig = {1};
    a3.p.b = 0;
    a3.p.n = 1;
    a3.p.dig = {3};
    a3.q.n = 1;
    a3.q.dig = {1};
    x.C = {a3, a2, a1};
    y.m = 1;
    b1.p.b = 0;
    b1.p.n = 1;
    b1.p.dig = {1};
    b1.q.n = 1;
    b1.q.dig = {1};
    b2.p.b = 0;
    b2.p.n = 1;
    b2.p.dig = {0};
    b2.q.n = 1;
    b2.q.dig = {1};
    y.C = {b2,b1};
    res.m = 3;
    res1.p.b = 0;
    res1.p.n = 1;
    res1.p.dig = {1};
    res1.q.n = 1;
    res1.q.dig = {1};
    res2.p.b = 0;
    res2.p.n = 1;
    res2.p.dig = {2};
    res2.q.n = 1;
    res2.q.dig = {1};
    res3.p.b = 0;
    res3.p.n = 1;
    res3.p.dig = {3};
    res3.q.n = 1;
    res3.q.dig = {1};
    res4.p.b = 0;
    res4.p.n = 1;
    res4.p.dig = {0};
    res4.q.n = 1;
    res4.q.dig = {1};
    res.C = {res4,res3,res2,res1};
    DO_CHECK(MUL_PP_P(x, y) == res);

    x.m = 2;
    a1.p.b = 0;
    a1.p.n = 1;
    a1.p.dig = {1};
    a1.q.n = 1;
    a1.q.dig = {1};
    a2.p.b = 0;
    a2.p.n = 1;
    a2.p.dig = {2};
    a2.q.n = 1;
    a2.q.dig = {1};
    a3.p.b = 0;
    a3.p.n = 1;
    a3.p.dig = {3};
    a3.q.n = 1;
    a3.q.dig = {1};
    x.C = {a3, a2, a1};
    y.m = 1;
    b1.p.b = 0;
    b1.p.n = 1;
    b1.p.dig = {2};
    b1.q.n = 1;
    b1.q.dig = {1};
    b2.p.b = 0;
    b2.p.n = 1;
    b2.p.dig = {0};
    b2.q.n = 1;
    b2.q.dig = {1};
    y.C = {b2,b1};
    res.m = 3;
    res1.p.b = 0;
    res1.p.n = 1;
    res1.p.dig = {2};
    res1.q.n = 1;
    res1.q.dig = {1};
    res2.p.b = 0;
    res2.p.n = 1;
    res2.p.dig = {4};
    res2.q.n = 1;
    res2.q.dig = {1};
    res3.p.b = 0;
    res3.p.n = 1;
    res3.p.dig = {6};
    res3.q.n = 1;
    res3.q.dig = {1};
    res4.p.b = 0;
    res4.p.n = 1;
    res4.p.dig = {0};
    res4.q.n = 1;
    res4.q.dig = {1};
    res.C = {res4,res3,res2,res1};
    DO_CHECK(MUL_PP_P(x, y) == res);
}

void BTest::test_DIV_PP_P() {
    string s = "(5)/(1)x^2 + (3)/(1)x^1 + (1)/(1)";
    std::stringstream s_0;
    s_0 << s;
    Poly x,y,res;
    s_0 >> read_Poly(x);
    s = "(2)/(1)x^1 + (1)/(1)";
    s_0 << s;
    s_0 >> read_Poly(y);
    string res1 = "(5)/(2)x^1 + (1)/(4)";
    s_0 << res1;
    s_0 >> read_Poly(res);

    DO_CHECK(DIV_PP_P(x,y) == res);
}

void BTest::test_MOD_PP_P() {
    string s = "(1)/(1)x^4 + (13)/(1)x^3 + (27)/(1)x^2 + (-97)/(1)x^1 + (56)/(1)";
    std::stringstream s_0;
    s_0 << s;
    Poly x,y,res;
    s_0 >> read_Poly(x);
    s = "(1)/(1)x^4 + (21)/(1)x^3 + (139)/(1)x^2 + (231)/(1)x^1 + (-392)/(1)";
    s_0 << s;
    s_0 >> read_Poly(y);
    string res1 = "(-8)/(1)x^3 + (-112)/(1)x^2 + (-328)/(1)x^1 + (448)/(1)";
    s_0 << res1;
    s_0 >> read_Poly(res);
    DO_CHECK(MOD_PP_P(x,y) == res);
}

void BTest::test_GCF_PP_P() {
    Poly x,y,res; std::stringstream s_0;string s,res1;
    s = "(-97)/(1)x^1 + (56)/(1)x^0";
    s_0 << s;
    s_0 >> read_Poly(x);
    s = "(-97)/(1)x^1 + (52)/(1)x^0";
    s_0 << s;
    s_0 >> read_Poly(y);
    res1 = "(-97)/(1)x^1 + (52)/(1)x^0";
    s_0 << res1;
    s_0 >> read_Poly(res);
    DO_CHECK(GCF_PP_P(x,y) == res);
}

void BTest::test_DER_P_P() {
    //(1)/(1)x^100 + (1)/(1)x^0
    Poly x,y,res; std::stringstream s_0;string s,res1;
    s = "(1)/(1)x^100 + (1)/(1)x^0";
    s_0 << s;
    s_0 >> read_Poly(x);
    s = "(100)/(1)x^99 + (0)/(1)x^0";
    s_0 << s;
    s_0 >> read_Poly(res);
    cout << write_Poly(x) << '\n';
    cout << write_Poly(res) << '\n';
    cout << write_Poly(DER_P_P(x)) << '\n';
    DO_CHECK(DER_P_P(x) == res);

}

void BTest::test_NMR_P_P() {
    Frac a1, a2, a3, a4, res1, res2, res3;
    Poly x, res;
    x.m = 3;
    a1.p.b = 0;
    a1.p.n = 1;
    a1.p.dig = {2};
    a1.q.n = 1;
    a1.q.dig = {1};
    a2.p.b = 1;
    a2.p.n = 1;
    a2.p.dig = {3};
    a2.q.n = 1;
    a2.q.dig = {1};
    a3.p.b = 0;
    a3.p.n = 1;
    a3.p.dig = {0};
    a3.q.n = 1;
    a3.q.dig = {1};
    a4.p.b = 0;
    a4.p.n = 1;
    a4.p.dig = {1};
    a4.q.n = 1;
    a4.q.dig = {1};
    x.C = {a1, a2, a3, a4};
    res.m = 2;
    res1.p.b = 1;
    res1.p.n = 1;
    res1.p.dig = {2};
    res1.q.n = 1;
    res1.q.dig = {1};
    res2.p.b = 0;
    res2.p.n = 1;
    res2.p.dig = {1};
    res2.q.n = 1;
    res2.q.dig = {1};
    res3.p.b = 0;
    res3.p.n = 1;
    res3.p.dig = {1};
    res3.q.n = 1;
    res3.q.dig = {1};
    res.C = {res1, res2, res3};
    DO_CHECK(NMR_P_P(x) == res);
}
//aaaa