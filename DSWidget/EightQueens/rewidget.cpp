#include "rewidget.h"
#include "ui_rewidget.h"
#include<QFile>
#include<QPushButton>
#pragma execution_character_set("utf-8")
ReWidget::ReWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReWidget)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("Eight Queens"));
    myScene=new QueenScene;
    ui->graphicsView->setScene(myScene);
    myThread=new WorkThread;
    connect(myThread,SIGNAL(thrdSetQueen(int*)),this,SLOT(wgtSetQueen(int*)));
    code_scene=new fadecodescene(ui->graphicsView_2->width()-3,ui->graphicsView_2->height()-3);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    ui->spinBox->setMinimum(6);
    ui->spinBox->setMaximum(10);
    ui->spinBox->setValue(8);
    QPushButton *button=new QPushButton(tr("停止"),this);
    connect(button,SIGNAL(clicked(bool)),this,SLOT(get_thread_finish()));
    button->move(900,600);
    hide();
}

ReWidget::~ReWidget()
{
    delete ui;
    if(myThread->isRunning()){
        myThread->terminate();
        myThread->wait();
    }
}

void ReWidget::wgtSetQueen(int *Q)
{
    for(int i=1;i<=8;i++)
        myScene->SceneQueens[i]=Q[i];
    myScene->sceneSetQueen();
}

void ReWidget::on_pushButton_clicked()
{
    if(ui->spinBox->value()==0)return;
    myScene->queen_num=ui->spinBox->value();
    myScene->setSceneRect(-0.5,-0.5,0.5+40*myScene->queen_num,0.5+40*myScene->queen_num);
    myScene->setGrids();
    ui->pushButton->setDisabled(true);
}

void ReWidget::on_pushButton_2_clicked()
{
    code_scene->clear();
    QList<QString> str_list;
    str_list.push_back("for row<-1 to n setQueen(row)");
    str_list.push_back("procedure setQueen(row)");
    str_list.push_back("\t\tfor column<-1 to n");
    str_list.push_back("\t\t\t\tif check(row,column)");
    str_list.push_back("\t\t\t\t\t\tthen Queens[row]<-column");
    str_list.push_back("\t\t\t\t\t\tif row==n then return");
    str_list.push_back("\t\t\t\t\t\telse setQueen(row+1)");
    str_list.push_back("end");
    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    myThread->n=myScene->queen_num;
    myScene->SceneQueens=new int[myScene->queen_num];
    myThread->start();
    ui->pushButton_2->setDisabled(true);
}
#include"QDebug"
void ReWidget::get_thread_finish()
{
    qDebug()<<"结束";
    if(myThread->isRunning()){
        myThread->terminate();
        myThread->wait();
    }
    code_scene->clear();
    delete myScene;
    myScene=new QueenScene;
    ui->graphicsView->setScene(myScene);
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
}

