#include "BackendIOWrapper.h"


BackendIOWrapper::BackendIOWrapper(QObject *parent) :
    QObject(parent)
{
    ;
}

QString BackendIOWrapper::input1()
{
    return m_input1;
}

QString BackendIOWrapper::input2()
{
    return m_input2;
}

QString BackendIOWrapper::input3()
{
    return m_input3;
}

void BackendIOWrapper::setInput1(const QString &input)
{
    if (input == m_input1)
        return;


    m_input1 = input;
    emit input1Changed();
}


void BackendIOWrapper::setInput2(const QString &input)
{
    if (input == m_input2)
        return;


    m_input2 = input;
    emit input2Changed();
}


void BackendIOWrapper::setInput3(const QString &input)
{
    if (input == m_input3)
        return;


    m_input3 = input;
    emit input3Changed();
}

vector<int> QStringTOVectorInt(const QString s) {
    vector<int> vec;
    QByteArray byteArray = s.toLocal8Bit();
    for (int i = 0; i < byteArray.size(); i++) {
        int asciiCode = (int)byteArray[i];
        vec.push_back(asciiCode);
    }
    return vec;

}


QString NaturalToQString(Natural a) {
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << write_Nat(a);
    ss >> std_s;
    QS = QString::fromStdString(std_s);

    return QS;
}


//a - натуральное число номер 1
//b - натуральное число номер 2
//s1 - строка, которкую ввел пользователь в окошко
//s2 - аналогично
//id - номер програмым от 1 до 14 в случае натуральных чисел
//для случая с интом  - id n 1 до 9
//для случая с дробями - 1 - 8
// полиномы - 1 -  13
// k - число, см. N-6 и другие


int checkInputNaturalByString(string s1, string s2) {
    for (size_t i = 0; i < s1.size(); i++)
    {
        if ((((s1[i]  - '0' >= 10) || (s1[i] - '0' < 0))&&(s1[i] != ' ') && (s1[i] != ')') && (s1[1] != '(')))
            return 0;
    }
    for (size_t i = 0; i < s2.size(); i++)
    {
        if (((s2[i] - '0' >= 10) || (s2[i] - '0' < 0)) && (s1[i] != ' ') && (s1[i] != ')') && (s1[1] != '('))
            return 0;
    }
    if (s1[0] == '-' || s2[0] == '-') return 0;
    return 1;
}



int checkInputNaturals(Natural a, Natural b, int k,int id) {
    switch (id) {
    case 5:
        if (COM_NN_D(a, b) == 1) return 0;
        break;
    case 6:
        if (k < 0) return 0;
        break;
    case 7:
        if (k < 0) return 0;
        break;
    case 9:
        if (COM_NN_D(a, MUL_ND_N(b, k)) == 1) return 0;
        break;
    case 10:
        if (COM_NN_D(a, b) == 1) return 0;
        break;
    case 11:
        if ((COM_NN_D(a, b) == 1)||(NZER_N_B(b))) return 0;
        break;
    case 12:
        if ((COM_NN_D(a, b) == 1)||(NZER_N_B(b))) return 0;
        break;
    }
    return 1;
}

