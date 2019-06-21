#include "hanoiwidget.h"
#include "ui_hanoiwidget.h"
#include <QDebug>
#include<QFile>
#pragma execution_character_set("utf-8")
HanoiWidget::HanoiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HanoiWidget)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("Hanoi Tower"));
    scene=new HanoiScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-300.5,-100.5,801,201);
    code_scene=new fadecodescene(ui->graphicsView_2->width()-3,ui->graphicsView_2->height()-3);
    pause=false;
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    ui->verticalSlider->setMaximum(1600);
    ui->verticalSlider->setMinimum(400);
    ui->verticalSlider->setSliderPosition(1000);
    hide();
}

HanoiWidget::~HanoiWidget()
{
    delete ui;
}
void HanoiWidget::on_pushButton_clicked()
{
    scene->clear();
    delete scene;
    scene=new HanoiScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-300.5,-100.5,801,201);
    QList<QString> str_list;
    str_list.push_back("procedure HanoiTower(n,A,B,C)");
    str_list.push_back("\t\tif n==1");
    str_list.push_back("\t\t\t\tthen move a[1] from A to C");
    str_list.push_back("\t\telse");
    str_list.push_back("\t\t\t\tHanoiTower(n-1,A,C,B)");
    str_list.push_back("\t\t\t\tmove a[n] from A to C");
    str_list.push_back("\t\t\t\tHanoiTower(n-1,B,C,A)");
    str_list.push_back("end");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);

    int value=ui->spinBox->value();
    scene->dishNum=value;
    scene->setDishes();
}

void HanoiWidget::on_pushButton_2_clicked()
{
    if(ui->spinBox->value()==0)return;
    scene->clear();
    delete scene;
    scene=new HanoiScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-300.5,-100.5,801,201);
    code_scene->clear();
    delete code_scene;
    code_scene=new fadecodescene(ui->graphicsView_2->width()-3,ui->graphicsView_2->height()-3);
    ui->pushButton->setDisabled(false);
}

void HanoiWidget::on_pushButton_3_clicked()
{
    scene->moveDishes(scene->dishNum,scene->pillar_vec[0],scene->pillar_vec[1],scene->pillar_vec[2]);
    scene->group.start();
    ui->pushButton->setDisabled(true);
}

void HanoiWidget::on_pushButton_4_clicked()
{
    if(!pause){
        scene->group.pause();
        ui->pushButton_4->setText(QString("继续"));
        pause=true;
    }
    else{
        scene->group.resume();
        ui->pushButton_4->setText(QString("暂停"));
        pause=false;
    }
}

void HanoiWidget::on_verticalSlider_sliderReleased()
{
    *(scene->ani_speed)=ui->verticalSlider->sliderPosition();
        for(int i=scene->group.animationCount()-1;i>=0;i--){
            QSequentialAnimationGroup *ani_group=qobject_cast<QSequentialAnimationGroup*>(scene->group.animationAt(i));
            for(int j=ani_group->animationCount()-1;j>=0;j--){
                QPropertyAnimation *ani=qobject_cast<QPropertyAnimation*>(ani_group->animationAt(j));
                if(ani->currentLoopTime()>0)break;
                ani->setDuration(*(scene->ani_speed));
            }
        }
}

