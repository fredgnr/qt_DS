#include "workthread.h"

int Count=0;

#include <QDebug>

WorkThread::WorkThread()
{
    stopped=false;
}

WorkThread::~WorkThread()
{
    delete Queens;
}

void WorkThread::run()
{
    Queens=new int[n+1];
    for(int i=1;i<=n;i++)
        Queens[i]=0;
    setQueen(1);
    emit myfinish();
}

void WorkThread::stop()
{
    stopped=true;
}

bool WorkThread::check(int row, int column)
{
    for (int check_row = 1; check_row < row; check_row++) {
        if (column == Queens[check_row] || (row - check_row) == abs(column - Queens[check_row]))
            return false;
    }
    return true;
}

void WorkThread::setQueen(int row)
{
    for (int column = 1; column <= n; column++)
    {
        Queens[row] = column;
        emit thrdSetQueen(Queens);
        msleep(100);
        if(!(check(row,column))){
            Queens[row] = 0;
            emit thrdSetQueen(Queens);
        }
        if (check(row,column))
        {
            Queens[row] = column;
            if (row == n)
            {
                Count++;
                emit thrdSetQueen(Queens);
                msleep(2000);
                Queens[row] = 0;
                return;
            }
            setQueen(row + 1);
            Queens[row] = 0;
        }
    }
}
