#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsObject>

class Element : public QGraphicsObject
{
public:
    Element();
    ~Element(){}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPointF tmp_pos;//存放每次动画结束后元素当前移动到的位置
    void setColor(QColor);

    int value;//元素值大小
    QColor eleColor;
};

#endif // ELEMENT_H
