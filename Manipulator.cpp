//
// Created by xtkcb on 22-Mar-20.
//

#include "Manipulator.h"

write_Poly::write_Poly(Poly poly) : poly_(poly) {

}

std::ostream &write_Poly::write(std::ostream &os) const {
    for (int i = poly_.m; i >= 0; i--) {
        os << write_Frac(poly_.C[i]);
        if (i != 0) os << "x^" << i << " + ";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, write_Poly WP) {
    assert(os);
    return WP.write(os);
}

read_Poly::read_Poly(Poly &poly) : poly_(&poly) {

}

std::istream &read_Poly::read(std::istream &is) {
    char c;
    Frac f;
    is >> read_Frac(f);
    poly_->C.pop_back();
    poly_->C.push_back(f);
    poly_->m = 0;
    is >> c >> c;
    int i = 0;
    is >> c;
    if (c == '0') return is;
    while (c >= '0' && c <= '9') {
        i *= 10;
        i += int(c) - int('0');
        is >> c;
    }
    is >> c;
    for (; i > 0; i--) {
        is >> c;
        is >> read_Frac(f);
        poly_->C.push_back(f);
        if (i != 1)
            while (c != '+')
                is >> c;
    }
    reverse(begin(poly_->C), end(poly_->C));
    poly_->m = int(poly_->C.size()) - 1;
    return is;
}

std::istream &operator>>(std::istream &is, read_Poly RP) {
    assert(is);
    is.unsetf(ios_base::skipws);
    return RP.read(is);
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

read_Frac::read_Frac(Frac &frac) : frac_(&frac) {

}

std::istream &read_Frac::read(std::istream &is) {
    char c;
    is >> c;
    Integ p;
    is >> read_Integ(p);
    frac_->p = p;
    is >> c >> c;
    Natural q;
    is >> read_Nat(q);
    frac_->q = q;
    return is;
}

std::istream &operator>>(std::istream &is, read_Frac RF) {
    assert(is);
    return RF.read(is);
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

read_Integ::read_Integ(Integ &integ) : integ_(&integ) {

}

std::istream &read_Integ::read(std::istream &is) {
    char c;
    is >> c;
    integ_->b = 0;
    if (c == '-') {
        integ_->b = 1;
        is >> c;
    }
    while (c >= '0' && c <= '9') {
        integ_->dig.push_back(int(c) - int('0'));
        is >> c;
    }
    integ_->n = int(integ_->dig.size());
    return is;
}

std::istream &operator>>(std::istream &is, read_Integ RI) {
    assert(is);
    return RI.read(is);
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

//----
read_Nat::read_Nat(Natural &nat) : nat_(&nat) {

}

std::istream &read_Nat::read(std::istream &is) {
    char c;
    is >> c;
    while (c >= '0' && c <= '9') {
        nat_->dig.push_back(int(c) - int('0'));
        is >> c;
    }
    nat_->n = int(nat_->dig.size());
    reverse(begin(nat_->dig), end(nat_->dig));
    while (nat_->dig[nat_->dig.size() - 1] == 0) nat_->dig.pop_back();
    nat_->n = int(nat_->dig.size());
    if (nat_->n == 0) {
        nat_->n = 1;
        nat_->dig.push_back(0);
    }
    reverse(begin(nat_->dig), end(nat_->dig));
    return is;
}

std::istream &operator>>(std::istream &is, read_Nat RN) {
    assert(is);
    return RN.read(is);
}

