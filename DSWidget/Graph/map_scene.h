#ifndef MAP_SCENE_H
#define MAP_SCENE_H
#include<QList>
#include"node.h"
#include"edge.h"
#include<QGraphicsScene>
#pragma execution_character_set("utf-8")
class Map_Scene:public QGraphicsScene
{
    Q_OBJECT
public:
    Map_Scene();
    void UpdateItems();
    void Add_Edge(int node1,int node2);
    bool isadding;
    Node *add1,*add2;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QList<Edge *> edgelist;
    QList<Node *> nodelist;
    void updatealledge();
    void updateallnode();
    void Add_Node(QPointF point);
public slots:
    void get_update();
    void get_delete_edge(Edge *);
    void get_delete_node(Node *);
    void get_add_edge();
    void calculate_adj_list();
    void set_node_color(int index,int color);
    void set_edge_color(int index,int color);
    void get_node_init();
    void recover();
signals:
    void send_node_number(int number);
    void edge_info(int node1,int node2,int length);
    void update_info(const  QList<Edge *> &edgelist,int size);
};

#endif // MAP_SCENE_H
