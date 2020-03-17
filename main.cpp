#include <iostream>
#include "Natural.h"
#define fore(i, j, n) for(long long i = j; i < n; i++)
void read_natural(Natural &a){
    cin >> a.n;
    char c;
    fore(i, 0, a.n) {
        cin >> c;
        a.dig.push_back(int(c) - int('0'));
    }
}

void solve_ADD_NN_N(){
    Natural a, b;
    read_natural(a);
    read_natural(b);
    Natural c = ADD_NN_N(a,b);
    fore(i, 0, c.n) cout << c.dig[i];
    cout << '\n';
}

int main() {
    solve_ADD_NN_N();
    return 0;
}


//this is message for artyom
