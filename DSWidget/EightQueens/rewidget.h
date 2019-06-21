#ifndef REWIDGET_H
#define REWIDGET_H

#include <QWidget>
#include "queenscene.h"
#include "workthread.h"
#include "fadecodescene.h"

namespace Ui {
class ReWidget;
}

class ReWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReWidget(QWidget *parent = 0);
    ~ReWidget();
    QueenScene *myScene;
    WorkThread *myThread;

public slots:
    void wgtSetQueen(int*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void get_thread_finish();
private:
    Ui::ReWidget *ui;
    fadecodescene *code_scene;
};

#endif // REWIDGET_H
