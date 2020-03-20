#ifndef DM_COMPUTER_ALGEBRA_TEST_H_N
#define DM_COMPUTER_ALGEBRA_TEST_H_N

#include <vector>
#include <iosfwd>
#include <algorithm>
#include <iostream>

using namespace std;

struct Natural {
    int n;
    vector<int> dig;

    bool operator==(const Natural &other);
};

int COM_NN_D(Natural a, Natural b);
//Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.

int NZER_N_B(Natural a);
//Проверка на ноль: если число не равно нулю, то «да» иначе «нет»

Natural ADD_1N_N(Natural a);
//Добавление 1 к натуральному числу

Natural ADD_NN_N(Natural a, Natural b);
//@COM_NN_D
//Сложение натуральных чисел

Natural SUB_NN_N(Natural a, Natural b);
//@COM_NN_D
//Вычитание из первого большего натурального числа второго меньшего или равного

Natural MUL_ND_N(Natural a, int n);
//Умножение натурального числа на цифру

Natural MUL_Nk_N(Natural a, int k);
//Умножение натурального числа на 10^k

Natural MUL_NN_N(Natural a, Natural b);
//@MUL_ND_Nm @MUL_Nk_N, @ADD_NN_N
//Умножение натуральных чисел

Natural SUB_NDN_N(Natural a, Natural b, int n);
//@SUB_NN_N, @MUL_ND_N, @CON_NN_D
//Вычитание из натурального другого натурального, умноженного на
// цифру для случая с неотрицательным результатом

int DIV_NN_Dk(Natural a, Natural b);
//@MUL_Nk_N, @COM_NN_D
//Вычисление первой цифры деления большего натурального на меньшее,
// домноженное на 10^k,где k - номер позиции этой цифры  (номер считается с нуля)

Natural DIV_NN_N(Natural a, Natural b);
//@DIV__NN_Dk, @SUB_NDN_N
//Частное от деления большего натурального числа на меньшее или равное 
// натуральное с остатком(делитель отличен от нуля)

Natural MOD_NN_N(Natural a, Natural b);
//@DIV_NN, @SUB_NDN_N
//Остаток от деления большего натурального числа на меньшее или равное натуральное
// с остатком(делитель отличен от нуля)

Natural GCF_NN_N(Natural a, Natural b);
//@MOD_NN_N, @COM__NN_D, @NZER_N_B
//НОД натуральных чисел

Natural LCM_NN_N(Natural a, Natural b);
//@GCF_NN_N, @MUL_NN_N
//НОК натуральных чисел

#endif //DM_COMPUTER_ALGEBRA_BTEST_H