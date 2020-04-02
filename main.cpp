//#define fore(i, j, n) for(long long i = j; i < n; i++)

//pure backend
#include "Test.h"
#include "Btest.h"

//backend wrapping
#include "NaturalBackendWrapper.h"
#include "IntegBackendWrapper.h"

// QT intrinsics
#include <QGuiApplication>
#include <QQmlApplicationEngine>



int main(int argc, char *argv[])
{

    BTest bt;
    bt.runAllTests();
    Test::showFinalResult();


    qmlRegisterType<NaturalBackendWrapper>("io.qt.examples.NaturalBackendWrapper", 1, 0, "NaturalBackendWrapper");
    NaturalBackendWrapper wr;
   // wr.input()

    qmlRegisterType<IntegBackendWrapper>("io.qt.examples.IntegBackendWrapper", 1, 0, "IntegBackendWrapper");
    IntegBackendWrapper zr;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

//    Poly c;
//    std::cin >> read_Poly(c); format: "(3)/(5)x^2 + (-1)/(4)x^1 + (1)/(1)" testi delaite 4erez  stringstream
//    std::cout << write_Poly(c) << std::endl;

    return app.exec();
}
