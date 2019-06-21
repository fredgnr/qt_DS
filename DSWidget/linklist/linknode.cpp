#include "linknode.h"
#pragma execution_character_set("utf-8")
const int MAX_ARROW_CAPASITY = 10;

linkNode::linkNode(QString data, linkNode *next)
    : m_data(data), m_next(next),
      m_dataRect(nullptr), m_pointerRect(nullptr),
      m_dataText(nullptr), m_pointerText(nullptr) {
    m_arrows.reserve(MAX_ARROW_CAPASITY);
    m_arrows.clear();
}

linkNode::~linkNode() {
}

void linkNode::setDataRect(QGraphicsRectItem *dRect) {
    m_dataRect = dRect;
}

void linkNode::setDataText(QGraphicsTextItem *dText) {
    m_dataText = dText;
}

void linkNode::setPointerRect(QGraphicsRectItem *pRect) {
    m_pointerRect = pRect;
}

void linkNode::setNodeSatus(QBrush brush) {
    m_dataRect->setBrush(brush);
}

void linkNode::clearAll(QGraphicsScene *scene) {
    if (m_dataRect) {
        scene->removeItem(m_dataRect);
        delete m_dataRect;
        m_dataRect = nullptr;
    }

    if (m_pointerRect) {
        scene->removeItem(m_pointerRect);
        delete m_pointerRect;
        m_pointerRect = nullptr;
    }

    if (m_dataText) {
        scene->removeItem(m_dataText);
        delete m_dataText;
        m_dataText = nullptr;
    }

    if (m_pointerText) {
        scene->removeItem(m_pointerText);
        delete m_pointerText;
        m_pointerText = nullptr;
    }

    for (Arrow *arrow: m_arrows) {
        scene->removeItem(arrow);
    }
    m_arrows.clear();
}

void linkNode::setArrows(std::vector<Arrow *> arrows) {
    m_arrows = arrows;
}
