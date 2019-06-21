#ifndef HANOIDISH_H
#define HANOIDISH_H
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include "hanoipillar.h"

class HanoiPillar;
class HanoiDish : public QGraphicsObject
{
    Q_OBJECT
public:
    HanoiDish();
    ~HanoiDish(){}
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=Q_NULLPTR);
    QRectF boundingRect() const;
    QSequentialAnimationGroup* move(HanoiPillar *des);//将盘子移动到目标柱子上

    int width;//盘子宽度
    HanoiPillar *current_pillar;//盘子移动前所在的柱子
    QPointF position[3];//移动过程中动画方向改变的三个目的位置
};

#endif // HANOIDISH_H
