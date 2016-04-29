#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QScopedPointer>
#include "coreapplication.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QScopedPointer<CoreApplication> coreApp(new CoreApplication(engine.rootContext()));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

