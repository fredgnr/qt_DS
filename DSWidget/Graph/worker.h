#ifndef WORKER_H
#define WORKER_H
#include<QThread>
#include<vector>
using namespace std;
struct edgeinfo{
    int node;
    int length;
    int edgeindex;
};
enum alg_type{none_type,e_djs,e_dfs,e_bfs,e_prim};

class Worker:public QThread
{
    Q_OBJECT
    bool check(vector<vector<edgeinfo>> &info);
public:
    Worker();
    void set_tag(alg_type tag);
    void set_file(string file);vector<int> djs(vector<vector<edgeinfo>> &info,int node);
    void DFS(vector<vector<edgeinfo>> &info);
    void BFS(vector<vector<edgeinfo>> &info);
    void dfs_work(vector<vector<edgeinfo>> &info,int startnode,vector<bool> &tag);
    void bfs_work(vector<vector<edgeinfo>> &info,int startnode,vector<bool> &tag);
    void Prim(vector<vector<edgeinfo>> &info);
    vector<vector<edgeinfo>> data2vector(string s);
    int nodestart;
protected:
    void run();
    alg_type tag;
    string file;
    int TIME;
signals:
    void set_node(int index,int color);
    void set_edge(int index,int color);
    void node_init();
    void code_activate(int index);
    void send_info(int);
    void send_dis(QVector<int> dis);
private:
    int edge_num;
public slots:
    void change_interval(int);
};

#endif // WORKER_H
