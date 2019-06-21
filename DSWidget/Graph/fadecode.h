#ifndef FADECODE_H
#define FADECODE_H
#include<QGraphicsRectItem>
#include<QGraphicsTextItem>
#include<QObject>
class FadeCode : public QGraphicsRectItem
{
public:
    FadeCode();
    void setString(QString &s);
    void clear();
    void activate(bool act);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QColor color;
    QString code;
    bool act;

};

#endif // FADECODE_H
