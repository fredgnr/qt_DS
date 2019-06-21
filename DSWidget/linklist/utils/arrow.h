#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsItem>

const int DEFAULT_SIZE_HEIGHT = 2;
const int DEFAULT_SIZE_WIDTH = 5;

class Arrow : public QGraphicsItem {
private:
    QRectF m_boundingRect;
    int m_direction;
    int m_length;
    int m_sizeHeight;
    int m_sizeWidth;

    QLine m_line1;
    QLine m_line2;
    QLine m_line3;

public:
    explicit Arrow(int length=1, int direction=1, bool haveArrow=true);
    ~Arrow();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget=0) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    void draw();
    void setLength(int length);
    void setDirection(int direction);
    void setArrowSize(int height=DEFAULT_SIZE_HEIGHT, int width=DEFAULT_SIZE_WIDTH);
};

#endif // ARROW_H
