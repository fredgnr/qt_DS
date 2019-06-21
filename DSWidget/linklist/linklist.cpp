#include <climits>
#include <QDebug>
#include "linklist.h"
#include "ui_linklist.h"
#pragma execution_character_set("utf-8")
#include<QTime>
void sleep(unsigned int msec);


const QBrush linkList::m_normalBursh = QBrush(Qt::GlobalColor::darkGray);
const QBrush linkList::m_visitedBrush = QBrush(Qt::GlobalColor::gray);
const QBrush linkList::m_markBrush = QBrush(Qt::GlobalColor::white);

const QFont linkList::m_headLabelFont = QFont("Consolas");
const QFont linkList::m_dataFont = QFont("Consolas",8);
const QIntValidator linkList::m_dataValidator(-INT_MAX, INT_MAX);


const int SCENE_MAX_WIDTH = 480;  // 场景最大宽度
const int SCENE_MAX_HEIGHT = 2000; // 场景最大高度

const int DATA_RECT_WIDTH = 75;     // 数据域宽度
const int POINTER_RECT_WIDTH = 25;  // 指针域宽度
const int RECT_HEIGHT = 30;         // 节点高度
const int SPACE = 10;               // 间距

const int NODE_WIDTH = DATA_RECT_WIDTH + POINTER_RECT_WIDTH + 25;
const int NODE_HEIGHT = RECT_HEIGHT + SPACE * 2;

const int ARROW_LENGTH = 25 + POINTER_RECT_WIDTH / 2;                   // 默认箭头长度
const int ARROW_H_OFFSET = DATA_RECT_WIDTH + POINTER_RECT_WIDTH / 2;    // 箭头距离节点图形起始坐标水平偏移
const int ARROW_V_OFFSET = SPACE + RECT_HEIGHT / 2;                     // 箭头距离节点图形起始坐标垂直偏移

const int SLEEP_TIME = 10;
#include<QFile>
linkList::linkList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::linkList)
{
    ui->setupUi(this);
    ui->vSplitter->setStretchFactor(0, 3);
    ui->vSplitter->setStretchFactor(1, 7);
    ui->hSplitter->setStretchFactor(0, 8);
    ui->hSplitter->setStretchFactor(1, 5);
    m_scene = nullptr;
    m_head = nullptr;
    m_nodeCnt = 0;
    initUi();
}

linkList::~linkList()
{
    clearAll();
    delete ui;
}

void linkList::initUi() {
    // 刚打开时，只有创建/初始化按钮可用
    ui->initButton->setEnabled(true);
    ui->clearButton->setEnabled(false);

    ui->insertButton->setEnabled(false);
    ui->insertNumberEdit->setEnabled(false);
    ui->insertComboBox->setEnabled(false);

    ui->deleteComboBox->setEnabled(false);
    ui->deleteButton->setEnabled(false);

    ui->searchNumberEdit->setEnabled(false);
    ui->searchButton->setEnabled(false);
    ui->searchResultEdit->setEnabled(false);

    ui->statusEdit->setEnabled(false);

    ui->insertNumberEdit->setPlaceholderText("插入值：int类型");
    ui->searchNumberEdit->setPlaceholderText("查找值：int类型");

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请创建一个单链表.");
}


void linkList::initSceneView() {
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0, 0, SCENE_MAX_WIDTH, SCENE_MAX_HEIGHT);
    ui->graphicsView->setScene(m_scene);
}

void linkList::initLinkList() {
    initSceneView();

    m_headLabel = m_scene->addText("LinkList", m_headLabelFont);
    m_headLabel->setPos((DATA_RECT_WIDTH - RECT_HEIGHT)>>1, SPACE);

    m_headArrow = new Arrow(ARROW_LENGTH);
    m_headArrow->draw();
    m_scene->addItem(m_headArrow);
    m_headArrow->setPos(ARROW_H_OFFSET, ARROW_V_OFFSET);

    sleep(SLEEP_TIME);

    m_head = new linkNode("头节点", nullptr);
    addLinkNodeGraphicsItem(m_head, getLinkNodePos(0));
}

