#include <iostream>
#include "Poly.h"
#include "Manipulator.h"

Poly ADD_PP_P(Poly a, Poly b) {
    if (a.m < b.m)
        swap(a, b);
    for (int i = 0; i <= b.m; i++)
        a.C[i] = ADD_QQ_Q(a.C[i], b.C[i]);
    Frac nul;
    for (int i = a.m; i >= 0; i--) {
        if (a.C[i] == nul) {
            a.C.pop_back();
            a.m--;
        } else
            break;
    }
    if (a.C.empty()) {
        a.C.push_back(Frac());
        a.m = 0;
    }
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
    if (a.C.empty()) {
        a.C.push_back(Frac());
        a.m = 0;
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
        NOD = TRANS_Z_N(a.C[0].p);
        NOK = a.C[0].q;
    }
    for (int i = 1; i <= a.m; i++) {
        NOD = GCF_NN_N(NOD, TRANS_Z_N(a.C[i].p));
        NOK = LCM_NN_N(NOK, a.C[i].q);
    }
    for (int i = 0; i <= a.m; i++) {
        int x = a.C[i].p.b;
        Integ nul;
        nul.b = 0; nul.n = 1; nul.dig = {0};
        if(a.C[i].p == nul);
        else a.C[i].p = MUL_ZZ_Z(TRANS_N_Z(DIV_NN_N(TRANS_Z_N(a.C[i].p), NOD)), TRANS_N_Z(DIV_NN_N(NOK, a.C[i].q)));
        a.C[i].p.b = x;
        a.C[i].q.n = 1;
        a.C[i].q.dig = {1};
    }
    if(a.C[a.m].p.b == 1){
        Integ nul;
        nul.b = 0;
        nul.n = 1;
        nul.dig = {0};
        for(int i = 0; i <= a.m; i++)
            if (!(nul == a.C[i].p)){
                a.C[i].p.b = 1 - a.C[i].p.b;
            }
    }
    return a;
}

Poly MUL_PP_P(Poly a, Poly b) {
    if (a.m < b.m)
        swap(a, b);
    Poly c = MUL_PQ_P(a, b.C[0]);
    for (int i = 1; i <= b.m; i++)
        c = ADD_PP_P(c, MUL_PQ_P(MUL_Pxk_P(a, i), b.C[i]));
    c.m = DEG_P_N(c);
    c.C.resize(c.m + 1);
    return c;
}

Poly DIV_PP_P(Poly a, Poly b) {
    int stepen_c = DEG_P_N(a) - DEG_P_N(b);
    if (stepen_c < 0) return Poly();
    Poly c;
    Frac x;
    int curr_check = DEG_P_N(a);
    for (;curr_check >= DEG_P_N(b); --curr_check) {
        if (a.m < curr_check) {
            c.C.push_back(Frac());
        } else {
            x = DIV_QQ_Q(a.C[a.m], b.C[b.m]);
            c.C.push_back(x);
            a = SUB_PP_P(a, MUL_Pxk_P(MUL_PQ_P(b, x), DEG_P_N(a) - DEG_P_N(b)));
        }
    }
    c.m = (c.C.size() - 1);
    reverse(begin(c.C), end(c.C));
    for (int i = c.m; i >= 0; i--) {
        if (c.C[i] == Frac()) {
            c.C.pop_back();
            c.m--;
        } else
            break;
    }
    return c;
}

Poly MOD_PP_P(Poly a, Poly b) {
    int stepen_c = DEG_P_N(a) - DEG_P_N(b);
    if (stepen_c < 0) return Poly();
    Poly c;
    Frac x;
    while (DEG_P_N(a) - DEG_P_N(b) >= 0) {
        x = DIV_QQ_Q(a.C[a.m], b.C[b.m]);
        c.C.push_back(x);
        a = SUB_PP_P(a, MUL_Pxk_P(MUL_PQ_P(b, x), DEG_P_N(a) - DEG_P_N(b)));
        if(a == Poly()) break;
    }
    return a;
}

Poly GCF_PP_P(Poly a, Poly b) {
    if (a.m < b.m)
        swap(a, b);
    bool f = true;
    Frac t = Frac();
    for (int i = 0; i <= b.m; i++)
        if (!(b.C[i] == t))
            f = false;
    if (f) {
        Frac s = a.C[a.m];
        int x = s.p.b;
        Natural c = TRANS_Z_N(ABS_Z_N(s.p));
        s.p = TRANS_N_Z(s.q);
        s.p.b = x;
        s.q = c;
        a = MUL_PQ_P(a,s);
        return a;
    } else
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

Poly NMR_P_P(Poly a) { //P-13
    Poly b = DER_P_P(a);
    return DIV_PP_P(a, GCF_PP_P(a, b));
}