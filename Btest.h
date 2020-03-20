#ifndef DM_COMPUTER_ALGEBRA_BTEST_H
#define DM_COMPUTER_ALGEBRA_BTEST_H

#include "Test.h"
#include "Natural.h"
#include "Integ.h"
#include "Frac.h"
#include "Poly.h"

class BTest : public Test {
public:
    void runAllTests() override;

private:
    void test_COM_NN_D();

    void test_NZER_N_B();

    void test_ADD_1N_N();

    void test_ADD_NN_N();

    void test_SUB_NN_N();

    void test_MUL_ND_N();

    void test_MUL_Nk_N();

    void test_MUL_NN_N();

    void test_SUB_NDN_N();

    void test_DIV_NN_Dk();

    void test_DIV_NN_N();

    void test_MOD_NN_N();

    void test_GCF_NN_N();

    void test_LCM_NN_N();

    void test_ABS_Z_N();

    void test_POZ_Z_D();

    void test_MUL_ZM_Z();

    void test_TRANS_N_Z();

    void test_TRANS_Z_N();

    void test_ADD_ZZ_Z();

    void test_SUB_ZZ_Z();

    void test_MUL_ZZ_Z();

    void test_DIV_ZZ_Z();

    void test_MOD_ZZ_Z();

    void test_RED_Q_Q();
};

#endif //DM_COMPUTER_ALGEBRA_BTEST_H