QString BackendIOWrapper::calculateNatural (const QString &input1, const QString &input2, const QString &integ,  const QString &id) {
    std::stringstream s_0;
    //custom string stream to read prettified input of polynomials etc

    string s1 = input1.toStdString();
    string s2 = input2.toStdString();

    string integer = integ.toStdString();
    //in algo's where integer needed. Else  - 0
    int k = stoi(integer);


    qDebug() << "String 1 : " << QString::fromStdString(s1);
    qDebug() << "String 2 : " << QString::fromStdString(s2);
    qDebug() << "Derived integer :" << k;

    Natural a, b, resNat;

    int checkToManip = checkInputNaturalByString(s1, s2);

    qDebug() << "Natural string test:: " << checkToManip;

    if(checkToManip) {
        //перед тем, как засылать в манипулятор, нужно проверить просто строки.
        //Например, если это хотя бы число. isnumeric() тоже неплохая фукнция для этого
        // Короче - техническая проверка ввода
        s1.push_back('.');
        s2.push_back('.');
        s_0 << s1;
        s_0 >> read_Nat(a);
        s_0 << s2;
        s_0 >> read_Nat(b);
    }
    else {
        return "Неправильный ввод\n";
    }

    //   qDebug() << "integer : " << QString::fromStdString(k);

    qDebug() << "Natural 1 : " << NaturalToQString(a);
    qDebug() << "Natural 2 : " << NaturalToQString(b);


    QString res = "";

    int int32_id = stoi(id.toStdString());

    int check = checkInputNaturals(a, b, k, int32_id);

    qDebug() << "Naturals switch tests :: " << check;

    //проверки на логику. Техническая правильность ввода уже не проверяется.

    if(check) {
        switch(int32_id) {
        case 1 : {
            res = QString::number(COM_NN_D(a, b));
            break;
        }
        case 2: {
            res = NZER_N_B(a) == 0 ? "Да" : "Нет" ;
            break;
        }
        case 3: {
            resNat = ADD_1N_N(a);
            res = NaturalToQString(resNat);
            break;
        }
        case 4: {
            resNat = ADD_NN_N(a, b);
            res = NaturalToQString(resNat);
            break;
        }
        case 5: {
            if(check) {
                resNat = SUB_NN_N(a, b);
                res = NaturalToQString(resNat);
            }
            break;
        }
        case 6: {
            resNat = MUL_ND_N(a, k);
            res = NaturalToQString(resNat);
            break;
        }
        case 7: {
            resNat = MUL_Nk_N(a, k);
            res = NaturalToQString(resNat);
            break;
        }
        case 8: {
            resNat = MUL_NN_N(a, b);
            res = NaturalToQString(resNat);
            break;
        }
        case 9: {
            resNat = SUB_NDN_N(a, b, k);
            res = NaturalToQString(resNat);
            break;
        }
        case 10: {
            res = QString::number(DIV_NN_Dk(a, b));
            break;
        }
        case 11: {
            resNat = DIV_NN_N(a, b);
            res = NaturalToQString(resNat);
            break;
        }
        case 12: {
            resNat = MOD_NN_N(a, b);
            res = NaturalToQString(resNat);
            break;
        }
        case 13: {
            resNat = GCF_NN_N(a, b);
            res = NaturalToQString(resNat);
            break;
        }
        case 14: {
            resNat = LCM_NN_N(a, b);
            res = NaturalToQString(resNat);
            break;
        }
        }
    }
    qDebug() << res;
    if(check  == 0) {
        res = "Неправильнынй ввод!\n";
    }
    return res;

}


QString IntegToQString(Integ a){
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << write_Integ(a);
    ss >> std_s;
    QS = QString::fromStdString(std_s);

    return QS;
}



int checkInputIntegerToManip(string s1, string s2) {
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (((s1[i] - '0' >= 10) || (s1[i] - '0' < 0))&&(s1[i] != ' ')&&(s1[i] != '-') && (s1[i] != ')') && (s1[1] != '('))
            return 0;
    }
    for (size_t i = 0; i < s2.size(); i++)
    {
        if (((s2[i]  - '0' >= 10) || (s2[i] - '0' < 0)) && (s1[i] != ' ') && (s2[i] != '-') && (s1[i] != ')') && (s1[1] != '('))
            return 0;
    }
    return 1;
}


int checkInputInteger(Integ a, Integ b, int id) {

    switch (id) {
    // Z-5
    case 5:
        if (a.b) return 0;
        break;
    case 9:
        if((b.dig[0] == 0)||(COM_NN_D(TRANS_Z_N(ABS_Z_N(a)), TRANS_Z_N(ABS_Z_N(b)))) != 1) return 0;
        break;
    case 10:
        if((b.dig[0] == 0)||(COM_NN_D(TRANS_Z_N(ABS_Z_N(a)), TRANS_Z_N(ABS_Z_N(b)))) != 1) return 0;
        break;
    }
    return 1;
}


