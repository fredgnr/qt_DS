#include "fadecode.h"
FadeCode::FadeCode():
    color(Qt::white)
{

}

void FadeCode::setString(QString &s)
{
    code=s;
}
#include<QDebug>
void FadeCode::activate(bool act)
{
    if(act){
        color=QColor(Qt::yellow);
    }
    else{
        color=QColor(Qt::white);
    }
}
#include<QDebug>
#include<QPainter>
void FadeCode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setBrush(color);
    //qDebug()<<(color==QColor(Qt::yellow));
    QGraphicsRectItem::paint(painter,option,widget);
    auto rect=QGraphicsRectItem::boundingRect();
    painter->drawText(QRectF(rect.x()+10,rect.y(),rect.width(),rect.height()),Qt::AlignLeft|Qt::AlignVCenter,code);
}
