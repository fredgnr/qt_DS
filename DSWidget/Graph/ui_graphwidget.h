/********************************************************************************
** Form generated from reading UI file 'graphwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWIDGET_H
#define UI_GRAPHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWidget
{
public:
    QGraphicsView *codeview;
    QSpinBox *mapspinbox;
    QTableWidget *tableWidget;
    QGraphicsView *testview;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *recoverptn;
    QPushButton *bfsptn;
    QPushButton *dfsptn;
    QPushButton *djsptn;
    QPushButton *primptn;

    void setupUi(QWidget *GraphWidget)
    {
        if (GraphWidget->objectName().isEmpty())
            GraphWidget->setObjectName(QStringLiteral("GraphWidget"));
        GraphWidget->resize(1600, 825);
        codeview = new QGraphicsView(GraphWidget);
        codeview->setObjectName(QStringLiteral("codeview"));
        codeview->setGeometry(QRect(830, 40, 561, 461));
        codeview->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        mapspinbox = new QSpinBox(GraphWidget);
        mapspinbox->setObjectName(QStringLiteral("mapspinbox"));
        mapspinbox->setGeometry(QRect(1330, 540, 91, 27));
        tableWidget = new QTableWidget(GraphWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(910, 530, 341, 261));
        testview = new QGraphicsView(GraphWidget);
        testview->setObjectName(QStringLiteral("testview"));
        testview->setGeometry(QRect(20, 20, 800, 800));
        testview->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        verticalLayoutWidget = new QWidget(GraphWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1310, 620, 160, 170));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recoverptn = new QPushButton(verticalLayoutWidget);
        recoverptn->setObjectName(QStringLiteral("recoverptn"));

        verticalLayout->addWidget(recoverptn);

        bfsptn = new QPushButton(verticalLayoutWidget);
        bfsptn->setObjectName(QStringLiteral("bfsptn"));

        verticalLayout->addWidget(bfsptn);

        dfsptn = new QPushButton(verticalLayoutWidget);
        dfsptn->setObjectName(QStringLiteral("dfsptn"));

        verticalLayout->addWidget(dfsptn);

        djsptn = new QPushButton(verticalLayoutWidget);
        djsptn->setObjectName(QStringLiteral("djsptn"));

        verticalLayout->addWidget(djsptn);

        primptn = new QPushButton(verticalLayoutWidget);
        primptn->setObjectName(QStringLiteral("primptn"));

        verticalLayout->addWidget(primptn);


        retranslateUi(GraphWidget);

        QMetaObject::connectSlotsByName(GraphWidget);
    } // setupUi

    void retranslateUi(QWidget *GraphWidget)
    {
        GraphWidget->setWindowTitle(QApplication::translate("GraphWidget", "GraphWidget", 0));
        recoverptn->setText(QApplication::translate("GraphWidget", "\346\201\242\345\244\215", 0));
        bfsptn->setText(QString());
        dfsptn->setText(QApplication::translate("GraphWidget", "DFS", 0));
        djsptn->setText(QApplication::translate("GraphWidget", "DJS", 0));
        primptn->setText(QApplication::translate("GraphWidget", "Prim", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphWidget: public Ui_GraphWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWIDGET_H
