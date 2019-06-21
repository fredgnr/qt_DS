#include "hanoiscene.h"
#include <QDebug>

HanoiScene::HanoiScene()
{
    for(int i=0;i<3;i++){
        HanoiPillar *pillar=new HanoiPillar;
        pillar_vec.push_back(pillar);
        addItem(pillar);
        pillar->setPos((i-1)*300,-100);
        pillar->index=i;
    }
    ani_speed=new int(1000);
}

void HanoiScene::setDishes()
{
    for(int i=0;i<dishNum;i++){
        HanoiDish *dish=new HanoiDish;
        dish_vec.push_back(dish);
        addItem(dish);
        dish->setPos(QPoint(-300,-100)+QPoint(100-0.5*dish->width+5*i,190-10*i));
        dish->position[0]=dish->scenePos();
        dish->width-=10*i;
        dish->current_pillar=pillar_vec[0];
        pillar_vec[0]->dishes.push_back(dish);
    }
    qDebug()<<"pillarA"<<pillar_vec[0]->dishes.size();
}

void HanoiScene::moveDishes(int dish_nums, HanoiPillar *A, HanoiPillar *B, HanoiPillar *C)
{
    if(dish_nums==1){
        group.addAnimation(dish_vec[dishNum-1]->move(C));
    }
    else{
        moveDishes(dish_nums-1,A,C,B);
        group.addAnimation(dish_vec[dishNum-dish_nums]->move(C));
        moveDishes(dish_nums-1,B,A,C);
    }
}
