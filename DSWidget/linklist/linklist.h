#ifndef LINKLIST_H
#define LINKLIST_H

#include <QWidget>
#include <QIntValidator>
#include "linknode.h"

namespace Ui {
class linkList;
}

class linkList : public QWidget
{
    Q_OBJECT

public:
    explicit linkList(QWidget *parent = 0);
    ~linkList();

private:
    Ui::linkList *ui;

    QGraphicsScene *m_scene;          // 可视化场景指针
    QGraphicsTextItem *m_headLabel;   // 链表符号指针
    Arrow *m_headArrow;               // 箭头符号指针
    linkNode *m_head;                 // 头节点指针

    int m_nodeCnt;                    // 节点个数（不包括头节点）

    const static QBrush m_normalBursh, m_visitedBrush, m_markBrush;
    const static QFont m_headLabelFont, m_dataFont;
    const static QIntValidator m_dataValidator;

    void initUi();
    void initSceneView();
    void initLinkList();
    void busyUiState();         // 动画过程中，界面不响应操作
    void recoveryUi();          // 动画结束，界面恢复
    void adjustControlPanel();  // 调整界面右侧控制面板状态

    QPoint getLinkNodePos(int nodeIndex);                       // 计算节点的场景坐标
    void addLinkNodeGraphicsItem(linkNode *pNode, QPoint p);    // 添加节点的图形项
    void adjustLinkNodeArrow(linkNode *pNode, int idx);         // 调整节点的箭头
    void adjustLinkNodePos(linkNode *pNode, QPoint p);          // 调整节点场景坐标
    void setLinkListNormalBrush();                              // 设置链表默认节点显示模式


    void insertLinkNode(int idx, QString data);     // 在第idx个位置插入节点，数据域为data
    void deleteLinkNode(int idx);                   // 删除第idx个节点
    int searchLinkNode(QString data);               // 查找第一次出现值为data的节点位置

    void clearAll();

private slots:
    void on_initButton_clicked();
    void on_clearButton_clicked();
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
};

#endif // LINKLIST_H
