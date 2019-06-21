#include "hanoidish.h"
#include <QPainter>
#include <QDebug>

HanoiDish::HanoiDish()
{
    width=150;
}

void HanoiDish::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QColor(255,192,203));
    painter->drawRect(0,0,width,10);
}

QRectF HanoiDish::boundingRect() const
{
    qreal penWidth=20;
    return QRectF(0-penWidth/2,0-penWidth/2,width+penWidth,10+penWidth);
}

QSequentialAnimationGroup* HanoiDish::move(HanoiPillar *des)
{

    QSequentialAnimationGroup *animation_set=new QSequentialAnimationGroup;

    QPropertyAnimation *animation[3];//三个动画
    for(int i=0;i<3;i++){
        animation[i]=new QPropertyAnimation(this,"pos");
        animation[i]->setDuration(1000);
    }

    animation[0]->setStartValue(position[0]);//第一个动画：将盘子移动到当前柱子的顶端
    animation[0]->setEndValue(current_pillar->scenePos()+QPointF((200-width)/2,-10));

    position[1]=current_pillar->scenePos()+QPointF((200-width)/2,-10);
    animation[1]->setStartValue(position[1]);//第二个动画：将盘子移动到目标柱子顶端
    animation[1]->setEndValue(des->scenePos()+QPointF((200-width)/2,-10));

    position[2]=des->scenePos()+QPointF((200-width)/2,-10);
    animation[2]->setStartValue(position[2]);//第三个动画，将盘子移动到目标柱子底端

    if(des->dishes.size()!=0){
        animation[2]->setEndValue(des->scenePos()+QPointF((200-width)/2,190-des->dishes.size()*10));
        position[0]=des->scenePos()+QPointF((200-width)/2,190-des->dishes.size()*10);
    }
    else{
        animation[2]->setEndValue(des->scenePos()+QPointF((200-width)/2,190));
        position[0]=des->scenePos()+QPoint((200-width)/2,190);
    }
    des->dishes.push_back(this);
    if(current_pillar->dishes.size()>1)
        current_pillar->dishes.pop_back();
    else if(current_pillar->dishes.size()==1){
        current_pillar->dishes.pop_back();
    }
    current_pillar=des;

    for(int i=0;i<3;i++)
        animation_set->addAnimation(animation[i]);

    return animation_set;
}
