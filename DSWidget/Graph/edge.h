#ifndef EDGE_H
#define EDGE_H
#pragma execution_character_set("utf-8")
#include<QGraphicsObject>
#include<QGraphicsView>
#include<QFont>
#include<QObject>
#include<QGraphicsLineItem>
class Node;
class QFont;
class Edge :public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    explicit Edge(Node *n1,Node *n2);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const;
    QRectF boundingRect() const;
    void set_path();
    double get_length();
    Node * node1,*node2;
    void set_color(QColor color);
protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
private:
    double length,angle;//线段长度以及偏斜角度
    QPainterPath path,boundingPath;//线段本身
    QColor color;//线段的颜色
    QPointF centerpoint;//绘制文字的中心
    QPointF start,end;
    QFont font;
signals:
    void send_delete_edge(Edge *);
};

#endif // EDGE_H
