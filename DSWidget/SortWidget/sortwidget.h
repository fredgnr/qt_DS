#ifndef SORTWIDGET_H
#define SORTWIDGET_H
#include <QWidget>
#include "sortscene.h"
#include "radixscene.h"
#include "fadecodescene.h"

namespace Ui {
class SortWidget;
}

class SortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SortWidget(QWidget *parent = 0);
    ~SortWidget();
    void setBtnDisable();
    void setBtnAble();

    SortScene *scene;
    RadixScene *rdxscene;

private slots:
    void on_pushButton_clicked();
    void on_btn1bubble_clicked();
    void on_btn2select_clicked();
    void on_btn3insert_clicked();
    void on_btn4quick_clicked();
    void on_btn5merge_clicked();
    void on_btn6radix_clicked();
    void on_pushButton_2_clicked();
    void getActivate(int);
    void on_horizontalSlider_sliderReleased();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();

private:
    fadecodescene *code_scene;
    Ui::SortWidget *ui;
};

#endif // SORTWIDGET_H
