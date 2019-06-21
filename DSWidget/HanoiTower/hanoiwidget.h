#ifndef HANOIWIDGET_H
#define HANOIWIDGET_H

#include <QWidget>
#include "hanoiscene.h"
#include "fadecodescene.h"
#pragma execution_character_set("utf-8")
namespace Ui {
class HanoiWidget;
}

class HanoiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HanoiWidget(QWidget *parent = 0);
    ~HanoiWidget();

private:
    Ui::HanoiWidget *ui;
    HanoiScene *scene;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_verticalSlider_sliderReleased();
private:
    fadecodescene *code_scene;
    bool pause;
};

#endif // HANOIWIDGET_H
