//
// Created by xtkcb on 22-Mar-20.
//

#include <cassert>
#include "Manipulator.h"

write_Poly::write_Poly(Poly poly) : poly_(poly) {

}

std::ostream &write_Poly::write(std::ostream &os) const {
    for (int i = poly_.m; i >= 0; i--){
        os << write_Frac(poly_.C[i]) ;
        if(i != 0) os << " x^"<<i << " + ";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, write_Poly WP) {
    assert(os);
    return WP.write(os);
}

//-----------------------

write_Frac::write_Frac(Frac frac) : frac_(frac) {

}

std::ostream &write_Frac::write(std::ostream &os) const {
    os << '(' << write_Integ(frac_.p) << ")/(" << write_Nat(frac_.q) << ')';
    return os;
}

std::ostream &operator<<(std::ostream &os, write_Frac WF) {
    assert(os);
    return WF.write(os);
}

//-----------------------

write_Integ::write_Integ(Integ integ) : integ_(integ) {

}

std::ostream &write_Integ::write(std::ostream &os) const {
    if (integ_.b == 1) os << '-';
    for (int i = 0; i < integ_.n; i++) os << integ_.dig[i];
    return os;
}

std::ostream &operator<<(std::ostream &os, write_Integ WI) {
    assert(os);
    return WI.write(os);
}

//-----------------------


write_Nat::write_Nat(Natural nat) : nat_(nat) {

}

std::ostream &write_Nat::write(std::ostream &os) const {
    for (int i = 0; i < nat_.n; i++) os << nat_.dig[i];
    return os;
}

std::ostream &operator<<(std::ostream &os, write_Nat WN) {
    assert(os);
    return WN.write(os);
}