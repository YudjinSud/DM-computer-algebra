#include "Natural.h"

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#define PI 2*asin(1)
#define mod 1000000007
#define all(a) begin(a),end(a)
#define fore(i, j, n) for(long long i = j; i < n; i++)
#define fi first
#define se second
//using namespace std;

/*
void read_natural(Natural &a){
    cin >> a.n;
    char c;
    fore(i, 0, a.n) {
        cin >> c;
        a.dig.push_back( int(c) - int('0'));
    }
}
*/
int COM_NN_D(Natural &a, Natural &b) {
    if (a.n > b.n) return 2;
    if (a.n < b.n) return 1;
    fore(i, 0, a.n) {
        if (a.dig[i] > b.dig[i]) return 2;
        if (a.dig[i] < b.dig[i]) return 1;
    }
    return 0;
}

/*
void solve_COM_NN_D(){
    Natural a,b;
    read_natural(a);
    read_natural(b);
    cout << COM_NN_D(a,b) << '\n';
}*/

int NZER_N_B(Natural &a) {
    if (a.n == 1 && a.dig[0] == 0) return 1;
    else return 0;
}

/*
void solve_NZER_N_B() {
    Natural a;
    read_natural(a);
    cout << NZER_N_B(a) << '\n';
}
*/

Natural ADD_1N_N(Natural &a) {
    for (int i = a.n - 1; i >= 0; i--) {
        a.dig[i]++;
        if (a.dig[i] != 10) return a;
        a.dig[i] = 0;
    }
    vector<int> B = a.dig;
    a.dig.push_back(0);
    a.dig[0] = 1;
    fore(i, 0, a.n) a.dig[i + 1] = B[i];
    a.n++;
    return a;
}

/*
void solve_ADD_1N_N(){
    Natural a;
    read_natural(a);
    a = ADD_1N_N(a);
    cout << a.n << '\n';
    fore(i,0,a.n) cout << a.dig[i];
    cout << '\n';
}
*/

Natural ADD_NN_N(Natural a, Natural b) {
    if (a.n < b.n) {
        swap(a, b);
    }
    Natural c;
    int delta = a.n - b.n;
    int ost = 0;
    for (int i = a.n - 1; i - delta >= 0; i--) {
        c.dig.push_back((a.dig[i] + b.dig[i - delta] + ost) % 10);
        ost = (a.dig[i] + b.dig[i - delta] + ost) / 10;
    }
    for (int i = delta - 1; i >= 0; i--) {
        c.dig.push_back((ost + a.dig[i]) % 10);
        ost = (ost + a.dig[i]) / 10;
    }
    if (ost != 0) c.dig.push_back(ost);
    reverse(all(c.dig));
    c.n = (int) (c.dig.size());
    return c;
}

Natural SUB_NN_N(Natural a, Natural b) {
    if (COM_NN_D(a,b) == 1) {
        swap(a, b);
    }
    reverse(all(a.dig));reverse(all(b.dig));
    int ost = 0;
    for(int i = 0; i < (int)(b.dig.size()) || ost; ++i) {
        if(i < (int)(b.dig.size()))
            a.dig[i] -= ost + b.dig[i];
        else
            a.dig[i] -= ost;
        if(a.dig[i] < 0){
            a.dig[i] += 10;
            ost = 1;
        }else ost = 0;
    }

    while((int)(a.dig.size()) > 1 && a.dig.back() == 0)
        a.dig.pop_back();
    reverse(all(a.dig));
    a.n = a.dig.size();
    return a;
}

Natural MUL_ND_N(Natural a, int n){
    int ost = 0;
    reverse(all(a.dig));
    for(int i = 0; i < (int)(a.dig.size()) || ost; ++i){
        if(i == (int)(a.dig.size()))
            a.dig.push_back(0);
        long long b = ost + a.dig[i] * 1ll * n;
        a.dig[i] = (int)(b % 10);
        ost = (int)(b / 10);
    }
    while((int)(a.dig.size()) > 1 && a.dig.back() == 0)
        a.dig.pop_back();
    reverse(all(a.dig));
    a.n = a.dig.size();
    return a;
}

