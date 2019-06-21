#include "dswidget.h"
#include <QApplication>
#include<QFile>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    DSWidget w;
    w.show();

    return a.exec();
}
