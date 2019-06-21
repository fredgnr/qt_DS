#ifndef QUEUENODE_H
#define QUEUENODE_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QBrush>
#pragma execution_character_set("utf-8")
class Queue;

class QueueNode {
public:
    QueueNode(QString data="", int idx=-1);
    ~QueueNode();

    friend class Queue;

    void setDataRect(QGraphicsRectItem *dataRect);
    void setIndexRect(QGraphicsRectItem *idxRect);
    void setDataText(QGraphicsTextItem *dataText);
    void setIndexText(QGraphicsTextItem *idxText);

    void setNodeStatus(QBrush brush);
    void clearAll(QGraphicsScene *scene);


protected:
    QString m_data;     // 节点数据
    int m_index;        // 节点序号

    // 节点图形项
    QGraphicsRectItem *m_dataRect, *m_indexRect;    // 矩形项
    QGraphicsTextItem *m_dataText, *m_indexText;    // 文字项
};

#endif  // QUEUENODE_H
