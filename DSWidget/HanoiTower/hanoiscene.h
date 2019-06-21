#ifndef HANOISCENE_H
#define HANOISCENE_H
#include <QGraphicsScene>
#include <QVector>
#include <QSequentialAnimationGroup>
#include "hanoidish.h"
#include "hanoipillar.h"

class HanoiScene : public QGraphicsScene
{
    Q_OBJECT
public:
    HanoiScene();
    ~HanoiScene(){}
    void setDishes();//向场景中添加盘子
    void moveDishes(int dish_nums,HanoiPillar *A,HanoiPillar *B,HanoiPillar *C);//将所有盘子从A经过B移动到C

    QVector<HanoiDish*> dish_vec;//场景中所有盘子的容器
    QVector<HanoiPillar*> pillar_vec;//场景中柱子容器
    int dishNum;//场景中盘子总数
    QSequentialAnimationGroup group;//串行动画组
     int *ani_speed;
};

#endif // HANOISCENE_H
