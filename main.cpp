#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QFile>
#include <QLatin1String>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile File("style.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    a.setStyleSheet(StyleSheet);
    w.show();
    return a.exec();
}
