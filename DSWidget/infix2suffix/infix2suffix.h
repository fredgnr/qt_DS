#ifndef INFIX2SUFFIX_H
#define INFIX2SUFFIX_H

#include <QWidget>
#include "stacknode.h"
#include "utils/arrow.h"
#include "utils/mathExpValidator.h"

namespace Ui {
class Infix2Suffix;
}

class Infix2Suffix : public QWidget
{
    Q_OBJECT

public:
    explicit Infix2Suffix(QWidget *parent = 0);
    ~Infix2Suffix();

private slots:
    void on_convertButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::Infix2Suffix *ui;

    QGraphicsScene *m_scene;
    std::vector<StackNode *> m_stack;   // 模拟栈
    std::vector<StackNode *> m_queue;   // 模拟存放结果的队列

    StackNode *m_stackHead;
    QGraphicsTextItem *m_topLabel;
    Arrow *m_topArrow;

    int m_rear;
    int m_front;

    StackNode *m_resHead;

    std::map<std::string, int> op = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2},
        {"(", 0}
    };

    mathExpValidator *m_validater; //验证中缀表达式是否合法

    const static QBrush m_normalBursh, m_markBrush;
    const static QFont m_arrowLabelFont, m_dataFont;

    void initUi();
    void initSceneView();
    void busyUistate();     // 动画过程中，界面不响应操作
    void recoveryUi();      // 动画结束，界面恢复
    void setNormalBrush();

    void clearAll();

    QPoint getTopElemPos();
    void addStackNodeGraphicsItem(StackNode *pNode, QPoint p);
    void adjustStackNodePos(StackNode *pNode, bool isDown);
    StackNode *stackTop();

    void stackPush(QString data);
    void stackPop();
    bool stackEmpty();

    QPoint getQueueNodePos(int idx);
    void initQueue();
    void enQueue(QString data);

    void startConvert(const std::vector<std::string> &wordList);
};

#endif // INFIX2SUFFIX_H
