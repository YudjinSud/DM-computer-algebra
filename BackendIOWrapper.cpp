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
int checkInputNaturals(Natural a, Natural b, int k, string s1, string s2, int id) {

    if (s1[0] == '-' ||  s2[0] == '-') return 0;
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
            if ((COM_NN_D(a, b) == 1 || NZER_N_B(b))) return 0;
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

    s1.push_back('.');
    s2.push_back('.');

    qDebug() << "Derived integer :" << k;

    Natural a, b, resNat;
    s_0 << s1;
    s_0 >> read_Nat(a);
    s_0 << s2;
    s_0 >> read_Nat(b);

    QString res = "";

    int int32_id = stoi(id.toStdString());
    int check = checkInputNaturals(a, b, k, s1, s2, int32_id);

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


QString BackendIOWrapper::calculateInteger (const QString &input1, const QString &input2, const QString &integ,  const QString &id) {
    std::stringstream s_0;
    //custom string stream to read prettified input of polynomials etc

    string s1 = input1.toStdString();
    string s2 = input2.toStdString();

    string integer = integ.toStdString();
    //in algo's where integer needed. Else  - 0
    int k = stoi(integer);

    s1.push_back('.');
    s2.push_back('.');

    qDebug() << "Derived integer :" << k;

    Integ a, b;
    Natural n;
    s_0 << s1;
    s_0 >> read_Integ(a);
    s_0 << s2;
    s_0 >> read_Integ(b);

    QString res = "";

    int int32_id = stoi(id.toStdString());

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


QString BackendIOWrapper::calculateFraction(const QString &frac1, const QString &frac2, const QString &integ,  const QString &id) {
    std::stringstream ss_for_fracs;
    std::stringstream ss_for_int;
    //custom string stream to read prettified input of polynomials etc

    string str_fraction1 = frac1.toStdString();
    string str_fraction2 = frac2.toStdString();
    string str_integer = integ.toStdString();

    qDebug() << "frac 1 : " << QString::fromStdString(str_fraction1);
    qDebug() << "frac 2 : " << QString::fromStdString(str_fraction2);
    qDebug() << "integer : " << QString::fromStdString(str_integer);

    //in algo's where integer needed. Else  - 0
 //   str_fraction1.push_back('.');
  //  str_fraction2.push_back('.');

    str_integer.push_back('.');

    Frac a, b;
    Integ z;


    ss_for_int << str_integer;
    ss_for_int >> read_Integ(z);
    ss_for_fracs << str_fraction1;
    ss_for_fracs >> read_Frac(a);
    ss_for_fracs << str_fraction2;
    ss_for_fracs >> read_Frac(b);

    qDebug() << "f1 : " << FractionToQString(a);
    qDebug() << "f2 : " << FractionToQString(b);
    qDebug() << "integ : " << IntegToQString(z);


    QString res = "";

    int int32_id = stoi(id.toStdString());

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

    return res;
}

QString PolyToQString(Poly a) {
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << write_Poly(a);
    getline(ss, std_s);
    QS = QString::fromStdString(std_s);

    return QS;
}


QString BackendIOWrapper::calculatePoly(const QString &input1, const QString &input2, const QString &integ, const QString &frac,  const QString &id) {
    std::stringstream s_0;
    //custom string stream to read prettified input of polynomials etc

    string s1 = input1.toStdString();
    string s2 = input2.toStdString();
    string str_fraction = frac.toStdString();
    string integer = integ.toStdString();

    //in algo's where integer needed. Else  - 0

    //(-97)/(1)x^1 + (56)/(1)

    qDebug() << "poly 1 : " << QString::fromStdString(s1);
    qDebug() << "poly 2 : " << QString::fromStdString(s2);
    qDebug() << "fraction : " << QString::fromStdString(str_fraction);
    qDebug() << "integer :: " << QString::fromStdString(integer);
    integer.push_back('.');
    Poly a, b;
    Integ i;
    Frac f;

    string tmp;


    s_0 << s1;
    s_0 >> read_Poly(a);
    s_0 << s2;
    s_0 >> read_Poly(b);
    s_0 << str_fraction;
    s_0 >> read_Frac(f);
    s_0 << integer;
    s_0 >> read_Integ(i);

    qDebug() << "p1 : " << PolyToQString(a);
    qDebug() << "p2 : " << PolyToQString(b);
    qDebug() << "frac: " << FractionToQString(f);
    qDebug() << "integer: " << IntegToQString(i);

    QString res = "";
    int int32_id = stoi(id.toStdString());

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
    //    res = PolyToQString(MUL_Pxk_P(a, k));
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
    qDebug() << res;
    return res;
}

