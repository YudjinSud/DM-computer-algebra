//
// Created by xtkcb on 18-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_BTEST_H
#define DM_COMPUTER_ALGEBRA_BTEST_H

#include "Test.h"
#include "Natural.h"

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
};

#endif //DM_COMPUTER_ALGEBRA_BTEST_H