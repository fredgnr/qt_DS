#include "worker.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <cstdio>
#include<QDebug>
#include <memory>
#pragma execution_character_set("utf-8")
using namespace std;
const int Inf=99999;
Worker::Worker()
{
    TIME=1500;
}
void Worker::set_tag(alg_type tag)
{
    this->tag=tag;
}
void Worker::set_file(string file)
{
    this->file=file;
}

void Worker::run()
{
    auto vec=data2vector("data.txt");
    emit node_init();
    msleep(100);
    for(int i=0,size=vec.size();i<size;i++){
        for(auto it=vec[i].begin();it!=vec[i].end();it++){
            emit set_edge(it->edgeindex,0);
        }
    }
    if(tag==e_bfs){
        this->BFS(vec);
    }
    else if(tag==e_dfs){
        this->DFS(vec);
    }
    else if(tag==e_djs){
        this->djs(vec,nodestart);
    }
    else if(tag==e_prim){
        this->Prim(vec);
    }
}

vector<vector<edgeinfo>> Worker::data2vector(string s)
{

    vector<vector<edgeinfo>> vec;

    FILE *fp=fopen(s.c_str(),"r");
    if(!fp){
        qDebug()<<"文件打开失败";
    }
    else{
        int size;
        fscanf(fp,"%d %d",&size,&edge_num);
        vec.resize(size);
        int node1,node2,length,edgeindex;
        while(edge_num&&(!feof(fp))) {
            if(fscanf(fp, "%d %d %d %d", &node1, &node2, &length,&edgeindex)==4)
            vec[node1-1].push_back({node2-1,length,edgeindex});
        }
    }
    fclose(fp);
    return vec;
}

vector<int> Worker::djs(vector<vector<edgeinfo>> &info,int node)
{
    emit code_activate(0);
    msleep(TIME);
    emit code_activate(1);
    msleep(TIME);
    vector<int> dis(info.size());
    vector<int> parent(info.size());
    unique_ptr<bool []> tag(new bool[info.size()]);
    for(int i=0;i<info.size();i++){
        tag[i]= false;
        parent[i]=i;
    }
    fill(dis.begin(),dis.end(),Inf);
    dis[node]=0;
    emit set_node(node,5);
    emit code_activate(2);
    msleep(TIME);
    vector<int> parent_edge(info.size());
    fill(parent_edge.begin(),parent_edge.end(),-1);
    for(auto it=info[node].begin();it!=info[node].end();it++){
        parent_edge[it->node]=it->edgeindex;
    }
    for(auto it=info[node].begin();it!=info[node].end();it++){
        emit set_node(it->node,2);
        emit code_activate(3);
        msleep(TIME);
        dis[it->node]=it->length;
        QVector<int> tempvec;
        for(auto it=dis.begin();it!=dis.end();it++)
            tempvec.push_back(*it);
        emit send_dis(tempvec);
        emit code_activate(4);
        msleep(TIME);
        emit set_node(it->node,3);
    }
    emit set_node(node,1);
    for(int time=0;time<info.size();time++){
        int index=-1,min=Inf;
        for(int i=0;i<dis.size();i++){
            if(dis[i]<min &&tag[i]== false){
                min=dis[i];
                index=i;
            }
        }
        if(index==-1)
            break;
        else{
            tag[index]=true;
            emit set_node(index,5);
            emit code_activate(2);
            msleep(TIME);
            if(parent_edge[index]!=-1)
                emit set_edge(parent_edge[index],1);
            for(auto it=info[index].begin();it!=info[index].end();it++){
                int temp=dis[index]+it->length;
                emit set_node(it->node,2);
                if(temp<dis[it->node]){
                    dis[it->node]=temp;
                    parent_edge[it->node]=it->edgeindex;
                    parent[it->node]=index;
                    emit code_activate(4);
                    QVector<int> tempvec;
                    for(auto it=dis.begin();it!=dis.end();it++)
                        tempvec.push_back(*it);
                    emit send_dis(tempvec);
                    msleep(TIME);
                }
                emit set_node(it->node,3);
            }
            msleep(TIME);
            emit set_node(index,1);
        }
        msleep(TIME);
    }
    emit code_activate(7);
    return dis;
}
struct node_info{
    int index;
    int edgeindex;
};

