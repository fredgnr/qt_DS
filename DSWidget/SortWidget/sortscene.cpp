#include "sortscene.h"
#include <QDebug>
#include <QGraphicsView>

SortScene::SortScene()
{
    SortTimer=new QTimer;
    connect(SortTimer,SIGNAL(timeout()),this,SLOT(dealTimer()));
    ani_speed=new int(500);
}

void SortScene::addElement()
{
    eleNum++;
    Element *element=new Element;
    element->value=eleValue;
    ele_vec.push_back(element);
    addItem(element);
    if(ele_vec.size()==1){
        element->setPos(5-15*eleNum,eleValue);
    }
    else{
        Element *ele=ele_vec[ele_vec.size()-2];
        element->setPos(ele->pos()+QPoint(30,ele->value-element->value));
    }
    element->tmp_pos=element->pos();
    setSceneRect(-10.5,ele_vec[0]->value-0.5,-9+30*ele_vec.size(),ele_vec[0]->value+1);
//    qDebug()<<ele_vec.size()<<":  "<<sceneRect();
//    qDebug()<<element->pos();
}

void SortScene::bubbleSort()
{
    for (int i = 0; i < eleNum-1; i++) {
        NODE* p = head;
        for (int j = 0; j < eleNum - 1 - i; j++)
            if (p != Q_NULLPTR && p->next != Q_NULLPTR) {
                compare(p,p->next);
                if ((p->data->value) > (p->next->data->value)){
                    swapEle(p, p->next);
                    Element* tmp;
                    tmp=p->data;
                    p->data=p->next->data;
                    p->next->data=tmp;
                }
                p = p->next;
        }
    }
    SortTimer->start(*ani_speed*1.2);
}

void SortScene::selectionSort()
{
    for (int i = 0; i < eleNum - 1; i++) {
        int min = Node(i)->data->value;
        for (int j = i + 1; j < eleNum; j++){
            NODE *p1=Node(i),*p2=Node(j);
            compare(p1,p2);
            if (min > (Node(j)->data->value)) {
                min = Node(j)->data->value;
                swapEle(p1,p2);
                Element* tmp=Node(i)->data;
                Node(i)->data=Node(j)->data;
                Node(j)->data=tmp;
            }
        }
    }
    SortTimer->start(*ani_speed*1.2);
}

void SortScene::insertionSort()
{
    for (int i = 0; i < eleNum - 1; i++) {
        NODE *p1=Node(i),*p2=Node(i+1);
        if (Node(i)->data->value <= Node(i + 1)->data->value)continue;
        compare(p1, p2);
        swapEle(p1, p2);

        Element* tmp=Node(i)->data;
        Node(i)->data=Node(i+1)->data;
        Node(i+1)->data=tmp;

        while (i != 0) {
            NODE *p3=Node(i),*p4=Node(i-1);
            compare(p3,p4);
            if (Node(i)->data->value >= Node(i - 1)->data->value)break;
            swapEle(p3, p4);

            Element* tmp=Node(i)->data;
            Node(i)->data=Node(i-1)->data;
            Node(i-1)->data=tmp;
            i--;
        }
    }
    SortTimer->start(*ani_speed*1.2);
}

void SortScene::quickSort()
{
    quickSort(0, eleNum - 1);
    SortTimer->start(*ani_speed*1.2);
}

void SortScene::mergeSort()
{
    if (head ==Q_NULLPTR || head->next == Q_NULLPTR)return;
    for (int n = 0; pow(2, n) < eleNum; n++) {
        int x = pow(2, n);
        if (pow(2, n + 1) >= eleNum) {
            mergeSort(x, (eleNum + x) / 2, eleNum - 1);
            mergeSort(0, x - 1, eleNum - 1);
            break;
        }
        for (int i=0; i<=eleNum-2*x;i+=2*x)
            if(i<=eleNum-2*x)
                mergeSort(i,i+x-1,i+2*x-1);
    }
    SortTimer->start(*ani_speed*1.2);
}