QString BackendIOWrapper::calculateInteger (const QString &input1, const QString &input2, const QString &integ,  const QString &id) {
    std::stringstream s_0;
    //custom string stream to read prettified input of polynomials etc

    string s1 = input1.toStdString();
    string s2 = input2.toStdString();

    string integer = integ.toStdString();
    //in algo's where integer needed. Else  - 0
    int k = stoi(integer);

    qDebug() << "Derived integer :" << k;

    Integ a, b;
    Natural n;

    int checkToManip = checkInputIntegerToManip(s1, s2);

    qDebug() << "Iteger string tests :: " << checkToManip;

    if(checkToManip) {
        s1.push_back('.');
        s2.push_back('.');
        s_0 << s1;
        s_0 >> read_Integ(a);
        s_0 << s2;
        s_0 >> read_Integ(b);
    }
    else {
        return "Неправильный ввод\n";
    }
    QString res = "";

    qDebug() << "Integer 1 : " << IntegToQString(a) << "Sign :: " << a.b;
    qDebug() << "Integer 2 : " << IntegToQString(b) << "Sign :: " << b.b;

    int int32_id = stoi(id.toStdString());

    int check = checkInputInteger(a, b, int32_id);

    qDebug() << "Intger switch tests :: " << check;

    if(check) {
        switch(int32_id) {
        case 1 : {
            res = IntegToQString(ABS_Z_N(a));
            break;
        }
        case 2: {
            res = QString::number(POZ_Z_D(a));
            break;
        }
        case 3: {
            res = IntegToQString(MUL_ZM_Z(a));
            Integ tmp = MUL_ZM_Z(a);

            qDebug() << tmp.b;
            break;
        }
        case 4: {
            res = IntegToQString(TRANS_N_Z(n));
            break;
        }
        case 5: {
            res = NaturalToQString(TRANS_Z_N(a));
            break;
        }
        case 6: {
            res = IntegToQString(ADD_ZZ_Z(a, b));
            break;
        }
        case 7: {
            res = IntegToQString(SUB_ZZ_Z(a, b));
            break;
        }
        case 8: {
            res = IntegToQString(MUL_ZZ_Z(a, b));
            break;
        }
        case 9:
        {
            n = TRANS_Z_N(b);
            res = IntegToQString(DIV_ZZ_Z(a, n));
            break;
        }
        case 10: {
            n = TRANS_Z_N(b);
            res = IntegToQString(MOD_ZZ_Z(a, n));
            break;
        }
        }
        qDebug() << res;
    }
    if(check == 0) {
        res = "Неправильный ввод\n";
    }

    return res;
}


QString FractionToQString(Frac a) {
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << write_Frac(a);
    ss >> std_s;
    QS = QString::fromStdString(std_s);

    return QS;
}


int checkInputFracByString(string s) {

    stack<int> pars; // стек для проверки скобок

    for (size_t i = 0; i < s.size(); i++)
    {
        if(!((s[i] >= '0' && s[i] <= '9') || (s[i] == '/') || (s[i] == '(') || (s[i] == ')') || (s[i] == '-') || (s[i] == ' '))) {
            qDebug() << s[i];
            return 0;
        }
        if(s[i] == '(') {
            if (pars.empty() == false) {
                return 0;
            }
            pars.push(1);
        }
        else if(s[i] == ')') {
            if (pars.empty() == true) {
                return 0;
            }
            pars.pop();
        }
        if (s[i] == '/')
        {
            i++;
            if(s[i] == '(') {
                if (pars.empty() == false) {
                    return 0;
                }
                pars.push(1);
            }
            while ((s[i] == ' ') || (s[i] == '(')) {
                i++;
                if(s[i] == '(') {
                    if (pars.empty() == false) {
                        return 0;
                    }
                    pars.push(1);
                }
            }
            if (((s[i] == '-')||(s[i] == '0')) || !((s[i] >= '0' && s[i] <= '9') || (s[i] == '/') || (s[i] == '(') || (s[i] == ')') || (s[i] == '-') || (s[i] == ' ')))
                return 0;
        }
    }
    if (pars.empty() == false) {
        qDebug() << "from there 3";
        return 0;
    }
    return 1;
}


