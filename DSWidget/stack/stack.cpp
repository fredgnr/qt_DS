#include <QDebug>
#include "stack.h"
#include "ui_stack.h"
#pragma execution_character_set("utf-8")
#include<QTime>
#include<QFile>
void sleep(unsigned int msec);

const QBrush Stack::m_normalBursh = QBrush(Qt::GlobalColor::darkGray);
const QBrush Stack::m_markBrush = QBrush(Qt::GlobalColor::white);

const QFont Stack::m_arrowLabelFont = QFont("Consolas");
const QFont Stack::m_dataFont = QFont("Consolas",8);

const int MAX_STACK_SIZE = 1000;  // 栈最大容量
const int SCENE_MAX_WIDTH = 300;  // 场景最大宽度
const int SCENE_MAX_HEIGHT = 100000; // 场景最大高度

const int RECT_HEIGHT = 30;    // 节点高度
const int RECT_WIDTH = 100;    // 节点宽度

const int SPACE = 10;   // 间距
const int NODE_HEIGHT = RECT_HEIGHT;

const int ARROW_LENGTH = 25;        // 默认箭头长度
const int ARROW_LABEL_WIDTH = 50;
const int ARROW_V_OFFSET = SPACE + RECT_HEIGHT / 2; // 箭头距离节点图形起始坐标垂直偏移

const int SLEEP_TIME = 10;


Stack::Stack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stack)
{
    ui->setupUi(this);

    ui->vSplitter->setStretchFactor(0, 3);
    ui->vSplitter->setStretchFactor(1, 7);
    ui->hSplitter->setStretchFactor(0, 8);
    ui->hSplitter->setStretchFactor(1, 5);
    QFile qss("mystyle.qss");
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
    m_scene = nullptr;
    m_head = nullptr;
    m_topLabel = nullptr;
    m_topArrow = nullptr;

    m_stack.reserve(MAX_STACK_SIZE);
    m_stack.clear();

    initUi();
}

Stack::~Stack()
{
    clearAll();
    delete ui;
}

void Stack::clearAll() {
    if (!m_scene) {
        return;
    }

    m_head->clearAll(m_scene);
    delete m_head;
    m_head = nullptr;

    m_scene->removeItem(m_topLabel);
    delete m_topLabel;
    m_topLabel = nullptr;
    m_scene->removeItem(m_topArrow);
    delete m_topArrow;
    m_topArrow = nullptr;

    for (StackNode * pNode : m_stack) {
        sleep(SLEEP_TIME);
        pNode->clearAll(m_scene);
    }
    m_stack.clear();

    m_scene = nullptr;
}

void Stack::initUi() {
    // 刚打开时，只有创建/初始化按钮可用
    ui->initButton->setEnabled(true);

    ui->clearButton->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->popButton->setEnabled(false);

    ui->pushEdit->setEnabled(false);
    ui->pushEdit->setPlaceholderText("输入值：int类型");

    ui->statusEdit->setEnabled(false);

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请创建一个顺序栈.");
}

void Stack::initSceneView() {
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0, 0, SCENE_MAX_WIDTH, SCENE_MAX_HEIGHT);
    ui->graphicsView->setScene(m_scene);
}

void Stack::busyUistate() {
    ui->initButton->setEnabled(false);
    ui->clearButton->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->popButton->setEnabled(false);
    ui->pushEdit->setEnabled(false);

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请稍等...");
}

void Stack::recoveryUi() {
    ui->initButton->setEnabled(true);
    ui->clearButton->setEnabled(true);

    ui->pushButton->setEnabled(true);
    ui->pushEdit->setEnabled(true);

    adjustControlPanel();
}

void Stack::adjustControlPanel() {
    int nodeNum = static_cast<int>(m_stack.size());
    ui->popButton->setEnabled(nodeNum);
}

void Stack::setStackNormalBrush() {
    for (StackNode *pNode : m_stack) {
        pNode->setNodeStatus(Stack::m_normalBursh);
    }
}

QPoint Stack::getTopElemPos() {
    return QPoint(SPACE+ARROW_LABEL_WIDTH+ARROW_LENGTH, 0);
}

