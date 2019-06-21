#include "map_scene.h"
#include<QGraphicsView>
#include"edge.h"
#include<QList>
#include<algorithm>
#include<QDebug>
#pragma execution_character_set("utf-8")
void Map_Scene::Add_Node(QPointF newpoint)
{
    Node *newnode=new Node;
    newnode->setPos(newpoint);
    connect(newnode,SIGNAL(send_delete(Node*)),this,SLOT(get_delete_node(Node*)));
    connect(newnode,SIGNAL(send_add_edge()),this,SLOT(get_add_edge()));
    nodelist.append(newnode);
    addItem(newnode);
    UpdateItems();
    views()[0]->update();
    emit send_node_number(nodelist.size());
}

Map_Scene::Map_Scene():
    add1(0),add2(0),isadding(false)
{
    setSceneRect(QRectF(0,0,800,800));
    for(int i=0;i<5;i++){
        nodelist.append(new Node);
        addItem(nodelist[i]);
        connect(nodelist[i],SIGNAL(send_delete(Node*)),this,SLOT(get_delete_node(Node*)));
        connect(nodelist[i],SIGNAL(send_add_edge()),this,SLOT(get_add_edge()));
    }
    updateallnode();
    //设置各个节点在图中的位置
    nodelist[0]->setPos(QPointF(63 ,240));
    nodelist[1]->setPos(QPointF(156,130));
    nodelist[2]->setPos(QPointF(179,391));
    nodelist[3]->setPos(QPointF(299,107));
    nodelist[4]->setPos(QPointF(273,241));
    emit send_node_number(nodelist.size());
}
void Map_Scene::updatealledge()
{
    for(auto it=edgelist.begin();it!=edgelist.end();it++){
        (*it)->set_path();
    }
}
#include<QDebug>
void Map_Scene::updateallnode()
{
    int i=1;
    //更新所有节点的数字标识
    for(auto it=nodelist.begin();it!=nodelist.end();it++){
        (*it)->SetNumber(i++);
    }
}

void Map_Scene::UpdateItems()
{
    updatealledge();
    updateallnode();
    emit update_info(edgelist,nodelist.size());
}
void Map_Scene::get_update()
{
    UpdateItems();
}

void Map_Scene::Add_Edge(int node1,int node2)
{
    bool flag=true;
    for(auto it=edgelist.begin();it!=edgelist.end();it++){
        if(((*it)->node1->GetNumber()==node1&&(*it)->node2->GetNumber()==node2)||((*it)->node1->GetNumber()==node2&&(*it)->node2->GetNumber()==node1))
            flag=false;
    }
    if(flag){
        Edge *e=new Edge(nodelist[node1-1],nodelist[node2-1]);
        edgelist.append(e);
        addItem(e);
        UpdateItems();
        connect(e,SIGNAL(send_delete_edge(Edge*)),this,SLOT(get_delete_edge(Edge*)));
        views()[0]->repaint();
        emit edge_info(node1-1,node2-1,(int)e->get_length());
    }
}

void Map_Scene::get_delete_edge(Edge *edge)
{
    auto it=std::find_if(edgelist.begin(),edgelist.end(),[=](Edge *e){return e==edge;});
    if(it!=edgelist.end()){
        Edge *e=*it;
        edgelist.erase(it);
        removeItem(e);
        emit edge_info(e->node1->GetNumber()-1,e->node2->GetNumber()-1,-100);
        delete e;
        updatealledge();
        views()[0]->viewport()->update();
    }
}

