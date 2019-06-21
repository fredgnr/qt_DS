/********************************************************************************
** Form generated from reading UI file 'queue.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUE_H
#define UI_QUEUE_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Queue
{
public:
    QGridLayout *gridLayout;
    QSplitter *hSplitter;
    QSplitter *vSplitter;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *initButton;
    QPushButton *clearButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *enQueueEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *enQueueButton;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *deQueueButton;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *statusEdit;

    void setupUi(QWidget *Queue)
    {
        if (Queue->objectName().isEmpty())
            Queue->setObjectName(QStringLiteral("Queue"));
        Queue->setWindowModality(Qt::ApplicationModal);
        Queue->resize(800, 800);
        gridLayout = new QGridLayout(Queue);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hSplitter = new QSplitter(Queue);
        hSplitter->setObjectName(QStringLiteral("hSplitter"));
        hSplitter->setOrientation(Qt::Horizontal);
        vSplitter = new QSplitter(hSplitter);
        vSplitter->setObjectName(QStringLiteral("vSplitter"));
        vSplitter->setOrientation(Qt::Vertical);
        textBrowser = new QTextBrowser(vSplitter);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        vSplitter->addWidget(textBrowser);
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

        enQueueEdit = new QLineEdit(layoutWidget);
        enQueueEdit->setObjectName(QStringLiteral("enQueueEdit"));

        horizontalLayout_2->addWidget(enQueueEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        enQueueButton = new QPushButton(layoutWidget);
        enQueueButton->setObjectName(QStringLiteral("enQueueButton"));

        horizontalLayout_3->addWidget(enQueueButton);


        verticalLayout->addLayout(horizontalLayout_3);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        deQueueButton = new QPushButton(layoutWidget);
        deQueueButton->setObjectName(QStringLiteral("deQueueButton"));

        horizontalLayout_4->addWidget(deQueueButton);


        verticalLayout->addLayout(horizontalLayout_4);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        statusEdit = new QLineEdit(layoutWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        horizontalLayout_5->addWidget(statusEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        hSplitter->addWidget(layoutWidget);

        gridLayout->addWidget(hSplitter, 0, 0, 1, 1);


        retranslateUi(Queue);

        QMetaObject::connectSlotsByName(Queue);
    } // setupUi

    void retranslateUi(QWidget *Queue)
    {
        Queue->setWindowTitle(QApplication::translate("Queue", "\351\241\272\345\272\217\351\230\237\345\210\227", Q_NULLPTR));
        initButton->setText(QApplication::translate("Queue", "\345\210\233\345\273\272/\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Queue", "\346\270\205\347\251\272", Q_NULLPTR));
        label->setText(QApplication::translate("Queue", "\345\205\245\351\230\237\345\205\203\347\264\240\345\200\274\357\274\232", Q_NULLPTR));
        enQueueButton->setText(QApplication::translate("Queue", "\345\205\245\351\230\237", Q_NULLPTR));
        deQueueButton->setText(QApplication::translate("Queue", "\345\207\272\351\230\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("Queue", "\347\212\266\346\200\201\346\217\220\347\244\272\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Queue: public Ui_Queue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUE_H
