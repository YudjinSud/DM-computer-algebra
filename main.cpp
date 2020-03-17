#include <iostream>
#include "Natural.h"

#define fore(i, j, n) for(long long i = j; i < n; i++)

void read_natural(Natural &a) {
    cin >> a.n;
    char c;
    fore(i, 0, a.n) {
        cin >> c;
        a.dig.push_back(int(c) - int('0'));
    }
}

void solve_MUL_Nk_N() {
    Natural a;
    int n;
    read_natural(a);
    cin >> n;
    Natural c = MUL_Nk_N(a, n);
    fore(i, 0, c.n) cout << c.dig[i];
    cout << '\n';
}

int main() {
    solve_MUL_Nk_N();
    return 0;
}