int checkInputFrac(Frac a, Frac b, int id) {
    switch (id) {
    case 4:
        if ((a.q.dig[0] != 1)||(a.q.dig.size()!=1)) return 0;
        break;
    case 8:
        if (b.p.dig[0] == 0) return 0;
        break;
    }
    return 1;
}



QString BackendIOWrapper::calculateFraction(const QString &frac1, const QString &frac2, const QString &integ,  const QString &id) {
    std::stringstream ss;
    //custom string stream to read prettified input of polynomials etc

    string str_fraction1 = frac1.toStdString();
    string str_fraction2 = frac2.toStdString();
    string str_integer = integ.toStdString();

    qDebug() << "frac 1 : " << QString::fromStdString(str_fraction1);
    qDebug() << "frac 2 : " << QString::fromStdString(str_fraction2);
    qDebug() << "integer : " << QString::fromStdString(str_integer);


    //in algo's where integer needed. Else  - 0

    str_integer.push_back('.');

    Frac a, b;
    Integ z;

    int checkFracStr1 = checkInputFracByString(str_fraction1);
    int checkFracStr2 = checkInputFracByString(str_fraction2);

    //(9)/(3)

    qDebug() << "Frack string tests :: " << ( int) (checkFracStr1 && checkFracStr2);

    if(checkFracStr1 && checkFracStr2) {
        ss << str_fraction1;
        ss >> read_Frac(a);
        ss << str_fraction2;
        ss >> read_Frac(b);
        ss << str_integer;
        ss >> read_Integ(z);
    } else {
        return "Неправильный ввод\n";
    }
    qDebug() << "f1 : " << FractionToQString(a);
    qDebug() << "f2 : " << FractionToQString(b);
    //    qDebug() << "integ : " << IntegToQString(z);


    QString res = "";

    int int32_id = stoi(id.toStdString());

    int check = checkInputFrac(a,b,int32_id);

    qDebug() << "Frack switch tests :: " << check;

    if(check) {
        switch(int32_id) {
        case 1 : {
            res = FractionToQString(RED_Q_Q(a));
            break;
        }
        case 2 : {
            res = INT_Q_B(a) == 1 ? "Да" : "Нет";
            break;
        }
        case 3 : {
            res = FractionToQString(TRANS_Z_Q(z));
            break;
        }
        case 4 : {
            res = IntegToQString(TRANS_Q_Z(a));
            break;
        }
        case 5 : {
            res = FractionToQString(ADD_QQ_Q(a, b));
            break;
        }
        case 6 : {
            res = FractionToQString(SUB_QQ_Q(a, b));
            break;
        }
        case 7 : {
            res = FractionToQString(MUL_QQ_Q(a, b));
            break;
        }
        case 8 : {
            res = FractionToQString(DIV_QQ_Q(a, b));
            break;
        }
        }
        qDebug() << res;
    }
    if(check == 0) {
        res = "Неправильный ввод!\n";
    }
    return res;
}

QString PolyToQString(Poly a) {
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << write_Poly(a);
    getline(ss, std_s);
    std_s.pop_back();
    std_s.pop_back();
    std_s.pop_back();
    QS = QString::fromStdString(std_s);

    return QS;
}


bool checkPolyByString(string s) {
    string s2;
    for (size_t _ = 0; _ < s.size(); _++) { //check na drobi

        while (_ < s.size() && s[_] != 'x') {
            s2.push_back(s[_]);
            _++;
        }
        //if (checkInputFracByString(s2) == 0) return false;
        while (_ < s.size() && s[_] != '(')
            _++;
        s2.clear();
        s2.push_back('(');
    }
    for (size_t _ = 0; _ < s.size(); _++) { //check na +, x, ^
        if (s[_] == '+') {
            if (_ == 0 || _ == s.size() - 1)return false;
            if (s[_ - 1] == s[_ + 1] && s[_ - 1] == ' ');
            else return false;
        }
        if (s[_] == 'x') {
            if (_ >= s.size() - 2)return false;
            if (s[_ + 1] != '^') return false;
        }
        if (s[_] == '^') {
            if(_ == 0 || s[_ - 1] != 'x') return false;
            _++;
            while (_ < s.size() && s[_] != ' ') {
                if (s[_] < '0' || s[_] > '9') return false;
                _++;
            }
        }
    }
    return true;
}


