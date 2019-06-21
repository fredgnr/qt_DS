#ifndef QUEENSCENE_H
#define QUEENSCENE_H
#include <QGraphicsScene>
#include "queengrid.h"
const int n=8;

class QueenScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QueenScene();
    ~QueenScene(){}
    void setGrids();
    QVector<QueenGrid*> grid_vec;
    void sceneSetQueen();

    int queen_num;
    int *SceneQueens;
};

#endif // QUEENSCENE_H
