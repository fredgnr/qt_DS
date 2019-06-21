#include "arrow.h"

#include <QGraphicsScene>
#include <QPainter>
#include <cstdio>

//direction:    0   up  |   1   right  |    2   down    |   3   left
//haveArrow:    false   no  |   true    yes

Arrow::Arrow(int length, int direction, bool haveArrow){
    setLength(length);
    setDirection(direction);
    if (haveArrow) {
        setArrowSize();
    }
    else {
        setArrowSize(0, 0);
    }
}

Arrow::~Arrow() {

}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawLine(m_line1);
    painter->drawLine(m_line2);
    painter->drawLine(m_line3);
}

QRectF Arrow::boundingRect() const {
    return m_boundingRect;
}

void Arrow::setLength(int length) {
    if (length > 0) {
        m_length = length;
    }
}

void Arrow::setDirection(int direction) {
    m_direction = direction;
}


void Arrow::setArrowSize(int height, int width) {
    if (height >= 0 && width >= 0) {
        m_sizeHeight = height;
        m_sizeWidth = width;
    }
}

void Arrow::draw() {
    QPoint Pstart(0,0), P1, P2, Pend;

    switch (m_direction) {
    case 0:
        Pend = QPoint(0, -m_length);
        P1 = Pend + QPoint(-m_sizeHeight, m_sizeWidth);
        P2 = Pend + QPoint(m_sizeHeight, m_sizeWidth);
        m_boundingRect = QRect(-m_sizeHeight, -m_length, m_sizeHeight<<1, m_length);
        break;
    case 1:
        Pend = QPoint(m_length, 0);
        P1 = Pend + QPoint(-m_sizeWidth, -m_sizeHeight);
        P2 = Pend + QPoint(-m_sizeWidth, m_sizeWidth);
        m_boundingRect = QRect(0, -m_sizeHeight, m_length, m_sizeHeight<<1);
        break;
    case 2:
        Pend = QPoint(0, m_length);
        P1 = Pend + QPoint(-m_sizeHeight, -m_sizeWidth);
        P2 = Pend + QPoint(m_sizeHeight, -m_sizeWidth);
        m_boundingRect = QRect(-m_sizeHeight, 0, m_sizeHeight<<1, m_length);
        break;
    case 3:
        Pend = QPoint(-m_length, 0);
        P1 = Pend + QPoint(m_sizeWidth, m_sizeHeight);
        P2 = Pend + QPoint(m_sizeWidth, -m_sizeHeight);
        m_boundingRect = QRect(-m_length, -m_sizeHeight, m_length,  m_sizeHeight<<1);
        break;
    default:
        break;
    }

    m_line1 = QLine(Pstart, Pend);
    m_line2 = QLine(Pend, P1);
    m_line3 = QLine(Pend, P2);
}