//Версия Вари(sinbar) - тоже рабочая!
//int checkInputPolyByString(string s1, string s2) {
//    //(100)/(1)x^1 + (1)/(1)x^0
//    int close = 0, open = 0, ixes = 0, pluses = 0, slesh = 0;
//    for (size_t i = 0; i < s1.size(); i++) {
//        if (s1[i] == '+')
//        {
//            pluses++;
//            if ((i < 1) || (i >= s1.size() - 1)) return 0;
//            if ((s1[i - 1] != ' ') || (s1[i + 1] != ' ')) return 0;
//        }
//        else if (s1[i] == ')') {
//            close++;
//            if (i == s1.size() - 1) return 0;
//            if ((s1[i + 1] != '/') && (s1[i + 1] != 'x')) return 0;
//        }
//        else if (s1[i] == '(') {
//            open++;
//            if (i) {
//                if (i > s1.size() - 5) return 0;
//                if ((s1[i - 1] != '/') && (s1[i - 1] != ' ')) return 0;
//            }
//        }
//        else if (s1[i] == 'x') {
//            ixes++;
//            if ((i < 1) || (i >= s1.size() - 1)) return 0;
//            if ((s1[i + 1] != '^') || (s1[i - 1] != ')')) return 0;
//        }
//        else if (s1[i] == '/') {
//            slesh++;
//            if ((i < 1) || (i > s1.size() - 6)) return 0;
//            if ((s1[i - 1] != ')') || (s1[i + 1] != '(') || (s1[i + 2] == '-') || (s1[i + 2] == '0')) return 0;
//        }
//        else if (((s1[i] > 57) || (s1[i] < 48))&&(s1[i] != '^')&&(s1[i] != ' ')&&(s1[i] != '-')) return 0;
//    }
//    if (open != close) return 0;
//    if (!open % 2) return 0;
//    if ((ixes != slesh) || (ixes != open / 2)) return 0;
//    if (pluses != ixes - 1) return 0;

//    close = 0;
//    open = 0;
//    ixes = 0;
//    pluses = 0;
//    slesh = 0;

//    for (size_t i = 0; i < s2.size(); i++) {
//        if (s2[i] == '+') {
//            pluses++;
//            if ((i < 1) || (i >= s2.size() - 1)) return 0;
//            if ((s2[i - 1] != ' ') || (s2[i + 1] != ' ')) return 0;
//        } else if (s2[i] == ')') {
//            close++;
//            if (i == s2.size() - 1) return 0;
//            if ((s2[i + 1] != '/') && (s2[i + 1] != 'x')) return 0;
//        } else if (s2[i] == '(') {
//            open++;
//            if (i) {
//                if (i > s2.size() - 5) return 0;
//                if ((s2[i - 1] != '/') && (s2[i - 1] != ' ')) return 0;
//            }
//        } else if (s2[i] == 'x') {
//            ixes++;
//            if ((i < 1) || (i >= s2.size() - 1)) return 0;
//            if ((s2[i + 1] != '^') || (s2[i - 1] != ')')) return 0;
//        } else if (s2[i] == '/') {
//            slesh++;
//            if ((i < 1) || (i > s2.size() - 6)) return 0;
//            if ((s2[i - 1] != ')') || (s2[i + 1] != '(') || (s2[i + 2] == '-') || (s2[i + 2] == '0')) return 0;
//        } else if (((s2[i] > 57) || (s2[i] < 48))&&(s2[i] != '^')&&(s2[i] != ' ')&&(s2[i] != '-')) return 0;
//    }
//    if (open != close) return 0;
//    if (!open % 2) return 0;
//    if ((ixes != slesh) || (ixes != open / 2)) return 0;
//    if (pluses != ixes - 1) return 0;

//    return 1;
//}


