//
// Created by xtkcb on 22-Mar-20.
//

#ifndef DM_COMPUTER_ALGEBRA_MANIPULATOR_H
#define DM_COMPUTER_ALGEBRA_MANIPULATOR_H

#include <fstream>
#include <string>
#include "Poly.h"

class write_Poly final {
public:
    explicit write_Poly(Poly poly);

    std::ostream &write(std::ostream &os) const;

private:
    Poly poly_;

};


std::ostream &operator<<(std::ostream &os, write_Poly WP);

class read_Poly final {
public:
    explicit read_Poly(Poly &poly);

    std::istream &read(std::istream &is);

private:
    Poly *poly_;

};

std::istream &operator>>(std::istream &is, read_Poly RP);

class write_Frac final {
public:
    explicit write_Frac(Frac frac);

    std::ostream &write(std::ostream &os) const;

private:
    Frac frac_;

};


std::ostream &operator<<(std::ostream &os, write_Frac WF);

class read_Frac final {
public:
    explicit read_Frac(Frac &frac);

    std::istream &read(std::istream &is);

private:
    Frac *frac_;

};

std::istream &operator>>(std::istream &is, read_Frac RF);

class write_Integ final {
public:
    explicit write_Integ(Integ integ);

    std::ostream &write(std::ostream &os) const;

private:
    Integ integ_;

};

std::ostream &operator<<(std::ostream &os, write_Integ WI);

class read_Integ final {
public:
    explicit read_Integ(Integ &integ);

    std::istream &read(std::istream &is);

private:
    Integ *integ_;

};

std::istream &operator>>(std::istream &is, read_Integ RI);

class write_Nat final {
public:
    explicit write_Nat(Natural nat);

    std::ostream &write(std::ostream &os) const;

private:
    Natural nat_;

};

std::ostream &operator<<(std::ostream &os, write_Nat WN);

class read_Nat final {
public:
    explicit read_Nat(Natural &nat);

    std::istream &read(std::istream &is);

private:
    Natural *nat_;

};

std::istream &operator>>(std::istream &is, read_Nat RN);


#endif //DM_COMPUTER_ALGEBRA_MANIPULATOR_H