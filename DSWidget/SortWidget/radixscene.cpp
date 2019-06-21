#include "radixscene.h"
#include <QDebug>

RadixScene::RadixScene()
{
    for(int i=0;i<10;i++){//创建十个桶
        Bucket *bucket=new Bucket;
        bucket_vec.push_back(bucket);
        addItem(bucket);
        bucket->setPos(-435+i*90,0);
        bucket->top_pos=bucket->pos()+QPointF(10,-5);
        bucket->index=i;
    }
    RadixTimer=new QTimer;
    connect(RadixTimer,SIGNAL(timeout()),this,SLOT(dealTimer()));
    ani_speed=new int(500);
}

void RadixScene::addBox()//向场景中添加数据
{
    boxNum++;
    NumberBox *number_box=new NumberBox;
    number_box->value=boxValue;
    box_vec.push_back(number_box);
    addItem(number_box);
    number_box->setPos(-550+boxNum*50,-490);
    number_box->tmp_pos=number_box->pos();
    setSceneRect(-435.5,-230.5,871,1);
//    qDebug()<<box_vec.size()<<":  "<<sceneRect();
}

void RadixScene::radixSort()
{
    if(boxNum<=1)return;
    for (int i = 1; i <= maxBit(); i++)
        radixSort(i);//依次按从低到高的位数进行排序
    RadixTimer->start(*ani_speed*1.2);//开始计时
}

void RadixScene::createList()
{
    head=new NODE;
    NODE* p=head;
    for (auto& r:box_vec) {
        p->data=r;
        if(&r!=&box_vec[boxNum-1]){
            p->next=new NODE;
            p=p->next;
        }
    }
}

RadixScene::NODE *RadixScene::Node(int x)
{
    if (x > boxNum)
            return Q_NULLPTR;
    NODE* p=head;
    for(int i=0;i<x;i++)
        p=p->next;
    return p;
}

int RadixScene::maxBit()
{
    int bit=1, n=10;
    for(NODE* p=head;p!=Q_NULLPTR;p=p->next)
        while(p->data->value>=n){
            bit++;
            n*=10;
        }
    return bit;
}

int RadixScene::bitNum(RadixScene::NODE *p, int n)
{
    int x=(p->data->value)/pow(10,n-1);
    return x%10;
}

void RadixScene::dealTimer()
{
    if(ani_list.size()==0){//若动画列表为空，即动画全部进行完毕，则停止定时器
        RadixTimer->stop();
        qDebug()<<"timer destructed";
        return;
    }
    ani_list[0]->start(QAbstractAnimation::DeleteWhenStopped);//每次进行列表首端的动画
    ani_list.pop_front();//删除列表首端动画
}

void RadixScene::radixSort(int x)//x=1:个位;x=2:十位;...
{
    QVector<NumberBox*> tmp_vec;//暂时存储按x位上的大小进行排序的数据
    for(int i=0;i<boxNum;i++){
        int index=Node(i)->data->bitNum(x);//桶序号对应数据x位上的数值
        ani_list.push_back(drag(Node(i)->data,bucket_vec[index]->top_pos+QPointF(0,-35)));
        bucket_vec[index]->box_vec.push_back(Node(i)->data);
        bucket_vec[index]->top_pos+=QPointF(0,-35);
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<bucket_vec[i]->box_vec.size();j++){
            tmp_vec.push_back(bucket_vec[i]->box_vec[j]);
        }
        bucket_vec[i]->top_pos=bucket_vec[i]->pos()+QPointF(10,-5);
    }
    for(int i=0;i<10;i++)
        while(bucket_vec[i]->box_vec.size()!=0)
            bucket_vec[i]->box_vec.pop_back();
    for(int i=0;i<tmp_vec.size();i++){
        Node(i)->data=tmp_vec[i];//对元素按x位上的大小进行重新排序
        ani_list.push_back(drag(Node(i)->data,QPointF(-500+i*50,-490)));
    }
}

QPropertyAnimation *RadixScene::drag(NumberBox *box, QPointF pos)//将box拖动到pos所对应的位置上
{
    QPropertyAnimation *ani=new QPropertyAnimation(box,"pos");
    ani->setStartValue(box->tmp_pos);
    ani->setEndValue(pos);
    ani->setDuration(*ani_speed);
    box->tmp_pos=pos;
    return ani;
}
