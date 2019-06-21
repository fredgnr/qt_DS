#ifndef DSWIDGET_H
#define DSWIDGET_H

#include <QWidget>
#include<QButtonGroup>
namespace Ui {
class DSWidget;
}

class DSWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DSWidget(QWidget *parent = 0);
    ~DSWidget();
private:
    Ui::DSWidget *ui;
    QButtonGroup *group;
    QWidget *widget;
public slots:
    void graphptn_down();
    void queenptn_down();
    void sortptn_down();
    void hanoipt_down();
    void queueptn_down();
    void linkptn_down();
    void stackptn_down();
    void infixptn_down();
};

#endif // DSWIDGET_H
