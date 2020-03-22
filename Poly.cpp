#include "Natural.h"
#include "Integ.h"
#include "Poly.h"
#include "Frac.h"

Poly ADD_PP_P(Poly a, Poly b) {
    if (a.m < b.m)
        swap(a, b);
    for (int i = 0; i <= b.m; i++)
        a.C[i] = ADD_QQ_Q(a.C[i], b.C[i]);
    return a;
}

Poly SUB_PP_P(Poly a, Poly b) {
    vector<int> null_vec = {0};
    for (int i = 0; i <= b.m; i++)
        a.C[i] = SUB_QQ_Q(a.C[i], b.C[i]);
    Frac nul;
    for (int i = a.m; i >= 0; i--) {
        if (a.C[i] == nul) {
            a.C.pop_back();
            a.m--;
        } else
            break;
    }
    return a;
}

Poly MUL_PQ_P(Poly a, Frac r) {
    Frac bla;
    Poly nul;
    if (r == bla)
        return nul;
    for (int i = 0; i <= a.m; i++)
        a.C[i] = MUL_QQ_Q(a.C[i], r);
    return a;
}

Poly MUL_Pxk_P(Poly a, int k) {
    Frac nul;
    reverse(a.C.begin(), a.C.end());
    for (int i = 0; i < k; i++)
        a.C.push_back(nul);
    a.m += k;
    reverse(a.C.begin(), a.C.end());
    return a;
}

Frac LED_P_Q(Poly a) {
    int i = a.m;
    Frac nul;
    while ((a.C[i] == nul) && (i > 0)) {
        i--;
    }
    return a.C[i];
}

int DEG_P_N(Poly a) {
    int i = a.m;
    Frac nul;
    while ((a.C[i] == nul) && (i > 0)) {
        i--;
    }
    return i;
}

Poly FAC_P_Q(Poly a) {
    Natural NOD, NOK;
    if (a.m > 0) {
        NOD = GCF_NN_N(TRANS_Z_N(a.C[0].p), TRANS_Z_N(a.C[1].p));
        NOK = LCM_NN_N(a.C[0].q, a.C[1].q);
    }
    for (int i = 2; i <= a.m; i++) {
        NOD = GCF_NN_N(NOD, TRANS_Z_N(a.C[i].p));
        NOK = LCM_NN_N(NOK, a.C[i].q);
    }
    for (int i = 0; i <= a.m; i++) {
        a.C[i].p = MUL_ZZ_Z(TRANS_N_Z(DIV_NN_N(TRANS_Z_N(a.C[i].p), NOD)), TRANS_N_Z(DIV_NN_N(NOK, a.C[i].q)));
        a.C[i].q.n = 1;
        a.C[i].q.dig = {1};
    }
    return a;
}

Poly MUL_PP_P(Poly a, Poly b) {
    if (a.m < b.m)
        swap(a, b);
    Poly c = MUL_PQ_P(a, b.C[0]);
    for (int i = 1; i <= b.m; i++)
        c = ADD_PP_P(c, ADD_PP_P(MUL_PQ_P(a, b.C[i]), MUL_Pxk_P(a, i)));
    c.m = DEG_P_N(c);
    c.C.resize(c.m + 1);
    return c;
}

Poly DIV_PP_P(Poly a, Poly b) {
    int stepen_c = DEG_P_N(a) - DEG_P_N(b);
    if (stepen_c <= 0) return Poly();
    Poly c;
    while (DEG_P_N(a) - DEG_P_N(b) >= 0) {
        Frac x = DIV_QQ_Q(a.C[b.m], b.C[b.m]);
        c.C.push_back(x);
        a = SUB_PP_P(a, MUL_Pxk_P(MUL_PQ_P(b, x), DEG_P_N(a) - DEG_P_N(b)));
    }
    c.m = (c.C.size() - 1);
    reverse(begin(c.C), end(c.C));
    return c;
}

Poly MOD_PP_P(Poly a, Poly b) {
    Poly c = DIV_PP_P(a, b);
    return SUB_PP_P(a, MOD_PP_P(c, b));
}

Poly GCF_PP_P(Poly a, Poly b) {
    if (a.m < b.m)
        swap(a, b);
    if (b == Poly())
        return a;
    else
        return GCF_PP_P(b, MOD_PP_P(a, b));
}

Poly DER_P_P(Poly a) { //P-12
    for (int i = 1; i <= a.m; i++) {
        int j = i;
        Integ h;
        h.b = 0;
        while (j > 0) {
            h.dig.push_back(j % 10);
            j /= 10;
        }
        h.n = int(h.dig.size());
        a.C[i - 1] = MUL_QQ_Q(a.C[i], TRANS_Z_Q(h));
    }
    a.C.pop_back();
    a.m--;
    return a;
}

