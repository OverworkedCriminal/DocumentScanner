#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <iostream>

QString readStyleSheet(QString file)
{
    QFile src(file);
    QString stylesheet;
    src.open(QIODevice::ReadOnly);
    if (src.isOpen())
    {
        stylesheet = src.readAll();
    }
    else
    {
        std::cerr << "stylesheet file not found\n";
    }
    return stylesheet;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet(readStyleSheet(":/stylesheets/main.qss"));
    w.show();
    return a.exec();
}
