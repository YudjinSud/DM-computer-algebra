//
// Created by xtkcb on 20-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_FRAC_H
#define DM_COMPUTER_ALGEBRA_FRAC_H


#include <vector>
#include <iosfwd>
#include <algorithm>
#include "Integ.h"
#include "Natural.h"
using namespace std;

struct Frac { // P/Q
    Integ p;
    Natural q;

    bool operator==(const Frac &other);

    Frac() {
        Integ I;
        I.b = 0;
        I.n = 1;
        I.dig.push_back(0);
        Natural Q;
        Q.n = 1;
        Q.dig.push_back(1);
        this->p = I;
        this->q = Q;
    }
};

Frac RED_Q_Q(Frac a);

int INT_Q_B(Frac a);

Frac TRANS_Z_Q(Integ a);

Integ TRANS_Q_Z(Frac a);

Frac ADD_QQ_Q(Frac a, Frac b);

Frac SUB_QQ_Q(Frac a, Frac b);

Frac MUL_QQ_Q(Frac a, Frac b);

Frac DIV_QQ_Q(Frac a, Frac b);

#endif //DM_COMPUTER_ALGEBRA_FRAC_H
