#include "sortwidget.h"
#include "ui_sortwidget.h"
#include <QDebug>
#include <QTime>
#include <QtGlobal>
SortWidget::SortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortWidget)
{
    ui->setupUi(this);
    setWindowTitle("Sort");
    scene=new SortScene;
    rdxscene=new RadixScene;
    code_scene=new fadecodescene(ui->graphicsView_2->width()-3,ui->graphicsView_2->height()-3);
    ui->graphicsView->setScene(scene);
    connect(scene,SIGNAL(code_activate(int)),this,SLOT(getActivate(int)));
    ui->horizontalSlider->setMaximum(800);
    ui->horizontalSlider->setMinimum(200);
    ui->horizontalSlider->setSliderPosition(500);
    setBtnDisable();
}

SortWidget::~SortWidget()
{
    delete ui;
}

void SortWidget::setBtnDisable()
{
    ui->btn1bubble->setDisabled(true);
    ui->btn2select->setDisabled(true);
    ui->btn3insert->setDisabled(true);
    ui->btn4quick->setDisabled(true);
    ui->btn5merge->setDisabled(true);
    ui->btn6radix->setDisabled(true);
}

void SortWidget::setBtnAble()
{
    ui->btn1bubble->setDisabled(false);
    ui->btn2select->setDisabled(false);
    ui->btn3insert->setDisabled(false);
    ui->btn4quick->setDisabled(false);
    ui->btn5merge->setDisabled(false);
    ui->btn6radix->setDisabled(false);
}

void SortWidget::on_pushButton_clicked()
{
    bool ok=true;
    QString str=ui->lineEdit->text();
    scene->eleValue=str.toInt(&ok);
    scene->addElement();

    rdxscene->boxValue=str.toInt(&ok);
    rdxscene->addBox();
    ui->lineEdit->clear();
    setBtnAble();
}

void SortWidget::on_btn1bubble_clicked()
{
    ui->pushButton->setDisabled(true);
    setBtnDisable();
    code_scene->clear();
    QList<QString> str_list;
    str_list.push_back("for i<-0 to length-2");
    str_list.push_back("\t\tflag<-a[0]");
    str_list.push_back("\t\tfor j<-0 to length-i-2");
    str_list.push_back("\t\t\t\tif flag>a[j+1]");
    str_list.push_back("\t\t\t\t\t\tthen swap flag and a[j+1]");
    str_list.push_back("\t\t\t\telse then flag<-a[j+1]");
    str_list.push_back("\t\tend for");
    str_list.push_back("end for");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    scene->createList();
    scene->bubbleSort();
}

void SortWidget::on_btn2select_clicked()
{
    ui->pushButton->setDisabled(true);
    setBtnDisable();
    code_scene->clear();

    QList<QString> str_list;
    str_list.push_back("for i<-0 to length-2");
    str_list.push_back("\t\tmin<-a[i]");
    str_list.push_back("\t\tfor j<-i+1 to length-1");
    str_list.push_back("\t\t\t\tif min>a[j]");
    str_list.push_back("\t\t\t\t\t\tthen swap min and a[j],min<-a[j]");
    str_list.push_back("\t\t\t\telse then ignore");
    str_list.push_back("\t\tend for");
    str_list.push_back("end for");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    scene->createList();
    scene->selectionSort();
}

void SortWidget::on_btn3insert_clicked()
{
    ui->pushButton->setDisabled(true);
    setBtnDisable();
    code_scene->clear();

    QList<QString> str_list;
    str_list.push_back("for i<-2 to length");
    str_list.push_back("\t\tx<-a[i]");
    str_list.push_back("\t\tj<-i-1");
    str_list.push_back("\t\twhile(j>0 and a[j]>x)");
    str_list.push_back("\t\t\t\ta[j+1]<-a[j]");
    str_list.push_back("\t\t\t\tj--");
    str_list.push_back("\t\tend while");
    str_list.push_back("\t\ta[j+1]<-x");
    str_list.push_back("end for");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    scene->createList();
    scene->insertionSort();
}

void SortWidget::on_btn4quick_clicked()
{
    ui->pushButton->setDisabled(true);
    setBtnDisable();
    code_scene->clear();

    QList<QString> str_list;
    str_list.push_back("procedure quicksort(low,high)");
    str_list.push_back("\t\tx<-a[low],i<-low,j<-high");
    str_list.push_back("\t\twhile i<j");
    str_list.push_back("\t\t\t\twhile a[j]>=x j--");
    str_list.push_back("\t\t\t\t\t\tswap a[i] and a[j],i++");
    str_list.push_back("\t\t\t\twhile a[i]<=x i++");
    str_list.push_back("\t\t\t\t\t\tswap a[i] and a[j],j--");
    str_list.push_back("\t\tend while");
    str_list.push_back("\t\tquicksort(low,i-1)");
    str_list.push_back("\t\tquicksort(i+1,high)");
    str_list.push_back("end");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    scene->createList();
    scene->quickSort();
}

