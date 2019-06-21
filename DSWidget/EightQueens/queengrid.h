#ifndef QUEENGRID_H
#define QUEENGRID_H
#include <QGraphicsObject>
#include <QPixmap>

class QueenGrid : public QGraphicsObject
{
    Q_OBJECT
public:
    QueenGrid(bool chse,QColor);
    ~QueenGrid(){}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    int grid_width;
    QColor grid_color;
    bool chosen;
    const QPixmap queen_pic;
};

#endif // QUEENGRID_H
