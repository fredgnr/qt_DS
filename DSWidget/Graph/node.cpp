#include "node.h"
#include<QPainter>
#include<QPen>
#include<QFont>
#include<QMenu>
#include<QAction>
#include "map_scene.h"
#include<QDebug>
#include<QGraphicsView>
#pragma execution_character_set("utf-8")
Node::Node():
    color(Qt::black)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    font.setPointSizeF(15);
    is_moving=false;
}
void Node::SetNumber(int number)
{
    this->number=number;
}
void Node::SetColor(QColor color)
{
    this->color=color;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *style, QWidget *widget)
{
    QPen pen(color,3);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(-0,-0),20,20);
    painter->setFont(font);
    painter->drawText(QRectF(-20,-20,40,40),Qt::AlignHCenter|Qt::AlignVCenter,QString("%1").arg(number));
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(-0,-0),20,20);
    return path;
}
QRectF Node::boundingRect() const
{
    return QRectF(-20,-20,40,40);
}

void Node::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QString string=QString("x:%1,y%2").arg(pos().x()).arg(pos().y());
    setToolTip(string);
    setCursor(Qt::OpenHandCursor);
}
#include<QGraphicsSceneContextMenuEvent>
#include<QColor>
#include"map_scene.h"
void Node::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu Menu;
    qDebug()<<"Node";
    QAction *actionadd=Menu.addAction(tr("增加连接"));
    QAction *actiondelete=Menu.addAction(tr("删除节点"));
    QAction *selected=Menu.exec(event->screenPos());
    if(selected==actionadd){
        if(dynamic_cast<Map_Scene *>(scene())->add1){
            dynamic_cast<Map_Scene *>(scene())->add1->SetColor(QColor(Qt::black));
        }
        this->color=QColor(Qt::red);
        dynamic_cast<Map_Scene *>(scene())->isadding=true;
        dynamic_cast<Map_Scene *>(scene())->add1=this;
        scene()->update();
    }
    else if(selected==actiondelete){
        emit send_delete(this);
    }
}
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsView>
void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->buttons()&Qt::LeftButton){
        is_moving=true;
        setFlag(QGraphicsItem::ItemIsMovable);
        setCursor(Qt::ClosedHandCursor);
        auto s= dynamic_cast<Map_Scene *>(scene());
        if(s->isadding){
            s->add2=this;
           emit send_add_edge();
        }
    }
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton){
        is_moving=false;
        setFlag(QGraphicsItem::ItemIsMovable,false);
    }
}
void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(is_moving){
    setPos(event->scenePos());
    if(event->buttons()&Qt::LeftButton){
        dynamic_cast<Map_Scene *>(scene())->UpdateItems();
        scene()->views()[0]->viewport()->update();
        }
    }
}


