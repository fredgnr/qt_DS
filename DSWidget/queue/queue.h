#ifndef QUEUE_H
#define QUEUE_H

#include <QWidget>
#include "queuenode.h"
#include "utils/arrow.h"
#pragma execution_character_set("utf-8")
namespace Ui {
class Queue;
}

class Queue : public QWidget {
    Q_OBJECT

public:
    explicit Queue(QWidget *parent = 0);
    ~Queue();

private slots:
    void on_initButton_clicked();

    void on_clearButton_clicked();

    void on_enQueueButton_clicked();

    void on_deQueueButton_clicked();

private:
    Ui::Queue *ui;

    QGraphicsScene *m_scene;
    std::vector<QueueNode *> m_queue;

    int m_rear;
    int m_front;

    QueueNode *m_head;

    QGraphicsTextItem *m_rearLabel;
    QGraphicsTextItem *m_frontLabel;
    Arrow *m_rearArrow;
    Arrow *m_frontArrow;

    const static QBrush m_normalBursh, m_markBrush;
    const static QFont m_arrowLabelFont, m_dataFont;

    void initUi();
    void initSceneView();
    void busyUistate();     // 动画过程中，界面不响应操作
    void recoveryUi();      // 动画结束，界面恢复
    void adjustControlPanel();  // 调整界面右侧控制面板状态
    void setQueueNormalBrush();

    void updateRearArrow();

    void clearAll();

    QPoint getQueueNodePos(int idx);
    void addQueueNodeGraphicsItem(QueueNode *pNode, QPoint p);
    void adjustQueueNodePos(QueueNode *pNode, int idx);

    void initQueue();
    void enQueue(QString data);
    void deQueue();
};

#endif  // QUEUE_H
