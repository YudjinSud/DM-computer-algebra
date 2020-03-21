//
// Created by xtkcb on 21-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_POLY_H
#define DM_COMPUTER_ALGEBRA_POLY_H


#include <vector>
#include <iosfwd>
#include <algorithm>
#include "Frac.h"
#include "Integ.h"
#include "Natural.h"

using namespace std;

struct Poly { // P/Q
    int m; // max степень в полиноме
    vector<Frac> C; // массив коэффициентов


    Poly() {
        Frac bla;
        this->C.push_back(bla);
        this->m = 1;
    }

    bool operator==(const Poly &other) {
        int k = 0;
        for (int i = 0; i < m; i++) {
            if (this->C[i] == other.C[i])
                k++;
        }
        return ((this->m == other.m) && (k == m));
    }

    ~Poly() {
        C.clear();
    }
};


Poly ADD_PP_P(Poly a, Poly b); // P-1 сложение многочленов

Poly SUB_PP_P(Poly a, Poly b); // P-2 вычитание многочленов

Poly MUL_PQ_P(Poly a, Frac r); // P-3 умножение многочлена на рациональное число

Poly MUL_Pxk_P(Poly a, int k); // P-4 умножение многочлена на x^k

Frac LED_P_Q(Poly a); // P-5 возвращает старший коэффициент многочлена

int DEG_P_N(Poly a); // P-6 возвращает степень многочлена

Poly FAC_P_Q(Poly a); // P-7 Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей

Poly MUL_PP_P(Poly a, Poly b); // P-8 перемножение многочленов

Poly DIV_PP_P(Poly a, Poly b); // P-9 Частное от деления многочлена на многочлен при делении с остатком

Poly MOD_PP_P(Poly a, Poly b); // P-10 Остаток от деления многочлена на многочлен при делении с остатком

Poly GCF_PP_P(Poly a, Poly b); // P-11 НОД многочленов

Poly DER_P_P(Poly a); // P-12 Производная многочлена

Poly NMR_P_P(Poly a); // P-13 Преобразование многочлена — кратные корни в простые

#endif //DM_COMPUTER_ALGEBRA_POLY_H
