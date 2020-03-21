//
// Created by xtkcb on 19-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_INTEG_H
#define DM_COMPUTER_ALGEBRA_INTEG_H

#include <vector>
#include <iosfwd>
#include <algorithm>

using namespace std;

struct Integ {
    int b;
    int n;
    vector<int> dig;

    bool operator==(const Integ &other);
};


Integ ABS_Z_N(Integ a);
//Абсолютная величина числа, результат - натуральное

int POZ_Z_D(Integ a);
//Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)

Integ MUL_ZM_Z(Integ a);
//Умножение целого на (-1)

Integ TRANS_N_Z(Natural a);
//Преобразование натурального в целое

Natural TRANS_Z_N(Integ a);
//Преобразование целого неотрицательного в натуральное

Integ ADD_ZZ_Z(Integ a, Integ b);
//Сложение целых чисел

Integ SUB_ZZ_Z(Integ a, Integ b);
//Вычитание целых чисел

Integ MUL_ZZ_Z(Integ a, Integ b);
//Вычитание целых чисел

Integ DIV_ZZ_Z(Integ a, Natural b);
//Частное от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)

Integ MOD_ZZ_Z(Integ a, Natural b);
//Частное от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)

#endif //DM_COMPUTER_ALGEBRA_INTEG_H
