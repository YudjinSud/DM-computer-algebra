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

vector<int> QStringTOVectorInt(const QString s) {
    vector<int> vec;
    QByteArray byteArray = s.toLocal8Bit();
    for (int i = 0; i < byteArray.size(); i++) {
         int asciiCode = (int)byteArray[i];
         vec.push_back(asciiCode);
    }
    return vec;

}


QString NaturalBackendWrapper::calculate(const QString &input1, const QString &input2, const QString id) {

//    string s = "(3)/(5)x^2 + (-1)/(4)x^1 + (1)/(1)";
//    std::stringstream s_0;
//    s_0 << s;
//    Poly c;
//    s_0 >> read_Poly(c);
//    Frac res;
//    string res1 = "(3)/(5)";
//    s_0 << res1;
//    s_0 >> read_Frac(res);

    std::stringstream s_0;
    string s1 = input1.toStdString();
    string s2 = input2.toStdString();

    s1.push_back('.');
    s2.push_back('.');


    Natural a, b;
    s_0 << s1;
    s_0 >> read_Nat(a);
    s_0 << s2;
    s_0 >> read_Nat(b);

    int res = 0;

    if(id == "n1") {
        res = COM_NN_D(a, b);
    }




//    vector<int> digits1;
//    vector<int> digits2;

//    digits1 = QStringTOVectorInt(input1);
//    digits2 = QStringTOVectorInt(input2);


//    b.n = digits2.size();
//    b.dig = digits2;

//    int res = COM_NN_D(a, b);

    qDebug() << res;

    return QString::number(res);

}
