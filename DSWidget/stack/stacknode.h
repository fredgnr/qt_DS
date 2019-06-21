#ifndef STACKNODE_H
#define STACKNODE_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QBrush>

class Stack;
class Infix2Suffix;

class StackNode
{
public:
    StackNode(QString data="");
    ~StackNode();

    friend class Stack;
    friend class Infix2Suffix;

    void setDataRect(QGraphicsRectItem *dataRect);
    void setDataText(QGraphicsTextItem *dataText);

    void setNodeStatus(QBrush brush);
    void clearAll(QGraphicsScene *scene);

protected:
    QString m_data;

    // 节点图形项
    QGraphicsRectItem *m_dataRect;    // 矩形项
    QGraphicsTextItem *m_dataText;    // 文字项
};

#endif // STACKNODE_H
