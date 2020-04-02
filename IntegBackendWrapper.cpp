#include "IntegBackendWrapper.h"


IntegBackendWrapper::IntegBackendWrapper(QObject *parent) :
    QObject(parent)
{
    ;
}

QString IntegBackendWrapper::input1()
{
    return m_input1;
}

QString IntegBackendWrapper::input2()
{
    return m_input2;
}

QString IntegBackendWrapper::input3()
{
    return m_input3;
}

void IntegBackendWrapper::setInput1(const QString &input)
{
    if (input == m_input1)
        return;


    m_input1 = input;
    emit input1Changed();
}


void IntegBackendWrapper::setInput2(const QString &input)
{
    if (input == m_input2)
        return;


    m_input2 = input;
    emit input2Changed();
}


void IntegBackendWrapper::setInput3(const QString &input)
{
    if (input == m_input3)
        return;


    m_input3 = input;
    emit input3Changed();
}

vector<int> QStringToVectorInt(const QString s) {
    vector<int> vec;
    QByteArray byteArray = s.toLocal8Bit();
    for (int i = 0; i < byteArray.size(); i++) {
         int asciiCode = (int)byteArray[i];
         vec.push_back(asciiCode);
    }
    return vec;

}


QString IntegToQString(Integ a) {
    QString s;
    for(int i = 0; i < a.n; i++) {
        s.push_back(QString::number(a.dig[i]));
    }
    return s;
}

QString NatToQString(Natural a) {
    QString s;
    for(int i = 0; i < a.n; i++) {
        s.push_back(QString::number(a.dig[i]));
    }
    return s;
}


QString IntegBackendWrapper::calculate(const QString &input1, const QString &input2, const QString &integ,  const QString &id) {

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

    Integ a, b, resInteg;
    Natural n;
    s_0 << s1;
    s_0 >> read_Integ(a);
    s_0 << s2;
    s_0 >> read_Integ(b);
    s_0 << s1;
    s_0 >> read_Nat(n);

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
        break;
    }
    case 4: {
        res = IntegToQString(TRANS_N_Z(n));
        break;
    }
    case 5: {
        res = NatToQString(TRANS_Z_N(a));
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
    case 9: {
        res = IntegToQString(DIV_ZZ_Z(a, n));
        break;
    }
    case 10: {
        res = IntegToQString(MOD_ZZ_Z(a, n));
        break;
    }
   }
    qDebug() << res;

    return res;

}