void SortWidget::on_btn5merge_clicked()
{
    ui->pushButton->setDisabled(true);
    setBtnDisable();
    code_scene->clear();

    QList<QString> str_list;
    str_list.push_back("while pow(2,n)<length x<-pow(2,n)");
    str_list.push_back("\t\tif pow(2,n+1)>=length");
    str_list.push_back("\t\t\t\tmergeSort(x,(length+x)/2,length-1)");
    str_list.push_back("\t\t\t\tmergeSort(0,x-1,length-1)");
    str_list.push_back("\t\tfor i<-0 to length-2*x");
    str_list.push_back("\t\t\t\tmergeSort(i,i+x-1,i+2*x-1),i+=2*x");
    str_list.push_back("\t\tn++");
    str_list.push_back("end while");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    scene->createList();
    scene->mergeSort();
}

void SortWidget::on_btn6radix_clicked()
{
    ui->pushButton->setDisabled(true);
    setBtnDisable();
    code_scene->clear();

    QList<QString> str_list;
    str_list.push_back("for x<-1 to maxBit radixSort(x)");
    str_list.push_back("procedure radixSort(x)");
    str_list.push_back("\t\tbucket[10]");
    str_list.push_back("\t\tfor i<-0 to length");
    str_list.push_back("\t\t\t\tj<-num of a[i] on Bit x");
    str_list.push_back("\t\t\t\tput a[i] into bucket[j]");
    str_list.push_back("\t\tfor i<-0 to length");
    str_list.push_back("\t\t\t\tpush a[i] back");
    str_list.push_back("end");

    for(int i=0;i<str_list.size();i++)
        code_scene->AddCode(str_list[i]);

    ui->graphicsView_2->setScene(code_scene);
    rdxscene->sort_scene=scene;
    rdxscene->createList();
    ui->graphicsView->setScene(rdxscene);
    rdxscene->radixSort();
}

void SortWidget::on_pushButton_2_clicked()
{
    setBtnAble();
    delete scene;
    scene=new SortScene;
    ui->graphicsView->setScene(scene);
    connect(scene,SIGNAL(code_activate(int)),this,SLOT(getActivate(int)));
//    ui->pushButton->setDisabled(true);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=0; i<20; i++)
    {
        scene->eleValue=qrand()%300;
        scene->addElement();
        rdxscene->boxValue=scene->eleValue;
        rdxscene->addBox();
    }
    ui->pushButton_2->setDisabled(true);
}

void SortWidget::getActivate(int x)
{
    code_scene->activate(x);
}

void SortWidget::on_horizontalSlider_sliderReleased()
{
    *(scene->ani_speed)=ui->horizontalSlider->sliderPosition();
    qDebug()<<*(scene->ani_speed);
    if(scene->ani_list.size()>=2){
        scene->SortTimer->setInterval(*(scene->ani_speed)*1.2);
        for(int i=0;i<scene->ani_list.size();i++)
            for(int j=0;j<scene->ani_list[i]->animationCount();j++){
                QPropertyAnimation *ani=qobject_cast<QPropertyAnimation*>(scene->ani_list[i]->animationAt(j));
                ani->setDuration(*(scene->ani_speed));
            }
    }

    *(rdxscene->ani_speed)=ui->horizontalSlider->sliderPosition();
    if(rdxscene->ani_list.size()>=2){
        rdxscene->RadixTimer->setInterval(*(rdxscene->ani_speed)*1.2);
        for(int i=0;i<rdxscene->ani_list.size();i++)
            rdxscene->ani_list[i]->setDuration(*(rdxscene->ani_speed));
    }
}

void SortWidget::on_pushButton_4_clicked()
{
    scene->ani_list.clear();
    rdxscene->ani_list.clear();
}

void SortWidget::on_pushButton_3_clicked()
{
    delete scene;
    delete rdxscene;
    delete code_scene;
    scene=new SortScene;
    ui->graphicsView->setScene(scene);
    rdxscene=new RadixScene;
    code_scene=new fadecodescene(ui->graphicsView_2->width()-3,ui->graphicsView_2->height()-3);
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
}
