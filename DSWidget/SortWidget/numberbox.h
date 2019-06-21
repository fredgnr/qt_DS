#ifndef NUMBERBOX_H
#define NUMBERBOX_H
#include <QGraphicsObject>

class NumberBox : public QGraphicsObject
{
    Q_OBJECT
public:
    NumberBox();
    ~NumberBox(){}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    int bitNum(int);//返回数据的位数

    int value;//值
    QPointF tmp_pos;//存放每次动画结束后元素当前移动到的位置
};

#endif // NUMBERBOX_H
