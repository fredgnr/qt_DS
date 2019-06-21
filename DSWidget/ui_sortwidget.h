/********************************************************************************
** Form generated from reading UI file 'sortwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTWIDGET_H
#define UI_SORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortWidget
{
public:
    QPushButton *btn5merge;
    QPushButton *pushButton_3;
    QPushButton *btn2select;
    QGraphicsView *graphicsView;
    QPushButton *btn1bubble;
    QPushButton *btn3insert;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btn4quick;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton_2;
    QPushButton *btn6radix;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QSlider *horizontalSlider;

    void setupUi(QWidget *SortWidget)
    {
        if (SortWidget->objectName().isEmpty())
            SortWidget->setObjectName(QStringLiteral("SortWidget"));
        SortWidget->resize(1419, 831);
        btn5merge = new QPushButton(SortWidget);
        btn5merge->setObjectName(QStringLiteral("btn5merge"));
        btn5merge->setGeometry(QRect(1140, 610, 93, 28));
        pushButton_3 = new QPushButton(SortWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1190, 730, 93, 28));
        btn2select = new QPushButton(SortWidget);
        btn2select->setObjectName(QStringLiteral("btn2select"));
        btn2select->setGeometry(QRect(1240, 530, 93, 28));
        graphicsView = new QGraphicsView(SortWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 1071, 791));
        btn1bubble = new QPushButton(SortWidget);
        btn1bubble->setObjectName(QStringLiteral("btn1bubble"));
        btn1bubble->setGeometry(QRect(1140, 530, 93, 28));
        btn3insert = new QPushButton(SortWidget);
        btn3insert->setObjectName(QStringLiteral("btn3insert"));
        btn3insert->setGeometry(QRect(1140, 570, 93, 28));
        label = new QLabel(SortWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1180, 300, 72, 15));
        lineEdit = new QLineEdit(SortWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(1180, 320, 91, 21));
        btn4quick = new QPushButton(SortWidget);
        btn4quick->setObjectName(QStringLiteral("btn4quick"));
        btn4quick->setGeometry(QRect(1240, 570, 93, 28));
        graphicsView_2 = new QGraphicsView(SortWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(1090, 0, 321, 251));
        pushButton_2 = new QPushButton(SortWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1180, 410, 93, 28));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        btn6radix = new QPushButton(SortWidget);
        btn6radix->setObjectName(QStringLiteral("btn6radix"));
        btn6radix->setGeometry(QRect(1240, 610, 93, 28));
        pushButton_4 = new QPushButton(SortWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1190, 690, 93, 28));
        pushButton = new QPushButton(SortWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1180, 350, 93, 28));
        horizontalSlider = new QSlider(SortWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(1150, 470, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(SortWidget);

        QMetaObject::connectSlotsByName(SortWidget);
    } // setupUi

    void retranslateUi(QWidget *SortWidget)
    {
        SortWidget->setWindowTitle(QApplication::translate("SortWidget", "SortWidget", 0));
        btn5merge->setText(QApplication::translate("SortWidget", "\345\275\222\345\271\266\346\216\222\345\272\217", 0));
        pushButton_3->setText(QApplication::translate("SortWidget", "\351\207\215\347\275\256", 0));
        btn2select->setText(QApplication::translate("SortWidget", "\351\200\211\346\213\251\346\216\222\345\272\217", 0));
        btn1bubble->setText(QApplication::translate("SortWidget", "\345\206\222\346\263\241\346\216\222\345\272\217", 0));
        btn3insert->setText(QApplication::translate("SortWidget", "\346\217\222\345\205\245\346\216\222\345\272\217", 0));
        label->setText(QApplication::translate("SortWidget", "\346\267\273\345\212\240\346\225\260\345\255\227\357\274\232", 0));
        btn4quick->setText(QApplication::translate("SortWidget", "\345\277\253\351\200\237\346\216\222\345\272\217", 0));
        pushButton_2->setText(QApplication::translate("SortWidget", "\351\232\217\346\234\272\347\224\237\346\210\220", 0));
        btn6radix->setText(QApplication::translate("SortWidget", "\345\237\272\346\225\260\346\216\222\345\272\217", 0));
        pushButton_4->setText(QApplication::translate("SortWidget", "\345\201\234\346\255\242\345\212\250\347\224\273", 0));
        pushButton->setText(QApplication::translate("SortWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SortWidget: public Ui_SortWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTWIDGET_H
