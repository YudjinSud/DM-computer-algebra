#include "NaturalBackendWrapper.h"


NaturalBackendWrapper::NaturalBackendWrapper(QObject *parent) :
    QObject(parent)
{
    ;
}

QString NaturalBackendWrapper::input1()
{
    return m_input1;
}

QString NaturalBackendWrapper::input2()
{
    return m_input2;
}

QString NaturalBackendWrapper::input3()
{
    return m_input3;
}

void NaturalBackendWrapper::setInput1(const QString &input)
{
    if (input == m_input1)
        return;


    m_input1 = input;
    emit input1Changed();
}


void NaturalBackendWrapper::setInput2(const QString &input)
{
    if (input == m_input2)
        return;


    m_input2 = input;
    emit input2Changed();
}


void NaturalBackendWrapper::setInput3(const QString &input)
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
    QString s;
    for(int i = 0; i < a.n; i++) {
        s.push_back(QString::number(a.dig[i]));
    }
    return s;
}


QString NaturalBackendWrapper::calculate(const QString &input1, const QString &input2, const QString &integ,  const QString &id) {

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
