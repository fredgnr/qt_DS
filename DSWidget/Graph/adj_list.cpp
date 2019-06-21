#include "adj_list.h"
#include<algorithm>
adj_list::adj_list(int size)
{
    m_list.resize(size);
}
adj_list::adj_list(adj_list & mlist)
{
    for(int i=0;i<mlist.m_list.size();i++){
        vector<edgeinfo> temp;
        for(auto e:mlist.m_list[i]){
            temp.push_back(e);
        }
        this->m_list.push_back(temp);
    }
}

adj_list::adj_list(adj_list && mlist)
 {
     swap(mlist.m_list,m_list);
 }
vector<adj_list::edgeinfo>& adj_list::Get(int i)
 {
     if(i<m_list.size()){
         return m_list.at(i);
     }
 }
#include<QDebug>
 void adj_list::insert(int i, int number,int length,int edgeindex)
 {
     if(i<=m_list.size()){
         (m_list[i-1]).push_back({number-1,length,edgeindex});
     }
 }
