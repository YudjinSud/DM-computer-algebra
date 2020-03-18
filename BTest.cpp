#include "BTest.h"

void BTest::runAllTests() {
    test_COM_NN_D();
}

void BTest::test_COM_NN_D() {
    Natural a,b;
    a.n = 3;
    a.dig = {1,1,1};
    b.n = 3;
    b.dig = {1,1,2};
    DO_CHECK(COM_NN_D(a,b) == 1);
}