void SortScene::swapEle(NODE*& p1, NODE*& p2)
{
//    qDebug()<<p1->data->value<<" and "<<p2->data->value<<" exchanged";
    ele_set change;
    change.push_back(p1->data);
    change.push_back(p2->data);
    change_list.push_back(change);
    QPropertyAnimation *ani_1=new QPropertyAnimation(p1->data,"pos");
    QPropertyAnimation *ani_2=new QPropertyAnimation(p2->data,"pos");
    QParallelAnimationGroup *ParaGroup=new QParallelAnimationGroup;

    ani_1->setStartValue(p1->data->tmp_pos);
    ani_1->setEndValue(p2->data->tmp_pos+QPointF(0,p2->data->value-p1->data->value));

    ani_2->setStartValue(p2->data->tmp_pos);
    ani_2->setEndValue(p1->data->tmp_pos+QPointF(0,p1->data->value-p2->data->value));

    ani_1->setDuration(*ani_speed);
    ani_2->setDuration(*ani_speed);

    ParaGroup->addAnimation(ani_1);
    ParaGroup->addAnimation(ani_2);

    ani_list.push_back(ParaGroup);
    QPointF tmp=p1->data->tmp_pos;
    p1->data->tmp_pos=p2->data->tmp_pos+QPointF(0,p2->data->value-p1->data->value);
    p2->data->tmp_pos=tmp+QPointF(0,p1->data->value-p2->data->value);
}

void SortScene::compare(SortScene::NODE *p1, SortScene::NODE *&p2)
{
//    qDebug()<<p1->data->value<<" and "<<p2->data->value<<" compared";
    ele_set change;
    change.push_back(p1->data);
    change.push_back(p2->data);
    change_list.push_back(change);
    QPropertyAnimation *ani_1=new QPropertyAnimation(p1->data,"pos");
    QPropertyAnimation *ani_2=new QPropertyAnimation(p2->data,"pos");
    QParallelAnimationGroup *ParaGroup=new QParallelAnimationGroup;

    ani_1->setStartValue(p1->data->tmp_pos);
    ani_1->setEndValue(p1->data->tmp_pos);

    ani_2->setStartValue(p2->data->tmp_pos);
    ani_2->setEndValue(p2->data->tmp_pos);

    ani_1->setDuration(*ani_speed);
    ani_2->setDuration(*ani_speed);

    ParaGroup->addAnimation(ani_1);
    ParaGroup->addAnimation(ani_2);

    ani_list.push_back(ParaGroup);
}

void SortScene::createList()
{
    head=new NODE;
    NODE* p = head;
    for (auto& r : ele_vec) {
        p->data = r;
        if (&r != &ele_vec[eleNum-1]) {
            p->next = new NODE;
            p = p->next;
        }
    }
}

SortScene::NODE* SortScene::Node(int x)
{
    if (x > eleNum)
            return Q_NULLPTR;
    NODE* p = head;
    for (int i = 0; i < x; i++)
        p = p->next;
    return p;
}

void SortScene::dealTimer()
{
    if(ani_list.size()==0){
        if(recover_list.size()!=0){
            recover_list[0][0]->setColor(QColor(255,192,203));
            recover_list[0][1]->setColor(QColor(255,192,203));
            views()[0]->viewport()->update();
            recover_list.pop_front();
        }
        SortTimer->stop();
//        qDebug()<<"timer destructed";
        return;
    }
    if(change_list.size()!=0){
        change_list[0][0]->setColor(QColor(107,142,35));
        change_list[0][1]->setColor(QColor(107,142,35));
        views()[0]->viewport()->update();
    }
    if(change_list.size()!=0&&recover_list.size()!=0){
        if(recover_list[0][0]!=change_list[0][0]&&recover_list[0][0]!=change_list[0][1])
            recover_list[0][0]->setColor(QColor(255,192,203));
        if(recover_list[0][1]!=change_list[0][0]&&recover_list[0][1]!=change_list[0][1])
            recover_list[0][1]->setColor(QColor(255,192,203));
        views()[0]->viewport()->update();
        recover_list.pop_front();
    }
    ani_list[0]->start(QAbstractAnimation::DeleteWhenStopped);
    ani_list.pop_front();
    if(change_list.size()!=0){
        recover_list.push_back(change_list[0]);
        change_list.pop_front();
    }
}

