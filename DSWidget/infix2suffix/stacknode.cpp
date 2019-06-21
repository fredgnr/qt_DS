#include "stacknode.h"

StackNode::StackNode(QString data)
    : m_data(data), m_dataRect(nullptr), m_dataText(nullptr) {

}


StackNode::~StackNode() {

}

void StackNode::setDataRect(QGraphicsRectItem *dataRect) {
    m_dataRect = dataRect;

}

void StackNode::setDataText(QGraphicsTextItem *dataText) {
    m_dataText = dataText;
}

void StackNode::setNodeStatus(QBrush brush) {
    m_dataRect->setBrush(brush);
}

void StackNode::clearAll(QGraphicsScene *scene) {
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
}
