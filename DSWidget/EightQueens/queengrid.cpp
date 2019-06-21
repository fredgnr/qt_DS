#include "queengrid.h"
#include <QPainter>
#include<QDebug>
QueenGrid::QueenGrid(bool chse=0,QColor color=Qt::white):
    grid_color(color),
    chosen(chse),
    queen_pic(QPixmap("../DSWidget/EightQueens/queen.png"))
{
    grid_width=40;
}

void QueenGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if(!chosen){
        painter->setBrush(grid_color);
        painter->drawRect(0,0,grid_width,grid_width);
    }
    if(chosen){
        painter->drawPixmap(3,2,queen_pic);
    }
}

QRectF QueenGrid::boundingRect() const
{
    qreal penWidth=1;
    return QRectF(0-penWidth/2,0-penWidth/2,grid_width+penWidth/2,grid_width+penWidth/2);
}

