#include <QDebug>
#include "infix2suffix.h"
#include "ui_infix2suffix.h"
#pragma execution_character_set("utf-8")
#include<QTime>
void sleep(unsigned int msec)
{
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
        QApplication::processEvents(QEventLoop::AllEvents,100);
}



const QBrush Infix2Suffix::m_normalBursh = QBrush(Qt::GlobalColor::darkGray);
const QBrush Infix2Suffix::m_markBrush = QBrush(Qt::GlobalColor::white);

const QFont Infix2Suffix::m_arrowLabelFont = QFont("Consolas");
const QFont Infix2Suffix::m_dataFont = QFont("Consolas",8);

const int SCENE_MAX_WIDTH = 500;  // 场景最大宽度
const int SCENE_MAX_HEIGHT = 100000; // 场景最大高度

const int RECT_HEIGHT = 30;    // 节点高度
const int RECT_WIDTH = 100;    // 节点宽度

const int SPACE = 10;   // 间距
const int NODE_HEIGHT = RECT_HEIGHT;

const int ARROW_LENGTH = 25;        // 默认箭头长度
const int ARROW_LABEL_WIDTH = 50;
const int ARROW_V_OFFSET = SPACE + RECT_HEIGHT / 2; // 箭头距离节点图形起始坐标垂直偏移

const int RES_START_X = SPACE*3+ARROW_LABEL_WIDTH+ARROW_LENGTH+RECT_WIDTH; // 结果栏的起始横坐标

const int SLEEP_TIME = 300;
#include<QFile>
Infix2Suffix::Infix2Suffix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Infix2Suffix)
{
    ui->setupUi(this);
    ui->vSplitter->setStretchFactor(0, 8);
    ui->vSplitter->setStretchFactor(1, 5);
    ui->hSplitter->setStretchFactor(0, 3);
    ui->hSplitter->setStretchFactor(1, 7);

    m_scene = nullptr;
    m_stackHead = nullptr;
    m_resHead = nullptr;
    m_topLabel = nullptr;
    m_topArrow = nullptr;
    m_validater = new mathExpValidator();

    initUi();
}

Infix2Suffix::~Infix2Suffix()
{
    delete m_validater;
    delete ui;
}

void Infix2Suffix::initUi() {
    ui->convertButton->setEnabled(true);
    ui->clearButton->setEnabled(false);

    ui->infixEdit->setEnabled(true);
    ui->infixEdit->clear();
    // ui->infixEdit->setPlaceholderText("请输入中缀表达式（仅限四则运算及括号）.");
    ui->suffixEdit->setEnabled(false);
    ui->suffixEdit->clear();
    ui->statusEdit->setEnabled(false);

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请输入中缀表达式(默认输入为有效的四则运算式)，然后点击转换按钮.");
}

void Infix2Suffix::initSceneView() {
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0, 0, SCENE_MAX_WIDTH, SCENE_MAX_HEIGHT);
    ui->graphicsView->setScene(m_scene);
}

void Infix2Suffix::busyUistate() {
    ui->convertButton->setEnabled(false);
    ui->clearButton->setEnabled(false);

    ui->infixEdit->setEnabled(false);
    ui->suffixEdit->setEnabled(false);
    ui->suffixEdit->clear();

    ui->statusEdit->setPalette(Qt::GlobalColor::darkGray);
    ui->statusEdit->setText("请稍等...");
}

void Infix2Suffix::recoveryUi() {
    ui->convertButton->setEnabled(true);
    ui->clearButton->setEnabled(true);

    ui->infixEdit->setEnabled(true);
}

void Infix2Suffix::setNormalBrush() {
    for (StackNode *pNode : m_queue) {
        pNode->setNodeStatus(Infix2Suffix::m_normalBursh);
    }
    for (StackNode *pNode : m_stack) {
        pNode->setNodeStatus(Infix2Suffix::m_normalBursh);
    }
}

void Infix2Suffix::clearAll() {
    if (!m_scene) {
        return;
    }

    m_stackHead->clearAll(m_scene);
    delete m_stackHead;
    m_stackHead = nullptr;

    m_resHead->clearAll(m_scene);
    delete m_resHead;
    m_resHead = nullptr;

    m_scene->removeItem(m_topLabel);
    delete m_topLabel;
    m_topLabel = nullptr;
    m_scene->removeItem(m_topArrow);
    delete m_topArrow;
    m_topArrow = nullptr;

    for (StackNode * pNode : m_stack) {
        pNode->clearAll(m_scene);
    }
    m_stack.clear();

    for (StackNode * pNode : m_queue ) {
        pNode->clearAll(m_scene);
    }
    m_queue.clear();

    m_scene = nullptr;
}