#include <stack>
void Worker::dfs_work(vector<vector<edgeinfo> > &info, int startnode, vector<bool> &tag)
{
    emit set_node(startnode,4);
    emit code_activate(0);
    msleep(TIME);
    if(edge_num){
    stack<node_info> s;
    s.push({startnode,-1});
    while(!s.empty()){
        if(find(tag.begin(),tag.end(),false)==tag.end())
            break;
        node_info cur=s.top();
        if(!tag[cur.index]){
        emit set_node(cur.index,5);
        emit code_activate(1);
        if(cur.edgeindex>=0)
            emit set_edge(cur.edgeindex,1);
        tag[cur.index]=true;
        }
        msleep(TIME);
        s.pop();
        for(auto it=info[cur.index].begin();it!=info[cur.index].end();it++){
            emit set_node(it->node,2);
            emit code_activate(2);
            msleep(TIME);
            if(!tag[(*it).node]){
                //tag[it->node]=true;
                s.push({(*it).node,(*it).edgeindex});
                emit set_node(it->node,4);
                emit code_activate(3);
            }
            else{
                emit set_node(it->node,3);
                emit code_activate(4);
            }
            msleep(TIME);
        }
        msleep(TIME);
        emit set_node(cur.index,1);
    }
    }
    else{
        emit set_node(startnode,1);
        msleep(TIME);
        tag[startnode]=true;
    }
}

void Worker::DFS(vector<vector<edgeinfo>> &info)
{
    vector<bool> tag(info.size(),false);
    dfs_work(info,this->nodestart,tag);
    vector<bool>::iterator it;
    while((it=find(tag.begin(),tag.end(),false))!=tag.end()){
        dfs_work(info,it-tag.begin(),tag);
    }
}

#include <queue>
#include<QColor>
#include<set>
struct deepth_tag{
    int index;
    int edgeindex;
};
void Worker::bfs_work(vector<vector<edgeinfo>> &info,int startnode,vector<bool> &tag)
{
    if(!(info[startnode]).empty()){
    bool f=false;
    queue<deepth_tag> q;
    q.push({startnode,info[startnode][0].edgeindex});
    emit set_node(startnode,4);
    emit code_activate(0);
    msleep(TIME);
    while(!q.empty()){
        emit code_activate(1);
        msleep(TIME);
        deepth_tag cur=q.front();
        emit code_activate(2);
        tag[cur.index]=true;
        emit set_node(cur.index,5);
        if(f){
        emit set_edge(cur.edgeindex,1);
        }
        else {
            f=true;
        }
        q.pop();
         msleep(TIME);
        for(auto it=info[cur.index].begin();it!=info[cur.index].end();it++){
            qDebug()<<info[cur.index].size();
            emit set_node(it->node,2);
            emit code_activate(3);
            msleep(TIME);
            if(!tag[it->node]){
                tag[it->node]=true;
                q.push({it->node,it->edgeindex});
                emit set_node(it->node,4);
                emit code_activate(4);
                msleep(TIME);

            }
            else {emit set_node(it->node,3);
            emit code_activate(5);msleep(TIME);}

        }
        emit set_node(cur.index,1);
    }
    }
    else{
        emit set_node(startnode,1);
        msleep(TIME);
        tag[startnode]=true;
    }

}

void Worker::BFS(vector<vector<edgeinfo>> &info)
{
    vector<bool> tag(info.size(),false);
    bfs_work(info,this->nodestart,tag);
    vector<bool>::iterator it;
    while((it=find(tag.begin(),tag.end(),false))!=tag.end())
        bfs_work(info,it-tag.begin(),tag);
}