int checkInputPoly(Poly a, Poly b, int k, int id) {
switch (id) {
        case 4:
            if (k < 0) return 0;
            break;
        case 9:
            if ((b.C[0].p.dig[0] == 0)&&(b.C.size() == 1)) return 0;
            break;
        case 10:
            if ((b.C[0].p.dig[0] == 0)&&(b.C.size() == 1)) return 0;
            break;
        case 11:
            if (((a.C[0].p.dig[0] == 0)&&(a.C.size() == 1))||((b.C[0].p.dig[0] == 0)&&(b.C.size() == 1))) return 0;
            break;
    }
    return 1;
}

QString BackendIOWrapper::calculatePoly(const QString &input1, const QString &input2, const QString &integ, const QString &frac,  const QString &id) {
    std::stringstream s_0;
    //custom string stream to read prettified input of polynomials etc

    string s1 = input1.toStdString();
    string s2 = input2.toStdString();
    string str_fraction = frac.toStdString();
    string integer = integ.toStdString();

    //in algo's where integer needed. Else  - 0

    //(-97)/(1)x^1 + (56)/(1)x^0

    int k = stoi(integer);


    qDebug() << "poly 1 : " << QString::fromStdString(s1);
    qDebug() << "poly 2 : " << QString::fromStdString(s2);
    qDebug() << "fraction : " << QString::fromStdString(str_fraction);
    qDebug() << "integer :: " << k;
    Poly a, b;
    Frac f;

    string tmp;


    s1.push_back('x');
    s1.push_back('^');
    s1.push_back('0');

    s2.push_back('x');
    s2.push_back('^');
    s2.push_back('0');



    int checkPolyString1 = checkPolyByString(s1);
    int checkPolyString2 = checkPolyByString(s2);

    qDebug() << "Poly string tests ::" << int (checkPolyString1 && checkPolyString2);


    if(checkPolyString1 && checkPolyString2) {
        s_0 << s1;
        s_0 >> read_Poly(a);
        s_0 << s2;
        s_0 >> read_Poly(b);
        s_0 << str_fraction;
        s_0 >> read_Frac(f);
    }
    else {
        return "Неправильный ввод!\n";
    }

    qDebug() << "p1 : " << PolyToQString(a);
    qDebug() << "p2 : " << PolyToQString(b);
    qDebug() << "frac: " << FractionToQString(f);
    qDebug() << "integer: " << k;

    QString res = "";
    int int32_id = stoi(id.toStdString());

    //(100)/(1)x^1 + (1)/(1)
    // (1)/(1)x^100 + (1)/(1)



    int check = checkInputPoly(a, b, k, int32_id);

    qDebug() << "Poly switch tests ::" << check;

    if(check) {
        switch(int32_id) {
        case 1 : {
            res = PolyToQString(ADD_PP_P(a, b));
            break;
        }
        case 2 : {
            res = PolyToQString(SUB_PP_P(a, b));
            break;
        }
        case 3 : {
            res = PolyToQString(MUL_PQ_P(a, f));
            break;
        }
        case 4 : {
            res = PolyToQString(MUL_Pxk_P(a, k));
            break;
        }
        case 5 : {
            res = FractionToQString(LED_P_Q(a));
            break;
        }
        case 6 : {
            res = QString::number(DEG_P_N(a));
            break;
        }
        case 7 : {
            res = PolyToQString(FAC_P_Q(a));
            break;
        }
        case 8 : {
            res = PolyToQString(MUL_PP_P(a, b));
            break;
        }
        case 9 : {
            res = PolyToQString(DIV_PP_P(a, b));
            break;
        }
        case 10: {
            res = PolyToQString(MOD_PP_P(a, b));
            break;
        }
        case 11: {
            res = PolyToQString(GCF_PP_P(a, b));
            // если степень второго = 0, ответ (0)
            break;
        }
        case 12: {
            res = PolyToQString(DER_P_P(a));
            break;
        }
        case 13: {
            res = PolyToQString(NMR_P_P(a));
            break;
        }
        }
    }
    else {
        return "Неправильный ввод!\n";
    }
    qDebug() << res;
    return res;
}


