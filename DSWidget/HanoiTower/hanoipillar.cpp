#include "hanoipillar.h"
#include <QPainter>
#include <QDebug>

HanoiPillar::HanoiPillar()
{
    index=0;
    qDebug()<<"constructed:"<<dishes.size();
}

void HanoiPillar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawLine(QPoint(0,200),QPoint(200,200));
    painter->drawLine(QPoint(100,200),QPoint(100,0));
}

QRectF HanoiPillar::boundingRect() const{
    qreal penWidth=1;
    return QRectF(0-penWidth/2,0-penWidth/2,200+penWidth,200+penWidth);
}
