#include "Natural.h"
#include "Integ.h"


Integ ABS_Z_N(Integ a){
    a.b = 0;
    return a;
}

int POZ_Z_D(Integ a){
    if(a.n == 1 && a.dig[0] == 0) return 0;
    return 2 - a.b;
}

Integ MUL_ZM_Z(Integ a){
    a.b = 1 - a.b;
    return a;
}

Integ TRANS_N_Z(Natural a){
    Integ c;
    c.b = 0;
    c.n = a.n;
    c.dig = a.dig;
    return c;
}

Natural TRANS_Z_N(Integ a){
    Natural c;
    c.n = a.n;
    c.dig = a.dig;
    return c;
}

Integ ADD_ZZ_Z(Integ a, Integ b){
    if(POZ_Z_D(a) == POZ_Z_D(b)){
        a = TRANS_N_Z(ADD_NN_N(TRANS_Z_N(a), TRANS_Z_N(b)));
        if(POZ_Z_D(b) == 1) a.b = 1;
        else a.b = 0;
        return a;
    }
    if((COM_NN_D(TRANS_Z_N(a),TRANS_Z_N(b)) == 1 && b.b == 1) ||
         (COM_NN_D(TRANS_Z_N(a),TRANS_Z_N(b)) == 2 && a.b == 1)){
        a = TRANS_N_Z(SUB_NN_N(TRANS_Z_N(a), TRANS_Z_N(b)));
        a.b = 1;
        return a;
    }
    a = TRANS_N_Z(SUB_NN_N(TRANS_Z_N(a), TRANS_Z_N(b)));
    a.b = 0;
    return a;
}
/*
Integ SUB_ZZ_Z(Integ a, Integ b){

}

Integ MUL_ZZ_Z(Integ a, Integ b){

}

Integ DIV_ZZ_Z(Integ a, Integ b){

}

Integ MOD_ZZ_Z(Integ a, Integ b){

}
*/
bool Integ::operator==(const Integ &other) {
    return n == other.n && dig == other.dig && b == other.b;
}