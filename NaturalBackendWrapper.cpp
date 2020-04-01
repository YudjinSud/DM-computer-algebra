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


QString NaturalBackendWrapper::calculate(const QString &input1, const QString &input2, const QString &id) {

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

    QString res = "";

    if(id == "1") {
        res = QString::number(COM_NN_D(a, b));
    }
    else if(id == "2") {
        res = NZER_N_B(a) == 0 ? "Да" : "Нет" ;
    }

    qDebug() << res;

    return res;

}
