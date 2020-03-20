//
// Created by xtkcb on 18-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_TEST_H
#define DM_COMPUTER_ALGEBRA_TEST_H

#include <cstddef>

#define DO_CHECK(expr) Test::check(expr,__FUNCTION__,__FILE__,__LINE__)

class Test {
public:

    static bool showFinalResult();

    virtual void runAllTests() = 0;

    static void check(bool expr, const char *func, const char *filename, size_t lineNum);

protected:
    static int failedNum;
    static int totalNum;

};

#endif //DM_COMPUTER_ALGEBRA_TEST_H