void Stack::addStackNodeGraphicsItem(StackNode *pNode, QPoint p) {
    int x = p.x();
    int y = p.y();

    pNode->setDataRect(m_scene->addRect(x, y+SPACE, RECT_WIDTH, RECT_HEIGHT, QPen(), m_markBrush));
    pNode->setDataText(m_scene->addText(pNode->m_data, m_dataFont));
    pNode->m_dataText->setPos(x, y+SPACE+5);
}

void Stack::adjustStackNodePos(StackNode *pNode, bool isDown) {
    QRectF dataRect0 = pNode->m_dataRect->rect();
    QPointF dataTextP0 = pNode->m_dataText->pos();
    QPoint dataRectP0 = QPoint(static_cast<int>(dataRect0.x()), static_cast<int>(dataRect0.y()));

    if (isDown) {
        // 往下调整
        pNode->m_dataRect->setRect(dataRectP0.x(), dataRectP0.y()+NODE_HEIGHT, dataRect0.width(), dataRect0.height());
        pNode->m_dataText->setPos(static_cast<int>(dataTextP0.x()), static_cast<int>(dataTextP0.y())+NODE_HEIGHT);
    }
    else {
        // 往上调整
        pNode->m_dataRect->setRect(dataRectP0.x(), dataRectP0.y()-NODE_HEIGHT, dataRect0.width(), dataRect0.height());
        pNode->m_dataText->setPos(static_cast<int>(dataTextP0.x()), static_cast<int>(dataTextP0.y())-NODE_HEIGHT);
    }
}

void Stack::initStack() {
    initSceneView();

    m_topLabel = m_scene->addText("top", m_arrowLabelFont);
    m_topLabel->setPos(SPACE, SPACE);
    m_topArrow = new Arrow(ARROW_LENGTH, 1);
    m_topArrow->draw();
    m_scene->addItem(m_topArrow);
    m_topArrow->setPos(SPACE+ARROW_LABEL_WIDTH, ARROW_V_OFFSET);

    m_head = new StackNode("顺序栈");
    addStackNodeGraphicsItem(m_head, getTopElemPos());
}

void Stack::push(QString data) {
    sleep(SLEEP_TIME);
    adjustStackNodePos(m_head, true);
    for (StackNode *a : m_stack) {
        sleep(SLEEP_TIME);
        adjustStackNodePos(a, true);
    }
    StackNode *pNode = new StackNode(data);
    addStackNodeGraphicsItem(pNode, getTopElemPos());
    m_stack.push_back(pNode);
}

void Stack::pop() {
    int nodeNum = static_cast<int>(m_stack.size());
    StackNode *pNode = m_stack[nodeNum-1];
    pNode->clearAll(m_scene);
    m_stack.pop_back();
    nodeNum--;
    for (int i = nodeNum-1; i >= 0; --i) {
        sleep(SLEEP_TIME);
        pNode = m_stack[i];
        adjustStackNodePos(pNode, false);
    }
    adjustStackNodePos(m_head, false);
}

void Stack::on_initButton_clicked()
{
    busyUistate();
    clearAll();
    initStack();

    // 初始化后添加三个随机节点
    for (int i = 1; i <= 3; ++i) {
        int x = static_cast<int>(rand() * RAND_MAX);
        push(QString::number(x));
    }

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();
    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("创建成功！");
}

void Stack::on_clearButton_clicked()
{
    busyUistate();
    clearAll();

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    initUi();
}

void Stack::on_pushButton_clicked()
{
    busyUistate();
    setStackNormalBrush();
    QString s = ui->pushEdit->text();
    if (s.isEmpty()) {
        ui->statusEdit->setPalette(Qt::GlobalColor::red);
        ui->statusEdit->setText("请给即将入栈的元素赋值！");
        recoveryUi();
        return;
    }
    push(s);

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();

    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("入栈成功！");
}


void Stack::on_popButton_clicked()
{
    busyUistate();
    pop();

    // 在此处将准备好的伪代码添加到伪代码窗口
    // ui->textBrowser->setText("伪代码");

    recoveryUi();
    ui->statusEdit->setPalette(Qt::GlobalColor::green);
    ui->statusEdit->setText("出栈成功！");
}
