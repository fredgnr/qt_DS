#include <QDebug>
#include "queue.h"
#include "ui_queue.h"
#include<QTime>
void sleep(unsigned int msec);
#include<QFile>

const QBrush Queue::m_normalBursh = QBrush(Qt::GlobalColor::darkGray);
const QBrush Queue::m_markBrush = QBrush(Qt::GlobalColor::white);

const QFont Queue::m_arrowLabelFont = QFont("Consolas");
const QFont Queue::m_dataFont = QFont("Consolas",8);


const int MAX_QUEUE_SIZE = 1000;    // 队列最大容量
const int SCENE_MAX_WIDTH = 300;  // 场景最大宽度
const int SCENE_MAX_HEIGHT = 100000; // 场景最大高度

const int RECT_HEIGHT = 30;         // 节点高度
const int DATA_RECT_WIDTH = 80;     // 数据宽度
const int INDEX_RECT_WIDTH = 40;    // 索引宽度
const int SPACE = 10;               // 间距

const int NODE_HEIGHT = RECT_HEIGHT;
const int ARROW_LENGTH = 25;        // 默认箭头长度
const int ARROW_LABEL_WIDTH = 50;
const int ARROW_H_OFFSET = DATA_RECT_WIDTH + INDEX_RECT_WIDTH;  // 箭头距离节点图形起始坐标水平偏移
const int ARROW_V_OFFSET = SPACE + RECT_HEIGHT / 2;             // 箭头距离节点图形起始坐标垂直偏移

const int SLEEP_TIME = 10;


Queue::Queue(QWidget *parent) :
    QWidget(parent), ui(new Ui::Queue) {
    ui->setupUi(this);

    ui->vSplitter->setStretchFactor(0, 3);
    ui->vSplitter->setStretchFactor(1, 7);
    ui->hSplitter->setStretchFactor(0, 8);
    ui->hSplitter->setStretchFactor(1, 5);

    m_scene = nullptr;
    m_frontLabel = nullptr;
    m_frontArrow = nullptr;
    m_rearLabel = nullptr;
    m_rearArrow = nullptr;
    m_head = nullptr;

    m_queue.reserve(MAX_QUEUE_SIZE);
    m_queue.clear();
    initUi();
}

Queue::~Queue() {
    clearAll();
    delete ui;
}

void Queue::initSceneView() {
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0, 0, SCENE_MAX_WIDTH, SCENE_MAX_HEIGHT);
    ui->graphicsView->setScene(m_scene);
}

QPoint Queue::getQueueNodePos(int idx) {
    return QPoint(SPACE+ARROW_LABEL_WIDTH+ARROW_LENGTH, idx*NODE_HEIGHT);
}

void Queue::addQueueNodeGraphicsItem(QueueNode *pNode, QPoint p) {
    int x = p.x();
    int y = p.y();
    pNode->setDataRect(m_scene->addRect(x, y+SPACE, DATA_RECT_WIDTH, RECT_HEIGHT, QPen(), m_markBrush));
    pNode->setIndexRect(m_scene->addRect(x+DATA_RECT_WIDTH, y+SPACE, INDEX_RECT_WIDTH, RECT_HEIGHT));

    pNode->setDataText(m_scene->addText(pNode->m_data, m_dataFont));
    pNode->m_dataText->setPos(x, y+SPACE+5);

    pNode->setIndexText(m_scene->addText(QString::number(pNode->m_index), m_dataFont));
    pNode->m_indexText->setPos(x+DATA_RECT_WIDTH+5, y+SPACE+5);
}

void Queue::adjustQueueNodePos(QueueNode *pNode, int idx) {
    QPoint p = getQueueNodePos(idx);
    int x = p.x();
    int y = p.y();
    pNode->m_dataRect->setRect(x, y+SPACE, DATA_RECT_WIDTH, RECT_HEIGHT);
    pNode->m_indexRect->setRect(x+DATA_RECT_WIDTH, y+SPACE, INDEX_RECT_WIDTH, RECT_HEIGHT);
    pNode->m_dataText->setPos(x, y+SPACE+5);
    m_scene->removeItem(pNode->m_indexText);
    pNode->setIndexText(m_scene->addText(QString::number(pNode->m_index), m_dataFont));
    pNode->m_indexText->setPos(x+DATA_RECT_WIDTH+5, y+SPACE+5);
}

void Queue::initUi() {
    // 刚打开时，只有创建/初始化按钮可用
    ui->initButton->setEnabled(true);

    ui->clearButton->setEnabled(false);
    ui->enQueueButton->setEnabled(false);
    ui->deQueueButton->setEnabled(false);

    ui->enQueueEdit->setEnabled(false);
    ui->enQueueEdit->setPlaceholderText("输入值：int类型");

    ui->statusEdit->setEnabled(false);

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请创建一个顺序队列.");
}

void Queue::busyUistate() {
    ui->initButton->setEnabled(false);
    ui->clearButton->setEnabled(false);

    ui->enQueueButton->setEnabled(false);
    ui->deQueueButton->setEnabled(false);
    ui->enQueueEdit->setEnabled(false);

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请稍等...");
}

