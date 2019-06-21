#include "dswidget.h"
#include "ui_dswidget.h"
#include"Graph/graphwidget.h"
#include"EightQueens/rewidget.h"
#include"SortWidget/sortwidget.h"
#include"HanoiTower/hanoiwidget.h"
#include"stack/stack.h"
#include"queue/queue.h"
#include"linklist/linklist.h"
#include"infix2suffix/infix2suffix.h"
#include<QFile>
DSWidget::DSWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DSWidget)
{
    ui->setupUi(this);
    widget=NULL;
    group=new QButtonGroup;
    group->addButton(ui->graphptn);
    group->addButton(ui->honoiptn);
    group->addButton(ui->queenptn);
    group->addButton(ui->sortptn);
    group->addButton(ui->infixptn);
    group->addButton(ui->linkptn);
    group->addButton(ui->queueptn);
    group->addButton(ui->stackptn);
    group->setExclusive(true);
   /* QFile qss("mystyle.qss");
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();*/
    /*setStyleSheet("background-color:white;"
                      "QPushButton{"
                      "background-color:white;"
                      "color:black;"
                      "text-align:center;"
                      "border-radius: 8px;"
                      "border: 2px groove gray;"
                      "border-style: outset;"
                      "}");*/
    connect(ui->graphptn,SIGNAL(clicked(bool)),this,SLOT(graphptn_down()));
    connect(ui->queenptn,SIGNAL(clicked(bool)),this,SLOT(queenptn_down()));
    connect(ui->sortptn,SIGNAL(clicked(bool)),this,SLOT(sortptn_down()));
    connect(ui->honoiptn,SIGNAL(clicked(bool)),this,SLOT(hanoipt_down()));
    connect(ui->stackptn,SIGNAL(clicked(bool)),this,SLOT(stackptn_down()));
    connect(ui->queueptn,SIGNAL(clicked(bool)),this,SLOT(queueptn_down()));
    connect(ui->infixptn,SIGNAL(clicked(bool)),this,SLOT(infixptn_down()));
    connect(ui->linkptn,SIGNAL(clicked(bool)),this,SLOT(linkptn_down()));
}

DSWidget::~DSWidget()
{
    delete ui;
}

void DSWidget::graphptn_down()
{
    if(widget)
        delete widget;
    widget=new GraphWidget(this);
    widget->move(200,0);
    widget->show();
}

void DSWidget::queenptn_down()
{
    if(widget)
        delete widget;
    widget=new ReWidget(this);
    widget->move(350,50);
    widget->show();
}

void DSWidget::sortptn_down()
{
    if(widget)
        delete widget;
    widget=new SortWidget(this);
    widget->move(200,10);
    widget->show();
}

void DSWidget::hanoipt_down()
{
    if(widget)
        delete widget;
    widget=new HanoiWidget(this);
    widget->move(300,100);
    widget->show();
}

void DSWidget::stackptn_down()
{
    if(widget)
        delete widget;
    widget=new Stack(this);
    widget->move(500,0);
    widget->show();
}

void DSWidget::queueptn_down()
{
    if(widget)
        delete widget;
    widget=new Queue(this);
    widget->move(500,0);
    widget->show();
}

void DSWidget::linkptn_down()
{
    if(widget)
        delete widget;
    widget=new linkList(this);
    widget->move(500,0);
    widget->show();
}

void DSWidget::infixptn_down()
{
    if(widget)
        delete widget;
    widget=new Infix2Suffix(this);
    widget->move(500,0);
    widget->show();
}
