#include <iostream>
#include "Natural.h"
#include "Integ.h"


Integ ABS_Z_N(Integ a) {
    a.b = 0;
    return a;
}

int POZ_Z_D(Integ a) {
    if (a.n == 1 && a.dig[0] == 0) return 0;
    return 2 - a.b;
}

Integ MUL_ZM_Z(Integ a) {
    if(NZER_N_B(TRANS_Z_N(ABS_Z_N(a)))) {
        a.b = 0;
        return a;
    }
    a.b = 1 - a.b;
    return a;
}

Integ TRANS_N_Z(Natural a) {
    Integ c;
    c.b = 0;
    c.n = a.n;
    c.dig = a.dig;
    return c;
}

Natural TRANS_Z_N(Integ a) {
    a = ABS_Z_N(a);
    Natural c;
    c.n = a.n;
    c.dig = a.dig;
    return c;
}

Integ ADD_ZZ_Z(Integ a, Integ b) {
    if (POZ_Z_D(a) == POZ_Z_D(b)) {
        a = TRANS_N_Z(ADD_NN_N(TRANS_Z_N(a), TRANS_Z_N(b)));
        if (POZ_Z_D(b) == 1) a.b = 1;
        else a.b = 0;
        return a;
    }
    if ((COM_NN_D(TRANS_Z_N(a), TRANS_Z_N(b)) == 1 && b.b == 1) ||
        (COM_NN_D(TRANS_Z_N(a), TRANS_Z_N(b)) == 2 && a.b == 1)) {
        a = TRANS_N_Z(SUB_NN_N(TRANS_Z_N(a), TRANS_Z_N(b)));
        a.b = 1;
        return a;
    }
    a = TRANS_N_Z(SUB_NN_N(TRANS_Z_N(a), TRANS_Z_N(b)));
    a.b = 0;
    return a;
}

Integ SUB_ZZ_Z(Integ a, Integ b) {
    b.b = 1 - b.b;
    return ADD_ZZ_Z(a, b);
}

Integ MUL_ZZ_Z(Integ a, Integ b) {
    Natural a1 = TRANS_Z_N(a);
    Natural b1 = TRANS_Z_N(b);
    a1 = MUL_NN_N(a1, b1);
    a.b = (a.b + b.b) % 2;
    a.n = a1.n;
    a.dig = a1.dig;
    if(NZER_N_B(a1)) a.b = 0;
    return a;
}

Integ DIV_ZZ_Z(Integ a, Natural b) {
    Natural a1 = TRANS_Z_N(a);
    Natural x;
    x.n = 1;
    x.dig = {1};
    if (a.b == 1) a1 = ADD_NN_N(a1, SUB_NN_N(b, x));
    a1 = DIV_NN_N(a1, b);
    a.n = a1.n;
    a.dig = a1.dig;
    return a;
}

Integ MOD_ZZ_Z(Integ a, Natural b) {
    Integ nul;
    nul.b = 0;
    nul.n = 1;
    nul.dig = {0};
    if(a == nul) return nul;
    a = SUB_ZZ_Z(a, MUL_ZZ_Z(DIV_ZZ_Z(a, b), TRANS_N_Z(b)));
    return a;
}

bool Integ::operator==(const Integ &other) {
    return n == other.n && dig == other.dig && b == other.b;
}