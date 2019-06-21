#include "fadecodescene.h"
#include"fadecode.h"
#include<QGraphicsView>
#include<QDebug>
#include<QObject>
fadecodescene::fadecodescene(int width,int height,QObject *parent):
    QGraphicsScene(parent)
{
    size=QSize(width,height);
    activateindex=-1;
}
void fadecodescene::AddCode(QString &s)
{
    FadeCode *code=new FadeCode;
    code->setString(s);
    codelist.append(code);
    addItem(code);
    double height=double(size.height())/double(codelist.size());
    for(int i=0;i<codelist.size();i++){
        codelist[i]->setRect(QRectF(0,height*i,size.width(),height));
    }
}
void fadecodescene::activate(int index)
{
    if(activateindex==-1){
        codelist[index]->activate(true);
        activateindex=index;
        views()[0]->viewport()->repaint();
    }
    else if(index<codelist.size()){
    codelist[activateindex]->activate(false);
    codelist[index]->activate(true);
    activateindex=index;
    views()[0]->viewport()->repaint();
    }
    else{
        codelist[activateindex]->activate(false);
        activateindex=-1;
    }
}

void fadecodescene::Get_Activate(int index)
{
    if(index>=0)
    activate(index);
    else
        codelist[index]->activate(false);
}

void fadecodescene::clear()
{
    while(!codelist.empty()){
        auto it=codelist.begin();
        auto item=*it;
        codelist.erase(it);
        removeItem(item);
        delete item;
    }
}
