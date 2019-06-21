#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>

class WorkThread : public QThread
{
    Q_OBJECT
public:
    WorkThread();
    ~WorkThread();
    void run();
    void stop();
    bool check(int row,int column);
    void setQueen(int row);
    bool stopped;
    int n;

signals:
    void thrdSetQueen(int*);
    void myfinish();
private:
    int *Queens;
};

#endif // WORKTHREAD_H
