#ifndef NODE_H
#define NODE_H
#include<QGraphicsObject>
#pragma execution_character_set("utf-8")
class Edge;
#include<QFont>
class Node : public QGraphicsObject
{
    Q_OBJECT
public:
    Node();
    void SetColor(QColor color);//设置颜色
    void SetNumber(int number);//设置数字
    QColor GetColor(){return color;}
    int GetNumber(){return number;}
    void save(){tempcolor=color;}
    void rec(){color=tempcolor;}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *style, QWidget *widget) Q_DECL_OVERRIDE ;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const;
    bool is_moving;
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color,tempcolor;
    int number;
    QFont font;

signals:
    void send_update();
    void send_delete(Node *);
    void send_add_edge();
};

#endif // NODE_H