void linkList::setLinkListNormalBrush() {
    linkNode *pNode = m_head;
    while (pNode) {
        pNode->setNodeSatus(linkList::m_normalBursh);
        pNode = pNode->m_next;
    }
}

QPoint linkList::getLinkNodePos(int nodeIndex) {
    const static int rowNum = SCENE_MAX_WIDTH / NODE_WIDTH;
    return QPoint((nodeIndex + 1) % rowNum * NODE_WIDTH, (nodeIndex + 1) / rowNum * NODE_HEIGHT);
}

void linkList::addLinkNodeGraphicsItem(linkNode *pNode, QPoint p) {
    int x = p.x();
    int y = p.y();
    pNode->setDataRect(m_scene->addRect(x, y+SPACE, DATA_RECT_WIDTH, RECT_HEIGHT, QPen(), m_markBrush));
    pNode->setPointerRect(m_scene->addRect(x+DATA_RECT_WIDTH, y+SPACE, POINTER_RECT_WIDTH, RECT_HEIGHT));
    pNode->setDataText(m_scene->addText(pNode->m_data, m_dataFont));
    pNode->m_dataText->setPos(x, y+SPACE+5);

    if (!pNode->m_next) {
        pNode->m_pointerText = m_scene->addText(" ^", m_dataFont);
        pNode->m_pointerText->setPos(x+DATA_RECT_WIDTH, y+SPACE+5);
    }
}

void linkList::busyUiState() {
    ui->initButton->setEnabled(false);
    ui->clearButton->setEnabled(false);

    ui->insertButton->setEnabled(false);
    ui->insertNumberEdit->setEnabled(false);
    ui->insertComboBox->setEnabled(false);

    ui->deleteComboBox->setEnabled(false);
    ui->deleteButton->setEnabled(false);

    ui->searchNumberEdit->setEnabled(false);
    ui->searchButton->setEnabled(false);
    ui->searchResultEdit->setEnabled(false);

    ui->statusEdit->setEnabled(false);

    ui->insertNumberEdit->setPlaceholderText("插入值：int类型");
    ui->searchNumberEdit->setPlaceholderText("查找值：int类型");

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请等待...");
}

void linkList::recoveryUi() {
    ui->initButton->setEnabled(true);
    ui->clearButton->setEnabled(true);

    ui->insertButton->setEnabled(true);
    ui->insertNumberEdit->setEnabled(true);
    ui->insertComboBox->setEnabled(true);

    ui->searchNumberEdit->setEnabled(true);
    ui->searchButton->setEnabled(true);

    adjustControlPanel();
}

void linkList::clearAll() {
    if (!m_scene) {
        return;
    }

    linkNode *pNode = m_head;
    linkNode *qNode = m_head;

    while (pNode) {
        sleep(SLEEP_TIME);
        qNode = pNode->m_next;
        pNode->clearAll(m_scene);   // 移除所有节点的图形项
        delete pNode;               // 释放节点内存
        pNode = qNode;
    }

    sleep(SLEEP_TIME);

    // 移除头节点，释放内存
    m_scene->removeItem(m_headLabel);
    m_scene->removeItem(m_headArrow);
    delete m_headLabel;
    delete m_headArrow;

    // 移除scene，释放内存
    m_scene = nullptr;

    m_nodeCnt = 0;      // 节点数置零
}

