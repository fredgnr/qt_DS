#include "graphwidget.h"
#include "ui_graphwidget.h"
#include"map_scene.h"
#include"fadecodescene.h"
#include"QThread"
#include"QTableWidgetItem"
#include"QTableWidget"
#include<QFile>
#include<QScrollBar>
#include<QPushButton>
#pragma execution_character_set("utf-8")
GraphWidget::GraphWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphWidget)
{
    ui->setupUi(this);
    qRegisterMetaType<QVector<int> >("QVector<int>");
    Map_Scene *scene=new Map_Scene;
    ui->testview->setScene(scene);
    ui->testview->resize(805,805);
    ui->testview->move(10,10);
    ui->codeview->move(950,10);
    ui->codeview->resize(600,400);
    fadecodescene * codescenetemp=new fadecodescene(ui->codeview->width()-3,ui->codeview->height()-3);
    ui->codeview->setScene(codescenetemp);
    ui->bfsptn->setText(QString("bfs"));
    connect(scene,SIGNAL(send_node_number(int)),this,SLOT(setnodenumber(int)));
    connect(ui->bfsptn,SIGNAL(clicked(bool)),this,SLOT(bfsdown()));
    connect(&thread,SIGNAL(set_node(int,int)),scene,SLOT(set_node_color(int,int)));
    connect(&thread,SIGNAL(set_edge(int,int)),scene,SLOT(set_edge_color(int,int)));
    connect(ui->dfsptn,SIGNAL(clicked(bool)),this,SLOT(dfsdown()));
    connect(&thread,SIGNAL(node_init()),scene,SLOT(get_node_init()));
    connect(ui->djsptn,SIGNAL(clicked(bool)),this,SLOT(djsdown()));
    connect(ui->primptn,SIGNAL(clicked(bool)),this,SLOT(primdown()));
    connect(ui->recoverptn,SIGNAL(clicked(bool)),scene,SLOT(get_node_init()));
    connect(&thread,SIGNAL(code_activate(int)),codescenetemp,SLOT(Get_Activate(int)));
    connect(scene,SIGNAL(edge_info(int,int,int)),this,SLOT(get_edge_info(int,int,int)));
    connect(scene,SIGNAL(update_info(QList<Edge*>,int)),this,SLOT(update_table(QList<Edge*>,int)));
    connect(&thread,SIGNAL(send_info(int)),this,SLOT(get_info(int)));
    connect(&thread,SIGNAL(send_dis(QVector<int>)),this,SLOT(get_dis(QVector<int>)));
    codescene=codescenetemp;
    //ui->mapspinbox->setMinimum(0);
    ui->mapspinbox->setRange(1,5);
    QStringList stringlist;
    for(int i=1;i<=5;i++)
        stringlist<<QString("%1").arg(i);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(stringlist);
    ui->tableWidget->setVerticalHeaderLabels(stringlist);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    for(int row=0;row<5;row++){
        for(int col=0;col<5;col++)
            ui->tableWidget->setItem(row,col,new QTableWidgetItem("INF"));
    }
    distable=new QTableWidget(this);
    distable->resize(ui->codeview->width(),60);
    distable->move(950,425);
    distable->setVisible(false);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();
    QScrollBar *bar=new QScrollBar(Qt::Vertical,this);
    bar->resize(20,200);
    bar->move(1500,600);
    bar->setMinimum(200);
    bar->setMaximum(2000);
    bar->setValue(1000);
    connect(bar,SIGNAL(valueChanged(int)),&thread,SLOT(change_interval(int)));
    QPushButton *button=new QPushButton(tr("停止动画"),this);
    connect(button,SIGNAL(clicked(bool)),this,SLOT(stop_ani()));
    ui->verticalLayout->insertWidget(1,button);
}

GraphWidget::~GraphWidget()
{
    delete ui;
    if(thread.isRunning()){
        thread.terminate();
        thread.wait();
    }
}
#include<QDebug>
void GraphWidget::setnodenumber(int number)
{
    ui->mapspinbox->setRange(1,number);
}

