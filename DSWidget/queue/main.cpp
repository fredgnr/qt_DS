#include <QApplication>
#include <QTime>
#include "queue.h"


void sleep(unsigned int msec)
{
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
        QApplication::processEvents(QEventLoop::AllEvents,100);
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Queue *q = new Queue();
    q->show();

    return app.exec();
}
