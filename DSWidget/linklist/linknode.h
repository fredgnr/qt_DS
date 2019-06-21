#ifndef LINKNODE_H
#define LINKNODE_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QBrush>
#include "utils/arrow.h"

class linkList;

class linkNode {
public:
    linkNode(QString data, linkNode *next);
    ~linkNode();

    friend class linkList;

    void setDataRect(QGraphicsRectItem *dRect);
    void setPointerRect(QGraphicsRectItem *pRect);
    void setDataText(QGraphicsTextItem *dText);
    void setArrows(std::vector<Arrow *> arrows);
    void setNodeSatus(QBrush brush);
    void clearAll(QGraphicsScene *scene);

protected:
    QString m_data;   // 节点数据域
    linkNode *m_next; // 节点指针域

    // 节点图形项
    std::vector<Arrow *> m_arrows;    // 箭头
    QGraphicsRectItem *m_dataRect, *m_pointerRect;  // 矩形项
    QGraphicsTextItem *m_dataText, *m_pointerText;  // 文字项
};

#endif  // LINKNODE_H
