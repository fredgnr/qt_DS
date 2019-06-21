#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include"worker.h"
#include"fadecodescene.h"
#include<QTableWidget>
#include"edge.h"
#pragma execution_character_set("utf-8")
namespace Ui {
class GraphWidget;
}

class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = 0);
    ~GraphWidget();

private:
    Ui::GraphWidget *ui;
    Worker thread;
    fadecodescene *codescene;
    QTableWidget *distable;
public slots:
    void setnodenumber(int number);
    void bfsdown();
    void dfsdown();
    void djsdown();
    void primdown();
    void get_edge_info(int node1,int node2,int length);
    void update_table(const  QList<Edge *> &edgelist,int size);
    void get_info(int info);
    void get_dis(QVector<int> dis);
    void stop_ani();

};

#endif // GRAPHWIDGET_H