void GraphWidget::bfsdown()
{
   distable->setVisible(false);
   qobject_cast<fadecodescene *>(ui->codeview->scene())->clear();
    qobject_cast<Map_Scene *>(ui->testview->scene())->calculate_adj_list();
    if(thread.isRunning()){
        thread.terminate();
        thread.wait();
    }
    thread.set_tag(e_bfs);
    thread.nodestart=ui->mapspinbox->value()-1;
    QList<QPair<QString,int>>stringlist;
    stringlist.append(QPair<QString,int>("bfs(u),Q(u) ////u为访问的起始节点",0));
    stringlist.append(QPair<QString,int>("while !Q.empty():",1));
    stringlist.append(QPair<QString,int>("cur=Q.front()",2));
    stringlist.append(QPair<QString,int>("for each neighbor v of cur:",2));
    stringlist.append(QPair<QString,int>("if v not visited ,Q.push(v)",3));
    stringlist.append(QPair<QString,int>("else ignore v",3));
    for(auto it=stringlist.begin();it!=stringlist.end();it++){
        QString temp;
        for(int i=0;i<it->second;i++)
            temp.append("\t\t\t\t\t");
        temp.append(it->first);
        codescene->AddCode(temp);
    }
    thread.start();
}
#include"fadecodescene.h"
void GraphWidget::dfsdown()
{
    distable->setVisible(false);
    qobject_cast<fadecodescene *>(ui->codeview->scene())->clear();
    QList<QPair<QString,int>>stringlist;
    stringlist.append(QPair<QString,int>("dfs(u) //u为访问的起始节点",0));
    stringlist.append(QPair<QString,int>("visit u",1));
    stringlist.append(QPair<QString,int>("for each neighbor v of u:",1));
    stringlist.append(QPair<QString,int>("if v not visited,dfs(u)",2));
    stringlist.append(QPair<QString,int>("else ignore v;",2));
    for(auto it=stringlist.begin();it!=stringlist.end();it++){
        QString temp;
        for(int i=0;i<it->second;i++)
            temp.append("\t\t\t\t\t");
        temp.append(it->first);
        codescene->AddCode(temp);
    }

    qobject_cast<Map_Scene *>(ui->testview->scene())->calculate_adj_list();
    if(thread.isRunning()){
        thread.terminate();
        thread.wait();
    }
    thread.set_tag(e_dfs);
    thread.nodestart=ui->mapspinbox->value()-1;
    thread.start();
}

void GraphWidget::djsdown()
{
    distable->setVisible(true);
    QStringList mylist;
    for(int i=0;i<ui->mapspinbox->maximum();i++){
        mylist.append(QString::number(i+1));
    }
    distable->setHorizontalHeaderLabels(mylist);
    mylist.clear();
    mylist.append(QString("distance"));
    distable->setVerticalHeaderLabels(mylist);
    distable->setRowCount(1);
    distable->setColumnCount(ui->mapspinbox->maximum());
    for(int i=0;i<ui->mapspinbox->maximum();i++)
        distable->setItem(0,i,new QTableWidgetItem(QString("INF")));
    distable->item(0,ui->mapspinbox->value()-1)->setText("0");
    distable->resizeColumnsToContents();
    distable->resizeRowsToContents();
    qobject_cast<fadecodescene *>(ui->codeview->scene())->clear();
    qobject_cast<Map_Scene *>(ui->testview->scene())->calculate_adj_list();
    if(thread.isRunning()){
        thread.terminate();
        thread.wait();
    }
    QList<QPair<QString,int>>stringlist;
    stringlist.append(QPair<QString,int>("DJS(start) V={v},S={},dis[]//dis[]=INF,dis[start]=0",0));
    stringlist.append(QPair<QString,int>("repeat number of nodes:",1));
    stringlist.append(QPair<QString,int>("D[j]=Min{D[i]| Vi in V} ,S=S+{vj},V=V-{vj}",2));
    stringlist.append(QPair<QString,int>("for neighbor Vk of Vj:",3));
    stringlist.append(QPair<QString,int>("if D[j]+vertex(vj,vk)<D[k] Dk=D[j]+vertex(vj,vk)",4));
    for(auto it=stringlist.begin();it!=stringlist.end();it++){
        QString temp;
        for(int i=0;i<it->second;i++)
            temp.append("\t\t\t\t\t");
        temp.append(it->first);
        codescene->AddCode(temp);
    }
    thread.set_tag(e_djs);
    thread.nodestart=ui->mapspinbox->value()-1;
    thread.start();
}

