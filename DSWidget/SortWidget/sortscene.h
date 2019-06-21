#ifndef SORTSCENE_H
#define SORTSCENE_H
#include <QGraphicsScene>
#include <QVector>
#include <QList>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QTimer>
#include "element.h"
#include "fadecodescene.h"

class SortScene : public QGraphicsScene
{
    Q_OBJECT
public:
    struct NODE{//定义结点
        Element* data;
        NODE* next=Q_NULLPTR;
    };
    NODE* head=Q_NULLPTR;
    typedef QList<Element*> ele_set;

    SortScene();
    ~SortScene(){}
    void addElement();//向场景中添加元素
    void deleteElement();//从场景中删除元素
    void bubbleSort();//冒泡排序
    void selectionSort();//选择排序
    void insertionSort();//插入排序
    void quickSort();//快速排序
    void mergeSort();//归并排序
    void swapEle(NODE*& p1, NODE*& p2);//交换p1和p2两个元素
    void compare(NODE* p1, NODE*& p2);//比较p1和p2两个元素

    void createList();//创建链表
    NODE* Node(int x);//返回序数所对应的结点

    int eleNum=0;//场景中的元素总数
    int eleValue;//场景中元素的值
    QVector<Element*> ele_vec;//场景中所有元素的容器
    QVector<Element*> tmp_vec;//暂时储存元素，便于重新排序
    QList<QParallelAnimationGroup*> ani_list;//动画列表
    QList<ele_set> change_list;//要进行比较的元素队列
    QList<ele_set> recover_list;//比较完毕的元素队列
    QTimer *SortTimer;
    int *ani_speed;

public slots:
    void dealTimer();

private:
    void quickSort(int,int);
    void mergeSort(int, int, int);
    QParallelAnimationGroup* drag(Element* ele,QPointF pos);//返回将要进行的动画

signals:
    void code_activate(int);
};

#endif // SORTSCENE_H
