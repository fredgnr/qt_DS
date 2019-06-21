/********************************************************************************
** Form generated from reading UI file 'hanoiwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANOIWIDGET_H
#define UI_HANOIWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HanoiWidget
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QSpinBox *spinBox;
    QSlider *verticalSlider;

    void setupUi(QWidget *HanoiWidget)
    {
        if (HanoiWidget->objectName().isEmpty())
            HanoiWidget->setObjectName(QStringLiteral("HanoiWidget"));
        HanoiWidget->resize(1223, 687);
        pushButton_2 = new QPushButton(HanoiWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(999, 455, 93, 28));
        pushButton = new QPushButton(HanoiWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(999, 375, 93, 28));
        label_2 = new QLabel(HanoiWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(439, 365, 72, 15));
        label = new QLabel(HanoiWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(139, 365, 72, 15));
        label_3 = new QLabel(HanoiWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(739, 365, 72, 15));
        pushButton_4 = new QPushButton(HanoiWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(999, 495, 93, 28));
        label_4 = new QLabel(HanoiWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(999, 315, 101, 16));
        pushButton_3 = new QPushButton(HanoiWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(999, 415, 93, 28));
        graphicsView = new QGraphicsView(HanoiWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 861, 471));
        graphicsView_2 = new QGraphicsView(HanoiWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(889, 15, 321, 251));
        spinBox = new QSpinBox(HanoiWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(1019, 345, 46, 22));
        verticalSlider = new QSlider(HanoiWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(1140, 330, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);

        retranslateUi(HanoiWidget);

        QMetaObject::connectSlotsByName(HanoiWidget);
    } // setupUi

    void retranslateUi(QWidget *HanoiWidget)
    {
        HanoiWidget->setWindowTitle(QApplication::translate("HanoiWidget", "HanoiWidget", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("HanoiWidget", "\351\207\215\346\226\260\350\256\276\347\275\256", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HanoiWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("HanoiWidget", "B", Q_NULLPTR));
        label->setText(QApplication::translate("HanoiWidget", "A", Q_NULLPTR));
        label_3->setText(QApplication::translate("HanoiWidget", "C", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("HanoiWidget", "\346\232\202\345\201\234", Q_NULLPTR));
        label_4->setText(QApplication::translate("HanoiWidget", "\350\256\276\347\275\256\347\233\230\345\255\220\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("HanoiWidget", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HanoiWidget: public Ui_HanoiWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANOIWIDGET_H