void linkList::insertLinkNode(int idx, QString data) {
    linkNode *pInsertNode = nullptr;
    linkNode *qNode = m_head;

    qNode->setNodeSatus(linkList::m_visitedBrush);

    for (int i = 0; i < idx-1; ++i) {
        sleep(SLEEP_TIME);

        qNode = qNode->m_next;
        qNode->setNodeSatus(linkList::m_visitedBrush);
    }

    sleep(SLEEP_TIME);

    if (!qNode->m_next) {
        m_scene->removeItem(qNode->m_pointerText);
        qNode->m_pointerText = nullptr;
    }

    // 添加节点
    pInsertNode = new linkNode(data, qNode->m_next);
    qNode->m_next = pInsertNode;
    ++m_nodeCnt;

    // 添加节点图形项
    addLinkNodeGraphicsItem(pInsertNode, getLinkNodePos(idx));

    idx -= 1;
    while (idx <= m_nodeCnt) {
        sleep(SLEEP_TIME);

        adjustLinkNodePos(qNode, getLinkNodePos(idx));
        adjustLinkNodeArrow(qNode, idx);
        qNode = qNode->m_next;

        ++idx;
    }
}

void linkList::deleteLinkNode(int idx) {
    linkNode *pDeleteNode = nullptr;
    linkNode *pNode = m_head;

    pNode->setNodeSatus(linkList::m_visitedBrush);

    for (int i = 0; i < idx-1; ++i) {
        sleep(SLEEP_TIME);
        pNode = pNode->m_next;
        pNode->setNodeSatus(linkList::m_visitedBrush);
    }

    sleep(SLEEP_TIME);

    pDeleteNode = pNode->m_next;
    pNode->m_next = pDeleteNode->m_next;
    pDeleteNode->clearAll(m_scene);
    delete pDeleteNode;
    --m_nodeCnt;

    if (!pNode->m_next) {
        QPoint p = getLinkNodePos(idx-1);
        pNode->m_pointerText = m_scene->addText(" ^", linkList::m_dataFont);
        pNode->m_pointerText->setPos(p.x()+DATA_RECT_WIDTH, p.y()+SPACE+5);
    }

    idx -= 1;
    while (idx <= m_nodeCnt) {
        sleep(SLEEP_TIME);
        adjustLinkNodePos(pNode, getLinkNodePos(idx));
        adjustLinkNodeArrow(pNode, idx);
        pNode = pNode->m_next;
        ++idx;
    }
}

int linkList::searchLinkNode(QString data) {
    int res = -1;

    linkNode *pNode = m_head;
    pNode->setNodeSatus(linkList::m_visitedBrush);

    int i = 0;
    while (pNode) {
        sleep(SLEEP_TIME);

        if (pNode->m_data == data) {
            pNode->setNodeSatus(linkList::m_markBrush);
            res = i;
            break;
        }
        else {
            pNode->setNodeSatus(linkList::m_visitedBrush);
            i++;
        }

        pNode = pNode->m_next;
    }
    return res;
}

void linkList::adjustControlPanel() {
    // 根据节点数量设定删除按钮的可用性
    ui->deleteButton->setEnabled(m_nodeCnt);
    ui->deleteComboBox->setEnabled(m_nodeCnt);



    if (m_nodeCnt != ui->deleteComboBox->count()) {
        ui->insertComboBox->clear();
        ui->deleteComboBox->clear();

        for (int i = 1; i <= m_nodeCnt; ++i) {
            ui->insertComboBox->addItem(QString::number(i));
            ui->deleteComboBox->addItem(QString::number(i));
        }
    }

    if ((m_nodeCnt+1) != ui->insertComboBox->count()) {
        ui->insertComboBox->addItem(QString::number(m_nodeCnt+1));
    }

}