void GraphWidget::primdown()
{
    distable->setVisible(false);
    qobject_cast<fadecodescene *>(ui->codeview->scene())->clear();
    codescene->AddCode(QString("Prim(s) u={s} ,v=V-u,Tree={},Edges"));
    codescene->AddCode(QString("\t\t\t\t\twhile v!=null"));
    QString temp;
    temp.append("\t\t\t\t\t\t\t\t\t\t");
    temp.append("find min edge(node1,node2) in edge\n");
    temp.append("\t\t\t\t\t\t\t\t\t\t");
    temp.append("\\\\node1 in u,node2 in v\n");
    temp.append("\t\t\t\t\t\t\t\t\t\t");
    temp.append("Tree=Tree+{edge},Edges=Edges-{edge}");
    codescene->AddCode(temp);
    qobject_cast<Map_Scene *>(ui->testview->scene())->calculate_adj_list();
    if(thread.isRunning()){
        thread.terminate();
        thread.wait();
    }
    thread.nodestart=ui->mapspinbox->value()-1;
    thread.set_tag(e_prim);
    thread.start();
}

void GraphWidget::get_edge_info(int node1, int node2, int length)
{
    if(length>0){
    ui->tableWidget->setItem(node1,node2,new QTableWidgetItem(QString::number(length)));
    ui->tableWidget->setItem(node2,node1,new QTableWidgetItem(QString::number(length)));
    }
    else{
        ui->tableWidget->setItem(node1,node2,new QTableWidgetItem(QString("INF")));
        ui->tableWidget->setItem(node2,node1,new QTableWidgetItem(QString("INF")));
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    //item1->setText(QString::number(length));
    //item2->setText(QString::number(length));
}
#include"edge.h"
void GraphWidget::update_table(const QList<Edge *> &edgelist, int size)
{
    if(ui->tableWidget->rowCount()!=size){
        QStringList header;
        for(int i=1;i<=size;i++)
            header<<QString::number(i);
        ui->tableWidget->setColumnCount(size);
        ui->tableWidget->setRowCount(size);
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setVerticalHeaderLabels(header);
        for(int row=0;row<size;row++){
            for(int col=0;col<size;col++)
                if(ui->tableWidget->item(row,col)==0)
                ui->tableWidget->setItem(row,col,new QTableWidgetItem(QString("INF")));
        }
    }
    for(auto it=edgelist.begin();it!=edgelist.end();it++){
        ui->tableWidget->item((*it)->node1->GetNumber()-1,(*it)->node2->GetNumber()-1)->setText(QString::number((int)(*it)->get_length()));
        ui->tableWidget->item((*it)->node2->GetNumber()-1,(*it)->node1->GetNumber()-1)->setText(QString::number((int)(*it)->get_length()));
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}
#include<QMessageBox>
void GraphWidget::get_info(int info)
{
    if(info==1){
        QMessageBox box;
        box.information(NULL, tr("警告"), tr("此图不是连通图"), QMessageBox::Cancel, QMessageBox::Cancel);
        box.show();
    }
    if(info==2){
        codescene->clear();
    }
    if(info==3){
        distable->setVisible(false);
    }
}

void GraphWidget::get_dis(QVector<int> dis)
{
    qDebug()<<"okk:\t"<<dis.size();
    for(int i=0;i<dis.size();i++){
        qDebug()<<dis[i];
       if(dis[i]==99999)
            distable->item(0,i)->setText("INF");
        else{
            distable->item(0,i)->setText(QString::number(dis[i]));
        }
       distable->resizeColumnsToContents();
       distable->resizeRowsToContents();
    }
}

void GraphWidget::stop_ani()
{
    if(thread.isRunning()){
        thread.terminate();
        thread.wait();
    }
    qobject_cast<Map_Scene*>(ui->testview->scene())->recover();
    codescene->clear();
    distable->setVisible(false);
}
