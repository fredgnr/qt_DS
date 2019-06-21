#ifndef RADIXSCENE_H
#define RADIXSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include <QList>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QTimer>
#include "numberbox.h"
#include "sortscene.h"
#include "bucket.h"

class RadixScene : public QGraphicsScene
{
    Q_OBJECT
public:
    struct NODE{//定义结点
        NumberBox* data;
        NODE* next=Q_NULLPTR;
    };
    NODE* head=Q_NULLPTR;

    RadixScene();
    ~RadixScene(){}
    void addBox();//向场景中添加数据盒子
    void radixSort();
    void createList();//创建链表

    SortScene *sort_scene;
    int boxValue;//用于存储从widget的lineEdit中获取的元素值
    QList<QPropertyAnimation*> ani_list;//动画列表
    int *ani_speed;
    QTimer *RadixTimer;

private:
    NODE* Node(int x);//返回序数所对应的结点
    int maxBit();//返回链表中数值的最大位数
    int bitNum(NODE*, int);//返回指定位数上的数值
    void radixSort(int x);//用于x位数的基数排序
    QPropertyAnimation* drag(NumberBox* box,QPointF pos);//返回要进行的动画

    int boxNum=0;//场景中元素的总数
    QVector<NumberBox*> box_vec;//场景中的所有元素
    QVector<Bucket*> bucket_vec;//场景中的所有桶

public slots:
    void dealTimer();
};

#endif // RADIXSCENE_H
