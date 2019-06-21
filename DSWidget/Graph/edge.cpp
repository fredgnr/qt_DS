#include "edge.h"
#include<QFont>
#include"node.h"
#include<QPainterPath>
#include<QMenu>
#include<QPen>
#include<QPainter>
#include<QtCore>
void swapx(QPointF& p1,QPointF& p2);
void swapy(QPointF& p1,QPointF& p2);
Edge::Edge(Node *n1,Node *n2):
    color(Qt::black),
    node1(n1),
    node2(n2)
{
    set_path();
    font.setPixelSize(15);
    QPen pen(color,5);
    setPen(pen);
    pen.setCapStyle(Qt::RoundCap);
    setAcceptHoverEvents(true);
}

QPainterPath Edge::shape() const
{
    return QGraphicsLineItem::shape().simplified();
}

QRectF Edge::boundingRect() const
{
    return QGraphicsLineItem::shape().boundingRect();
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color,3));
    painter->drawLine(start,end);
    painter->setFont(font);
    painter->translate(centerpoint);
    painter->rotate(qRadiansToDegrees(-angle));
    painter->drawText(QRectF(-20,-20,40,40),QString("%1").arg(int(length)));
    painter->resetMatrix();
}


int quadrant(QPointF point,QPointF origin);
void Edge::set_path()
{
    auto p1=node1->pos(),p2=node2->pos();
    centerpoint=(p1+p2)/2.0;
    length=sqrt(pow(p1.x()-p2.x(),2)+pow(p1.y()-p2.y(),2));
    double a=asin(abs(p1.y()-p2.y())/length);
    swapx(p1,p2);
    QPainterPath path;
    if(a<(asin(1.0)/2.0)){
        start=p1+QPointF(-21,0);
        end=p2+QPointF(21,0);

    }
    else{
       swapy(p1,p2);
       start=p1+QPointF(0,-21);
       end=p2+QPointF(0,21);

    }
    setLine(start.x(),start.y(),end.x(),end.y());
    this->path=path;
    int tag1=quadrant(p1,centerpoint),tag2=quadrant(p2,centerpoint);
    if((tag1|tag2)==5){
        angle=-a;
    }
    else{
        angle=a;
    }
}
double Edge::get_length()
{
    return length;
}

#include<QGraphicsSceneContextMenuEvent>
void Edge::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *action=menu.addAction("删除此连接");
    QAction *selected=menu.exec(event->screenPos());
    if(selected==action){
        emit send_delete_edge(this);
    }
    /*QMenu menu;
    QAction *action=menu.addAction("删除此连接");
    QAction *selected=menu.exec(event->screenPos());
    if(selected==action){
       emit send_delete_edge(this);
    }*/
}
void Edge::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
}
void Edge::set_color(QColor color)
{
    this->color=color;
}

void swapx(QPointF& p1,QPointF& p2)
{
    if(p1.x()<p2.x()){
        double x=p2.x(),y=p2.y();
        p2.setX(p1.x()),p2.setY(p1.y());
        p1.setX(x),p1.setY(y);
    }
}
void swapy(QPointF& p1,QPointF& p2)
{
    if(p1.y()<p2.y()){
        double x=p2.x(),y=p2.y();
        p2.setX(p1.x()),p2.setY(p1.y());
        p1.setX(x),p1.setY(y);
    }
}
int quadrant(QPointF point,QPointF origin)
{
    if (point.x()>origin.x()&&point.y()>origin.y())
        return 1;
    else if (point.x()>origin.x()&&point.y()<origin.y())
        return 1<<2;
    else if (point.x()<origin.x()&&point.y()<origin.y())
        return 1<<3;
    else
        return 1<<4;
}
