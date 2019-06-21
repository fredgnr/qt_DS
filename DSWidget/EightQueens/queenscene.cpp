#include "queenscene.h"
#include <QDebug>
#include <QPainter>

QueenScene::QueenScene()
{
}

void QueenScene::setGrids()
{
    for(int i=1;i<=queen_num;i++){
        for(int j=1;j<=queen_num;j++){
            QueenGrid* grid;
            if(((i%2)&&(j%2==0))||((i%2==0)&&(j%2)))
                grid=new QueenGrid(0,QColor(255,192,203));
            else
                grid=new QueenGrid(0,Qt::white);
            grid_vec.push_back(grid);
            addItem(grid);
            grid->setPos((j-1)*40,(i-1)*40);
        }
    }
}

void QueenScene::sceneSetQueen()
{
    clear();
    for(int i=1;i<=queen_num*queen_num;i++)
        if(grid_vec.size()!=0)
            grid_vec.pop_back();

    QVector<int> QueenPos;
    QueenPos.push_back(0);
    for(int i=1;i<=queen_num;i++)
        QueenPos.push_back(i*SceneQueens[i]);
    for(int i=1;i<=queen_num;i++){
        for(int j=1;j<=queen_num;j++){
            QueenGrid* grid;
            if(QueenPos[i]==i*j)
                    grid=new QueenGrid(true,Qt::white);
            else if(((i%2)&&(j%2==0))||((i%2==0)&&(j%2))){
                grid=new QueenGrid(false,QColor(255,192,203));
            }
            else{
                grid=new QueenGrid(false,Qt::white);
            }
            grid_vec.push_back(grid);
            addItem(grid);
            grid->setPos((j-1)*40,(i-1)*40);
        }
    }
}