void Queue::recoveryUi() {
    ui->initButton->setEnabled(true);
    ui->clearButton->setEnabled(true);

    ui->enQueueButton->setEnabled(true);
    ui->enQueueEdit->setEnabled(true);

    adjustControlPanel();
}

void Queue::adjustControlPanel() {
    int nodeNum = static_cast<int>(m_queue.size());
    ui->deQueueButton->setEnabled(nodeNum);
}

void Queue::setQueueNormalBrush() {
    for (QueueNode *pNode : m_queue) {
        pNode->setNodeStatus(Queue::m_normalBursh);
    }
}

void Queue::clearAll() {
    if (!m_scene) {
        return;
    }

    m_head->clearAll(m_scene);
    delete m_head;
    m_head = nullptr;

    m_scene->removeItem(m_rearLabel);
    delete m_rearLabel;
    m_rearLabel = nullptr;
    m_scene->removeItem(m_frontLabel);
    delete m_frontLabel;
    m_frontLabel = nullptr;
    m_scene->removeItem(m_rearArrow);
    delete m_rearArrow;
    m_rearArrow = nullptr;
    m_scene->removeItem(m_frontArrow);
    delete m_frontArrow;
    m_frontArrow = nullptr;

    for (QueueNode *a : m_queue) {
        sleep(SLEEP_TIME);
        a->clearAll(m_scene);
    }
    m_queue.clear();

    m_scene = nullptr;
}

void Queue::updateRearArrow() {
    if (m_rear == -1) {
        m_rearLabel->setPos(SPACE, SPACE*2);
        m_rearArrow->setPos(SPACE+ARROW_LABEL_WIDTH, ARROW_V_OFFSET+SPACE);
    }
    else {
        QPoint p = getQueueNodePos(m_rear+1);
        int y = p.y();
        m_rearLabel->setPos(SPACE, y+SPACE);
        m_rearArrow->setPos(SPACE+ARROW_LABEL_WIDTH, y+ARROW_V_OFFSET);
    }
}

void Queue::initQueue() {
    initSceneView();

    m_rear = -1;
    m_front = -1;

    m_frontLabel = m_scene->addText("front", m_arrowLabelFont);
    m_frontLabel->setPos(SPACE, SPACE);
    m_frontArrow = new Arrow(ARROW_LENGTH, 1);
    m_frontArrow->draw();
    m_scene->addItem(m_frontArrow);
    m_frontArrow->setPos(SPACE+ARROW_LABEL_WIDTH, ARROW_V_OFFSET);

    m_rearArrow = new Arrow(ARROW_LENGTH, 1);
    m_rearArrow->draw();
    m_scene->addItem(m_rearArrow);
    m_rearArrow->setPos(SPACE+ARROW_LABEL_WIDTH, ARROW_V_OFFSET+SPACE);
    m_rearLabel = m_scene->addText("rear", m_arrowLabelFont);
    m_rearLabel->setPos(SPACE, SPACE*2);

    m_head = new QueueNode("顺序队列", -1);
    addQueueNodeGraphicsItem(m_head, getQueueNodePos(0));
}

void Queue::enQueue(QString data) {
    int idx = static_cast<int>(m_queue.size());
    QueueNode *pNode = new QueueNode(data, idx);
    m_rear = idx;
    m_queue.push_back(pNode);
    QPoint node_pos = getQueueNodePos(idx+1);
    sleep(SLEEP_TIME);
    addQueueNodeGraphicsItem(pNode, node_pos);
    updateRearArrow();
}

void Queue::deQueue() {
    QueueNode *pNode = m_queue[0];
    pNode->clearAll(m_scene);
    m_queue.erase(m_queue.begin());
    int nodeNum = static_cast<int>(m_queue.size());
    m_rear = nodeNum-1;
    for (int i = 0; i < nodeNum; ++i) {
        sleep(SLEEP_TIME);
        pNode = m_queue[i];
        pNode->m_index = i;
        adjustQueueNodePos(pNode, i+1);
    }
    updateRearArrow();
}

void Queue::on_initButton_clicked()
{
    busyUistate();
    clearAll();
    initQueue();

    // 初始化后添加三个随机节点
    for (int i = 1; i <= 3; ++i) {
        int x = static_cast<int>(rand() * RAND_MAX);
        enQueue(QString::number(x));
    }

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();
    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("创建成功！");
}

void Queue::on_clearButton_clicked()
{
    busyUistate();
    clearAll();

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    initUi();
}

void Queue::on_enQueueButton_clicked()
{
    busyUistate();
    setQueueNormalBrush();

    QString s = ui->enQueueEdit->text();
    if (s.isEmpty()) {
        ui->statusEdit->setPalette(Qt::GlobalColor::red);
        ui->statusEdit->setText("请给即将入队的元素赋值！");
        recoveryUi();
        return;
    }
    enQueue(s);

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();

    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("入队成功！");
}

void Queue::on_deQueueButton_clicked()
{
    busyUistate();
    deQueue();

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();
    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("出队成功！");
}
