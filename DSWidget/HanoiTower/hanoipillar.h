#ifndef HANOIPILLAR_H
#define HANOIPILLAR_H
#include <QGraphicsObject>
#include <QVector>
#include "hanoidish.h"
class HanoiDish;

class HanoiPillar : public QGraphicsObject
{
    Q_OBJECT
public:
    HanoiPillar();
    ~HanoiPillar(){}
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=Q_NULLPTR);
    QRectF boundingRect() const;

    int index;//柱子序号
    QVector<HanoiDish*> dishes;//存储每个柱子上叠放的盘子

};

#endif // HANOIPILLAR_H
