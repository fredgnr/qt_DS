#ifndef FADECODESCENE_H
#define FADECODESCENE_H
#include<QObject>
#include<QGraphicsScene>
class FadeCode;
class fadecodescene:public QGraphicsScene
{
   Q_OBJECT
public:
    //窗口大小，这里直接给codeview->size()-QSize(3,3)
    fadecodescene(int width,int height,QObject *parent=0);
    //添加伪代码，直接输入一行就行了，但是记得添加\t来控制缩进
    void AddCode(QString &s);
    //使index对应的代码段高亮，之前的代码段恢复正常颜色
    void activate(int index);
    //清除所有代码
    void clear();
private:
    QList<FadeCode *> codelist;
    QSize size;
    int activateindex;
public slots:
    //槽，参数为对应高亮的代码段的索引，直接connect就好
    void Get_Activate(int index);
};

#endif // FADECODESCENE_H
