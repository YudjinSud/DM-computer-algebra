#include <iostream>
#include "Natural.h"
#include "Test.h"
#include "Btest.h"

#define fore(i, j, n) for(long long i = j; i < n; i++)

int main() {
    BTest bt;
    bt.runAllTests();
    Test::showFinalResult();
    return 0;
}

