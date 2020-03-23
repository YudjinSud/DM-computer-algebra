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
    Frac(int P, int Q)
    {
       Integ up(P);
       Natural down(Q);
       this->p = up;
       this->q = down;
    }
    Frac (string P, string Q)
    {
        Integ up(P);
        Natural down(Q);
        this->p = up;
        this->q = down;
    }
    Frac (string a)
    {
        vector <char> up, down;
        //string up, down;
        int i = 0;
        while ((a[i] != '/')&&(i<a.size()))
        {
                up.push_back(a[i]);
                i++;
                if (a[i] == '/')
                {
                    i++;
                    while (i<a.size())
                    {
                        down.push_back(a[i]);
                        i++;
                    }
                }
        }
        Integ bla(up);
        this->p = bla;
        if (!down.size())
        {
            Natural la;
            this->q = la;
        } else
        {
            Natural la (down);
            this->q = la;
        }
    }
};

void print_frac(Frac a);

Frac RED_Q_Q(Frac a);

int INT_Q_B(Frac a);

Frac TRANS_Z_Q(Integ a);

Integ TRANS_Q_Z(Frac a);

Frac ADD_QQ_Q(Frac a, Frac b);

Frac SUB_QQ_Q(Frac a, Frac b);

Frac MUL_QQ_Q(Frac a, Frac b);

Frac DIV_QQ_Q(Frac a, Frac b);

#endif //DM_COMPUTER_ALGEBRA_FRAC_H