#include "computeralgebra.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComputerAlgebra w;
    w.show();
    return a.exec();
}
