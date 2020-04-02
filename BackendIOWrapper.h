#ifndef BACKENDIOWRAPPER_H
#define BACKENDIOWRAPPER_H


#include <QObject>
#include <QString>
#include <QDebug>

#include "Natural.h"
#include "Manipulator.h"
#include "Integ.h"

#include <cstdlib>


class BackendIOWrapper : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString input1 READ input1 WRITE setInput1 NOTIFY input1Changed)//natural #1
    Q_PROPERTY(QString input2 READ input2 WRITE setInput2 NOTIFY input2Changed)//natural #2
    Q_PROPERTY(QString input3 READ input3 WRITE setInput3 NOTIFY input3Changed)//additional integer

public:

    explicit BackendIOWrapper(QObject *parent = nullptr);

    QString input1();
    QString input2();
    QString input3();


public slots :
   void setInput1(const QString &input);
   void setInput2(const QString &input);
   void setInput3(const QString &input);
   QString calculateNatural(const QString &input1, const QString &input2, const QString &integ,  const QString &id);
   QString calculateInteger(const QString &input1, const QString &input2, const QString &integ,  const QString &id);
   QString calculateFraction(const QString &input1, const QString &input2, const QString &integ,  const QString &id);
   QString calculatePoly(const QString &input1, const QString &input2, const QString &integ,  const QString &id);


signals:
    void input1Changed();
    void input2Changed();
    void input3Changed();

private:
    QString m_input1;
    QString m_input2;
    QString m_input3;
};

#endif // BACKENDIOWRAPPER_H
