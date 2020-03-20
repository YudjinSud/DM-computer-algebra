//
// Created by xtkcb on 20-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_FRAC_H
#define DM_COMPUTER_ALGEBRA_FRAC_H


#include <vector>
#include <iosfwd>
#include <algorithm>

using namespace std;

struct Frac { // P/Q
    Integ p;
    Natural q;
    bool operator==(const Frac &other);
};

Frac RED_Q_Q(Frac a);

int INT_Q_B(Frac a);

Frac TRANS_Z_Q(Integ a);

Integ TRANS_Q_Z(Frac a);

Frac ADD_QQ_Q(Frac a, Frac b);

Frac ADD_QQ_Q(Frac a, Frac b);

Frac MUL_QQ_Q(Frac a, Frac b);

Frac DIV_QQ_Q(Frac a, Frac b);

#endif //DM_COMPUTER_ALGEBRA_FRAC_H
