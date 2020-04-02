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


QString BackendIOWrapper::calculateNatural(const QString &input1, const QString &input2, const QString &integ,  const QString &id) {

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
        resNat = SUB_NN_N(a, b);
        res = NaturalToQString(resNat);
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
    qDebug() << res;

    return res;

}


QString IntegToQString(Integ a) {
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << write_Integ(a);
    ss >> std_s;
    QS = QString::fromStdString(std_s);

    return QS;
}


QString BackendIOWrapper::calculateInteger(const QString &input1, const QString &input2, const QString &integ,  const QString &id) {
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
   // если считать сначала две дроби, а потом целое - то целое будет 0 :)) минус полчаса)) - грустно звучит( а ещё очень больно...
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
    ss >> std_s;
    QS = QString::fromStdString(std_s);

    return QS;
}

QString intToQString(int a) {
    std::stringstream ss;
    QString QS;
    std::string std_s;
    ss << a;
    ss >> std_s;
    QS = QString::fromStdString(std_s);

    return QS;
}

QString BackendIOWrapper::calculatePoly(const QString &input1, const QString &input2, const QString &integ, const QString &frac,  const QString &id) {
    std::stringstream s_0;
    std::stringstream ss_for_int;
    std::stringstream ss_for_fracs;
    //custom string stream to read prettified input of polynomials etc

    string s1 = input1.toStdString();
    string s2 = input2.toStdString();
    string str_fraction = frac.toStdString();

    string integer = integ.toStdString();
    //in algo's where integer needed. Else  - 0
    int k = stoi(integer);

    s1.push_back('.');
    s2.push_back('.');

    qDebug() << "Derived integer :" << k;

    Poly a, b;
    Integ I;
    Frac f;
    s_0 << s1;
    s_0 >> read_Poly(a);
    s_0 << s2;
    s_0 >> read_Poly(b);
    ss_for_fracs << str_fraction;
    ss_for_fracs >> read_Frac(f);

    QString res = "";
    int int32_id = stoi(id.toStdString());

    switch(int32_id) {
    case 1 : {
        res = PolyToQString(ADD_PP_P(a, b));
    }
    case 2 : {
        res = PolyToQString(SUB_PP_P(a, b));
    }
    case 3 : {
        res = PolyToQString(MUL_PQ_P(a, f));
    }
    case 4 : {
        res = PolyToQString(MUL_Pxk_P(a, k));
    }
    case 5 : { // Тут дроби, мой мозг пока ничего не додумал для них
        res = FractionToQString(LED_P_Q(a));
    }
    case 6 : {
        res = intToQString(DEG_P_N(a));
    }
    case 7 : {
        res = PolyToQString(FAC_P_Q(a));
    }
    case 8 : {
        res = PolyToQString(MUL_PP_P(a, b));
    }
    case 9 : {
        res = PolyToQString(DIV_PP_P(a, b));
    }
    case 10: {
        res = PolyToQString(MOD_PP_P(a, b));
    }
    case 11: {
        res = PolyToQString(GCF_PP_P(a, b));
    }
    case 12: {
        res = PolyToQString(DER_P_P(a));
    }
    case 13: {
        res = PolyToQString(NMR_P_P(a));
    }
    }
    qDebug() << res;
    return res;
}