#include <set>
struct edge{
    int tag;
    int length;
    int edgeindex;
};
int mycompare( const edge &e1, const edge &e2)
{
    return e1.tag<e2.tag;
}
vector<int> two_node(int tag)
{
    vector<int> temp;
    for(int i=0;i<sizeof(int)*8;i++){
        if(tag&(1<<i)){
            temp.push_back(i);
        }
    }
    return temp;
}
bool Worker::check(vector<vector<edgeinfo>> &info)
{
    vector<bool> tag(info.size(),false);
    if(info[0].size()==0)
        return false;
    else{
        queue<int> nodequeue;
        nodequeue.push(0);
        while(!nodequeue.empty()){
            int cur=nodequeue.front();
            for(auto it=info[cur].begin();it!=info[cur].end();it++){
                if(!tag[it->node]){
                    nodequeue.push(it->node);
                    tag[it->node]=true;
                }
            }
            nodequeue.pop();
        }
    } for(auto it:tag){
        qDebug()<<it;
    }
    if(find(tag.begin(),tag.end(),false)==tag.end()){
        return true;
    }

    else return false;
}

void Worker::Prim(vector<vector<edgeinfo>> &info)
{
    bool checked=check(info);
    qDebug()<<"check:"<<checked;
    if(!checked){
    emit send_info(1);
    }else{
    set<edge, decltype(mycompare) *> newedge(mycompare),oldedge(mycompare);
    for(int index1=0;index1<info.size();index1++){
        for(int index2=0;index2<info[index1].size();index2++) {
            edge temp;
            temp.tag=(1 << index1) | (1 << info[index1][index2].node);
            temp.length=info[index1][index2].length;
            temp.edgeindex=(info[index1][index2]).edgeindex;
            oldedge.insert(temp);
        }
    }
    //判断一个顶点是否加入到新的点集中
    vector<bool> tag(info.size());
    fill(tag.begin(),tag.end(), false);
    tag[nodestart]=true;
    emit set_node(nodestart,1);
    emit code_activate(0);
    msleep(TIME);
    //找到初始种子边
    /*{
        auto minedge=oldedge.begin();
        for(auto it=oldedge.begin();it!=oldedge.end();it++){
            if(it->length<minedge->length){
                minedge=it;
            }
        }
        newedge.insert(*minedge);
        emit set_edge(minedge->edgeindex,1);
        vector<int> temp;
        for(int i=0;i<info.size();i++){
            if(minedge->tag&(1<<i)){
                temp.push_back(i);
            }
        }
        tag[temp[0]]=tag[temp[1]]=true;
        emit set_node(temp[0],1);
        emit set_node(temp[1],1);
        oldedge.erase(minedge);
    }*/
    while(find(tag.begin(),tag.end(), false)!=tag.end()&&!oldedge.empty()){
        set<edge>::iterator minedge;
        int min_length=Inf;
        //找出还未加入集合的最小的边
        for(auto it=oldedge.begin();it!=oldedge.end();it++){
            emit code_activate(1);
            msleep(TIME/2);
            if(it->length<min_length){
                auto tempvec=two_node(it->tag);
                if(tag[tempvec[0]]||tag[tempvec[1]]) {
                    minedge = it;
                    min_length=it->length;
                }
            }
        }
        qDebug()<<"tag:"<<minedge->tag;
        int time=0;
        vector<int> temp;
        for(int i=0;i<info.size();i++)
            if((minedge->tag)&(1<<i)){
                temp.push_back(i);
                if(tag[i]==false)
                    time++;
            }
        if(time==1){
            int node1,node2;
            //node1是已经加入新集合中的点，node2是即将加入新集合中的点
            if(tag[temp[0]]) {
                node1=temp[0],node2=temp[1];
            }
            else{
                node1=temp[1],node2=temp[0];
            }
            emit set_edge(minedge->edgeindex,1);
            emit set_node(node1,1);
            emit set_node(node2,1);
            emit code_activate(2);
            msleep(TIME);
            newedge.insert(*minedge);
            oldedge.erase(minedge);
            tag[node2]=true;
            //qDebug()<<node1<<"\t"<<node2;
        }
        else{
            oldedge.erase(minedge);
        }
    }
    }
    emit send_info(2);
}

void Worker::change_interval(int t)
{
    TIME=t;
}
