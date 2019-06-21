#ifndef STACK_H
#define STACK_H

#include <QWidget>
#include "stacknode.h"
#include "utils/arrow.h"

namespace Ui {
class Stack;
}

class Stack : public QWidget
{
    Q_OBJECT

public:
    explicit Stack(QWidget *parent = 0);
    ~Stack();

private slots:
    void on_initButton_clicked();

    void on_clearButton_clicked();

    void on_pushButton_clicked();

    void on_popButton_clicked();

private:
    Ui::Stack *ui;

    QGraphicsScene *m_scene;
    std::vector<StackNode *> m_stack;

    StackNode *m_head;

    QGraphicsTextItem *m_topLabel;
    Arrow *m_topArrow;

    const static QBrush m_normalBursh, m_markBrush;
    const static QFont m_arrowLabelFont, m_dataFont;

    void initUi();
    void initSceneView();
    void busyUistate();     // 动画过程中，界面不响应操作
    void recoveryUi();      // 动画结束，界面恢复
    void adjustControlPanel();  // 调整界面右侧控制面板状态
    void setStackNormalBrush();

    void clearAll();

    QPoint getTopElemPos();
    void addStackNodeGraphicsItem(StackNode *pNode, QPoint p);
    void adjustStackNodePos(StackNode *pNode, bool isDown);

    void initStack();
    void push(QString data);
    void pop();
};

#endif // STACK_H