void linkList::adjustLinkNodeArrow(linkNode *pNode, int idx) {
    for (auto &a : pNode->m_arrows) {
        m_scene->removeItem(a);
    }
    pNode->m_arrows.clear();

    if (!pNode->m_next) {
        return;
    }

    QPoint coord0 = getLinkNodePos(idx);
    QPoint coord1 = getLinkNodePos(idx+1);

    Arrow *pArrow;

    if (coord0.y() == coord1.y()) {
        // 该节点和后一节点在同一行
        pArrow = new Arrow(ARROW_LENGTH);
        pArrow->draw();
        m_scene->addItem(pArrow);
        pArrow->setPos(coord0.x()+ARROW_H_OFFSET, coord0.y()+ARROW_V_OFFSET);
        pNode->m_arrows.push_back(pArrow);
    }
    else {
        // 下一节点在下一行
        QPoint p1(coord0.x()+ARROW_H_OFFSET, coord0.y()+ARROW_V_OFFSET);
        QPoint p2(p1.x(), p1.y()+NODE_HEIGHT/2);
        QPoint p3(DATA_RECT_WIDTH >> 1, p2.y());

        pArrow = new Arrow(NODE_HEIGHT>>1, 2, false);
        pArrow->draw();
        m_scene->addItem(pArrow);
        pArrow->setPos(p1);
        pNode->m_arrows.push_back(pArrow);

        pArrow = new Arrow(p2.x()-p3.x(), 3, false);
        pArrow->draw();
        m_scene->addItem(pArrow);
        pArrow->setPos(p2);
        pNode->m_arrows.push_back(pArrow);

        pArrow = new Arrow(SPACE, 2);
        pArrow->draw();
        m_scene->addItem(pArrow);
        pArrow->setPos(p3);
        pNode->m_arrows.push_back(pArrow);
    }

}

void linkList::adjustLinkNodePos(linkNode *pNode, QPoint p) {
    int x = p.x();
    int y = p.y();

    pNode->m_dataRect->setRect(x, y+SPACE, DATA_RECT_WIDTH, RECT_HEIGHT);
    pNode->m_pointerRect->setRect(x+DATA_RECT_WIDTH, y+SPACE, POINTER_RECT_WIDTH, RECT_HEIGHT);
    pNode->m_dataText->setPos(x, y+SPACE+5);

    if (pNode->m_pointerText) {
        pNode->m_pointerText->setPos(x+DATA_RECT_WIDTH, y+SPACE);
    }
}

void linkList::on_initButton_clicked() {
    busyUiState();
    clearAll(); // 若已经建立单链表，则清理之后重建。

    initLinkList();

    // 初始化后添加三个随机节点
    for (int i = 1; i <= 3; ++i) {
        int x = static_cast<int>(rand() * RAND_MAX);
        insertLinkNode(1, QString::number(x));
    }

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();

    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("创建成功!");
}

void linkList::on_clearButton_clicked() {
    busyUiState();
    clearAll();

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    initUi();
}

void linkList::on_insertButton_clicked() {
    busyUiState();
    setLinkListNormalBrush();

    QString s = ui->insertNumberEdit->text();
    if (s.isEmpty()) {
        ui->statusEdit->setPalette(Qt::GlobalColor::red);
        ui->statusEdit->setText("请给即将插入的节点赋值！");
        recoveryUi();
        return;
    }

    insertLinkNode(ui->insertComboBox->currentText().toInt(), s);

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();

    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("插入节点成功！");
}

void linkList::on_deleteButton_clicked()
{
    busyUiState();

    setLinkListNormalBrush();
    sleep(SLEEP_TIME);

    deleteLinkNode(ui->deleteComboBox->currentText().toInt());

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();

    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("删除节点成功");
}

void linkList::on_searchButton_clicked()
{
    busyUiState();

    setLinkListNormalBrush();
    sleep(SLEEP_TIME);

    QString data = ui->searchNumberEdit->text();

    if (data.isEmpty()) {
        ui->statusEdit->setPalette(Qt::GlobalColor::red);
        ui->statusEdit->setText("查询失败！");
        ui->searchResultEdit->setText("请给出需要查询的数值。");
        recoveryUi();
        return;
    }

    int idx = searchLinkNode(data);
    if (idx == -1) {
        ui->statusEdit->setPalette(Qt::GlobalColor::red);
        ui->statusEdit->setText("查询失败！");
        ui->searchResultEdit->setText("没有该节点。");
    }
    else {
        ui->statusEdit->setPalette(Qt::GlobalColor::green);
        ui->statusEdit->setText("查询成功！");
        QString res = QString("第一个符合的节点是第") + QString::number(idx) + QString("节点。");
        ui->searchResultEdit->setText(res);
    }

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();
}
