#include "Natural.h"
#include "Integ.h"
#include "Frac.h"


Frac RED_Q_Q(Frac a) {
    Integ p = a.p;
    Natural q = a.q;
    int x = p.b;
    Natural p1 = TRANS_Z_N(p);
    Natural gcd = GCF_NN_N(p1, q);
    p = TRANS_N_Z(DIV_NN_N(p1, gcd));
    q = DIV_NN_N(q, gcd);
    p.b = x;
    a.p = p;
    a.q = q;
    return a;
}

int INT_Q_B(Frac a) {
    a = RED_Q_Q(a);
    Natural c;
    c.n = 1;
    c.dig = {1};
    if (a.q == c) return 1;
    else return 0;
}

Frac TRANS_Z_Q(Integ a) {
    Frac b;
    b.p = a;
    Natural c;
    c.n = 1;
    c.dig = {1};
    b.q = c;
    return b;
}

Integ TRANS_Q_Z(Frac a) {
    a = RED_Q_Q(a);
    Integ c;
    c = a.p;
    return c;
}

Frac ADD_QQ_Q(Frac a, Frac b) {
    a = RED_Q_Q(a);
    b = RED_Q_Q(b);
    Natural lcm = LCM_NN_N(a.q, b.q);
    a.p = MUL_ZZ_Z(TRANS_N_Z(DIV_NN_N(lcm, a.q)), a.p);
    b.p = MUL_ZZ_Z(TRANS_N_Z(DIV_NN_N(lcm, b.q)), b.p);
    a.p = ADD_ZZ_Z(a.p, b.p);
    a.q = lcm;
    return RED_Q_Q(a);
}

Frac SUB_QQ_Q(Frac a, Frac b) {
    b.p.b = 1 - b.p.b;
    return ADD_QQ_Q(a, b);
}

Frac MUL_QQ_Q(Frac a, Frac b) {
    a = RED_Q_Q(a);
    b = RED_Q_Q(b);
    a.p = MUL_ZZ_Z(a.p, b.p);
    a.q = MUL_NN_N(a.q, b.q);
    return RED_Q_Q(a);
}

Frac DIV_QQ_Q(Frac a, Frac b) {
    a = RED_Q_Q(a);
    b = RED_Q_Q(b);
    int x = b.p.b;
    Natural c = TRANS_Z_N(ABS_Z_N(b.p));
    b.p = TRANS_N_Z(b.q);
    b.p.b = x;
    b.q = c;
    return MUL_QQ_Q(a, b);
}


bool Frac::operator==(const Frac &other) {
    return p == other.p && q == other.q;
}