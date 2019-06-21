#ifndef ADJ_LIST_H
#define ADJ_LIST_H
#include<vector>
using namespace std;
class adj_list
{
public:
    adj_list(int size);
    adj_list(adj_list &);
    adj_list(adj_list &&);
    ~adj_list(){}
    struct edgeinfo{
        int node;
        int length;
        int edgeindex;
    };
    //返回第几个节点的邻接表
    vector<edgeinfo> & Get(int i);
    //在某个节点的邻接表中插入节点
    void insert(int i,int number,int length,int edgeindex);
private:
    vector<vector<edgeinfo>> m_list;

};

#endif // ADJ_LIST_H
