#include "Test.h"
#include <iostream>

int Test::failedNum = 0;
int Test::totalNum = 0;

bool Test::showFinalResult() {
    std::cout << "Total tests: " << totalNum << '\n';
    std::cout << "Tests passed: " << totalNum - failedNum << '\n';
    std::cout << "Tests failed: " << failedNum << '\n';
    return !failedNum;
}

void Test::check(bool expr, const char *func, const char *filename, size_t lineNum) {
    ++totalNum;
    if (!expr) {
        ++failedNum;
        std::cout << "Test failed:\n";
        std::cout << "File: " << filename << '\n';
        std::cout << "Line: " << lineNum << '\n';
        std::cout << "Function: " << func << "\n\n";
    }
}