#include "numberbox.h"
#include <QPainter>

NumberBox::NumberBox()
{

}

void NumberBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColor(255,192,203));
    painter->drawRect(0,0,40,30);

    QString str=QString("%1").arg(value);
    QPoint elePoint=QPoint(10,20);
    painter->drawText(elePoint,str);
}

QRectF NumberBox::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(0-penWidth/2,0-penWidth/2,40+penWidth,30+penWidth);
}

int NumberBox::bitNum(int n)
{
    int x=(this->value)/pow(10,n-1);
    return x%10;
}
