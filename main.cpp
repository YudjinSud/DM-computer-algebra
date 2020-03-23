#include "Test.h"
#include "Btest.h"

#define fore(i, j, n) for(long long i = j; i < n; i++)

int main() {
    BTest bt;
    bt.runAllTests();
    Test::showFinalResult();
//    Poly c;
//    std::cin >> read_Poly(c); format: "(3)/(5)x^2 + (-1)/(4)x^1 + (1)/(1)" testi delaite 4erez  stringstream
//    std::cout << write_Poly(c) << std::endl;
    return 0;
}

