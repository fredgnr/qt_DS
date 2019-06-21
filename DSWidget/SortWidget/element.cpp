#include "element.h"
#include <QPainter>

Element::Element()
{
    eleColor=QColor(255,192,203);
}

void Element::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(eleColor);
    painter->drawRect(0,0,20,value);

    QString str=QString("%1").arg(value);
    QPoint elePoint=QPoint(2,value+20);
    painter->drawText(elePoint,str);
}

QRectF Element::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(0-penWidth/2,0-penWidth/2,30+penWidth,value+40+penWidth);
}

void Element::setColor(QColor c)
{
    eleColor=c;
}