void Map_Scene::get_delete_node(Node *node)
{
    auto it=std::find_if(nodelist.begin(),nodelist.end(),[=](Node *n){return n==node;});
    if(it!=nodelist.end()){
        Node *n=*it;
        nodelist.erase(it);
        //删除与这个节点有关的边
        for(auto e:edgelist){
            auto eit=std::find_if(edgelist.begin(),edgelist.end()
                                  ,[=](Edge *tempe){return tempe->node1==n||tempe->node2==n;});
            if(eit!=edgelist.end()){
                Edge *e=*eit;
                edgelist.erase(eit);
                removeItem(e);
                delete e;
            }
        }
        removeItem(n);
        disconnect(n,0,0,0);
        delete n;
        updatealledge();
        UpdateItems();
        views()[0]->update();
        for(auto n:nodelist){
            n->update();
        }
    }
    emit update_info(edgelist,nodelist.size());
}
#include<QMenu>
#include<QGraphicsSceneMouseEvent>
void Map_Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        if(isadding&&items(event->scenePos()).empty()){
            isadding=false;
            add1->SetColor(QColor(Qt::black));
            add1->update();
            add1=0;
            }
    else if((event->buttons()&Qt::RightButton)){
        if(items(event->scenePos()).empty()){
        QMenu menu;
        QAction *add=menu.addAction(tr("增加节点"));
        QAction *selected=menu.exec(event->screenPos());
        if(selected==add){
            Add_Node(event->scenePos());
            }
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void Map_Scene::get_add_edge()
{
    if(add1!=add2){
    Add_Edge(add1->GetNumber(),add2->GetNumber());
    UpdateItems();
    views()[0]->repaint();
    }
    emit edge_info(add1->GetNumber()-1,add2->GetNumber()-1,edgelist[edgelist.size()-1]->get_length());
    add1->SetColor(QColor(Qt::black));
    add1=add2=nullptr;
    isadding=false;
}
#include"adj_list.h"
#include<vector>
using namespace  std;
#include<QFile>
void Map_Scene::calculate_adj_list()
{
   adj_list adj(nodelist.size());
   int i=0;
    for (auto e :edgelist){
        adj.insert(e->node1->GetNumber(),e->node2->GetNumber(),e->get_length(),i);
        adj.insert(e->node2->GetNumber(),e->node1->GetNumber(),e->get_length(),i);
        i++;
    }
    QFile data("data.txt");
    data.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&data);
    out<<nodelist.size()<<"\t"<<edgelist.size()<<endl;
    for(int i=0;i<nodelist.size();i++){       
       for(auto it=adj.Get(i).begin();it!=adj.Get(i).end();it++)
           out<<i+1<<"\t"<<it->node+1<<"\t"<<it->length<<"\t"<<it->edgeindex<<endl;
    }
    data.close();
}

void Map_Scene::set_node_color(int index,int color)
{
    if(color==1)
        nodelist[index]->SetColor(QColor(Qt::red));
    else if(color==2){
        nodelist[index]->save();
        nodelist[index]->SetColor(QColor(Qt::yellow));
    }
    else if(color==3){
        nodelist[index]->rec();
    }
    else if(color==4){
        nodelist[index]->SetColor(QColor(Qt::darkGreen));
    }
    else if(color==5){
        nodelist[index]->SetColor(QColor(58, 95, 205));
    }
    views()[0]->viewport()->repaint();
}

void Map_Scene::set_edge_color(int index, int color)
{
    if(color==1){
        edgelist[index]->set_color(QColor(Qt::red));
    }
    else if(color==0){
        edgelist[index]->set_color(QColor(Qt::gray));
    }
     views()[0]->viewport()->repaint();
}

void Map_Scene::get_node_init()
{
    for(auto it=nodelist.begin();it!=nodelist.end();it++){
        (*it)->SetColor(QColor(Qt::gray));
    }
    for(auto it=edgelist.begin();it!=edgelist.end();it++){
        (*it)->set_color(QColor(Qt::gray));
    }
     views()[0]->viewport()->repaint();
}

void Map_Scene::recover()
{

    for(auto it=nodelist.begin();it!=nodelist.end();it++){
        (*it)->SetColor(QColor(Qt::black));
    }
    for(auto it=edgelist.begin();it!=edgelist.end();it++){
        (*it)->set_color(QColor(Qt::black));
    }
     views()[0]->viewport()->repaint();
}