void SortScene::quickSort(int beg, int end)
{
    if (beg >= end)return;
    int i = beg;
    int j = end + 1;
    int pivot = Node(beg)->data->value;
    while (true) {
        while (Node(++i)->data->value < pivot){
            NODE *p1=Node(i),*p2=Node(end);
            compare(p1, p2);
            if (i == end)break;
        }
        while (Node(--j)->data->value > pivot){
            NODE *p1=Node(j),*p2=Node(beg);
            compare(p1, p2);
            if (j == beg)break;
        }
        NODE *p1=Node(i),*p2=Node(j);
        compare(p1,p2);
        if (i >= j)break;
        swapEle(p1, p2);
        Element* tmp=Node(i)->data;
        Node(i)->data=Node(j)->data;
        Node(j)->data=tmp;
    }
    NODE *p3=Node(beg),*p4=Node(j);
    compare(p3, p4);
    swapEle(p3, p4);
    Element* tmp=Node(beg)->data;
    Node(beg)->data=Node(j)->data;
    Node(j)->data=tmp;

    quickSort(beg, j - 1);
    quickSort(j + 1, end);
}

void SortScene::mergeSort(int a, int b, int c)
{
    if ((a >= c)||(b>=c))return;

//    qDebug()<<"Sort from "<<Node(a)->data->value<<","<<Node(b)->data->value<<" to "<<Node(c)->data->value;
    QPointF initial_pos=Node(a)->data->tmp_pos;
    QPointF current_pos=Node(a)->data->tmp_pos+QPointF(-30,sceneRect().y());
    Element *initial_ele=Node(a)->data;
    Element *current_ele=Node(a)->data;

    int i = a, j = b + 1;
    for (int k = 0; k < c - a + 1; k++){
        if (i >= b + 1 && j <= c) {
            int y_change=Node(j)->data->value;
            ani_list.push_back(drag(Node(j)->data,current_pos+QPointF(30,current_ele->value-y_change)));
            current_pos=Node(j)->data->tmp_pos;
            current_ele=Node(j)->data;
            j++;
            continue;
        }
        if (j >= c + 1 && i <= b) {
            int y_change=Node(i)->data->value;
            ani_list.push_back(drag(Node(i)->data,current_pos+QPointF(30,current_ele->value-y_change)));
            current_pos=Node(i)->data->tmp_pos;
            current_ele=Node(i)->data;
            i++;
            continue;
        }
        if (Node(i)->data->value < Node(j)->data->value) {
            int y_change=Node(i)->data->value;
            ani_list.push_back(drag(Node(i)->data,current_pos+QPointF(30,current_ele->value-y_change)));
            current_pos=Node(i)->data->tmp_pos;
            current_ele=Node(i)->data;
            i++;
            continue;
        }
        int y_change=Node(j)->data->value;
        ani_list.push_back(drag(Node(j)->data,current_pos+QPointF(30,current_ele->value-y_change)));
        current_ele=Node(j)->data;
        current_pos=Node(j)->data->tmp_pos;
        j++;
    }
    for(int i=a;i<c+1;i++){
        Node(i)->data=tmp_vec[i-a];
        ani_list.push_back(drag(tmp_vec[i-a],initial_pos+QPointF(30*(i-a),initial_ele->value-tmp_vec[i-a]->value)));
//        qDebug()<<tmp_vec[i-a]->value<<" drag back";
    }
    while(tmp_vec.size()!=0)
        tmp_vec.pop_back();
}

QParallelAnimationGroup *SortScene::drag(Element *ele, QPointF pos)
{
    QParallelAnimationGroup* group=new QParallelAnimationGroup;
    QPropertyAnimation *ani=new QPropertyAnimation(ele,"pos");
    ani->setStartValue(ele->tmp_pos);
    ani->setEndValue(pos);
    ani->setDuration(*ani_speed);
    ele->tmp_pos=pos;
    group->addAnimation(ani);
    tmp_vec.push_back(ele);
    return group;
}
