#include "bucket.h"
#include <QPainter>

Bucket::Bucket()
{
}

void Bucket::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawLine(QPointF(0,0),QPointF(60,0));

    QString str=QString("%1").arg(index);
    QPoint bucketPoint=QPoint(28,25);
    painter->drawText(bucketPoint,str);
}

QRectF Bucket::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(0-penWidth/2,0-penWidth/2,60+penWidth,0+penWidth);
}
