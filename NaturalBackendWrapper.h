#ifndef NATURALBACKENDWRAPPER_H
#define NATURALBACKENDWRAPPER_H


#include <QObject>
#include <QString>
#include <QDebug>

#include "Natural.h"
#include "Manipulator.h"

#include <cstdlib>


class NaturalBackendWrapper : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString input1 READ input1 WRITE setInput1 NOTIFY input1Changed)
    Q_PROPERTY(QString input2 READ input2 WRITE setInput2 NOTIFY input2Changed)

public:

    explicit NaturalBackendWrapper(QObject *parent = nullptr);

    QString input1();
    QString input2();


public slots :
   void setInput1(const QString &input);
   void setInput2(const QString &input);
   QString calculate(const QString &input1, const QString &input2, const QString id);


signals:
    void input1Changed();
    void input2Changed();

private:
    QString m_input1;
    QString m_input2;
};

#endif // NATURALBACKENDWRAPPER_H
