#include <iostream>
#include "Natural.h"

#define all(a) begin(a), end(a)
#define fore(i, j, n) for(long long i = j; i < n; i++)

int COM_NN_D(Natural a, Natural b) {
    if (a.n > b.n) return 2;
    if (a.n < b.n) return 1;
    fore(i, 0, a.n) {
        if (a.dig[i] > b.dig[i]) return 2;
        if (a.dig[i] < b.dig[i]) return 1;
    }
    return 0;
}

int NZER_N_B(Natural a) {
    if (a.n == 1 && a.dig[0] == 0) return 1;
    else return 0;
}

Natural ADD_1N_N(Natural a) {
    for (int i = a.n - 1; i >= 0; i--) {
        a.dig[i]++;
        if (a.dig[i] != 10) return a;
        a.dig[i] = 0;
    }
    a.dig.push_back(0);
    a.n = int(a.dig.size());
    for (int i = a.n - 1; i > 0; i--) a.dig[i] = a.dig[i - 1];
    a.dig[0] = 1;
    return a;
}

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
    if (COM_NN_D(a, b) == 1) {
        swap(a, b);
    }
    reverse(all(a.dig));
    reverse(all(b.dig));
    int ost = 0;
    for (int i = 0; i < (int) (b.dig.size()) || ost; ++i) {
        if (i < (int) (b.dig.size()))
            a.dig[i] -= ost + b.dig[i];
        else
            a.dig[i] -= ost;
        if (a.dig[i] < 0) {
            a.dig[i] += 10;
            ost = 1;
        } else ost = 0;
    }

    while ((int) (a.dig.size()) > 1 && a.dig.back() == 0)
        a.dig.pop_back();
    reverse(all(a.dig));
    a.n = a.dig.size();
    return a;
}

Natural MUL_ND_N(Natural a, int n) {
    int ost = 0;
    reverse(all(a.dig));
    for (int i = 0; i < (int) (a.dig.size()) || ost; ++i) {
        if (i == (int) (a.dig.size()))
            a.dig.push_back(0);
        long long b = ost + a.dig[i] * 1ll * n;
        a.dig[i] = (int) (b % 10);
        ost = (int) (b / 10);
    }
    while ((int) (a.dig.size()) > 1 && a.dig.back() == 0)
        a.dig.pop_back();
    reverse(all(a.dig));
    a.n = a.dig.size();
    return a;
}

Natural MUL_Nk_N(Natural a, int k) {
    fore(i, 0, k) a.dig.push_back(0);
    a.n = (int) (a.dig.size());
    return a;
}

Natural MUL_NN_N(Natural a, Natural b) {
    Natural result;
    result.n = 1;
    result.dig = {0};
    if (a.n < b.n)
        swap(a, b);
    for (int i = 0; i < b.n; i++)
        result = ADD_NN_N(result, MUL_ND_N(MUL_Nk_N(a, b.n - i - 1), b.dig[i]));
    return result;
}

Natural SUB_NDN_N(Natural a, Natural b, int n) {
    if (COM_NN_D(a, b) == 1)
        swap(a, b);
    b = MUL_ND_N(b, n);
    return (SUB_NN_N(a, b));
}

int DIV_NN_Dk(Natural a, Natural b) {
    if (COM_NN_D(a, b) == 1)
        swap(a, b);
    int k = a.n - b.n;;
    if (a.dig[0] < b.dig[0])
        k--;
    b = MUL_Nk_N(b, k);
    fore(i, 1, 10) {
        if (COM_NN_D(a, MUL_ND_N(b, i)) == 0) {
            return i;
        } else if (COM_NN_D(a, MUL_ND_N(b, i)) == 1) {
            return (i - 1);
        }
    }
}

Natural DIV_NN_N(Natural a, Natural b) {
    if (COM_NN_D(a, b) == 1)
        swap(a, b);
    Natural c;
    while(COM_NN_D(a,b) == 2) {
        int x = DIV_NN_Dk(a, b);
        c.dig.push_back(x);
        int k = a.n - b.n;
        if (a.dig[0] < b.dig[0])
            k--;
        a = SUB_NN_N(a, MUL_ND_N(MUL_Nk_N(b, k),x));
    }
    c.n = int(c.dig.size());
    return c;
}

Natural MOD_NN_N(Natural a, Natural b) {
    if (COM_NN_D(a, b) == 1)
        swap(a, b);
    return SUB_NN_N(a, MUL_NN_N(DIV_NN_N(a,b),b));
}

bool Natural::operator==(const Natural &other) {
    return n == other.n && dig == other.dig;
}
