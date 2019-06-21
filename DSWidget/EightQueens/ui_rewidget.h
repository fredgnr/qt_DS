/********************************************************************************
** Form generated from reading UI file 'rewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REWIDGET_H
#define UI_REWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReWidget
{
public:
    QGraphicsView *graphicsView;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView_2;

    void setupUi(QWidget *ReWidget)
    {
        if (ReWidget->objectName().isEmpty())
            ReWidget->setObjectName(QStringLiteral("ReWidget"));
        ReWidget->resize(1130, 704);
        graphicsView = new QGraphicsView(ReWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 761, 621));
        spinBox = new QSpinBox(ReWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(920, 450, 46, 22));
        pushButton = new QPushButton(ReWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(900, 500, 93, 28));
        pushButton_2 = new QPushButton(ReWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(900, 550, 93, 28));
        graphicsView_2 = new QGraphicsView(ReWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(790, 20, 331, 271));

        retranslateUi(ReWidget);

        QMetaObject::connectSlotsByName(ReWidget);
    } // setupUi

    void retranslateUi(QWidget *ReWidget)
    {
        ReWidget->setWindowTitle(QApplication::translate("ReWidget", "ReWidget", 0));
        pushButton->setText(QApplication::translate("ReWidget", "\347\241\256\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("ReWidget", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class ReWidget: public Ui_ReWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REWIDGET_H