void Infix2Suffix::adjustStackNodePos(StackNode *pNode, bool isDown) {
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

QPoint Infix2Suffix::getTopElemPos() {
    return QPoint(SPACE+ARROW_LABEL_WIDTH+ARROW_LENGTH, 0);
}

void Infix2Suffix::addStackNodeGraphicsItem(StackNode *pNode, QPoint p) {
    int x = p.x();
    int y = p.y();

    pNode->setDataRect(m_scene->addRect(x, y+SPACE, RECT_WIDTH, RECT_HEIGHT, QPen(), m_markBrush));
    pNode->setDataText(m_scene->addText(pNode->m_data, m_dataFont));
    pNode->m_dataText->setPos(x, y+SPACE+5);
}

void Infix2Suffix::stackPush(QString data) {
    setNormalBrush();

    adjustStackNodePos(m_stackHead, true);
    for (StackNode *a : m_stack) {
        adjustStackNodePos(a, true);
    }
    StackNode *pNode = new StackNode(data);
    addStackNodeGraphicsItem(pNode, getTopElemPos());
    m_stack.push_back(pNode);
}

void Infix2Suffix::stackPop() {
    setNormalBrush();

    StackNode *pNode = stackTop();
    pNode->clearAll(m_scene);
    m_stack.pop_back();
    int nodeNum = static_cast<int>(m_stack.size());
    for (int i = nodeNum-1; i >= 0; --i) {
        pNode = m_stack[i];
        adjustStackNodePos(pNode, false);
    }
    adjustStackNodePos(m_stackHead, false);
}

StackNode *Infix2Suffix::stackTop() {
    int nodeNum = static_cast<int>(m_stack.size());
    StackNode *pNode = m_stack[nodeNum-1];
    return pNode;
}

bool Infix2Suffix::stackEmpty() {
    if (m_stack.size() == 0) {
        return true;
    }
    return false;
}

void Infix2Suffix::startConvert(const std::vector<std::string> &wordList) {
    busyUistate();
    clearAll();
    initSceneView();
    initQueue();

    m_topLabel = m_scene->addText("top", m_arrowLabelFont);
    m_topLabel->setPos(SPACE, SPACE);
    m_topArrow = new Arrow(ARROW_LENGTH, 1);
    m_topArrow->draw();
    m_scene->addItem(m_topArrow);
    m_topArrow->setPos(SPACE+ARROW_LABEL_WIDTH, ARROW_V_OFFSET);

    m_stackHead = new StackNode("操作符栈");
    addStackNodeGraphicsItem(m_stackHead, getTopElemPos());

    for (auto &word : wordList) {
        QString data = QString::fromStdString(word);
        if (word == "(") {
            stackPush(data);
        }
        else if (word == "+" || word == "-" || word == "*" ||word == "/") {
            if (stackEmpty()) {
                // 如果操作符栈为空，则直接压栈
                stackPush(data);
            }
            else {
                // 否则与操作符栈中的运算符比较
                while (!stackEmpty()) {
                    sleep(SLEEP_TIME);
                    StackNode *pNode = stackTop();
                    if (op[word] > op[pNode->m_data.toStdString()]) {
                        // 如果该运算符的优先级大于栈顶运算符的优先级时，将其压栈。并结束
                        stackPush(data);
                        break;
                    }
                    else {
                        // 如果该运算符的优先级不大于栈顶运算符的优先级时，将栈顶运算符弹出并输出，接着和新的栈顶运算符比较小于，继续将栈顶运算符弹出并输出.
                        enQueue(pNode->m_data);
                        stackPop();
                        if (stackEmpty()) {
                            stackPush(data);
                            break;
                        }
                    }
                }
            }
        }
        else if (word == ")") {
            // 若遇到右括号，表达括号内的中缀表达式已经扫描完毕。
            while (!stackEmpty()) {
                sleep(SLEEP_TIME);
                StackNode *pNode = stackTop();
                if (pNode->m_data == "(") {
                    // 遇到左括号弹出但不输出，然后停止弹出
                    stackPop();
                    break;
                }
                else {
                    // 其他情况弹出并输出
                    enQueue(pNode->m_data);
                    stackPop();
                }
            }
        }
        else {
            // 遇到数字直接输出
            enQueue(data);
        }
        sleep(SLEEP_TIME);
    }

    while (!stackEmpty()) {
        printf("%d\n", m_stack.size());
        StackNode *pNode = stackTop();
        sleep(SLEEP_TIME);
        enQueue(pNode->m_data);
        stackPop();
    }
}

QPoint Infix2Suffix::getQueueNodePos(int idx) {
    return QPoint(RES_START_X, idx*NODE_HEIGHT);
}

void Infix2Suffix::initQueue() {
    m_rear = -1;
    m_front = -1;

    m_resHead = new StackNode("结果队列");
    addStackNodeGraphicsItem(m_resHead, getQueueNodePos(0));
}

void Infix2Suffix::enQueue(QString data) {
    setNormalBrush();

    int idx = static_cast<int>(m_queue.size());
    StackNode *pNode = new StackNode(data);
    m_rear = idx;
    m_queue.push_back(pNode);
    QPoint node_pos = getQueueNodePos(idx+1);
    sleep(SLEEP_TIME);
    addStackNodeGraphicsItem(pNode, node_pos);
}

void Infix2Suffix::on_convertButton_clicked()
{
    ui->suffixEdit->setText("");

    QString s = ui->infixEdit->text();
    if (s.isEmpty()) {
        ui->statusEdit->setPalette(Qt::GlobalColor::red);
        ui->statusEdit->setText("输入为空，请重新输入！");
    }
    else {
        // 词法分析，得到词列表
        bool err = m_validater->word_analysis(s.toStdString());
        // if (err) // 取消，不做判断。
        std::vector<std::string> wordList = m_validater->getWordList();

        startConvert(wordList);

        // 在此处将准备好的伪代码添加到伪代码窗口
        // ui->textBrowser->setText("伪代码");

        recoveryUi();
        QString res;
        for (StackNode *pNode : m_queue) {
            res = res + pNode->m_data + " ";
        }
        ui->suffixEdit->setText(res);
        ui->statusEdit->setPalette(Qt::GlobalColor::green);
        ui->statusEdit->setText("转换成功！");
    }
}

void Infix2Suffix::on_clearButton_clicked()
{
    busyUistate();
    clearAll();
    initUi();
}
