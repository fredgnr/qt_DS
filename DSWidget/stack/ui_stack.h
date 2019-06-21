/********************************************************************************
** Form generated from reading UI file 'stack.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACK_H
#define UI_STACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stack
{
public:
    QGridLayout *gridLayout;
    QSplitter *hSplitter;
    QSplitter *vSplitter;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *initButton;
    QPushButton *clearButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *pushEdit;
    QPushButton *pushButton;
    QFrame *line_2;
    QPushButton *popButton;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *statusEdit;

    void setupUi(QWidget *Stack)
    {
        if (Stack->objectName().isEmpty())
            Stack->setObjectName(QStringLiteral("Stack"));
        Stack->setWindowModality(Qt::ApplicationModal);
        Stack->resize(800, 800);
        gridLayout = new QGridLayout(Stack);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hSplitter = new QSplitter(Stack);
        hSplitter->setObjectName(QStringLiteral("hSplitter"));
        hSplitter->setOrientation(Qt::Horizontal);
        vSplitter = new QSplitter(hSplitter);
        vSplitter->setObjectName(QStringLiteral("vSplitter"));
        vSplitter->setOrientation(Qt::Vertical);
        graphicsView = new QGraphicsView(vSplitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        vSplitter->addWidget(graphicsView);
        hSplitter->addWidget(vSplitter);
        layoutWidget = new QWidget(hSplitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        initButton = new QPushButton(layoutWidget);
        initButton->setObjectName(QStringLiteral("initButton"));

        horizontalLayout->addWidget(initButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        pushEdit = new QLineEdit(layoutWidget);
        pushEdit->setObjectName(QStringLiteral("pushEdit"));

        horizontalLayout_2->addWidget(pushEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        popButton = new QPushButton(layoutWidget);
        popButton->setObjectName(QStringLiteral("popButton"));

        verticalLayout->addWidget(popButton);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        statusEdit = new QLineEdit(layoutWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        horizontalLayout_3->addWidget(statusEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        hSplitter->addWidget(layoutWidget);

        gridLayout->addWidget(hSplitter, 0, 0, 1, 1);


        retranslateUi(Stack);

        QMetaObject::connectSlotsByName(Stack);
    } // setupUi

    void retranslateUi(QWidget *Stack)
    {
        Stack->setWindowTitle(QApplication::translate("Stack", "\351\241\272\345\272\217\346\240\210", 0));
        initButton->setText(QApplication::translate("Stack", "\345\210\233\345\273\272/\345\210\235\345\247\213\345\214\226", 0));
        clearButton->setText(QApplication::translate("Stack", "\346\270\205\347\251\272", 0));
        label->setText(QApplication::translate("Stack", "\345\205\245\346\240\210\345\205\203\347\264\240\345\200\274\357\274\232", 0));
        pushButton->setText(QApplication::translate("Stack", "\345\205\245\346\240\210", 0));
        popButton->setText(QApplication::translate("Stack", "\345\207\272\346\240\210", 0));
        label_2->setText(QApplication::translate("Stack", "\347\212\266\346\200\201\346\217\220\347\244\272\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Stack: public Ui_Stack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACK_H
