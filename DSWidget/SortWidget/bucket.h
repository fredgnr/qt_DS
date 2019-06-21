#ifndef BUCKET_H
#define BUCKET_H
#include <QGraphicsObject>
#include <QVector>
#include "numberbox.h"

class Bucket : public QGraphicsObject
{
    Q_OBJECT
public:
    Bucket();
    ~Bucket(){}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int index;//桶的序号
    QVector<NumberBox*> box_vec;//每个桶中存放的数据信息
    QPointF top_pos;//桶中最高元素的位置
};

#endif // BUCKET_H
