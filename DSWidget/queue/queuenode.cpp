#include "queuenode.h"

QueueNode::QueueNode(QString data, int idx)
    : m_data(data), m_index(idx),
      m_dataRect(nullptr), m_indexRect(nullptr),
      m_dataText(nullptr), m_indexText(nullptr) {
}

QueueNode::~QueueNode() {

}

void QueueNode::setDataRect(QGraphicsRectItem *dataRect) {
    m_dataRect = dataRect;
}

void QueueNode::setDataText(QGraphicsTextItem *dataText) {
    m_dataText = dataText;
}

void QueueNode::setIndexRect(QGraphicsRectItem *idxRect) {
    m_indexRect = idxRect;
}

void QueueNode::setIndexText(QGraphicsTextItem *idxText) {
    m_indexText = idxText;
}

void QueueNode::setNodeStatus(QBrush brush) {
    m_dataRect->setBrush(brush);
}

void QueueNode::clearAll(QGraphicsScene *scene) {
    if (m_dataRect) {
        scene->removeItem(m_dataRect);
        delete m_dataRect;
        m_dataRect = nullptr;
    }
    if (m_dataText) {
        scene->removeItem(m_dataText);
        delete m_dataText;
        m_dataText = nullptr;
    }
    if (m_indexRect) {
        scene->removeItem(m_indexRect);
        delete m_indexRect;
        m_indexRect = nullptr;
    }
    if (m_indexText) {
        scene->removeItem(m_indexText);
        delete m_indexText;
        m_indexText = nullptr;
    }
}
