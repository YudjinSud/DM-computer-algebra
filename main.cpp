#include <iostream>
#include "Natural.h"
#define fore(i, j, n) for(long long i = j; i < n; i++)

void read_natural(Natural &a){
    cin >> a.n;
    char c;
    fore(i, 0, a.n) {
        cin >> c;
        a.dig.push_back( int(c) - int('0'));
    }
}

void solve_ADD_1N_N(){
    Natural a;
    read_natural(a);
    a = ADD_1N_N(a);
    cout << a.n << '\n';
    fore(i,0,a.n) cout << a.dig[i];
    cout << '\n';
}

int main() {
    solve_ADD_1N_N();
    return 0;
}